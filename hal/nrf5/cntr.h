/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef NRF_RTC
#if defined(NRF5340_XXAA_APPLICATION)
#define NRF_RTC NRF_RTC0_S
#elif defined(NRF5340_XXAA_NETWORK)
#define NRF_RTC NRF_RTC0_NS
#else
#define NRF_RTC NRF_RTC0
#endif
#endif

void cntr_init(void);
uint32_t cntr_start(void);
uint32_t cntr_stop(void);
uint32_t cntr_cnt_get(void);
void cntr_cmp_set(uint8_t cmp, uint32_t value);
