/*
Copyright (c) 2016-2020, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#define ASSERT(x) do { \
			if (!(x)) { \
				__asm__ inline volatile (".inst 0xde00\n"); \
			} \
		} while (0)

#if defined(DEBUG) && DEBUG

#include "hal/nrf5/gpio_internal.h"

#define DEBUG_PIN_INIT(p) do { \
				uint8_t x = p; \
				\
				if (x < 32) { \
					NRF_GPIO->DIRSET = (1 << x); \
					NRF_GPIO->OUTCLR = (1 << x); \
				} else if ((x >= 32) && (x < 64)) { \
					NRF_P1->DIRSET = (1 << (x - 32)); \
					NRF_P1->OUTCLR = (1 << (x - 32)); \
				} \
			  } while (0)
#define DEBUG_PIN_SET(p)  do { \
				uint8_t x = p; \
				\
				if (x < 32) { \
					NRF_GPIO->OUTSET = (1 << x); \
				} else if ((x >= 32) && (x < 64)) { \
					NRF_P1->OUTSET = (1 << (x - 32)); \
				} \
			  } while (0)
#define DEBUG_PIN_CLR(p)  do { \
				uint8_t x = p; \
				\
				if (x < 32) { \
					NRF_GPIO->OUTCLR = (1 << x); \
				} else if ((x >= 32) && (x < 64)) { \
					NRF_P1->OUTCLR = (1 << (x - 32)); \
				} \
			  } while (0)
#define DEBUG_PIN_ON(p)   do { \
				uint8_t x = p; \
				\
				if (x < 32) { \
					NRF_GPIO->OUTCLR = (1 << x); \
					NRF_GPIO->OUTSET = (1 << x); \
				} else if ((x >= 32) && (x < 64)) { \
					NRF_P1->OUTCLR = (1 << (x - 32)); \
					NRF_P1->OUTSET = (1 << (x - 32)); \
				} \
			  } while (0)
#define DEBUG_PIN_OFF(p)  do { \
				uint8_t x = p; \
				\
				if (x < 32) { \
					NRF_GPIO->OUTSET = (1 << x); \
					NRF_GPIO->OUTCLR = (1 << x); \
				} else if ((x >= 32) && (x < 64)) { \
					NRF_P1->OUTSET = (1 << (x - 32)); \
					NRF_P1->OUTCLR = (1 << (x - 32)); \
				} \
			  } while (0)
#else
#define DEBUG_PIN_INIT(x)
#define DEBUG_PIN_SET(x)
#define DEBUG_PIN_CLR(x)
#define DEBUG_PIN_ON(x)
#define DEBUG_PIN_OFF(x)
#endif

#if defined(DEBUG_PINS)
#if defined(CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP) || \
	defined(CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP_NS) || \
	defined(CONFIG_BOARD_NRF5340DK_NRF5340_CPUNET)
#define DEBUG_PORT       NRF_P1
#define DEBUG_PIN_IDX0   0
#define DEBUG_PIN_IDX1   1
#define DEBUG_PIN_IDX2   4
#define DEBUG_PIN_IDX3   5
#define DEBUG_PIN_IDX4   6
#define DEBUG_PIN_IDX5   7
#define DEBUG_PIN_IDX6   8
#define DEBUG_PIN_IDX7   9
#define DEBUG_PIN_IDX8   10
#define DEBUG_PIN_IDX9   11
#define DEBUG_PIN0       BIT(DEBUG_PIN_IDX0)
#define DEBUG_PIN1       BIT(DEBUG_PIN_IDX1)
#define DEBUG_PIN2       BIT(DEBUG_PIN_IDX2)
#define DEBUG_PIN3       BIT(DEBUG_PIN_IDX3)
#define DEBUG_PIN4       BIT(DEBUG_PIN_IDX4)
#define DEBUG_PIN5       BIT(DEBUG_PIN_IDX5)
#define DEBUG_PIN6       BIT(DEBUG_PIN_IDX6)
#define DEBUG_PIN7       BIT(DEBUG_PIN_IDX7)
#define DEBUG_PIN8       BIT(DEBUG_PIN_IDX8)
#define DEBUG_PIN9       BIT(DEBUG_PIN_IDX9)
#if defined(CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP) || \
	(defined(CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP_NS) && defined(CONFIG_BUILD_WITH_TFM))
#include <soc_secure.h>
#define DEBUG_SETUP() \
	do { \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX0, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX1, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX2, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX3, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX4, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX5, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX6, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX7, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX8, NRF_GPIO_PIN_SEL_NETWORK); \
		soc_secure_gpio_pin_mcu_select(32 + DEBUG_PIN_IDX9, NRF_GPIO_PIN_SEL_NETWORK); \
	} while (0)
#endif /* CONFIG_BOARD_NRF5340DK_NRF5340_CPUAPP */
#elif defined(CONFIG_BOARD_NRF52840DK_NRF52840) || \
	defined(CONFIG_BOARD_NRF52833DK_NRF52833)
