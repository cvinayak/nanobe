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

#ifndef NRF9230_CELLRF_H
#define NRF9230_CELLRF_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_CELLRF                                    /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
  Reset_IRQn                             = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn                    = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                         = -13,      /*!< -13 Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                            = -5,       /*!<  -5 System Service Call via SVC instruction                          */
  PendSV_IRQn                            = -2,       /*!<  -2 Pendable request for system service                              */
  SysTick_IRQn                           = -1,       /*!<  -1 System Tick Timer                                                */
/* ============================================== Processor Specific Interrupts ============================================== */
  TXDFE_IRQn                             = 0,        /*!< 0 TXDFE                                                              */
  EGUTX_IRQn                             = 1,        /*!< 1 EGUTX                                                              */
  RXDFE_0_IRQn                           = 2,        /*!< 2 RXDFE_0                                                            */
  RXDFE_1_IRQn                           = 3,        /*!< 3 RXDFE_1                                                            */
  EGURX_IRQn                             = 4,        /*!< 4 EGURX                                                              */
  RXDFEGNSS_0_IRQn                       = 5,        /*!< 5 RXDFEGNSS_0                                                        */
  RXDFEGNSS_1_IRQn                       = 6,        /*!< 6 RXDFEGNSS_1                                                        */
  DSA2TX_0_IRQn                          = 7,        /*!< 7 DSA2TX_0                                                           */
  DSA2TX_1_IRQn                          = 8,        /*!< 8 DSA2TX_1                                                           */
  DSA2RX_0_IRQn                          = 9,        /*!< 9 DSA2RX_0                                                           */
  DSA2RX_1_IRQn                          = 10,       /*!< 10 DSA2RX_1                                                          */
  GPIOTE_0_IRQn                          = 11,       /*!< 11 GPIOTE_0                                                          */
  SENSORADC_IRQn                         = 12,       /*!< 12 SENSORADC                                                         */
  RFTIMERSTC_IRQn                        = 13,       /*!< 13 RFTIMERSTC                                                        */
  MIPIRFFE0_IRQn                         = 14,       /*!< 14 MIPIRFFE0                                                         */
  MIPIRFFE1_IRQn                         = 15,       /*!< 15 MIPIRFFE1                                                         */
  RFSERVICES_IRQn                        = 16,       /*!< 16 RFSERVICES                                                        */
  RFCORESERVICES_IRQn                    = 19,       /*!< 19 RFCORESERVICES                                                    */
  MVDMA_IRQn                             = 20,       /*!< 20 MVDMA                                                             */
  GPIOTE131_IRQn                         = 21,       /*!< 21 GPIOTE131                                                         */
  MIPIRFFE_IRQn                          = 22,       /*!< 22 MIPIRFFE                                                          */
  BELLBOARD_0_IRQn                       = 23,       /*!< 23 BELLBOARD_0                                                       */
  BELLBOARD_1_IRQn                       = 24,       /*!< 24 BELLBOARD_1                                                       */
  BELLBOARD_2_IRQn                       = 25,       /*!< 25 BELLBOARD_2                                                       */
  BELLBOARD_3_IRQn                       = 26,       /*!< 26 BELLBOARD_3                                                       */
  IPCT_0_IRQn                            = 27,       /*!< 27 IPCT_0                                                            */
  IPCT_1_IRQn                            = 28,       /*!< 28 IPCT_1                                                            */
  IPCT_2_IRQn                            = 29,       /*!< 29 IPCT_2                                                            */
  IPCT_3_IRQn                            = 30,       /*!< 30 IPCT_3                                                            */
  IPCT_4_IRQn                            = 31,       /*!< 31 IPCT_4                                                            */
  IPCT_5_IRQn                            = 32,       /*!< 32 IPCT_5                                                            */
} IRQn_Type;


/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ============================ Configuration of the ARM Cortex-M0 Processor and Core Peripherals ============================ */
#define __CM0_REV                   r0p0             /*!< CM0 Core Revision                                                    */
#define __DSP_PRESENT                  0             /*!< DSP present or not                                                   */
#define __NVIC_PRIO_BITS               2             /*!< Number of Bits used for Priority Levels                              */
#define __VTOR_PRESENT                 0             /*!< CPU supports alternate Vector Table address                          */
#define __MPU_PRESENT                  0             /*!< MPU present                                                          */
#define __FPU_PRESENT                  0             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX              33             /*!< Size of interrupt vector table                                       */
#define __Vendor_SysTickConfig         0             /*!< Vendor SysTick Config implementation is used                         */
#define __SAUREGION_PRESENT            0             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               0             /*!< Number of regions                                                    */

