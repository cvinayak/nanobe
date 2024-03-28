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

#if defined(NRF54L15_ENGA_XXAA) && defined(NRF_APPLICATION)
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
#endif

	return 0;
}
