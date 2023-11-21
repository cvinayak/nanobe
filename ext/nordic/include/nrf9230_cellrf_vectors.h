/*
Copyright (c) 2010 - 2023, Nordic Semiconductor ASA

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form, except as embedded into a Nordic
   Semiconductor ASA integrated circuit in a product or a software update for
   such product, must reproduce the above copyright notice, this list of
   conditions and the following disclaimer in the documentation and/or other
   materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

4. This software, with or without modification, must only be used with a
   Nordic Semiconductor ASA integrated circuit.

5. Any software provided in binary form under this license must not be reverse
   engineered, decompiled, modified and/or disassembled.

THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRF_DEVICE_VECTORS_H_
#define NRF_DEVICE_VECTORS_H_

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void Reset_Handler                                               (void);
__WEAK void NMI_Handler(void)
{
    while(1);
}

__WEAK void HardFault_Handler(void)
{
    while(1);
}

__WEAK void SVC_Handler(void)
{
    while(1);
}

__WEAK void PendSV_Handler(void)
{
    while(1);
}

__WEAK void SysTick_Handler(void)
{
    while(1);
}

/* Device specific interrupt handlers */
 __HANDLER("Default_Handler") void TXDFE_IRQHandler                                            (void);
 __HANDLER("Default_Handler") void EGUTX_IRQHandler                                            (void);
 __HANDLER("Default_Handler") void RXDFE_0_IRQHandler                                          (void);
 __HANDLER("Default_Handler") void RXDFE_1_IRQHandler                                          (void);
 __HANDLER("Default_Handler") void EGURX_IRQHandler                                            (void);
 __HANDLER("Default_Handler") void RXDFEGNSS_0_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void RXDFEGNSS_1_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void DSA2TX_0_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void DSA2TX_1_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void DSA2RX_0_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void DSA2RX_1_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void GPIOTE_0_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void SENSORADC_IRQHandler                                        (void);
 __HANDLER("Default_Handler") void RFTIMERSTC_IRQHandler                                       (void);
 __HANDLER("Default_Handler") void MIPIRFFE0_IRQHandler                                        (void);
 __HANDLER("Default_Handler") void MIPIRFFE1_IRQHandler                                        (void);
 __HANDLER("Default_Handler") void RFSERVICES_IRQHandler                                       (void);
 __HANDLER("Default_Handler") void RFCORESERVICES_IRQHandler                                   (void);
 __HANDLER("Default_Handler") void MVDMA_IRQHandler                                            (void);
 __HANDLER("Default_Handler") void GPIOTE131_IRQHandler                                        (void);
 __HANDLER("Default_Handler") void MIPIRFFE_IRQHandler                                         (void);
 __HANDLER("Default_Handler") void BELLBOARD_0_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void BELLBOARD_1_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void BELLBOARD_2_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void BELLBOARD_3_IRQHandler                                      (void);
 __HANDLER("Default_Handler") void IPCT_0_IRQHandler                                           (void);
 __HANDLER("Default_Handler") void IPCT_1_IRQHandler                                           (void);
 __HANDLER("Default_Handler") void IPCT_2_IRQHandler                                           (void);
 __HANDLER("Default_Handler") void IPCT_3_IRQHandler                                           (void);
 __HANDLER("Default_Handler") void IPCT_4_IRQHandler                                           (void);
 __HANDLER("Default_Handler") void IPCT_5_IRQHandler                                           (void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

__VECTOR_TABLE_ATTRIBUTE const VECTOR_TABLE_Type __VECTOR_TABLE[] = {
    (VECTOR_TABLE_Type)(__STACK_BASE),
/* Exceptions */
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SVC_Handler,
    0,
    0,
    PendSV_Handler,
    SysTick_Handler,
/* Device specific interrupt handlers */
    TXDFE_IRQHandler,
    EGUTX_IRQHandler,
    RXDFE_0_IRQHandler,
    RXDFE_1_IRQHandler,
    EGURX_IRQHandler,
    RXDFEGNSS_0_IRQHandler,
    RXDFEGNSS_1_IRQHandler,
    DSA2TX_0_IRQHandler,
    DSA2TX_1_IRQHandler,
    DSA2RX_0_IRQHandler,
    DSA2RX_1_IRQHandler,
    GPIOTE_0_IRQHandler,
    SENSORADC_IRQHandler,
    RFTIMERSTC_IRQHandler,
    MIPIRFFE0_IRQHandler,
    MIPIRFFE1_IRQHandler,
    RFSERVICES_IRQHandler,
    0,
    0,
    RFCORESERVICES_IRQHandler,
    MVDMA_IRQHandler,
    GPIOTE131_IRQHandler,
    MIPIRFFE_IRQHandler,
    BELLBOARD_0_IRQHandler,
    BELLBOARD_1_IRQHandler,
    BELLBOARD_2_IRQHandler,
    BELLBOARD_3_IRQHandler,
    IPCT_0_IRQHandler,
    IPCT_1_IRQHandler,
    IPCT_2_IRQHandler,
    IPCT_3_IRQHandler,
    IPCT_4_IRQHandler,
    IPCT_5_IRQHandler,
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

__STATIC_FORCEINLINE void NRFPreInit()
{
}

#endif
