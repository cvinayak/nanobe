/*
Copyright (c) 2016, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stddef.h>
#include <stdbool.h>

#include "soc.h"
#include "board.h"
#include "cpu.h"
#include "irq.h"

#include "util/misc.h"
#include "util/util.h"
#include "util/memq.h"
#include "util/mayfly.h"

#include "hal/isr.h"
#include "hal/swi.h"
#include "hal/clock.h"
#include "hal/cntr.h"
#include "hal/ticker.h"
#include "hal/uart.h"
#include "hal/debug.h"

#include "nanobe.h"
#include "nanobe_sched.h"

#include "ticker/ticker.h"

#if UART
static char __noinit buf[256];

#define PRINT(x) do { \
			uint8_t lock; \
			\
			lock = nanobe_sched_lock(); \
			uart_tx_str(x); \
			while (!uart_tx_done()) { \
			} \
			/* clear event due to UART IRQ */ \
			cpu_sleep(); \
			nanobe_sched_unlock(lock); \
		} while (0)
#else
#define PRINT(x)
#endif

static uint8_t __noinit isr_stack[256];
static uint8_t __noinit main_stack[512];

void * const isr_stack_top = isr_stack + sizeof(isr_stack);
void * const main_stack_top = main_stack + sizeof(main_stack);

#define TICKER_INTERVAL_US    1000000UL
#define TICKER_TICKS_SLOT_US  500U

#define TICKER_NODE_COUNT     1
#define TICKER_USER_COUNT     MAYFLY_CALLER_COUNT
#define TICKER_USER0_OP_COUNT 1
#define TICKER_USER1_OP_COUNT 1
#define TICKER_USER2_OP_COUNT 1
#define TICKER_USER3_OP_COUNT (TICKER_NODE_COUNT + 1U)
#define TICKER_USER_OP_TOTAL  (TICKER_USER0_OP_COUNT + \
			       TICKER_USER1_OP_COUNT + \
			       TICKER_USER2_OP_COUNT + \
			       TICKER_USER3_OP_COUNT)
static uint8_t ALIGNED(4) ticker_nodes[TICKER_NODE_COUNT][TICKER_NODE_T_SIZE];
static uint8_t ALIGNED(4) ticker_users[TICKER_USER_COUNT][TICKER_USER_T_SIZE];
static uint8_t ALIGNED(4) ticker_user_ops[TICKER_USER_OP_TOTAL][TICKER_USER_OP_T_SIZE];

static void isr_rtc0(void *param)
{
	ARG_UNUSED(param);

	if (NRF_RTC->EVENTS_COMPARE[0]) {
		NRF_RTC->EVENTS_COMPARE[0] = 0;

		ticker_trigger(0);
	}

	if (NRF_RTC->EVENTS_COMPARE[1]) {
		NRF_RTC->EVENTS_COMPARE[1] = 0;

		ticker_trigger(1);
	}

	mayfly_run(MAYFLY_CALL_ID_1);

	if ((HAL_SWI_JOB_IRQ) == (RTC0_IRQn)) {
		mayfly_run(MAYFLY_CALL_ID_2);
	}
}

static void isr_swi_job(void *param)
{
	ARG_UNUSED(param);

	mayfly_run(MAYFLY_CALL_ID_2);
}

static uint32_t latency_max;

static void ticker_cb(uint32_t ticks_at_expire, uint32_t ticks_drift, uint32_t remainder,
		      uint16_t lazy, uint8_t force, void *context)
{
	static uint32_t tick;

	ARG_UNUSED(ticks_at_expire);
	ARG_UNUSED(ticks_drift);
	ARG_UNUSED(remainder);
	ARG_UNUSED(lazy);
	ARG_UNUSED(force);
	ARG_UNUSED(context);

	uint32_t diff;

	diff = ticker_ticks_diff_get(ticker_ticks_now_get(), ticks_at_expire);
	if (diff > latency_max) {
		latency_max = diff;
	}

	switch ((++tick) & 0x03) {
	case 1:
		DEBUG_PIN_CLR(LED1);
		break;

	case 2:
		DEBUG_PIN_SET(LED1);
		DEBUG_PIN_CLR(LED2);
		break;

	case 3:
		DEBUG_PIN_SET(LED2);
		DEBUG_PIN_CLR(LED3);
		break;

	default:
		DEBUG_PIN_SET(LED3);
		break;
	}
}

void nanobe_injection(void)
{
	uint8_t lock = nanobe_sched_lock();
	mayfly_run(MAYFLY_CALL_ID_PROGRAM);
	nanobe_sched_unlock(lock);

	return;
}

