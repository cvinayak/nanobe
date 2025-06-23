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

#if defined(NRF54L_SERIES)
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

	NRF_VPRCLIC->CLIC.CLICINT[EGU10_IRQn] = 0x3FC30000;

	NRF_EGU10->EVENTS_TRIGGERED[0] = 0U;
	NRF_EGU10->INTENSET = BIT(0);

	NRF_VPRCLIC->CLIC.CLICINT[EGU10_IRQn] = 0x3FC30100;

	__asm__ volatile ("csrsi mstatus, 0x8");

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

			if ((value % 5) == 4U) {
				NRF_EGU10->TASKS_TRIGGER[0] = 1U;
			}

			// __asm__ volatile ("ecall");
		}
	}
#endif /* !NRF_APPLICATION */
#endif /* NRF54L_SERIES */

	return 0;
}

void machine_exception(void)
{
	static volatile int i;

	gpio_pin_out_config(LED4, LED4_ON);
	for (i = 0U; i < 0xFFFFF; i++) {
	}

	gpio_pin_out_config(LED2, LED2_ON);
	for (i = 0U; i < 0xFFFFF; i++) {
	}

	gpio_pin_out_config(LED2, (~LED2_ON & 0x1));
}

void machine_interrupt(void)
{
	static volatile int i;

	gpio_pin_out_config(LED2, LED2_ON);
	for (i = 0U; i < 0xFFFFF; i++) {
	}

	gpio_pin_out_config(LED4, LED4_ON);
	for (i = 0U; i < 0xFFFFF; i++) {
	}

	gpio_pin_out_config(LED4, (~LED4_ON & 0x1));
}

#if defined(NRF54L_SERIES)
#if !defined(NRF_APPLICATION)
void EGU10_IRQHandler(void)
{
	static volatile int i;

	NRF_EGU10->EVENTS_TRIGGERED[0] = 0U;

	gpio_pin_out_config(LED2, LED2_ON);
	for (i = 0U; i < 0xFFFFF; i++) {
	}

	gpio_pin_out_config(LED2, (~LED2_ON & 0x1));
	for (i = 0U; i < 0xFFFFF; i++) {
	}
}
#endif /* !NRF_APPLICATION */
#endif /* NRF54L_SERIES */
