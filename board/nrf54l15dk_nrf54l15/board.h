#ifndef _BOARD_H_
#define _BOARD_H_

#define LED_RED   4  /* P0.04 */
#define LED_GREEN 40 /* P1.08 */
#define LED_BLUE  45 /* P1.13 */

#define LED1      4  /* P0.04 */
#define LED2      40 /* P1.08 */
#define LED3      45 /* P1.13 */
#define LED4      46 /* P1.14 */

#define LED1_ON   1  /* On value */
#define LED2_ON   1  /* On value */
#define LED3_ON   1  /* On value */
#define LED4_ON   1  /* On value */

#if defined(NRF_APPLICATION)
#define LED_BLINK    (LED1)
#define LED_BLINK_ON 1      /* On value */
#else
#define LED_BLINK    (LED3)
#define LED_BLINK_ON 1      /* On value */
#endif

#endif
