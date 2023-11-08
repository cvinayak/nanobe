/*
Copyright (c) 2012, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "soc.h"
#include "irq.h"

#include "hal/clock.h"
#include "hal/debug.h"

static uint8_t _m16src_ref;
static uint8_t _m16src_grd;

uint32_t clock_m16src_start(uint32_t blocking)
{
	uint32_t imask;

	/* if clock is already started then just increment refcount.
	 * refcount can handle 255 (uint8_t) requests, if the start
	 * and stop dont happen in pairs, a rollover will be caught
	 * and system should assert.
	 */
	imask = irq_lock();
	if (_m16src_ref++) {
		irq_unlock(imask);
		goto hf_already_started;
	}
	if (_m16src_grd) {
		--_m16src_ref;
		irq_unlock(imask);
		return 2;
	}
	++_m16src_grd;
	irq_unlock(imask);

	if (blocking) {
		uint32_t intenset;

		irq_disable(POWER_CLOCK_IRQn);

		NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;

		intenset = NRF_CLOCK->INTENSET;
		NRF_CLOCK->INTENSET = CLOCK_INTENSET_HFCLKSTARTED_Msk;

		NRF_CLOCK->TASKS_HFCLKSTART = 1;
		while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0) {
			__WFE();
			__SEV();
			__WFE();
		}
		NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;

		if (!(intenset & CLOCK_INTENSET_HFCLKSTARTED_Msk)) {
			NRF_CLOCK->INTENCLR = CLOCK_INTENCLR_HFCLKSTARTED_Msk;
		}

		irq_pending_clear(POWER_CLOCK_IRQn);
		irq_enable(POWER_CLOCK_IRQn);
	} else {
		NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
		NRF_CLOCK->TASKS_HFCLKSTART = 1;
	}

	/* release the guard */
	--_m16src_grd;

hf_already_started:

	/* rollover should not happen as start and stop shall be
	 * called in pairs.
	 */
	ASSERT(_m16src_ref);

	return (((NRF_CLOCK->HFCLKSTAT & CLOCK_HFCLKSTAT_STATE_Msk)) ? 0 : 1);
}

uint32_t clock_m16src_stop(void)
{
	uint32_t imask;

	imask = irq_lock();
	if(!_m16src_ref) {
		irq_unlock(imask);
		return 1;
	}
	if (--_m16src_ref) {
		irq_unlock(imask);
		return 0;
	}
	if (_m16src_grd) {
		++_m16src_ref;
		irq_unlock(imask);
		return 2;
	}
	++_m16src_grd;
	irq_unlock(imask);

	NRF_CLOCK->TASKS_HFCLKSTOP = 1;

	/* release the guard */
	--_m16src_grd;

	return 0;
}

uint32_t clock_k32src_start(uint32_t src)
{
	uint32_t intenset;

	if ((NRF_CLOCK->LFCLKSTAT & CLOCK_LFCLKSTAT_STATE_Msk)) {
		return 0;
	}

	irq_disable(POWER_CLOCK_IRQn);

	NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;

	intenset = NRF_CLOCK->INTENSET;
	NRF_CLOCK->INTENSET = CLOCK_INTENSET_LFCLKSTARTED_Msk;

	NRF_CLOCK->LFCLKSRC = src;
	NRF_CLOCK->TASKS_LFCLKSTART = 1;
	while (NRF_CLOCK->EVENTS_LFCLKSTARTED == 0) {
		__WFE();
		__SEV();
		__WFE();
	}
	NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;

	if (!(intenset & CLOCK_INTENSET_LFCLKSTARTED_Msk)) {
		NRF_CLOCK->INTENCLR = CLOCK_INTENCLR_LFCLKSTARTED_Msk;
	}

	irq_pending_clear(POWER_CLOCK_IRQn);
	irq_enable(POWER_CLOCK_IRQn);

	/* Calibrate RC, and start timer for consecutive calibrations */
	NRF_CLOCK->INTENCLR = CLOCK_INTENCLR_DONE_Msk;
	NRF_CLOCK->EVENTS_DONE = 0;

#if defined(NRF52_SERIES)
	NRF_CLOCK->INTENCLR = CLOCK_INTENCLR_CTTO_Msk;
	NRF_CLOCK->EVENTS_CTTO = 0;
#endif

	if (!src) {
		uint32_t err;

		/* Enable DONE IRQs */
		NRF_CLOCK->INTENSET = CLOCK_INTENSET_DONE_Msk;

#if defined(NRF52_SERIES)
		/* Set the Calibration Timer initial value */
		NRF_CLOCK->CTIV = 16;	/* 4s in 0.25s units */

		/* Enable CTTO IRQs */
		NRF_CLOCK->INTENSET = CLOCK_INTENSET_CTTO_Msk;
#endif

		/* Start HF clock, if already started then explicitly
		 * assert IRQ
		 */
		NRF_CLOCK->INTENSET = CLOCK_INTENSET_HFCLKSTARTED_Msk;
		err = clock_m16src_start(0);
		if (!err) {
			irq_pending_set(POWER_CLOCK_IRQn);
		} else {
			ASSERT(err == 1);
		}
	}

	return ((NRF_CLOCK->LFCLKSTAT & CLOCK_LFCLKSTAT_STATE_Msk)) ? 0 : 1;
}

