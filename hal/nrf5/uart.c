/*
Copyright (c) 2012, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "soc.h"

#include "hal/cpu.h"
#include "hal/uart.h"
#include "hal/debug.h"

#include "util/misc.h"
#include "util/util.h"

#if defined(NRF51_SERIES) || defined(NRF52832_XXAB)
#define NRF_UARTX                          NRF_UART0
#define UARTX_IRQn                         UART0_IRQn
#define UARTX_ENABLE_ENABLE_Enabled        UART_ENABLE_ENABLE_Enabled
#define UARTX_BAUDRATE_BAUDRATE_Baud115200 UART_BAUDRATE_BAUDRATE_Baud115200
#define UARTX_CONFIG_HWFC_Pos              UART_CONFIG_HWFC_Pos
#define UARTX_CONFIG_HWFC_Msk              UART_CONFIG_HWFC_Msk
#define UARTX_INTENSET_RXDRDY_Msk          UART_INTENSET_RXDRDY_Msk
#define UARTX_INTENSET_TXDRDY_Msk          UART_INTENSET_TXDRDY_Msk
#define UARTX_INTENSET_ERROR_Msk           UART_INTENSET_ERROR_Msk
#elif defined(NRF52840_XXAA)
#define NRF_UARTX                          NRF_UARTE0
#define UARTX_IRQn                         UART0_IRQn
#define PSELTXD                            PSEL.TXD
#define PSELRXD                            PSEL.RXD
#define PSELRTS                            PSEL.RTS
#define PSELCTS                            PSEL.CTS
#define UARTX_ENABLE_ENABLE_Enabled        UARTE_ENABLE_ENABLE_Enabled
#define UARTX_BAUDRATE_BAUDRATE_Baud115200 UARTE_BAUDRATE_BAUDRATE_Baud115200
#define UARTX_CONFIG_HWFC_Pos              UARTE_CONFIG_HWFC_Pos
#define UARTX_CONFIG_HWFC_Msk              UARTE_CONFIG_HWFC_Msk
#define UARTX_INTENSET_RXDRDY_Msk          UARTE_INTENSET_RXDRDY_Msk
#define UARTX_INTENSET_TXDRDY_Msk          UARTE_INTENSET_TXDRDY_Msk
#define UARTX_INTENSET_ERROR_Msk           UARTE_INTENSET_ERROR_Msk
#elif defined(NRF5340_XXAA_APPLICATION) || defined(NRF5340_XXAA_NETWORK)
#if defined(NRF5340_XXAA_APPLICATION)
#define NRF_UARTX                          NRF_UARTE0_S
#else
#define NRF_UARTX                          NRF_UARTE0_NS
#endif
#define UARTX_IRQn                         SERIAL0_IRQn
#define PSELTXD                            PSEL.TXD
#define PSELRXD                            PSEL.RXD
#define PSELRTS                            PSEL.RTS
#define PSELCTS                            PSEL.CTS
#define UARTX_ENABLE_ENABLE_Enabled        UARTE_ENABLE_ENABLE_Enabled
#define UARTX_BAUDRATE_BAUDRATE_Baud115200 UARTE_BAUDRATE_BAUDRATE_Baud115200
#define UARTX_CONFIG_HWFC_Pos              UARTE_CONFIG_HWFC_Pos
#define UARTX_CONFIG_HWFC_Msk              UARTE_CONFIG_HWFC_Msk
#define UARTX_INTENSET_RXDRDY_Msk          UARTE_INTENSET_RXDRDY_Msk
#define UARTX_INTENSET_TXDRDY_Msk          UARTE_INTENSET_TXDRDY_Msk
#define UARTX_INTENSET_ERROR_Msk           UARTE_INTENSET_ERROR_Msk
#define UART0_IRQn                         SERIAL0_IRQn
#elif defined(NRF54L15_ENGA_XXAA)
#if defined(UART1)
#define NRF_UARTX                          NRF_UARTE20
#define UARTX_IRQn                         SERIAL20_IRQn
#else
#define NRF_UARTX                          NRF_UARTE30
#define UARTX_IRQn                         SERIAL30_IRQn
#endif
#define PSELTXD                            PSEL.TXD
#define PSELRXD                            PSEL.RXD
#define PSELRTS                            PSEL.RTS
#define PSELCTS                            PSEL.CTS
#define UARTX_ENABLE_ENABLE_Enabled        UARTE_ENABLE_ENABLE_Enabled
#define UARTX_BAUDRATE_BAUDRATE_Baud115200 UARTE_BAUDRATE_BAUDRATE_Baud115200
#define UARTX_CONFIG_HWFC_Pos              UARTE_CONFIG_HWFC_Pos
#define UARTX_CONFIG_HWFC_Msk              UARTE_CONFIG_HWFC_Msk
#define UARTX_CONFIG_FRAMESIZE_8bit        UARTE_CONFIG_FRAMESIZE_8bit
#define UARTX_CONFIG_FRAMESIZE_Pos         UARTE_CONFIG_FRAMESIZE_Pos
#define UARTX_CONFIG_FRAMESIZE_Msk         UARTE_CONFIG_FRAMESIZE_Msk
#define UARTX_INTENSET_RXDRDY_Msk          UARTE_INTENSET_RXDRDY_Msk
#define UARTX_INTENSET_TXDRDY_Msk          UARTE_INTENSET_TXDRDY_Msk
#define UARTX_INTENSET_ERROR_Msk           UARTE_INTENSET_ERROR_Msk
#define TASKS_STARTTX                      TASKS_DMA.TX.START
#define TASKS_STOPTX                       TASKS_DMA.TX.STOP
#define TASKS_STARTRX                      TASKS_DMA.RX.START
#define TASKS_STOPRX                       TASKS_DMA.RX.STOP
#endif

#define UART_TX_BUFFER_MAX  (1)
#define UART_RX_BUFFER_MAX  (1)

#define UART_TX_BUFFER_SIZE (UART_TX_BUFFER_MAX + 1)
#define UART_RX_BUFFER_SIZE (UART_RX_BUFFER_MAX + 1)

static uint32_t tx[UART_TX_BUFFER_SIZE];
static uint8_t volatile tx_first;
static uint8_t volatile tx_last;
static uint32_t rx[UART_RX_BUFFER_SIZE];
static uint8_t volatile rx_first;
static uint8_t volatile rx_last;

uint32_t uart_init(uint8_t pin_txd, uint8_t pin_rxd,
		   uint8_t pin_rts, uint8_t pin_cts,
		   uint8_t hwfc)
{
	NRF_UARTX->CONFIG =
		((hwfc << UARTX_CONFIG_HWFC_Pos) &
		 UARTX_CONFIG_HWFC_Msk) |
#if defined(NRF54L15_ENGA_XXAA)
		((UARTX_CONFIG_FRAMESIZE_8bit << UARTX_CONFIG_FRAMESIZE_Pos) &
		 UARTX_CONFIG_FRAMESIZE_Msk) |
#endif
		0U;
	NRF_UARTX->BAUDRATE = UARTX_BAUDRATE_BAUDRATE_Baud115200;
	NRF_UARTX->PSELTXD = pin_txd;
	NRF_UARTX->PSELRXD = pin_rxd;
	if (hwfc) {
		NRF_UARTX->PSELRTS = pin_rts;
		NRF_UARTX->PSELCTS = pin_cts;
	}
	NRF_UARTX->ENABLE = UARTX_ENABLE_ENABLE_Enabled;
	NRF_UARTX->ERRORSRC = 0x0F;
	NRF_UARTX->EVENTS_TXDRDY = 0;
	NRF_UARTX->EVENTS_RXDRDY = 0;
	NRF_UARTX->EVENTS_ERROR = 0;
	NRF_UARTX->INTENSET = (UARTX_INTENSET_RXDRDY_Msk |
			       UARTX_INTENSET_TXDRDY_Msk |
			       UARTX_INTENSET_ERROR_Msk);

#if defined(NRF52840_XXAA)
	NRF_UARTX->SHORTS = UARTE_SHORTS_ENDRX_STOPRX_Msk;

	NRF_UARTX->RXD.MAXCNT = UART_RX_BUFFER_MAX;
	NRF_UARTX->RXD.PTR = (uint32_t)&rx[rx_last];
	NRF_UARTX->TASKS_STARTRX = 1;

#elif defined(NRF5340_XXAA_APPLICATION) || defined(NRF5340_XXAA_NETWORK)
	NRF_UARTX->SHORTS = UARTE_SHORTS_ENDRX_STOPRX_Msk;

	NRF_UARTX->RXD.MAXCNT = UART_RX_BUFFER_MAX;
	NRF_UARTX->RXD.PTR = (uint32_t)&rx[rx_last];
	NRF_UARTX->TASKS_STARTRX = 1;

#elif defined(NRF54L15_ENGA_XXAA)
	NRF_UARTX->SHORTS = UARTE_SHORTS_DMA_TX_END_DMA_TX_STOP_Msk |
			    UARTE_SHORTS_DMA_RX_END_DMA_RX_STOP_Msk;

	NRF_UARTX->DMA.RX.MAXCNT = UART_RX_BUFFER_MAX;
	NRF_UARTX->DMA.RX.PTR = (uint32_t)&rx[rx_last];
	NRF_UARTX->TASKS_STARTRX = 1;

#else
	NRF_UARTX->TASKS_STARTTX = 1;
	NRF_UARTX->TASKS_STARTRX = 1;
#endif

	return UARTX_IRQn;
}

void uart_tx(uint8_t x)
{
	uint8_t prev_last;
	uint8_t last;

	last = tx_last + 1;
	if (last == UART_TX_BUFFER_SIZE) {
		last = 0;
	}

	while (last == tx_first) {
		cpu_sleep();
	}

	tx[tx_last] = x;
	prev_last = tx_last;
	tx_last = last;

	if (tx_first == prev_last) {
#if defined(NRF52840_XXAA)
		NRF_UARTX->TXD.MAXCNT = 1;
		NRF_UARTX->TXD.PTR = (uint32_t)&tx[tx_first];
		NRF_UARTX->TASKS_STARTTX = 1;

#elif defined(NRF5340_XXAA_APPLICATION) || defined(NRF5340_XXAA_NETWORK)
		NRF_UARTX->TXD.MAXCNT = 1;
		NRF_UARTX->TXD.PTR = (uint32_t)&tx[tx_first];
		NRF_UARTX->TASKS_STARTTX = 1;

#elif defined(NRF54L15_ENGA_XXAA)
		NRF_UARTX->DMA.TX.MAXCNT = 1;
		NRF_UARTX->DMA.TX.PTR = (uint32_t)&tx[tx_first];
		NRF_UARTX->TASKS_STARTTX = 1;

#else
		NRF_UARTX->TXD = tx[tx_first];
#endif
	}
}

uint32_t uart_tx_done(void)
{
	return (tx_first == tx_last);
}

void uart_tx_str(char *s)
{
	while (*s) {
		uart_tx(*s++);
	}
}

void uart_tx_hex(uint8_t *p, uint16_t size, uint16_t warp_size, uint8_t *p_warp)
{
	uint16_t index;

	index = 0;
	while (size--) {
		char buf[3];

		util_itoa(buf, 'x', *p++);

		uart_tx_str(buf);
		uart_tx(' ');

		if ((0 != warp_size) && (0 != p_warp) && (0 != size) &&
		    (0 == (++index % warp_size))) {
			uart_tx_str((char *) p_warp);
		}
	}
}

uint32_t uart_rx(uint8_t *p_x)
{
	uint8_t first;

	if (rx_first == rx_last) {
		return(0);
	}

	*p_x = rx[rx_first];
	first = rx_first + 1;
	if (first == UART_RX_BUFFER_SIZE) {
		first = 0;
	}
	rx_first = first;

	if (NRF_UARTX->EVENTS_RXDRDY) {
		NRF_UARTX->INTENSET = UARTX_INTENSET_RXDRDY_Msk;
	}

	return(1);
}

void uart_echo(void)
{
	uint8_t x;

	if (uart_rx(&x)) {
		uart_tx(x);
	}
}

void isr_uart0(void *param)
{
	/* TODO: use param as s/w instance of h/w */
	(void)param;

	if (NRF_UARTX->EVENTS_TXDRDY) {
		uint8_t first;

		NRF_UARTX->EVENTS_TXDRDY = 0;

		first = tx_first + 1;
		if (first == UART_TX_BUFFER_SIZE) {
			first = 0;
		}
		tx_first = first;

		if (tx_first != tx_last) {
#if defined(NRF52840_XXAA)
			NRF_UARTX->TXD.MAXCNT = 1;
			NRF_UARTX->TXD.PTR = (uint32_t)&tx[tx_first];
			NRF_UARTX->TASKS_STARTTX = 1;

#elif defined(NRF5340_XXAA_APPLICATION) || defined(NRF5340_XXAA_NETWORK)
			NRF_UARTX->TXD.MAXCNT = 1;
			NRF_UARTX->TXD.PTR = (uint32_t)&tx[tx_first];
			NRF_UARTX->TASKS_STARTTX = 1;

#elif defined(NRF54L15_ENGA_XXAA)
			NRF_UARTX->DMA.TX.MAXCNT = 1;
			NRF_UARTX->DMA.TX.PTR = (uint32_t)&tx[tx_first];
			NRF_UARTX->TASKS_STARTTX = 1;

#else
			NRF_UARTX->TXD = tx[tx_first];
#endif
		}
	}

	while ((NRF_UARTX->INTENSET & UARTX_INTENSET_RXDRDY_Msk) &&
	       NRF_UARTX->EVENTS_RXDRDY) {
		uint8_t last;

		last = rx_last + 1;
		if (last == UART_RX_BUFFER_SIZE) {
			last = 0;
		}

		if (last == rx_first) {
			NRF_UARTX->INTENCLR = UARTX_INTENSET_RXDRDY_Msk;

			break;
		}

		NRF_UARTX->EVENTS_RXDRDY = 0;

#if defined(NRF52840_XXAA)
		rx_last = last;

		NRF_UARTX->RXD.MAXCNT = UART_RX_BUFFER_MAX;
		NRF_UARTX->RXD.PTR = (uint32_t)&rx[rx_last];
		NRF_UARTX->TASKS_STARTRX = 1;

#elif defined(NRF5340_XXAA_APPLICATION) || defined(NRF5340_XXAA_NETWORK)
		rx_last = last;

		NRF_UARTX->RXD.MAXCNT = UART_RX_BUFFER_MAX;
		NRF_UARTX->RXD.PTR = (uint32_t)&rx[rx_last];
		NRF_UARTX->TASKS_STARTRX = 1;

#elif defined(NRF54L15_ENGA_XXAA)
		rx_last = last;

		NRF_UARTX->DMA.RX.MAXCNT = UART_RX_BUFFER_MAX;
		NRF_UARTX->DMA.RX.PTR = (uint32_t)&rx[rx_last];
		NRF_UARTX->TASKS_STARTRX = 1;

#else
		rx[rx_last] = NRF_UARTX->RXD;
		rx_last = last;
#endif
	}

#if defined(NRF54L15_ENGA_XXAA)
	if (NRF_UARTX->EVENTS_DMA.TX.END) {
		NRF_UARTX->EVENTS_DMA.TX.END = 0;
	}

	if (NRF_UARTX->EVENTS_TXSTOPPED) {
		NRF_UARTX->EVENTS_TXSTOPPED = 0;
	}

	if (NRF_UARTX->EVENTS_DMA.RX.END) {
		NRF_UARTX->EVENTS_DMA.RX.END = 0;
	}
#endif

	ASSERT(NRF_UARTX->EVENTS_ERROR == 0);
	if (NRF_UARTX->EVENTS_ERROR) {
		NRF_UARTX->EVENTS_ERROR = 0;
	}
}