#include "core_cm0.h"                                /*!< ARM Cortex-M0 processor and core peripherals                         */
#include "system_nrf.h"                              /*!< nrf9230_cellrf System Library                                        */

#endif                                               /*!< NRF_CELLRF                                                           */


/* ========================================= Start of section using anonymous unions ========================================= */

#include "compiler_abstraction.h"

#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#elif defined (_CEVA)
  /* anonymous unions are enabled by default */
#else
  #warning Unsupported compiler type
#endif

/* =========================================================================================================================== */
/* ================                                  Peripheral Address Map                                  ================ */
/* =========================================================================================================================== */

#define NRF_CELLRF_PCGCS0_BASE            0x46000000UL
#define NRF_CELLRF_RAMCM0_BASE            0x46001000UL
#define NRF_CELLRF_RAMCDATA_BASE          0x46002000UL
#define NRF_CELLRF_RAMCIPC_BASE           0x46003000UL
#define NRF_CELLRF_PCGCS1_BASE            0x46004000UL
#define NRF_CELLRF_MUTEX_BASE             0x46005000UL
#define NRF_CELLRF_PCGCM0_BASE            0x46006000UL
#define NRF_CELLRF_LRCCONF0_BASE          0x46007000UL
#define NRF_CELLRF_HSFLL_BASE             0x46008000UL
#define NRF_CELLRF_MPC_BASE               0x4600A000UL
#define NRF_CELLRF_PCGCM1_BASE            0x46010000UL
#define NRF_CELLRF_LRCCONF1_BASE          0x46011000UL
#define NRF_CELLRF_CPUCONF_BASE           0x46013000UL
#define NRF_CELLRF_MEMCONF_BASE           0x46014000UL
#define NRF_CELLRF_BILS_BASE              0x46016000UL
#define NRF_CELLRF_RFTIMERTX_BASE         0x46021000UL
#define NRF_CELLRF_RFTIMERRX_BASE         0x46032000UL
#define NRF_CELLRF_RFPLL_BASE             0x46047000UL
#define NRF_CELLRF_DPPIC_BASE             0x46050000UL
#define NRF_CELLRF_RAMCTX_BASE            0x46051000UL
#define NRF_CELLRF_RAMCRX_BASE            0x46052000UL
#define NRF_CELLRF_PCGCM2_BASE            0x46053000UL
#define NRF_CELLRF_LRCCONF2_BASE          0x46054000UL
#define NRF_CELLRF_RAMCGNSS_BASE          0x46056000UL
#define NRF_CELLRF_PCGCS2_BASE            0x46057000UL
#define NRF_CELLRF_CTI_BASE               0xF0001000UL
#define NRF_CELLRF_TXDFE_BASE             0x46020000UL
#define NRF_CELLRF_EGUTX_BASE             0x46022000UL
#define NRF_CELLRF_RXDFE_BASE             0x46030000UL
#define NRF_CELLRF_EGURX_BASE             0x46033000UL
#define NRF_CELLRF_RXDFEGNSS_BASE         0x46034000UL
#define NRF_CELLRF_DSA2TX_BASE            0x46040000UL
#define NRF_CELLRF_DSA2RX_BASE            0x46042000UL
#define NRF_CELLRF_GPIOTE_BASE            0x46044000UL
#define NRF_CELLRF_SENSORADC_BASE         0x46046000UL
#define NRF_CELLRF_RFTIMERSTC_BASE        0x46048000UL
#define NRF_CELLRF_MIPIRFFE0_BASE         0x46049000UL
#define NRF_CELLRF_MIPIRFFE1_BASE         0x4604A000UL
#define NRF_CELLRF_RFSERVICES_BASE        0x46045000UL
#define NRF_CELLRF_RFCORESERVICES_BASE    0x46009000UL
#define NRF_CELLRF_MVDMA_BASE             0x4600B000UL
#define NRF_CELLRF_BELLBOARD_BASE         0x4F09E000UL
#define NRF_CELLRF_IPCT_BASE              0x46015000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_CELLRF_PCGCS0                 ((NRF_PCGCSLAVE_Type*)                NRF_CELLRF_PCGCS0_BASE)
#define NRF_CELLRF_RAMCM0                 ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCM0_BASE)
#define NRF_CELLRF_RAMCDATA               ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCDATA_BASE)
#define NRF_CELLRF_RAMCIPC                ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCIPC_BASE)
#define NRF_CELLRF_PCGCS1                 ((NRF_PCGCSLAVE_Type*)                NRF_CELLRF_PCGCS1_BASE)
#define NRF_CELLRF_MUTEX                  ((NRF_MUTEX_Type*)                    NRF_CELLRF_MUTEX_BASE)
#define NRF_CELLRF_PCGCM0                 ((NRF_PCGCMASTER_Type*)               NRF_CELLRF_PCGCM0_BASE)
#define NRF_CELLRF_LRCCONF0               ((NRF_LRCCONF_Type*)                  NRF_CELLRF_LRCCONF0_BASE)
#define NRF_CELLRF_HSFLL                  ((NRF_HSFLL_Type*)                    NRF_CELLRF_HSFLL_BASE)
#define NRF_CELLRF_MPC                    ((NRF_MPC_Type*)                      NRF_CELLRF_MPC_BASE)
#define NRF_CELLRF_PCGCM1                 ((NRF_PCGCMASTER_Type*)               NRF_CELLRF_PCGCM1_BASE)
#define NRF_CELLRF_LRCCONF1               ((NRF_LRCCONF_Type*)                  NRF_CELLRF_LRCCONF1_BASE)
#define NRF_CELLRF_CPUCONF                ((NRF_CPUCONF_Type*)                  NRF_CELLRF_CPUCONF_BASE)
#define NRF_CELLRF_MEMCONF                ((NRF_MEMCONF_Type*)                  NRF_CELLRF_MEMCONF_BASE)
#define NRF_CELLRF_BILS                   ((NRF_BILS_Type*)                     NRF_CELLRF_BILS_BASE)
#define NRF_CELLRF_RFTIMERTX              ((NRF_RFTIMER_Type*)                  NRF_CELLRF_RFTIMERTX_BASE)
#define NRF_CELLRF_RFTIMERRX              ((NRF_RFTIMER_Type*)                  NRF_CELLRF_RFTIMERRX_BASE)
#define NRF_CELLRF_RFPLL                  ((NRF_RFPLL_Type*)                    NRF_CELLRF_RFPLL_BASE)
#define NRF_CELLRF_DPPIC                  ((NRF_DPPIC_Type*)                    NRF_CELLRF_DPPIC_BASE)
#define NRF_CELLRF_RAMCTX                 ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCTX_BASE)
#define NRF_CELLRF_RAMCRX                 ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCRX_BASE)
#define NRF_CELLRF_PCGCM2                 ((NRF_PCGCMASTER_Type*)               NRF_CELLRF_PCGCM2_BASE)
#define NRF_CELLRF_LRCCONF2               ((NRF_LRCCONF_Type*)                  NRF_CELLRF_LRCCONF2_BASE)
#define NRF_CELLRF_RAMCGNSS               ((NRF_RAMC_Type*)                     NRF_CELLRF_RAMCGNSS_BASE)
#define NRF_CELLRF_PCGCS2                 ((NRF_PCGCSLAVE_Type*)                NRF_CELLRF_PCGCS2_BASE)
#define NRF_CELLRF_CTI                    ((NRF_CTI_Type*)                      NRF_CELLRF_CTI_BASE)
#define NRF_CELLRF_TXDFE                  ((NRF_TXDFE_Type*)                    NRF_CELLRF_TXDFE_BASE)
#define NRF_CELLRF_EGUTX                  ((NRF_EGU_Type*)                      NRF_CELLRF_EGUTX_BASE)
#define NRF_CELLRF_RXDFE                  ((NRF_RXDFE_Type*)                    NRF_CELLRF_RXDFE_BASE)
#define NRF_CELLRF_EGURX                  ((NRF_EGU_Type*)                      NRF_CELLRF_EGURX_BASE)
#define NRF_CELLRF_RXDFEGNSS              ((NRF_RXDFE_Type*)                    NRF_CELLRF_RXDFEGNSS_BASE)
#define NRF_CELLRF_DSA2TX                 ((NRF_DSA2_Type*)                     NRF_CELLRF_DSA2TX_BASE)
#define NRF_CELLRF_DSA2RX                 ((NRF_DSA2_Type*)                     NRF_CELLRF_DSA2RX_BASE)
#define NRF_CELLRF_GPIOTE                 ((NRF_GPIOTE_Type*)                   NRF_CELLRF_GPIOTE_BASE)
#define NRF_CELLRF_SENSORADC              ((NRF_SENSORADC_Type*)                NRF_CELLRF_SENSORADC_BASE)
#define NRF_CELLRF_RFTIMERSTC             ((NRF_RFTIMER_Type*)                  NRF_CELLRF_RFTIMERSTC_BASE)
#define NRF_CELLRF_MIPIRFFE0              ((NRF_MIPIRFFE_Type*)                 NRF_CELLRF_MIPIRFFE0_BASE)
#define NRF_CELLRF_MIPIRFFE1              ((NRF_MIPIRFFE_Type*)                 NRF_CELLRF_MIPIRFFE1_BASE)
#define NRF_CELLRF_RFSERVICES             ((NRF_RFSERVICES_Type*)               NRF_CELLRF_RFSERVICES_BASE)
#define NRF_CELLRF_RFCORESERVICES         ((NRF_RFCORESERVICES_Type*)           NRF_CELLRF_RFCORESERVICES_BASE)
#define NRF_CELLRF_MVDMA                  ((NRF_MVDMA_Type*)                    NRF_CELLRF_MVDMA_BASE)
#define NRF_CELLRF_BELLBOARD              ((NRF_BELLBOARD_Type*)                NRF_CELLRF_BELLBOARD_BASE)
#define NRF_CELLRF_IPCT                   ((NRF_IPCT_Type*)                     NRF_CELLRF_IPCT_BASE)

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_CELLRF                                    /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_PCGCS0                              NRF_CELLRF_PCGCS0
  #define NRF_RAMCM0                              NRF_CELLRF_RAMCM0
  #define NRF_RAMCDATA                            NRF_CELLRF_RAMCDATA
  #define NRF_RAMCIPC                             NRF_CELLRF_RAMCIPC
  #define NRF_PCGCS1                              NRF_CELLRF_PCGCS1
  #define NRF_MUTEX                               NRF_CELLRF_MUTEX
  #define NRF_PCGCM0                              NRF_CELLRF_PCGCM0
  #define NRF_LRCCONF0                            NRF_CELLRF_LRCCONF0
  #define NRF_HSFLL                               NRF_CELLRF_HSFLL
  #define NRF_MPC                                 NRF_CELLRF_MPC
  #define NRF_PCGCM1                              NRF_CELLRF_PCGCM1
  #define NRF_LRCCONF1                            NRF_CELLRF_LRCCONF1
  #define NRF_CPUCONF                             NRF_CELLRF_CPUCONF
  #define NRF_MEMCONF                             NRF_CELLRF_MEMCONF
  #define NRF_BILS                                NRF_CELLRF_BILS
  #define NRF_RFTIMERTX                           NRF_CELLRF_RFTIMERTX
  #define NRF_RFTIMERRX                           NRF_CELLRF_RFTIMERRX
  #define NRF_RFPLL                               NRF_CELLRF_RFPLL
  #define NRF_DPPIC                               NRF_CELLRF_DPPIC
  #define NRF_RAMCTX                              NRF_CELLRF_RAMCTX
  #define NRF_RAMCRX                              NRF_CELLRF_RAMCRX
  #define NRF_PCGCM2                              NRF_CELLRF_PCGCM2
  #define NRF_LRCCONF2                            NRF_CELLRF_LRCCONF2
  #define NRF_RAMCGNSS                            NRF_CELLRF_RAMCGNSS
  #define NRF_PCGCS2                              NRF_CELLRF_PCGCS2
  #define NRF_CTI                                 NRF_CELLRF_CTI
  #define NRF_TXDFE                               NRF_CELLRF_TXDFE
  #define NRF_EGUTX                               NRF_CELLRF_EGUTX
  #define NRF_RXDFE                               NRF_CELLRF_RXDFE
  #define NRF_EGURX                               NRF_CELLRF_EGURX
  #define NRF_RXDFEGNSS                           NRF_CELLRF_RXDFEGNSS
  #define NRF_DSA2TX                              NRF_CELLRF_DSA2TX
  #define NRF_DSA2RX                              NRF_CELLRF_DSA2RX
  #define NRF_GPIOTE                              NRF_CELLRF_GPIOTE
  #define NRF_SENSORADC                           NRF_CELLRF_SENSORADC
  #define NRF_RFTIMERSTC                          NRF_CELLRF_RFTIMERSTC
  #define NRF_MIPIRFFE0                           NRF_CELLRF_MIPIRFFE0
  #define NRF_MIPIRFFE1                           NRF_CELLRF_MIPIRFFE1
  #define NRF_RFSERVICES                          NRF_CELLRF_RFSERVICES
  #define NRF_RFCORESERVICES                      NRF_CELLRF_RFCORESERVICES
  #define NRF_MVDMA                               NRF_CELLRF_MVDMA
  #define NRF_BELLBOARD                           NRF_CELLRF_BELLBOARD
  #define NRF_IPCT                                NRF_CELLRF_IPCT
#endif                                               /*!< NRF_CELLRF                                                           */

/* ========================================== End of section using anonymous unions ========================================== */

#if defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#elif defined (_CEVA)
  /* anonymous unions are enabled by default */
#endif


#ifdef __cplusplus
}
#endif
#endif /* NRF9230_CELLRF_H */

