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

#elif defined(NRF54L15_ENGA_XXAA)
	/* Set all GPIOs as output and pull down */
	NRF_P0_S->DIRSET = UINT32_MAX;
	NRF_P0_S->OUTCLR = UINT32_MAX;
	NRF_P1_S->DIRSET = UINT32_MAX;
	NRF_P1_S->OUTCLR = UINT32_MAX;
	NRF_P2_S->DIRSET = UINT32_MAX;
	NRF_P2_S->OUTCLR = UINT32_MAX;

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

	/* LFXO internal capacitors */
	#define CONFIG_SOC_LFXO_CAP_INT_VALUE_X2 31

	uint32_t xosc32ktrim = NRF_FICR->XOSC32KTRIM;

	uint32_t offset_k =
		(xosc32ktrim & FICR_XOSC32KTRIM_OFFSET_Msk) >> FICR_XOSC32KTRIM_OFFSET_Pos;

	uint32_t slope_field_k =
		(xosc32ktrim & FICR_XOSC32KTRIM_SLOPE_Msk) >> FICR_XOSC32KTRIM_SLOPE_Pos;
	uint32_t slope_mask_k = FICR_XOSC32KTRIM_SLOPE_Msk >> FICR_XOSC32KTRIM_SLOPE_Pos;
	uint32_t slope_sign_k = (slope_mask_k - (slope_mask_k >> 1));
	int32_t slope_k = (int32_t)(slope_field_k ^ slope_sign_k) - (int32_t)slope_sign_k;

	/* As specified in the nRF54L15 PS:
	 * CAPVALUE = round( (CAPACITANCE - 4) * (FICR->XOSC32KTRIM.SLOPE + 0.765625 * 2^9)/(2^9)
	 *            + FICR->XOSC32KTRIM.OFFSET/(2^6) );
	 * where CAPACITANCE is the desired capacitor value in pF, holding any
	 * value between 4 pF and 18 pF in 0.5 pF steps.
	 */
	uint32_t mid_val = ((CONFIG_SOC_LFXO_CAP_INT_VALUE_X2 - 8UL) * (uint32_t)(slope_k + 392)) +
			   (offset_k << 4UL);
	uint32_t capvalue_k = mid_val >> 10UL;

	/* Round. */
	if ((mid_val % 1024UL) >= 512UL) {
		capvalue_k++;
	}

	NRF_OSCILLATORS->XOSC32KI.INTCAP =
		(capvalue_k << OSCILLATORS_XOSC32KI_INTCAP_VAL_Pos) &
		OSCILLATORS_XOSC32KI_INTCAP_VAL_Msk;

	/* HFXO internal capacitors */
	#define CONFIG_SOC_HFXO_CAP_INT_VALUE_X4 60

	uint32_t xosc32mtrim = NRF_FICR->XOSC32MTRIM;
	/* The SLOPE field is in the two's complement form, hence this special
	 * handling. Ideally, it would result in just one SBFX instruction for
	 * extracting the slope value, at least gcc is capable of producing such
	 * output, but since the compiler apparently tries first to optimize
	 * additions and subtractions, it generates slightly less than optimal
	 * code.
	 */
	uint32_t slope_field =
		(xosc32mtrim & FICR_XOSC32MTRIM_SLOPE_Msk) >> FICR_XOSC32MTRIM_SLOPE_Pos;
	uint32_t slope_mask = FICR_XOSC32MTRIM_SLOPE_Msk >> FICR_XOSC32MTRIM_SLOPE_Pos;
	uint32_t slope_sign = (slope_mask - (slope_mask >> 1));
	int32_t slope_m = (int32_t)(slope_field ^ slope_sign) - (int32_t)slope_sign;
	uint32_t offset_m =
		(xosc32mtrim & FICR_XOSC32MTRIM_OFFSET_Msk) >> FICR_XOSC32MTRIM_OFFSET_Pos;
	/* As specified in the nRF54L15 PS:
	 * CAPVALUE = (((CAPACITANCE-5.5)*(FICR->XOSC32MTRIM.SLOPE+791)) +
	 *              FICR->XOSC32MTRIM.OFFSET<<2)>>8;
	 * where CAPACITANCE is the desired total load capacitance value in pF,
	 * holding any value between 4.0 pF and 17.0 pF in 0.25 pF steps.
	 */
	uint32_t capvalue =
		(((CONFIG_SOC_HFXO_CAP_INT_VALUE_X4 - 22UL) * (uint32_t)(slope_m + 791) / 4UL) +
		 (offset_m << 2UL)) >>
		8UL;

	NRF_OSCILLATORS->XOSC32M.CONFIG.INTCAP =
		(capvalue << OSCILLATORS_XOSC32M_CONFIG_INTCAP_VAL_Pos) &
		OSCILLATORS_XOSC32M_CONFIG_INTCAP_VAL_Msk;

	/* Disable glitch detection (reduces CPU idle current consumption) */
	NRF_GLITCHDET_S->CONFIG = 0;

	/* Disable APPROTECT */
	NRF_TAMPC->PROTECT.DOMAIN[0].DBGEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Clear <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].DBGEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_High <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Disabled <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].NIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_WRITEPROTECTION_Clear <<
		 TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_WRITEPROTECTION_Pos) |
		(TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].NIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_VALUE_High <<
		 TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_VALUE_Pos) |
		(TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_LOCK_Disabled <<
		 TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_LOCK_Pos) |
		(TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_NIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].SPIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_WRITEPROTECTION_Clear <<
		 TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_WRITEPROTECTION_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].SPIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_VALUE_High <<
		 TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_VALUE_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_LOCK_Disabled <<
		 TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_LOCK_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_SPIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].SPNIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_WRITEPROTECTION_Clear <<
		 TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_WRITEPROTECTION_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.DOMAIN[0].SPNIDEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_VALUE_High <<
		 TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_VALUE_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_LOCK_Disabled <<
		 TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_LOCK_Pos) |
		(TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_SPNIDEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.AP[0].DBGEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Clear <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_WRITEPROTECTION_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos);
	NRF_TAMPC->PROTECT.AP[0].DBGEN.CTRL =
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_High <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_VALUE_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Disabled <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_LOCK_Pos) |
		(TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_KEY <<
		 TAMPC_PROTECT_DOMAIN_DBGEN_CTRL_KEY_Pos);

	/* Disable tamper detection reset (needed to disable APPROTECT)*/
	NRF_TAMPC_S->PROTECT.GLITCHSLOWDOMAIN.CTRL = 0;
	NRF_TAMPC_S->PROTECT.GLITCHFASTDOMAIN.CTRL = 0;
	NRF_TAMPC_S->PROTECT.EXTRESETEN.CTRL = 0;
	NRF_TAMPC_S->PROTECT.INTRESETEN.CTRL = 0;

