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

#ifndef NRF9230_ISIMCORE_H
#define NRF9230_ISIMCORE_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_ISIMCORE                                  /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
  Reset_IRQn                             = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn                    = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                         = -13,      /*!< -13 Hard Fault, all classes of Fault                                 */
  SecureFault_IRQn                       = -9,       /*!<  -9 Secure Fault Handler                                             */
  SVCall_IRQn                            = -5,       /*!<  -5 System Service Call via SVC instruction                          */
  PendSV_IRQn                            = -2,       /*!<  -2 Pendable request for system service                              */
  SysTick_IRQn                           = -1,       /*!<  -1 System Tick Timer                                                */
/* ============================================== Processor Specific Interrupts ============================================== */
  SPU0_IRQn                              = 0,        /*!< 0 SPU0                                                               */
  CICTRL_IRQn                            = 2,        /*!< 2 CICTRL                                                             */
  SPU1_IRQn                              = 16,       /*!< 16 SPU1                                                              */
  MPC_IRQn                               = 17,       /*!< 17 MPC                                                               */
  SPU2_IRQn                              = 32,       /*!< 32 SPU2                                                              */
  MHUIRQMAP_0_IRQn                       = 37,       /*!< 37 MHUIRQMAP_0                                                       */
  MHUIRQMAP_1_IRQn                       = 38,       /*!< 38 MHUIRQMAP_1                                                       */
  GPIOTE130_0_IRQn                       = 104,      /*!< 104 GPIOTE130_0                                                      */
  GPIOTE130_1_IRQn                       = 105,      /*!< 105 GPIOTE130_1                                                      */
  GPIOTE131_0_IRQn                       = 106,      /*!< 106 GPIOTE131_0                                                      */
  GPIOTE131_1_IRQn                       = 107,      /*!< 107 GPIOTE131_1                                                      */
  GRTC_0_IRQn                            = 108,      /*!< 108 GRTC_0                                                           */
  GRTC_1_IRQn                            = 109,      /*!< 109 GRTC_1                                                           */
  GRTC_2_IRQn                            = 110,      /*!< 110 GRTC_2                                                           */
  TBM_IRQn                               = 127,      /*!< 127 TBM                                                              */
  USBHS_IRQn                             = 134,      /*!< 134 USBHS                                                            */
  MRAMC110_IRQn                          = 146,      /*!< 146 MRAMC110                                                         */
  MRAMC111_IRQn                          = 147,      /*!< 147 MRAMC111                                                         */
  EXMIF_IRQn                             = 149,      /*!< 149 EXMIF                                                            */
  OTPC_IRQn                              = 197,      /*!< 197 OTPC                                                             */
  VPR120_IRQn                            = 200,      /*!< 200 VPR120                                                           */
  IPCT120_0_IRQn                         = 209,      /*!< 209 IPCT120_0                                                        */
  I3C120_IRQn                            = 211,      /*!< 211 I3C120                                                           */
  VPR121_IRQn                            = 212,      /*!< 212 VPR121                                                           */
  CAN120_IRQn                            = 216,      /*!< 216 CAN120                                                           */
  MVDMA120_IRQn                          = 217,      /*!< 217 MVDMA120                                                         */
  CAN121_IRQn                            = 219,      /*!< 219 CAN121                                                           */
  MVDMA121_IRQn                          = 220,      /*!< 220 MVDMA121                                                         */
  I3C121_IRQn                            = 222,      /*!< 222 I3C121                                                           */
  TIMER120_IRQn                          = 226,      /*!< 226 TIMER120                                                         */
  TIMER121_IRQn                          = 227,      /*!< 227 TIMER121                                                         */
  PWM120_IRQn                            = 228,      /*!< 228 PWM120                                                           */
  SPIS120_IRQn                           = 229,      /*!< 229 SPIS120                                                          */
  SPIM120_UARTE120_IRQn                  = 230,      /*!< 230 SPIM120_UARTE120                                                 */
  SPIM121_IRQn                           = 231,      /*!< 231 SPIM121                                                          */
  TWIM120_IRQn                           = 232,      /*!< 232 TWIM120                                                          */
  SACR_IRQn                              = 233,      /*!< 233 SACR                                                             */
  VPR130_IRQn                            = 264,      /*!< 264 VPR130                                                           */
  IPCT130_0_IRQn                         = 289,      /*!< 289 IPCT130_0                                                        */
  RTC130_IRQn                            = 296,      /*!< 296 RTC130                                                           */
  RTC131_IRQn                            = 297,      /*!< 297 RTC131                                                           */
  WDT131_IRQn                            = 299,      /*!< 299 WDT131                                                           */
  WDT132_IRQn                            = 300,      /*!< 300 WDT132                                                           */
  EGU130_IRQn                            = 301,      /*!< 301 EGU130                                                           */
  RESETHUB_IRQn                          = 329,      /*!< 329 RESETHUB                                                         */
  SAADC_IRQn                             = 386,      /*!< 386 SAADC                                                            */
  COMP_LPCOMP_IRQn                       = 387,      /*!< 387 COMP_LPCOMP                                                      */
  TEMP_IRQn                              = 388,      /*!< 388 TEMP                                                             */
  I2S130_IRQn                            = 402,      /*!< 402 I2S130                                                           */
  PDM_IRQn                               = 403,      /*!< 403 PDM                                                              */
  QDEC130_IRQn                           = 404,      /*!< 404 QDEC130                                                          */
  QDEC131_IRQn                           = 405,      /*!< 405 QDEC131                                                          */
  SIMIF130_IRQn                          = 406,      /*!< 406 SIMIF130                                                         */
  I2S131_IRQn                            = 407,      /*!< 407 I2S131                                                           */
  SIMIF131_IRQn                          = 410,      /*!< 410 SIMIF131                                                         */
  MIPIRFFE_IRQn                          = 411,      /*!< 411 MIPIRFFE                                                         */
  TIMER130_IRQn                          = 418,      /*!< 418 TIMER130                                                         */
  TIMER131_IRQn                          = 419,      /*!< 419 TIMER131                                                         */
  PWM130_IRQn                            = 420,      /*!< 420 PWM130                                                           */
  SERIAL0_IRQn                           = 421,      /*!< 421 SERIAL0                                                          */
  SERIAL1_IRQn                           = 422,      /*!< 422 SERIAL1                                                          */
  TIMER132_IRQn                          = 434,      /*!< 434 TIMER132                                                         */
  TIMER133_IRQn                          = 435,      /*!< 435 TIMER133                                                         */
  PWM131_IRQn                            = 436,      /*!< 436 PWM131                                                           */
  SERIAL2_IRQn                           = 437,      /*!< 437 SERIAL2                                                          */
  SERIAL3_IRQn                           = 438,      /*!< 438 SERIAL3                                                          */
  TIMER134_IRQn                          = 450,      /*!< 450 TIMER134                                                         */
  TIMER135_IRQn                          = 451,      /*!< 451 TIMER135                                                         */
  PWM132_IRQn                            = 452,      /*!< 452 PWM132                                                           */
  SERIAL4_IRQn                           = 453,      /*!< 453 SERIAL4                                                          */
  SERIAL5_IRQn                           = 454,      /*!< 454 SERIAL5                                                          */
  TIMER136_IRQn                          = 466,      /*!< 466 TIMER136                                                         */
  TIMER137_IRQn                          = 467,      /*!< 467 TIMER137                                                         */
  PWM133_IRQn                            = 468,      /*!< 468 PWM133                                                           */
  SERIAL6_IRQn                           = 469,      /*!< 469 SERIAL6                                                          */
  SERIAL7_IRQn                           = 470,      /*!< 470 SERIAL7                                                          */
} IRQn_Type;


