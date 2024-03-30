#include <stdint.h>

#include "soc.h"

#include "board.h"

#include "hal/gpio.h"

#include "util/misc.h"

static uint8_t __noinit isr_stack[256];
static uint8_t __noinit main_stack[512];

void * const isr_stack_top = isr_stack + sizeof(isr_stack);
void * const main_stack_top = main_stack + sizeof(main_stack);

int main(void)
{
	gpio_pin_out_config(LED_BLINK, LED_BLINK_ON);

#if defined(NRF54L15_ENGA_XXAA)
	/* Shared memory queue with first and last index. APP sends value
	 * to VPR core.
	 */
	volatile uint32_t *first = (uint32_t *)0x2003FFFC;
	volatile uint32_t *last = (uint32_t *)0x2003FFF8;
	uint32_t *queue = (uint32_t *)0x2003FFF0;

#if defined(NRF_APPLICATION)
	/* Initialize shared memory indices in APP core */
	*first = 0U;
	*last = 0U;

	/* GPIO control select VPR */
	NRF_P1_S->PIN_CNF[LED3-32] = (GPIO_PIN_CNF_CTRLSEL_VPR <<
				      GPIO_PIN_CNF_CTRLSEL_Pos) &
				      GPIO_PIN_CNF_CTRLSEL_Msk;

	/* VPR peripheral index 0xC */
	uint32_t index = (NRF_VPR00_S_BASE & (0x3F << 12)) >> 12;

	/* Configure VPR as secure peripheral, so it can access RAM */
	NRF_SPU00_S->PERIPH[index].PERM =
		(NRF_SPU00_S->PERIPH[index].PERM &
		 ~SPU_PERIPH_PERM_SECATTR_Msk) |
		((SPU_PERIPH_PERM_SECATTR_Secure <<
		  SPU_PERIPH_PERM_SECATTR_Pos) &
		 SPU_PERIPH_PERM_SECATTR_Msk);

	/* Load initial PC value */
	NRF_VPR00_S->INITPC = 0x00100000;

	/* Run VPR CPU */
	NRF_VPR00_S->CPURUN = 1U;

	/* Enqueue value (toggle) in share memory */
	uint32_t value = 0U;
	while (1) {
		if (*first == *last) {
			uint32_t index;

			index = *last;
			queue[index] = value;

			gpio_pin_out_config(LED_BLINK, (value & 0x01));

			index++;
			if (index == 2U) {
				index = 0U;
			}
			*last = index;

			value++;
		}

		/* Spin loop as delay between enqueue value (toggle) */
		for (int i = 0U; i < 0x000FFFFF; i++);
	}

#else /* !NRF_APPLICATION */
	/* Dequeue value (toggle) from shared memory */
	while (1) {
		if (*first != *last) {
			uint32_t index;
			uint32_t value;

			index = *first;
			value = queue[index];

			gpio_pin_out_config(LED_BLINK, (value & 0x01));

			index++;
			if (index == 2U) {
				index = 0U;
			}
			*first = index;
		}
	}
#endif /* !NRF_APPLICATION */
#endif /* NRF54L15_ENGA_XXAA */

	return 0;
}
