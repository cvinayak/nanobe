/*
Copyright (c) 2016-2020, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "soc.h"
#include "board.h"
#include "util/misc.h"

/****************************************************************************
System
****************************************************************************/
void soc_init(void)
{
#if defined(NRF51_SERIES)
	/* Power on peripherals */
	*(uint32_t *)0x40000504 = 0xC002FFC7;

#elif defined(NRF52_SERIES)
	/* Disconnect all GPIOs */
	do {
		uint8_t i;

		NRF_GPIO->DIRCLR = 0xFFFFFFFF;

		for (i = 0; i < 32; i++) {
			NRF_GPIO->PIN_CNF[i] = 0x00000002;
		}
	} while (0);

	/* Turn on Instruction Cache */
	NRF_NVMC->ICACHECNF = (NVMC_ICACHECNF_CACHEEN_Enabled <<
			       NVMC_ICACHECNF_CACHEEN_Pos) &
			      NVMC_ICACHECNF_CACHEEN_Msk;

#elif defined(NRF5340_XXAA_APPLICATION)
	/* LFXO internal capacitors */
	NRF_OSCILLATORS_S->XOSC32KI.INTCAP =
		(OSCILLATORS_XOSC32KI_INTCAP_INTCAP_C7PF <<
		 OSCILLATORS_XOSC32KI_INTCAP_INTCAP_Pos) &
		OSCILLATORS_XOSC32KI_INTCAP_INTCAP_Msk;

	/* XL1 GPIO Pins as peripheral control */
	NRF_P0_S->PIN_CNF[0] =
		(GPIO_PIN_CNF_MCUSEL_Peripheral <<
		 GPIO_PIN_CNF_MCUSEL_Pos) &
		GPIO_PIN_CNF_MCUSEL_Msk;
	NRF_P0_S->PIN_CNF[1] =
		(GPIO_PIN_CNF_MCUSEL_Peripheral <<
		 GPIO_PIN_CNF_MCUSEL_Pos) &
		GPIO_PIN_CNF_MCUSEL_Msk;

	/* Trimming of the device. Copy all the trimming values from FICR into
	 * the target addresses. Trim until one ADDR is not initialized.
	 */
	uint32_t index = 0ul;
	for (index = 0ul;
	     index < 64ul &&
	     (uint32_t)NRF_FICR_S->TRIMCNF[index].ADDR != 0xFFFFFFFFul &&
	     (uint32_t)NRF_FICR_S->TRIMCNF[index].ADDR != 0x00000000ul;
	     index++) {
		*((volatile uint32_t *)NRF_FICR_S->TRIMCNF[index].ADDR) =
			NRF_FICR_S->TRIMCNF[index].DATA;
	}

	/* Load APPROTECT soft branch from UICR.
	 * If UICR->APPROTECT is disabled, CTRLAP->APPROTECT will be
	 * disabled.
	 */
	NRF_CTRLAP_S->APPROTECT.DISABLE = NRF_UICR_S->APPROTECT;

	/* Load SECURE APPROTECT soft branch from UICR.
	 * If UICR->SECUREAPPROTECT is disabled,
	 * CTRLAP->SECUREAPPROTECT will be disabled.
	 */
	NRF_CTRLAP_S->SECUREAPPROTECT.DISABLE = NRF_UICR_S->SECUREAPPROTECT;

#if defined(NRF5340_CPUNET_ON)
#if defined(DEBUG) && (DEBUG)
	NRF_P0_S->PIN_CNF[LED_BLINK_NET] = (GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
					    GPIO_PIN_CNF_MCUSEL_Pos) &
					   GPIO_PIN_CNF_MCUSEL_Msk;
	if (UART_PIN_TXD_NET < 32) {
		NRF_P0_S->PIN_CNF[UART_PIN_TXD_NET] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	} else {
		NRF_P1_S->PIN_CNF[UART_PIN_TXD_NET - 32] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	}

	if (UART_PIN_RXD_NET < 32) {
		NRF_P0_S->PIN_CNF[UART_PIN_RXD_NET] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	} else {
		NRF_P1_S->PIN_CNF[UART_PIN_RXD_NET - 32] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	}

	if (UART_PIN_RTS_NET < 32) {
		NRF_P0_S->PIN_CNF[UART_PIN_RTS_NET] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	} else {
		NRF_P1_S->PIN_CNF[UART_PIN_RTS_NET - 32] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	}

	if (UART_PIN_CTS_NET < 32) {
		NRF_P0_S->PIN_CNF[UART_PIN_CTS_NET] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	} else {
		NRF_P1_S->PIN_CNF[UART_PIN_CTS_NET - 32] =
			(GPIO_PIN_CNF_MCUSEL_NetworkMCU <<
			 GPIO_PIN_CNF_MCUSEL_Pos) &
			GPIO_PIN_CNF_MCUSEL_Msk;
	}
#endif /* DEBUG */

	NRF_RESET_S->NETWORK.FORCEOFF = 0;

#endif /* NRF5340_CPUNET_ON */

#elif defined(NRF5340_XXAA_NETWORK)
	/* Trimming of the device. Copy all the trimming values from FICR into
	 * the target addresses. Trim until one ADDR is not initialized.
	 */
	uint32_t index = 0ul;
	for (index = 0ul;
	     index < 64ul &&
	     (uint32_t)NRF_FICR_NS->TRIMCNF[index].ADDR != 0xFFFFFFFFul &&
	     (uint32_t)NRF_FICR_NS->TRIMCNF[index].ADDR != 0x00000000ul;
	     index++) {
		*((volatile uint32_t *)NRF_FICR_NS->TRIMCNF[index].ADDR) =
			NRF_FICR_NS->TRIMCNF[index].DATA;
	}

	/* Turn on Instruction Cache */
	NRF_NVMC_NS->ICACHECNF = (NVMC_ICACHECNF_CACHEEN_Enabled <<
			       NVMC_ICACHECNF_CACHEEN_Pos) &
			      NVMC_ICACHECNF_CACHEEN_Msk;

	/* Load APPROTECT soft branch from UICR.
	 * If UICR->APPROTECT is disabled, CTRLAP->APPROTECT will be
	 * disabled.
	 */
	NRF_CTRLAP_NS->APPROTECT.DISABLE = NRF_UICR_NS->APPROTECT;
#endif /* NRF5340_XXAA_NETWORK */

	/* SEVONPEND */
	SCB->SCR |= SCB_SCR_SEVONPEND_Msk;
}