#if 0
	SCB->NSACR |= (3UL << 10ul);

	SCB->CPACR |= (3UL << 20ul) | (3UL << 22ul);
	__DSB();
	__ISB();
#endif

	NRF_NFCT_S->PADCONFIG = (NFCT_PADCONFIG_ENABLE_Disabled <<
				 NFCT_PADCONFIG_ENABLE_Pos) &
				NFCT_PADCONFIG_ENABLE_Msk;

	/* Enable DCDC */
	if (NRF_REGULATORS_S->VREGMAIN.INDUCTORDET) {
		NRF_REGULATORS_S->VREGMAIN.DCDCEN = 1U;
	}

	/* Running application at 128MHz clock frequency */
	NRF_OSCILLATORS->PLL.FREQ = OSCILLATORS_PLL_FREQ_FREQ_CK128M;
#endif /* NRF54L15_ENGA_XXAA */

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
#elif defined(NRF54L15_ENGA_XXAA)
#define ASSERT_STACK_FRAME (0x0001F000)
#define NRF_GPIO NRF_P0_S
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

#if !defined(NRF54L15_ENGA_XXAA)
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

#else /* NRF54L15_ENGA_XXAA */
	/* turn LEDs on */
	NRF_GPIO->DIRSET = 0xFFFFFFFF;
	NRF_GPIO->OUTSET = 0xFFFFFFFF;

	/* turn LEDs on */
	NRF_P1_S->DIRSET = 0xFFFFFFFF;
	NRF_P1_S->OUTSET = 0xFFFFFFFF;

	/* enable write to flash */
	NRF_RRAMC_S->CONFIG = (RRAMC_CONFIG_WEN_Enabled <<
			       RRAMC_CONFIG_WEN_Pos) &&
			      RRAMC_CONFIG_WEN_Msk;
	while (NRF_RRAMC_S->READY == 0U);

	/* write to flash */
	while (count--)	{
		*p_flash++ = *((uint32_t *)sp);
		sp += 4;
		while (NRF_RRAMC_S->READY == 0U);
	}
	*p_flash = 0U;
	while (NRF_RRAMC_S->READY == 0U);

	/* disable write to flash */
	NRF_RRAMC_S->CONFIG = (RRAMC_CONFIG_WEN_Disabled <<
			       RRAMC_CONFIG_WEN_Pos) &&
			      RRAMC_CONFIG_WEN_Msk;
#endif /* NRF54L15_ENGA_XXAA */

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
