/*
Copyright (c) 2012, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _CLOCK_H_
#define _CLOCK_H_

#if defined(NRF54L_SERIES)
#define HFCLKSTAT                       XO.STAT
#define LFCLKSRC                        LFCLK.SRC
#define LFCLKSTAT                       LFCLK.STAT
#define TASKS_HFCLKSTART                TASKS_XOSTART
#define TASKS_HFCLKSTOP                 TASKS_XOSTOP
#define EVENTS_HFCLKSTARTED             EVENTS_XOSTARTED
#define CLOCK_INTENSET_HFCLKSTARTED_Msk CLOCK_INTENSET_XOSTARTED_Msk
#define CLOCK_INTENCLR_HFCLKSTARTED_Msk CLOCK_INTENCLR_XOSTARTED_Msk
#define CLOCK_HFCLKSTAT_STATE_Msk       CLOCK_XO_STAT_STATE_Msk
#define CLOCK_LFCLKSTAT_STATE_Msk       CLOCK_LFCLK_STAT_STATE_Msk
#define POWER_CLOCK_IRQn                CLOCK_POWER_IRQn
#elif defined(NRF5340_XXAA_APPLICATION)
#define NRF_CLOCK        NRF_CLOCK_S
#define NRF_POWER        NRF_POWER_S
#define POWER_CLOCK_IRQn CLOCK_POWER_IRQn
#elif defined(NRF5340_XXAA_NETWORK)
#define NRF_CLOCK        NRF_CLOCK_NS
#define NRF_POWER        NRF_POWER_NS
#define POWER_CLOCK_IRQn CLOCK_POWER_IRQn
#endif

uint32_t clock_m16src_start(uint32_t blocking);
uint32_t clock_m16src_stop(void);
uint32_t clock_k32src_start(uint32_t src);
void isr_power_clock(void *param);

#endif