/****************************************************************************
Assert handler
****************************************************************************/
#if UART
#include "util/util.h"
#include "hal/uart.h"
#endif

#if defined(NRF51_SERIES) || defined(NRF52_SERIES)
#define ASSERT_STACK_FRAME (0x0001F000)
#elif defined(NRF5340_XXAA_APPLICATION)
#define ASSERT_STACK_FRAME (0x0001F000)
#define NRF_NVMC NRF_NVMC_S
#define NRF_GPIO NRF_P0_S
#elif defined(NRF5340_XXAA_NETWORK)
#define ASSERT_STACK_FRAME (0x0101F000)
#define NRF_NVMC NRF_NVMC_NS
#define NRF_GPIO NRF_P0_NS
#endif

void exc_hardfault(uint32_t sp)
{
	uint32_t *p_flash = (uint32_t *) ASSERT_STACK_FRAME;
	uint32_t count = 9; /* Cortex-M0 stack frame size = 8 32-bit words, 
			     * plus SP itself to store.
			     */

	/* turn LEDs on */
	NRF_GPIO->DIRSET = 0xFFFFFFFF;
	NRF_GPIO->OUTCLR = 0xFFFFFFFF;

	/* Store SP before the stack frame */
	*((uint32_t *) (sp - 4)) = sp;
	sp -= 4;

	/* erase flash page */
#if defined(NRF51_SERIES) || defined(NRF52_SERIES)
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Een;
	NRF_NVMC->ERASEPAGE = (uint32_t) p_flash;
#elif defined(NRF5340_XXAA_APPLICATION)
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_PEen;
	*p_flash = 0xFFFFFFFF;
#elif defined(NRF5340_XXAA_NETWORK)
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_PEen;
	*p_flash = 0xFFFFFFFF;
#endif
	while (NRF_NVMC->READY == 0) {
	}

	/* write to flash */
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen;
	while (count--)	{
		*p_flash++ = *((uint32_t *)sp);
		sp += 4;
		while (NRF_NVMC->READY == 0) {
		}
	}

	*p_flash = 0;
	while (NRF_NVMC->READY == 0) {
	}
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;

	/* low power hang! */
	while(1)
	{
		__WFE();
	}
}

#if UART
void assert_print(void)
{
	uint32_t sp = ASSERT_STACK_FRAME;
	char buf[0xFF];
	char *p_buf = buf;

	if (*((uint32_t *) sp) == 0xFFFFFFFF) {
		return;
	}

	sp += 4;

	/* prepare string to write in flash */
	util_sprintf(buf, "\nAssert @ 0x%x\nStack Frame @ 0x%x\nR0: 0x%x\nR1: 0x%x\nR2: 0x%x\nR3: 0x%x\n"
		, *((uint32_t *)(sp + 0x18))
		, *((uint32_t *)(sp - 0x04))
		, *((uint32_t *)(sp + 0x00))
		, *((uint32_t *)(sp + 0x04))
		, *((uint32_t *)(sp + 0x08))
		, *((uint32_t *)(sp + 0x0C))
		);

	while (*p_buf) {
		uart_tx(*p_buf++);
	}
}
#endif