/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ============================ Configuration of the ARM Cortex-M0 Processor and Core Peripherals ============================ */
#define __CM0_REV                   r0p1             /*!< CM0 Core Revision                                                    */
#define __DSP_PRESENT                  0             /*!< DSP present or not                                                   */
#define __NVIC_PRIO_BITS               2             /*!< Number of Bits used for Priority Levels                              */
#define __VTOR_PRESENT                 1             /*!< CPU supports alternate Vector Table address                          */
#define __MPU_PRESENT                  1             /*!< MPU present                                                          */
#define __FPU_PRESENT                  0             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX              32             /*!< Size of interrupt vector table                                       */
#define __Vendor_SysTickConfig         0             /*!< Vendor SysTick Config implementation is used                         */
#define __SAUREGION_PRESENT            0             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               0             /*!< Number of regions                                                    */

#include "core_cm0.h"                                /*!< ARM Cortex-M0 processor and core peripherals                         */
#include "system_nrf.h"                              /*!< nrf9230_isimcore System Library                                      */

#endif                                               /*!< NRF_ISIMCORE                                                         */


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

#define NRF_ISIMCORE_SPU0_S_BASE          0x57000000UL
#define NRF_ISIMCORE_CPUCONF_NS_BASE      0x47001000UL
#define NRF_ISIMCORE_CPUCONF_S_BASE       0x57001000UL
#define NRF_ISIMCORE_CICTRL_NS_BASE       0x47002000UL
#define NRF_ISIMCORE_CICTRL_S_BASE        0x57002000UL
#define NRF_ISIMCORE_LRCCONF0_S_BASE      0x57003000UL
#define NRF_ISIMCORE_PCGCM0_S_BASE        0x57004000UL
#define NRF_ISIMCORE_PCGCS0_S_BASE        0x57005000UL
#define NRF_ISIMCORE_SPU1_S_BASE          0x57010000UL
#define NRF_ISIMCORE_MPC_S_BASE           0x57011000UL
#define NRF_ISIMCORE_HSFLL_S_BASE         0x57012000UL
#define NRF_ISIMCORE_LRCCONF1_S_BASE      0x57013000UL
#define NRF_ISIMCORE_PCGCM1_S_BASE        0x57014000UL
#define NRF_ISIMCORE_PCGCS1_S_BASE        0x57015000UL
#define NRF_ISIMCORE_SPU2_S_BASE          0x57020000UL
#define NRF_ISIMCORE_MHU0SND_NS_BASE      0x47021000UL
#define NRF_ISIMCORE_MHU0SND_S_BASE       0x57021000UL
#define NRF_ISIMCORE_MHU0RCV_NS_BASE      0x47022000UL
#define NRF_ISIMCORE_MHU0RCV_S_BASE       0x57022000UL
#define NRF_ISIMCORE_MHU1SND_NS_BASE      0x47023000UL
#define NRF_ISIMCORE_MHU1SND_S_BASE       0x57023000UL
#define NRF_ISIMCORE_MHU1RCV_NS_BASE      0x47024000UL
#define NRF_ISIMCORE_MHU1RCV_S_BASE       0x57024000UL
#define NRF_ISIMCORE_MHUIRQMAP_NS_BASE    0x47025000UL
#define NRF_ISIMCORE_MHUIRQMAP_S_BASE     0x57025000UL
#define NRF_ISIMCORE_PCGCS2_S_BASE        0x57026000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_ISIMCORE_SPU0_S               ((NRF_SPU_Type*)                      NRF_ISIMCORE_SPU0_S_BASE)
#define NRF_ISIMCORE_CPUCONF_NS           ((NRF_CPUCONF_Type*)                  NRF_ISIMCORE_CPUCONF_NS_BASE)
#define NRF_ISIMCORE_CPUCONF_S            ((NRF_CPUCONF_Type*)                  NRF_ISIMCORE_CPUCONF_S_BASE)
#define NRF_ISIMCORE_CICTRL_NS            ((NRF_CICTRL_Type*)                   NRF_ISIMCORE_CICTRL_NS_BASE)
#define NRF_ISIMCORE_CICTRL_S             ((NRF_CICTRL_Type*)                   NRF_ISIMCORE_CICTRL_S_BASE)
#define NRF_ISIMCORE_LRCCONF0_S           ((NRF_LRCCONF_Type*)                  NRF_ISIMCORE_LRCCONF0_S_BASE)
#define NRF_ISIMCORE_PCGCM0_S             ((NRF_PCGCMASTER_Type*)               NRF_ISIMCORE_PCGCM0_S_BASE)
#define NRF_ISIMCORE_PCGCS0_S             ((NRF_PCGCSLAVE_Type*)                NRF_ISIMCORE_PCGCS0_S_BASE)
#define NRF_ISIMCORE_SPU1_S               ((NRF_SPU_Type*)                      NRF_ISIMCORE_SPU1_S_BASE)
#define NRF_ISIMCORE_MPC_S                ((NRF_MPC_Type*)                      NRF_ISIMCORE_MPC_S_BASE)
#define NRF_ISIMCORE_HSFLL_S              ((NRF_HSFLL_Type*)                    NRF_ISIMCORE_HSFLL_S_BASE)
#define NRF_ISIMCORE_LRCCONF1_S           ((NRF_LRCCONF_Type*)                  NRF_ISIMCORE_LRCCONF1_S_BASE)
#define NRF_ISIMCORE_PCGCM1_S             ((NRF_PCGCMASTER_Type*)               NRF_ISIMCORE_PCGCM1_S_BASE)
#define NRF_ISIMCORE_PCGCS1_S             ((NRF_PCGCSLAVE_Type*)                NRF_ISIMCORE_PCGCS1_S_BASE)
#define NRF_ISIMCORE_SPU2_S               ((NRF_SPU_Type*)                      NRF_ISIMCORE_SPU2_S_BASE)
#define NRF_ISIMCORE_MHU0SND_NS           ((NRF_MHUSND_Type*)                   NRF_ISIMCORE_MHU0SND_NS_BASE)
#define NRF_ISIMCORE_MHU0SND_S            ((NRF_MHUSND_Type*)                   NRF_ISIMCORE_MHU0SND_S_BASE)
#define NRF_ISIMCORE_MHU0RCV_NS           ((NRF_MHURCV_Type*)                   NRF_ISIMCORE_MHU0RCV_NS_BASE)
#define NRF_ISIMCORE_MHU0RCV_S            ((NRF_MHURCV_Type*)                   NRF_ISIMCORE_MHU0RCV_S_BASE)
#define NRF_ISIMCORE_MHU1SND_NS           ((NRF_MHUSND_Type*)                   NRF_ISIMCORE_MHU1SND_NS_BASE)
#define NRF_ISIMCORE_MHU1SND_S            ((NRF_MHUSND_Type*)                   NRF_ISIMCORE_MHU1SND_S_BASE)
#define NRF_ISIMCORE_MHU1RCV_NS           ((NRF_MHURCV_Type*)                   NRF_ISIMCORE_MHU1RCV_NS_BASE)
#define NRF_ISIMCORE_MHU1RCV_S            ((NRF_MHURCV_Type*)                   NRF_ISIMCORE_MHU1RCV_S_BASE)
#define NRF_ISIMCORE_MHUIRQMAP_NS         ((NRF_MHUIRQMAP_Type*)                NRF_ISIMCORE_MHUIRQMAP_NS_BASE)
#define NRF_ISIMCORE_MHUIRQMAP_S          ((NRF_MHUIRQMAP_Type*)                NRF_ISIMCORE_MHUIRQMAP_S_BASE)
#define NRF_ISIMCORE_PCGCS2_S             ((NRF_PCGCSLAVE_Type*)                NRF_ISIMCORE_PCGCS2_S_BASE)

