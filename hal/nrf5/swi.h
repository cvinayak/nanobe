/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* nRF51 and nRF52 Series IRQ mapping*/
#if defined(NRF51_SERIES) || defined(NRF52_SERIES)

#define HAL_SWI_RADIO_IRQ  SWI4_IRQn
#define HAL_SWI_WORKER_IRQ RTC0_IRQn

#if !defined(CONFIG_BT_CTLR_LOW_LAT) && \
	(CONFIG_BT_CTLR_ULL_HIGH_PRIO == CONFIG_BT_CTLR_ULL_LOW_PRIO)
#define HAL_SWI_JOB_IRQ    HAL_SWI_WORKER_IRQ
#else
#define HAL_SWI_JOB_IRQ    SWI5_IRQn
#endif

/* nRF53 Series IRQ mapping */
#elif defined(NRF53_SERIES)

/* nRF53 Series Engineering D and Revision 1 IRQ mapping */
#if defined(NRF_APPLICATION)

#define HAL_SWI_RADIO_IRQ  EGU4_IRQn
#define HAL_SWI_WORKER_IRQ RTC0_IRQn
#define HAL_SWI_JOB_IRQ    EGU5_IRQn
#define SWI5_IRQn          EGU5_IRQn

#elif defined(NRF_NETWORK)

#define HAL_SWI_RADIO_IRQ  SWI2_IRQn
#define HAL_SWI_WORKER_IRQ RTC0_IRQn

#if !defined(CONFIG_BT_CTLR_LOW_LAT) && \
	(CONFIG_BT_CTLR_ULL_HIGH_PRIO == CONFIG_BT_CTLR_ULL_LOW_PRIO)
#define HAL_SWI_JOB_IRQ    HAL_SWI_WORKER_IRQ
#else
#define HAL_SWI_JOB_IRQ    SWI3_IRQn
#endif

#elif /* !NRF_NETWORK */
#error Unknown NRF5340 CPU.
#endif /* !NRF_NETWORK */

/* nRF54 Series IRQ mapping */
#elif defined(NRF54L_SERIES)

#define HAL_SWI_RADIO_IRQ  SWI02_IRQn

#if defined(CONFIG_GRTC)
#define HAL_SWI_WORKER_IRQ GRTC_0_IRQn
#define RTC0_IRQn          GRTC_0_IRQn
#else
#define HAL_SWI_WORKER_IRQ RTC10_IRQn
#define RTC0_IRQn          RTC10_IRQn
#endif

#if !defined(CONFIG_BT_CTLR_LOW_LAT) && \
	(CONFIG_BT_CTLR_ULL_HIGH_PRIO == CONFIG_BT_CTLR_ULL_LOW_PRIO)
#define HAL_SWI_JOB_IRQ    HAL_SWI_WORKER_IRQ
#else
#define HAL_SWI_JOB_IRQ    SWI03_IRQn
#endif

#endif

static inline void hal_swi_init(void)
{
	/* No platform-specific initialization required. */
}

static inline void hal_swi_lll_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_RADIO_IRQ);
}

static inline void hal_swi_worker_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_WORKER_IRQ);
}

static inline void hal_swi_job_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_JOB_IRQ);
}
