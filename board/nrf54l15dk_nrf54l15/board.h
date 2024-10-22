#ifndef _BOARD_H_
#define _BOARD_H_

#define LED_RED   73 /* P2.09 */
#define LED_GREEN 42 /* P1.10 */
#define LED_BLUE  71 /* P2.07 */

#define LED1      73 /* P2.09 */
#define LED2      42 /* P1.10 */
#define LED3      71 /* P2.07 */
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

#if defined(UART) && !defined(UART1)
#define UART_PIN_TXD 0
#define UART_PIN_RXD 1
#define UART_PIN_RTS 2
#define UART_PIN_CTS 3

#elif defined(UART1)
#define UART_PIN_TXD 36
#define UART_PIN_RXD 37
#define UART_PIN_RTS 38
#define UART_PIN_CTS 39
#endif

#endif