/* =========================================================================================================================== */
/* ================                                    TrustZone Remapping                                    ================ */
/* =========================================================================================================================== */

#ifdef NRF_TRUSTZONE_NONSECURE                       /*!< Remap NRF_X_NS instances to NRF_X symbol for ease of use.            */
  #define NRF_ISIMCORE_CPUCONF                    NRF_ISIMCORE_CPUCONF_NS
  #define NRF_ISIMCORE_CICTRL                     NRF_ISIMCORE_CICTRL_NS
  #define NRF_ISIMCORE_MHU0SND                    NRF_ISIMCORE_MHU0SND_NS
  #define NRF_ISIMCORE_MHU0RCV                    NRF_ISIMCORE_MHU0RCV_NS
  #define NRF_ISIMCORE_MHU1SND                    NRF_ISIMCORE_MHU1SND_NS
  #define NRF_ISIMCORE_MHU1RCV                    NRF_ISIMCORE_MHU1RCV_NS
  #define NRF_ISIMCORE_MHUIRQMAP                  NRF_ISIMCORE_MHUIRQMAP_NS
#else                                                /*!< Remap NRF_X_S instances to NRF_X symbol for ease of use.             */
  #define NRF_ISIMCORE_SPU0                       NRF_ISIMCORE_SPU0_S
  #define NRF_ISIMCORE_CPUCONF                    NRF_ISIMCORE_CPUCONF_S
  #define NRF_ISIMCORE_CICTRL                     NRF_ISIMCORE_CICTRL_S
  #define NRF_ISIMCORE_LRCCONF0                   NRF_ISIMCORE_LRCCONF0_S
  #define NRF_ISIMCORE_PCGCM0                     NRF_ISIMCORE_PCGCM0_S
  #define NRF_ISIMCORE_PCGCS0                     NRF_ISIMCORE_PCGCS0_S
  #define NRF_ISIMCORE_SPU1                       NRF_ISIMCORE_SPU1_S
  #define NRF_ISIMCORE_MPC                        NRF_ISIMCORE_MPC_S
  #define NRF_ISIMCORE_HSFLL                      NRF_ISIMCORE_HSFLL_S
  #define NRF_ISIMCORE_LRCCONF1                   NRF_ISIMCORE_LRCCONF1_S
  #define NRF_ISIMCORE_PCGCM1                     NRF_ISIMCORE_PCGCM1_S
  #define NRF_ISIMCORE_PCGCS1                     NRF_ISIMCORE_PCGCS1_S
  #define NRF_ISIMCORE_SPU2                       NRF_ISIMCORE_SPU2_S
  #define NRF_ISIMCORE_MHU0SND                    NRF_ISIMCORE_MHU0SND_S
  #define NRF_ISIMCORE_MHU0RCV                    NRF_ISIMCORE_MHU0RCV_S
  #define NRF_ISIMCORE_MHU1SND                    NRF_ISIMCORE_MHU1SND_S
  #define NRF_ISIMCORE_MHU1RCV                    NRF_ISIMCORE_MHU1RCV_S
  #define NRF_ISIMCORE_MHUIRQMAP                  NRF_ISIMCORE_MHUIRQMAP_S
  #define NRF_ISIMCORE_PCGCS2                     NRF_ISIMCORE_PCGCS2_S