void isr_power_clock(void *param)
{
	uint8_t pof, sleepen, sleepex, hf_intenset, hf_stat, hf, lf, done, ctto;

	(void)param;

	pof = (NRF_POWER->EVENTS_POFWARN != 0);

#if !defined(NRF51_SERIES)
	sleepen = (NRF_POWER->EVENTS_SLEEPENTER != 0);
	sleepex = (NRF_POWER->EVENTS_SLEEPEXIT != 0);
#else
	sleepen = 1U;
	sleepex = 1U;
#endif

	hf_intenset =
	    ((NRF_CLOCK->INTENSET & CLOCK_INTENSET_HFCLKSTARTED_Msk) != 0);
	hf_stat = ((NRF_CLOCK->HFCLKSTAT & CLOCK_HFCLKSTAT_STATE_Msk) != 0);
	hf = (NRF_CLOCK->EVENTS_HFCLKSTARTED != 0);

	lf = (NRF_CLOCK->EVENTS_LFCLKSTARTED != 0);

	done = (NRF_CLOCK->EVENTS_DONE != 0);

#if defined(NRF52_SERIES)
	ctto = (NRF_CLOCK->EVENTS_CTTO != 0);
#else
	ctto = 0U;
#endif

	ASSERT(pof || sleepen || sleepex ||
	       hf || hf_intenset || lf || done || ctto);

	if (pof) {
		NRF_POWER->EVENTS_POFWARN = 0;
	}

#if !defined(NRF51_SERIES)
	if (sleepen) {
		NRF_POWER->EVENTS_SLEEPENTER = 0;
	}

	if (sleepex) {
		NRF_POWER->EVENTS_SLEEPEXIT = 0;
	}
#endif

	if (hf) {
		NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
	}

	if (hf_intenset && hf_stat) {
		NRF_CLOCK->INTENCLR = CLOCK_INTENCLR_HFCLKSTARTED_Msk;

		/* Start Calibration */
		NRF_CLOCK->TASKS_CAL = 1;
	}

	if (lf) {
		NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;

		ASSERT(0);
	}

	if (done) {
		uint32_t err;

		NRF_CLOCK->EVENTS_DONE = 0;

		/* Calibration done, stop 16M Xtal. */
		err = clock_m16src_stop();
		ASSERT(!err);

#if defined(NRF52_SERIES)
		/* Start timer for next calibration. */
		NRF_CLOCK->TASKS_CTSTART = 1;
#endif
	}

#if defined(NRF52_SERIES)
	if (ctto) {
		uint32_t err;

		NRF_CLOCK->EVENTS_CTTO = 0;

		/* Start HF clock, if already started
		 * then explicitly assert IRQ
		 */
		NRF_CLOCK->INTENSET = CLOCK_INTENSET_HFCLKSTARTED_Msk;
		err = clock_m16src_start(0);
		if (!err) {
			irq_pending_set(POWER_CLOCK_IRQn);
		} else {
			ASSERT(err == 1);
		}
	}
#endif
}
