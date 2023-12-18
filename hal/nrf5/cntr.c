/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "soc.h"

#include "util/misc.h"

#include "hal/cntr.h"
#include "hal/debug.h"

static uint8_t _refcount;

void cntr_init(void)
{
#if defined(CONFIG_GRTC)
	NRF_GRTC->MODE = (GRTC_MODE_SYSCOUNTEREN_Disabled <<
			  GRTC_MODE_SYSCOUNTEREN_Pos) &
			 GRTC_MODE_SYSCOUNTEREN_Msk;

	NRF_GRTC->TASKS_CLEAR = 1U;

#if defined(CONFIG_GRTC_KEEPRUNNING)
	NRF_GRTC->KEEPRUNNING =
		(GRTC_KEEPRUNNING_REQUEST0_Active <<
		 GRTC_KEEPRUNNING_REQUEST0_Pos) &
		GRTC_KEEPRUNNING_REQUEST0_Msk;
#endif

	NRF_GRTC->TIMEOUT = 5U;
	NRF_GRTC->WAKETIME = 4U;
	NRF_GRTC->INTERVAL = 0U;

	NRF_GRTC->CLKCFG = ((GRTC_CLKCFG_CLKSEL_LFXO <<
			     GRTC_CLKCFG_CLKSEL_Pos) &
			    GRTC_CLKCFG_CLKSEL_Msk) |
			   ((GRTC_CLKCFG_CLKFASTDIV_Min <<
			     GRTC_CLKCFG_CLKFASTDIV_Pos) &
			    GRTC_CLKCFG_CLKFASTDIV_Msk);

	NRF_GRTC->EVENTS_COMPARE[0] = 0U;
	NRF_GRTC->EVENTS_COMPARE[1] = 0U;
	NRF_GRTC->INTENSET0 = (GRTC_INTENSET0_COMPARE0_Msk |
			       GRTC_INTENSET0_COMPARE1_Msk);

	NRF_GRTC->MODE = ((GRTC_MODE_SYSCOUNTEREN_Enabled <<
			   GRTC_MODE_SYSCOUNTEREN_Pos) &
			  GRTC_MODE_SYSCOUNTEREN_Msk) |
#if defined(CONFIG_GRTC_AUTOEN_CPUACTIVE)
			 ((GRTC_MODE_AUTOEN_CpuActive <<
			   GRTC_MODE_AUTOEN_Pos) &
			  GRTC_MODE_AUTOEN_Msk) |
#endif
#if defined(CONFIG_GRTC_AUTOEN_DEFAULT)
			 ((GRTC_MODE_AUTOEN_Default <<
			   GRTC_MODE_AUTOEN_Pos) &
			  GRTC_MODE_AUTOEN_Msk) |
#endif
			 0U;

	NRF_GRTC->TASKS_START = 1U;

	/* Wait for a counter value change */
	uint32_t value;

	value = cntr_cnt_get();
	while (cntr_cnt_get() == value);

#else
	NRF_RTC->PRESCALER = 0;
	NRF_RTC->EVTENSET = (RTC_EVTENSET_COMPARE0_Msk |
			     RTC_EVTENSET_COMPARE1_Msk);
	NRF_RTC->INTENSET = (RTC_INTENSET_COMPARE0_Msk |
			     RTC_INTENSET_COMPARE1_Msk);
#endif
}

uint32_t cntr_start(void)
{
	if (_refcount++) {
		return 1;
	}

#if defined(CONFIG_GRTC)
	/* TODO: */
#else
	NRF_RTC->TASKS_START = 1;
#endif

	return 0;
}

uint32_t cntr_stop(void)
{
	ASSERT(_refcount);

	if (--_refcount) {
		return 1;
	}

#if defined(CONFIG_GRTC)
	/* TODO: */
#else
	NRF_RTC->TASKS_STOP = 1;
#endif

	return 0;
}

uint32_t cntr_cnt_get(void)
{
#if defined(CONFIG_GRTC)
	uint32_t l, h, ho;

	/* NOTE: For a 32-bit implementation, L value is read after H
	 *       to avoid another L value after SYSCOUNTER gets ready.
	 *       If both H and L values are desired, then swap the order and
	 *       ensure that L value does not change when H value is read.
	 */
	do {
		h = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERH;
		l = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERL;
		ho = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERH;
	} while ((h & GRTC_SYSCOUNTER_SYSCOUNTERH_BUSY_Msk) ||
		 (ho & GRTC_SYSCOUNTER_SYSCOUNTERH_OVERFLOW_Msk));

	return l;
#else
	return NRF_RTC->COUNTER;
#endif
}

void cntr_cmp_set(uint8_t cmp, uint32_t value)
{
#if defined(CONFIG_GRTC)
	uint32_t l, h, ho, stale;

	/* Disable capture/compare */
	NRF_GRTC->CC[cmp].CCEN = 0U;

	/* NOTE: We are going to use TASKS_CAPTURE to read current
	 *       SYSCOUNTER H and L, so that COMPARE registers can be set
	 *       considering that we need to set H compare value too.
	 */

	/* Read current syscounter value */
	do {
		h = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERH;
		l = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERL;
		ho = NRF_GRTC->SYSCOUNTER[0].SYSCOUNTERH;
	} while ((h & GRTC_SYSCOUNTER_SYSCOUNTERH_BUSY_Msk) ||
		 (ho & GRTC_SYSCOUNTER_SYSCOUNTERH_OVERFLOW_Msk));

	/* Set a stale value in capture value */
	stale = l - 1U;
	NRF_GRTC->CC[cmp].CCL = stale;

	/* Trigger a capture */
	NRF_GRTC->TASKS_CAPTURE[cmp] = 1U;

	/* Wait to get a new L value */
	do {
		l = NRF_GRTC->CC[cmp].CCL;
	} while (l == stale);

	/* Read H value */
	h = NRF_GRTC->CC[cmp].CCH;

	/* NOTE: HERE, we have h and l in sync. */

	/* Handle rollover between current and expected value */
	if (value < l) {
		h++;
	}

	/* Set compare register values */
	NRF_GRTC->CC[cmp].CCL = value;
	NRF_GRTC->CC[cmp].CCH = h & GRTC_CC_CCH_CCH_Msk;

	/* Enable compare */
	NRF_GRTC->CC[cmp].CCEN = 1U;

#else
	NRF_RTC->CC[cmp] = value;
#endif
}