#define DEBUG_PORT       NRF_P1
#define DEBUG_PIN0       BIT(1)
#define DEBUG_PIN1       BIT(2)
#define DEBUG_PIN2       BIT(3)
#define DEBUG_PIN3       BIT(4)
#define DEBUG_PIN4       BIT(5)
#define DEBUG_PIN5       BIT(6)
#define DEBUG_PIN6       BIT(7)
#define DEBUG_PIN7       BIT(8)
#define DEBUG_PIN8       BIT(10)
#define DEBUG_PIN9       BIT(11)
#elif defined(CONFIG_BOARD_NRF52DK_NRF52832) || \
	defined(CONFIG_BOARD_NRF52DK_NRF52810)
#define DEBUG_PORT       NRF_GPIO
#define DEBUG_PIN0       BIT(11)
#define DEBUG_PIN1       BIT(12)
#define DEBUG_PIN2       BIT(13)
#define DEBUG_PIN3       BIT(14)
#define DEBUG_PIN4       BIT(15)
#define DEBUG_PIN5       BIT(16)
#define DEBUG_PIN6       BIT(17)
#define DEBUG_PIN7       BIT(18)
#define DEBUG_PIN8       BIT(19)
#define DEBUG_PIN9       BIT(20)
#elif defined(CONFIG_BOARD_NRF51DK_NRF51422)
#define DEBUG_PORT       NRF_GPIO
#define DEBUG_PIN0       BIT(12)
#define DEBUG_PIN1       BIT(13)
#define DEBUG_PIN2       BIT(14)
#define DEBUG_PIN3       BIT(15)
#define DEBUG_PIN4       BIT(16)
#define DEBUG_PIN5       BIT(17)
#define DEBUG_PIN6       BIT(18)
#define DEBUG_PIN7       BIT(19)
#define DEBUG_PIN8       BIT(20)
#define DEBUG_PIN9       BIT(23)
#else
#error BT_CTLR_DEBUG_PINS not supported on this board.
#endif

#define DEBUG_PIN_MASK   (DEBUG_PIN0 | DEBUG_PIN1 | DEBUG_PIN2 | DEBUG_PIN3 | \
			  DEBUG_PIN4 | DEBUG_PIN5 | DEBUG_PIN6 | DEBUG_PIN7 | \
			  DEBUG_PIN8 | DEBUG_PIN9)
#define DEBUG_CLOSE_MASK (DEBUG_PIN3 | DEBUG_PIN4 | DEBUG_PIN5 | DEBUG_PIN6)

/* below are some interesting macros referenced by controller
 * which can be defined to SoC's GPIO toggle to observe/debug the
 * controller's runtime behavior.
 */
#define DEBUG_INIT() \
	do { \
		DEBUG_PORT->DIRSET = DEBUG_PIN_MASK; \
		DEBUG_PORT->OUTCLR = DEBUG_PIN_MASK; \
	} while (0)

#define DEBUG_CPU_SLEEP(flag) \
	do { \
		if (flag) { \
			DEBUG_PORT->OUTSET = DEBUG_PIN0; \
			DEBUG_PORT->OUTCLR = DEBUG_PIN0; \
		} else { \
			DEBUG_PORT->OUTCLR = DEBUG_PIN0; \
			DEBUG_PORT->OUTSET = DEBUG_PIN0; \
		} \
	} while (0)

#define DEBUG_TICKER_ISR(flag) \
	do { \
		if (flag) { \
			DEBUG_PORT->OUTCLR = DEBUG_PIN1; \
			DEBUG_PORT->OUTSET = DEBUG_PIN1; \
		} else { \
			DEBUG_PORT->OUTSET = DEBUG_PIN1; \
			DEBUG_PORT->OUTCLR = DEBUG_PIN1; \
		} \
	} while (0)

#define DEBUG_TICKER_TASK(flag) \
	do { \
		if (flag) { \
			DEBUG_PORT->OUTCLR = DEBUG_PIN1; \
			DEBUG_PORT->OUTSET = DEBUG_PIN1; \
		} else { \
			DEBUG_PORT->OUTSET = DEBUG_PIN1; \
			DEBUG_PORT->OUTCLR = DEBUG_PIN1; \
		} \
	} while (0)

#define DEBUG_TICKER_JOB(flag) \
	do { \
		if (flag) { \
			DEBUG_PORT->OUTCLR = DEBUG_PIN2; \
			DEBUG_PORT->OUTSET = DEBUG_PIN2; \
		} else { \
			DEBUG_PORT->OUTSET = DEBUG_PIN2; \
			DEBUG_PORT->OUTCLR = DEBUG_PIN2; \
		} \
	} while (0)

#else /* !DEBUG_PINS */
#define DEBUG_INIT()
#define DEBUG_CPU_SLEEP(flag)
#define DEBUG_TICKER_ISR(flag)
#define DEBUG_TICKER_TASK(flag)
#define DEBUG_TICKER_JOB(flag)
#endif /* !DEBUG_PINS */

#endif /* _DEBUG_H_ */