#endif                                               /*!<  NRF_TRUSTZONE_NONSECURE                                             */

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_ISIMCORE                                  /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_SPU0                                NRF_ISIMCORE_SPU0
  #define NRF_CPUCONF                             NRF_ISIMCORE_CPUCONF
  #define NRF_CICTRL                              NRF_ISIMCORE_CICTRL
  #define NRF_LRCCONF0                            NRF_ISIMCORE_LRCCONF0
  #define NRF_PCGCM0                              NRF_ISIMCORE_PCGCM0
  #define NRF_PCGCS0                              NRF_ISIMCORE_PCGCS0
  #define NRF_SPU1                                NRF_ISIMCORE_SPU1
  #define NRF_MPC                                 NRF_ISIMCORE_MPC
  #define NRF_HSFLL                               NRF_ISIMCORE_HSFLL
  #define NRF_LRCCONF1                            NRF_ISIMCORE_LRCCONF1
  #define NRF_PCGCM1                              NRF_ISIMCORE_PCGCM1
  #define NRF_PCGCS1                              NRF_ISIMCORE_PCGCS1
  #define NRF_SPU2                                NRF_ISIMCORE_SPU2
  #define NRF_MHU0SND                             NRF_ISIMCORE_MHU0SND
  #define NRF_MHU0RCV                             NRF_ISIMCORE_MHU0RCV
  #define NRF_MHU1SND                             NRF_ISIMCORE_MHU1SND
  #define NRF_MHU1RCV                             NRF_ISIMCORE_MHU1RCV
  #define NRF_MHUIRQMAP                           NRF_ISIMCORE_MHUIRQMAP
  #define NRF_PCGCS2                              NRF_ISIMCORE_PCGCS2
#endif                                               /*!< NRF_ISIMCORE                                                         */

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
#endif /* NRF9230_ISIMCORE_H */