int main(void)
{
	uint32_t reset_reason;
	uint32_t ret;

#if defined(NRF51_SERIES) || defined(NRF52_SERIES)
#define NRF_RESET NRF_POWER
#elif defined(NRF5340_XXAA_APPLICATION)
#define NRF_RESET NRF_RESET_S
#elif defined(NRF5340_XXAA_NETWORK)
#define NRF_RESET NRF_RESET_NS
#endif

	reset_reason = NRF_RESET->RESETREAS;
	NRF_RESET->RESETREAS = reset_reason;

	DEBUG_INIT();
	DEBUG_PIN_INIT(LED1);
	DEBUG_PIN_INIT(LED2);
	DEBUG_PIN_INIT(LED3);

	/* Mayfly shall be initialized before any ISR executes */
	mayfly_init();

#if UART
	extern void isr_uart0(void *);
	uint32_t irqn;

	irqn = uart_init(UART_PIN_TXD, UART_PIN_RXD,
			 UART_PIN_RTS, UART_PIN_CTS, 0);
	_isr_table[irqn].isr = isr_uart0;
	irq_priority_set(irqn, 0xFF);
	irq_enable(irqn);

	PRINT("\n\n\napp_ticker.\n");

	{
		extern void assert_print(void);
		uint8_t lock;

		lock = nanobe_sched_lock();
		assert_print();
		nanobe_sched_unlock(lock);
	}
#endif

	_isr_table[POWER_CLOCK_IRQn].isr = isr_power_clock;
	irq_priority_set(POWER_CLOCK_IRQn, 0xFF);
	irq_enable(POWER_CLOCK_IRQn);

	clock_k32src_start(1);

	cntr_init();

	_isr_table[RTC0_IRQn].isr = isr_rtc0;
	irq_priority_set(RTC0_IRQn, 0xFF);
	irq_enable(RTC0_IRQn);

	if ((HAL_SWI_JOB_IRQ) != (RTC0_IRQn)) {
		_isr_table[HAL_SWI_JOB_IRQ].isr = isr_swi_job;
		irq_priority_set(HAL_SWI_JOB_IRQ, 0xFF);
		irq_enable(HAL_SWI_JOB_IRQ);
	}

	ticker_users[0][0]  = TICKER_USER0_OP_COUNT;
	ticker_users[1][0]  = TICKER_USER1_OP_COUNT;
	ticker_users[2][0]  = TICKER_USER2_OP_COUNT;
	ticker_users[3][0]  = TICKER_USER3_OP_COUNT;

	ret = ticker_init(0,
		TICKER_NODE_COUNT, ticker_nodes,
		TICKER_USER_COUNT, ticker_users,
		TICKER_USER_OP_TOTAL, ticker_user_ops,
		hal_ticker_instance0_caller_id_get,
		hal_ticker_instance0_sched,
		hal_ticker_instance0_trigger_set);
	ASSERT(!ret);

	#if UART
	{
		uint32_t ret;
		uint8_t c;

		util_sprintf(buf, "reset reason: 0x%x\n", reset_reason);
		PRINT(buf);

		if (!reset_reason) {
			PRINT("Press c to continue...\n");
			do {
				ret = uart_rx(&c);
				if (!ret) {
					cpu_sleep();
				}
			} while (!ret || (c != 'c'));
		}
	}
	#endif

	uint32_t imask;

	imask = irq_lock();

	const uint32_t ticks_now = ticker_ticks_now_get();

	for (uint8_t ticker_id = 0U; ticker_id < TICKER_NODE_COUNT; ticker_id++) {
		ret = ticker_start(0 /* instance */
			, 3 /* user */
			, ticker_id /* ticker id */
			, (ticks_now + ticker_id) /* anchor point */
			, HAL_TICKER_US_TO_TICKS(TICKER_INTERVAL_US) /* first interval */
			, HAL_TICKER_US_TO_TICKS(TICKER_INTERVAL_US) /* periodic interval */
			, HAL_TICKER_REMAINDER(TICKER_INTERVAL_US) /* remainder */
			, 0 /* lazy */
			, HAL_TICKER_US_TO_TICKS(TICKER_TICKS_SLOT_US) /* slot */
			, ticker_cb /* timeout callback function */
			, (void *)(uint32_t)ticker_id /* context */
			, 0 /* op func */
			, 0 /* op context */
			);
		ASSERT((ret == TICKER_STATUS_SUCCESS) || (ret == TICKER_STATUS_BUSY));
	}

#if UART
	const uint32_t cputime = ticker_ticks_diff_get(ticker_ticks_now_get(), ticks_now);
#endif

	irq_unlock(imask);

#if UART
	util_sprintf(buf, "main: ticker_start cputime %u\n", cputime);
	PRINT(buf);
#endif

	while (1) {
#if UART
		uint32_t uptime;

		uptime = ticker_ticks_now_get();
		util_sprintf(buf, "main: uptime %u, ticker_cb latency %u\n", uptime, latency_max);
		PRINT(buf);
#endif

		DEBUG_CPU_SLEEP(1);
		cpu_sleep();
		DEBUG_CPU_SLEEP(0);
	}
}
