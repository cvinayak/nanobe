#ifndef _BOARD_H_
#define _BOARD_H_

#define LED_RED   29 /* P0.29 */
#define LED_GREEN 30 /* P0.30 */
#define LED_BLUE  31 /* P0.31 */

#define LED1      28 /* P0.28 */
#define LED2      29 /* P0.29 */
#define LED3      30 /* P0.30 */
#define LED4      31 /* P0.31 */

#define LED_BLINK_NET (LED_RED)

#define UART_PIN_TXD_NET 33
#define UART_PIN_RXD_NET 32
#define UART_PIN_RTS_NET 11
#define UART_PIN_CTS_NET 10

#if defined(NRF5340_XXAA_APPLICATION)
#define LED_BLINK (LED1)

#define UART_PIN_TXD     20
#define UART_PIN_RXD     22
#define UART_PIN_RTS     19
#define UART_PIN_CTS     21

#elif defined(NRF5340_XXAA_NETWORK)
#define LED_BLINK (LED_BLINK_NET)

#define UART_PIN_TXD UART_PIN_TXD_NET
#define UART_PIN_RXD UART_PIN_RXD_NET
#define UART_PIN_RTS UART_PIN_RTS_NET
#define UART_PIN_CTS UART_PIN_CTS_NET

#endif

#endif
