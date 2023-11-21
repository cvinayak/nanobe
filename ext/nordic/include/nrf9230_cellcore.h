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

#ifndef NRF9230_CELLCORE_H
#define NRF9230_CELLCORE_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_CELLCORE                                  /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
  Reset_IRQn                             = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn                    = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                         = -13,      /*!< -13 Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn                  = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No
                                                          Match*/
  BusFault_IRQn                          = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                          related Fault*/
  UsageFault_IRQn                        = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SecureFault_IRQn                       = -9,       /*!<  -9 Secure Fault Handler                                             */
  SVCall_IRQn                            = -5,       /*!<  -5 System Service Call via SVC instruction                          */
  DebugMonitor_IRQn                      = -4,       /*!<  -4 Debug Monitor                                                    */
  PendSV_IRQn                            = -2,       /*!<  -2 Pendable request for system service                              */
  SysTick_IRQn                           = -1,       /*!<  -1 System Tick Timer                                                */
/* ============================================== Processor Specific Interrupts ============================================== */
  SPU0_IRQn                              = 0,        /*!< 0 SPU0                                                               */
  MPC_IRQn                               = 3,        /*!< 3 MPC                                                                */
  MVDMA_IRQn                             = 5,        /*!< 5 MVDMA                                                              */
  AESLTE_IRQn                            = 8,        /*!< 8 AESLTE                                                             */
  SNOW_IRQn                              = 9,        /*!< 9 SNOW                                                               */
  ZUC_IRQn                               = 10,       /*!< 10 ZUC                                                               */
  SPU1_IRQn                              = 16,       /*!< 16 SPU1                                                              */
  WDT0_IRQn                              = 21,       /*!< 21 WDT0                                                              */
  WDT1_IRQn                              = 22,       /*!< 22 WDT1                                                              */
  RTC_IRQn                               = 23,       /*!< 23 RTC                                                               */
  SPU2_IRQn                              = 32,       /*!< 32 SPU2                                                              */
  LFCLKCALIBMEAS_IRQn                    = 35,       /*!< 35 LFCLKCALIBMEAS                                                    */
  SPU3_IRQn                              = 48,       /*!< 48 SPU3                                                              */
  MCPLL_IRQn                             = 53,       /*!< 53 MCPLL                                                             */
  SYSTEMTIMER_0_IRQn                     = 69,       /*!< 69 SYSTEMTIMER_0                                                     */
  SYSTEMTIMER_1_IRQn                     = 70,       /*!< 70 SYSTEMTIMER_1                                                     */
  LTETIMER_0_IRQn                        = 71,       /*!< 71 LTETIMER_0                                                        */
  LTETIMER_1_IRQn                        = 72,       /*!< 72 LTETIMER_1                                                        */
  GNSSTIMER_0_IRQn                       = 73,       /*!< 73 GNSSTIMER_0                                                       */
  GNSSTIMER_1_IRQn                       = 74,       /*!< 74 GNSSTIMER_1                                                       */
  IPCT_0_IRQn                            = 75,       /*!< 75 IPCT_0                                                            */
  IPCT_1_IRQn                            = 76,       /*!< 76 IPCT_1                                                            */
  IPCT_2_IRQn                            = 77,       /*!< 77 IPCT_2                                                            */
  IPCT_3_IRQn                            = 78,       /*!< 78 IPCT_3                                                            */
  IPCT_4_IRQn                            = 79,       /*!< 79 IPCT_4                                                            */
  IPCT_5_IRQn                            = 80,       /*!< 80 IPCT_5                                                            */
  SWI0_IRQn                              = 88,       /*!< 88 SWI0                                                              */
  SWI1_IRQn                              = 89,       /*!< 89 SWI1                                                              */
  SWI2_IRQn                              = 90,       /*!< 90 SWI2                                                              */
  SWI3_IRQn                              = 91,       /*!< 91 SWI3                                                              */
  SWI4_IRQn                              = 92,       /*!< 92 SWI4                                                              */
  SWI5_IRQn                              = 93,       /*!< 93 SWI5                                                              */
  SWI6_IRQn                              = 94,       /*!< 94 SWI6                                                              */
  SWI7_IRQn                              = 95,       /*!< 95 SWI7                                                              */
  BELLBOARD_0_IRQn                       = 96,       /*!< 96 BELLBOARD_0                                                       */
  BELLBOARD_1_IRQn                       = 97,       /*!< 97 BELLBOARD_1                                                       */
  BELLBOARD_2_IRQn                       = 98,       /*!< 98 BELLBOARD_2                                                       */
  BELLBOARD_3_IRQn                       = 99,       /*!< 99 BELLBOARD_3                                                       */
  GPIOTE130_0_IRQn                       = 104,      /*!< 104 GPIOTE130_0                                                      */
  GPIOTE130_1_IRQn                       = 105,      /*!< 105 GPIOTE130_1                                                      */
  GPIOTE131_0_IRQn                       = 106,      /*!< 106 GPIOTE131_0                                                      */
  GPIOTE131_1_IRQn                       = 107,      /*!< 107 GPIOTE131_1                                                      */
  GRTC_0_IRQn                            = 108,      /*!< 108 GRTC_0                                                           */
  GRTC_1_IRQn                            = 109,      /*!< 109 GRTC_1                                                           */
  GRTC_2_IRQn                            = 110,      /*!< 110 GRTC_2                                                           */
  ISIM_MHU_0_IRQn                        = 111,      /*!< 111 ISIM_MHU_0                                                       */
  ISIM_MHU_1_IRQn                        = 112,      /*!< 112 ISIM_MHU_1                                                       */
  ISIM_SPU_IRQn                          = 113,      /*!< 113 ISIM_SPU                                                         */
  ISIM_MPC_IRQn                          = 114,      /*!< 114 ISIM_MPC                                                         */
  ISIM_CICTRL_IRQn                       = 115,      /*!< 115 ISIM_CICTRL                                                      */
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

/* =========================== Configuration of the ARM Cortex-M33 Processor and Core Peripherals ============================ */
#define __CM33_REV                  r0p4             /*!< CM33 Core Revision                                                   */
#define __DSP_PRESENT                  1             /*!< DSP present or not                                                   */
#define __NVIC_PRIO_BITS               3             /*!< Number of Bits used for Priority Levels                              */
#define __VTOR_PRESENT                 1             /*!< CPU supports alternate Vector Table address                          */
#define __MPU_PRESENT                  1             /*!< MPU present                                                          */
#define __FPU_PRESENT                  1             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX             480             /*!< Size of interrupt vector table                                       */
#define __Vendor_SysTickConfig         0             /*!< Vendor SysTick Config implementation is used                         */
#define __SAUREGION_PRESENT            1             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               8             /*!< Number of regions                                                    */

#include "core_cm33.h"                               /*!< ARM Cortex-M33 processor and core peripherals                        */
#include "system_nrf.h"                              /*!< nrf9230_cellcore System Library                                      */

#endif                                               /*!< NRF_CELLCORE                                                         */


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

#define NRF_CELLCORE_UICR_NS_BASE         0x0E3FF800UL
#define NRF_CELLCORE_ICACHEDATA_S_BASE    0x14F00000UL
#define NRF_CELLCORE_ICACHEINFO_S_BASE    0x14F10000UL
#define NRF_CELLCORE_DCACHEDATA_S_BASE    0x34F00000UL
#define NRF_CELLCORE_DCACHEINFO_S_BASE    0x34F10000UL
#define NRF_CELLCORE_ETM_NS_BASE          0xE0041000UL
#define NRF_CELLCORE_CTI_S_BASE           0xE0042000UL
#define NRF_CELLCORE_CPUC_S_BASE          0xE0080000UL
#define NRF_CELLCORE_ICACHE_S_BASE        0xE0082000UL
#define NRF_CELLCORE_DCACHE_S_BASE        0xE0083000UL
#define NRF_CELLCORE_SPU0_S_BASE          0x54000000UL
#define NRF_CELLCORE_HSFLL_NS_BASE        0x44001000UL
#define NRF_CELLCORE_HSFLL_S_BASE         0x54001000UL
#define NRF_CELLCORE_LRCCONF0_NS_BASE     0x44002000UL
#define NRF_CELLCORE_LRCCONF0_S_BASE      0x54002000UL
#define NRF_CELLCORE_MPC_S_BASE           0x54003000UL
#define NRF_CELLCORE_MVDMA_NS_BASE        0x44005000UL
#define NRF_CELLCORE_MVDMA_S_BASE         0x54005000UL
#define NRF_CELLCORE_RAMC00_NS_BASE       0x44006000UL
#define NRF_CELLCORE_RAMC00_S_BASE        0x54006000UL
#define NRF_CELLCORE_AESLTE_NS_BASE       0x44008000UL
#define NRF_CELLCORE_AESLTE_S_BASE        0x54008000UL
#define NRF_CELLCORE_SNOW_NS_BASE         0x44009000UL
#define NRF_CELLCORE_SNOW_S_BASE          0x54009000UL
#define NRF_CELLCORE_ZUC_NS_BASE          0x4400A000UL
#define NRF_CELLCORE_ZUC_S_BASE           0x5400A000UL
#define NRF_CELLCORE_TRACEDELAYREG_NS_BASE 0x4400B000UL
#define NRF_CELLCORE_TRACEDELAYREG_S_BASE 0x5400B000UL
#define NRF_CELLCORE_PCGCS0_NS_BASE       0x4400C000UL
#define NRF_CELLCORE_PCGCS0_S_BASE        0x5400C000UL
#define NRF_CELLCORE_PCGCM0_NS_BASE       0x4400D000UL
#define NRF_CELLCORE_PCGCM0_S_BASE        0x5400D000UL
#define NRF_CELLCORE_SPU1_S_BASE          0x54010000UL
#define NRF_CELLCORE_LRCCONF1_NS_BASE     0x44011000UL
#define NRF_CELLCORE_LRCCONF1_S_BASE      0x54011000UL
#define NRF_CELLCORE_RESETINFO_S_BASE     0x54011000UL
#define NRF_CELLCORE_CPUCONF_NS_BASE      0x44012000UL
#define NRF_CELLCORE_CPUCONF_S_BASE       0x54012000UL
#define NRF_CELLCORE_MEMCONF_NS_BASE      0x44013000UL
#define NRF_CELLCORE_MEMCONF_S_BASE       0x54013000UL
#define NRF_CELLCORE_WDT0_NS_BASE         0x44015000UL
#define NRF_CELLCORE_WDT0_S_BASE          0x54015000UL
#define NRF_CELLCORE_WDT1_NS_BASE         0x44016000UL
#define NRF_CELLCORE_WDT1_S_BASE          0x54016000UL
#define NRF_CELLCORE_RTC_NS_BASE          0x44017000UL
#define NRF_CELLCORE_RTC_S_BASE           0x54017000UL
#define NRF_CELLCORE_PCGCS1_NS_BASE       0x44018000UL
#define NRF_CELLCORE_PCGCS1_S_BASE        0x54018000UL
#define NRF_CELLCORE_PCGCM1_NS_BASE       0x44019000UL
#define NRF_CELLCORE_PCGCM1_S_BASE        0x54019000UL
#define NRF_CELLCORE_PPIB0_NS_BASE        0x4401A000UL
#define NRF_CELLCORE_PPIB0_S_BASE         0x5401A000UL
#define NRF_CELLCORE_BILS_S_BASE          0x5401B000UL
#define NRF_CELLCORE_SPU2_S_BASE          0x54020000UL
#define NRF_CELLCORE_DPPIC0_NS_BASE       0x44021000UL
#define NRF_CELLCORE_DPPIC0_S_BASE        0x54021000UL
#define NRF_CELLCORE_LFCLKCALIBMEAS_NS_BASE 0x44023000UL
#define NRF_CELLCORE_LFCLKCALIBMEAS_S_BASE 0x54023000UL
#define NRF_CELLCORE_TIMEREVENTSYNCH_NS_BASE 0x44024000UL
#define NRF_CELLCORE_TIMEREVENTSYNCH_S_BASE 0x54024000UL
#define NRF_CELLCORE_TIMEMARKMUX0_NS_BASE 0x44025000UL
#define NRF_CELLCORE_TIMEMARKMUX0_S_BASE  0x54025000UL
#define NRF_CELLCORE_PPIB1_NS_BASE        0x44026000UL
#define NRF_CELLCORE_PPIB1_S_BASE         0x54026000UL
#define NRF_CELLCORE_PCGCS2_NS_BASE       0x44027000UL
#define NRF_CELLCORE_PCGCS2_S_BASE        0x54027000UL
#define NRF_CELLCORE_SPU3_S_BASE          0x54030000UL
#define NRF_CELLCORE_LRCCONF3_NS_BASE     0x44031000UL
#define NRF_CELLCORE_LRCCONF3_S_BASE      0x54031000UL
#define NRF_CELLCORE_DPPIC1_NS_BASE       0x44032000UL
#define NRF_CELLCORE_DPPIC1_S_BASE        0x54032000UL
#define NRF_CELLCORE_TIMEMARKMUX1_NS_BASE 0x44034000UL
#define NRF_CELLCORE_TIMEMARKMUX1_S_BASE  0x54034000UL
#define NRF_CELLCORE_MCPLL_NS_BASE        0x44035000UL
#define NRF_CELLCORE_MCPLL_S_BASE         0x54035000UL
#define NRF_CELLCORE_PCGCS3_NS_BASE       0x44036000UL
#define NRF_CELLCORE_PCGCS3_S_BASE        0x54036000UL
#define NRF_CELLCORE_PCGCM3_NS_BASE       0x44037000UL
#define NRF_CELLCORE_PCGCM3_S_BASE        0x54037000UL
#define NRF_CELLCORE_TIMEMARKMUX2_NS_BASE 0x44038000UL
#define NRF_CELLCORE_TIMEMARKMUX2_S_BASE  0x54038000UL
#define NRF_CELLCORE_PPIB2_NS_BASE        0x44039000UL
#define NRF_CELLCORE_PPIB2_S_BASE         0x54039000UL
#define NRF_CELLCORE_SYSTEMTIMER_NS_BASE  0x44007000UL
#define NRF_CELLCORE_SYSTEMTIMER_S_BASE   0x54007000UL
#define NRF_CELLCORE_LTETIMER_NS_BASE     0x44022000UL
#define NRF_CELLCORE_LTETIMER_S_BASE      0x54022000UL
#define NRF_CELLCORE_GNSSTIMER_NS_BASE    0x44033000UL
#define NRF_CELLCORE_GNSSTIMER_S_BASE     0x54033000UL
#define NRF_CELLCORE_IPCT_NS_BASE         0x44014000UL
#define NRF_CELLCORE_IPCT_S_BASE          0x54014000UL
#define NRF_CELLCORE_SWI0_NS_BASE         0x42058000UL
#define NRF_CELLCORE_SWI1_NS_BASE         0x42059000UL
#define NRF_CELLCORE_SWI2_NS_BASE         0x4205A000UL
#define NRF_CELLCORE_SWI3_NS_BASE         0x4205B000UL
#define NRF_CELLCORE_SWI4_NS_BASE         0x4205C000UL
#define NRF_CELLCORE_SWI5_NS_BASE         0x4205D000UL
#define NRF_CELLCORE_SWI6_NS_BASE         0x4205E000UL
#define NRF_CELLCORE_SWI7_NS_BASE         0x4205F000UL
#define NRF_CELLCORE_BELLBOARD_NS_BASE    0x4F09C000UL
#define NRF_CELLCORE_BELLBOARD_S_BASE     0x5F09C000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_CELLCORE_UICR_NS              ((NRF_UICR_Type*)                     NRF_CELLCORE_UICR_NS_BASE)
#define NRF_CELLCORE_ICACHEDATA_S         ((NRF_ICACHEDATA_Type*)               NRF_CELLCORE_ICACHEDATA_S_BASE)
#define NRF_CELLCORE_ICACHEINFO_S         ((NRF_ICACHEINFO_Type*)               NRF_CELLCORE_ICACHEINFO_S_BASE)
#define NRF_CELLCORE_DCACHEDATA_S         ((NRF_DCACHEDATA_Type*)               NRF_CELLCORE_DCACHEDATA_S_BASE)
#define NRF_CELLCORE_DCACHEINFO_S         ((NRF_DCACHEINFO_Type*)               NRF_CELLCORE_DCACHEINFO_S_BASE)
#define NRF_CELLCORE_ETM_NS               ((NRF_ETM_Type*)                      NRF_CELLCORE_ETM_NS_BASE)
#define NRF_CELLCORE_CTI_S                ((NRF_CTI_Type*)                      NRF_CELLCORE_CTI_S_BASE)
#define NRF_CELLCORE_CPUC_S               ((NRF_CM33SS_Type*)                   NRF_CELLCORE_CPUC_S_BASE)
#define NRF_CELLCORE_ICACHE_S             ((NRF_CACHE_Type*)                    NRF_CELLCORE_ICACHE_S_BASE)
#define NRF_CELLCORE_DCACHE_S             ((NRF_CACHE_Type*)                    NRF_CELLCORE_DCACHE_S_BASE)
#define NRF_CELLCORE_SPU0_S               ((NRF_SPU_Type*)                      NRF_CELLCORE_SPU0_S_BASE)
#define NRF_CELLCORE_HSFLL_NS             ((NRF_HSFLL_Type*)                    NRF_CELLCORE_HSFLL_NS_BASE)
#define NRF_CELLCORE_HSFLL_S              ((NRF_HSFLL_Type*)                    NRF_CELLCORE_HSFLL_S_BASE)
#define NRF_CELLCORE_LRCCONF0_NS          ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF0_NS_BASE)
#define NRF_CELLCORE_LRCCONF0_S           ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF0_S_BASE)
#define NRF_CELLCORE_MPC_S                ((NRF_MPC_Type*)                      NRF_CELLCORE_MPC_S_BASE)
#define NRF_CELLCORE_MVDMA_NS             ((NRF_MVDMA_Type*)                    NRF_CELLCORE_MVDMA_NS_BASE)
#define NRF_CELLCORE_MVDMA_S              ((NRF_MVDMA_Type*)                    NRF_CELLCORE_MVDMA_S_BASE)
#define NRF_CELLCORE_RAMC00_NS            ((NRF_RAMC_Type*)                     NRF_CELLCORE_RAMC00_NS_BASE)
#define NRF_CELLCORE_RAMC00_S             ((NRF_RAMC_Type*)                     NRF_CELLCORE_RAMC00_S_BASE)
#define NRF_CELLCORE_AESLTE_NS            ((NRF_AESLTE_Type*)                   NRF_CELLCORE_AESLTE_NS_BASE)
#define NRF_CELLCORE_AESLTE_S             ((NRF_AESLTE_Type*)                   NRF_CELLCORE_AESLTE_S_BASE)
#define NRF_CELLCORE_SNOW_NS              ((NRF_SNOW_Type*)                     NRF_CELLCORE_SNOW_NS_BASE)
#define NRF_CELLCORE_SNOW_S               ((NRF_SNOW_Type*)                     NRF_CELLCORE_SNOW_S_BASE)
#define NRF_CELLCORE_ZUC_NS               ((NRF_ZUC_Type*)                      NRF_CELLCORE_ZUC_NS_BASE)
#define NRF_CELLCORE_ZUC_S                ((NRF_ZUC_Type*)                      NRF_CELLCORE_ZUC_S_BASE)
#define NRF_CELLCORE_TRACEDELAYREG_NS     ((NRF_TRACEDELAYREG_Type*)            NRF_CELLCORE_TRACEDELAYREG_NS_BASE)
#define NRF_CELLCORE_TRACEDELAYREG_S      ((NRF_TRACEDELAYREG_Type*)            NRF_CELLCORE_TRACEDELAYREG_S_BASE)
#define NRF_CELLCORE_PCGCS0_NS            ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS0_NS_BASE)
#define NRF_CELLCORE_PCGCS0_S             ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS0_S_BASE)
#define NRF_CELLCORE_PCGCM0_NS            ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM0_NS_BASE)
#define NRF_CELLCORE_PCGCM0_S             ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM0_S_BASE)
#define NRF_CELLCORE_SPU1_S               ((NRF_SPU_Type*)                      NRF_CELLCORE_SPU1_S_BASE)
#define NRF_CELLCORE_LRCCONF1_NS          ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF1_NS_BASE)
#define NRF_CELLCORE_LRCCONF1_S           ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF1_S_BASE)
#define NRF_CELLCORE_RESETINFO_S          ((NRF_RESETINFO_Type*)                NRF_CELLCORE_RESETINFO_S_BASE)
#define NRF_CELLCORE_CPUCONF_NS           ((NRF_CPUCONF_Type*)                  NRF_CELLCORE_CPUCONF_NS_BASE)
#define NRF_CELLCORE_CPUCONF_S            ((NRF_CPUCONF_Type*)                  NRF_CELLCORE_CPUCONF_S_BASE)
#define NRF_CELLCORE_MEMCONF_NS           ((NRF_MEMCONF_Type*)                  NRF_CELLCORE_MEMCONF_NS_BASE)
#define NRF_CELLCORE_MEMCONF_S            ((NRF_MEMCONF_Type*)                  NRF_CELLCORE_MEMCONF_S_BASE)
#define NRF_CELLCORE_WDT0_NS              ((NRF_WDT_Type*)                      NRF_CELLCORE_WDT0_NS_BASE)
#define NRF_CELLCORE_WDT0_S               ((NRF_WDT_Type*)                      NRF_CELLCORE_WDT0_S_BASE)
#define NRF_CELLCORE_WDT1_NS              ((NRF_WDT_Type*)                      NRF_CELLCORE_WDT1_NS_BASE)
#define NRF_CELLCORE_WDT1_S               ((NRF_WDT_Type*)                      NRF_CELLCORE_WDT1_S_BASE)
#define NRF_CELLCORE_RTC_NS               ((NRF_RTC_Type*)                      NRF_CELLCORE_RTC_NS_BASE)
#define NRF_CELLCORE_RTC_S                ((NRF_RTC_Type*)                      NRF_CELLCORE_RTC_S_BASE)
#define NRF_CELLCORE_PCGCS1_NS            ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS1_NS_BASE)
#define NRF_CELLCORE_PCGCS1_S             ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS1_S_BASE)
#define NRF_CELLCORE_PCGCM1_NS            ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM1_NS_BASE)
#define NRF_CELLCORE_PCGCM1_S             ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM1_S_BASE)
#define NRF_CELLCORE_PPIB0_NS             ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB0_NS_BASE)
#define NRF_CELLCORE_PPIB0_S              ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB0_S_BASE)
#define NRF_CELLCORE_BILS_S               ((NRF_BILS_Type*)                     NRF_CELLCORE_BILS_S_BASE)
#define NRF_CELLCORE_SPU2_S               ((NRF_SPU_Type*)                      NRF_CELLCORE_SPU2_S_BASE)
#define NRF_CELLCORE_DPPIC0_NS            ((NRF_DPPIC_Type*)                    NRF_CELLCORE_DPPIC0_NS_BASE)
#define NRF_CELLCORE_DPPIC0_S             ((NRF_DPPIC_Type*)                    NRF_CELLCORE_DPPIC0_S_BASE)
#define NRF_CELLCORE_LFCLKCALIBMEAS_NS    ((NRF_LFCLKCALIBMEAS_Type*)           NRF_CELLCORE_LFCLKCALIBMEAS_NS_BASE)
#define NRF_CELLCORE_LFCLKCALIBMEAS_S     ((NRF_LFCLKCALIBMEAS_Type*)           NRF_CELLCORE_LFCLKCALIBMEAS_S_BASE)
#define NRF_CELLCORE_TIMEREVENTSYNCH_NS   ((NRF_TIMEREVENTSYNCH_Type*)          NRF_CELLCORE_TIMEREVENTSYNCH_NS_BASE)
#define NRF_CELLCORE_TIMEREVENTSYNCH_S    ((NRF_TIMEREVENTSYNCH_Type*)          NRF_CELLCORE_TIMEREVENTSYNCH_S_BASE)
#define NRF_CELLCORE_TIMEMARKMUX0_NS      ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX0_NS_BASE)
#define NRF_CELLCORE_TIMEMARKMUX0_S       ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX0_S_BASE)
#define NRF_CELLCORE_PPIB1_NS             ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB1_NS_BASE)
#define NRF_CELLCORE_PPIB1_S              ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB1_S_BASE)
#define NRF_CELLCORE_PCGCS2_NS            ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS2_NS_BASE)
#define NRF_CELLCORE_PCGCS2_S             ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS2_S_BASE)
#define NRF_CELLCORE_SPU3_S               ((NRF_SPU_Type*)                      NRF_CELLCORE_SPU3_S_BASE)
#define NRF_CELLCORE_LRCCONF3_NS          ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF3_NS_BASE)
#define NRF_CELLCORE_LRCCONF3_S           ((NRF_LRCCONF_Type*)                  NRF_CELLCORE_LRCCONF3_S_BASE)
#define NRF_CELLCORE_DPPIC1_NS            ((NRF_DPPIC_Type*)                    NRF_CELLCORE_DPPIC1_NS_BASE)
#define NRF_CELLCORE_DPPIC1_S             ((NRF_DPPIC_Type*)                    NRF_CELLCORE_DPPIC1_S_BASE)
#define NRF_CELLCORE_TIMEMARKMUX1_NS      ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX1_NS_BASE)
#define NRF_CELLCORE_TIMEMARKMUX1_S       ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX1_S_BASE)
#define NRF_CELLCORE_MCPLL_NS             ((NRF_MCPLL_Type*)                    NRF_CELLCORE_MCPLL_NS_BASE)
#define NRF_CELLCORE_MCPLL_S              ((NRF_MCPLL_Type*)                    NRF_CELLCORE_MCPLL_S_BASE)
#define NRF_CELLCORE_PCGCS3_NS            ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS3_NS_BASE)
#define NRF_CELLCORE_PCGCS3_S             ((NRF_PCGCSLAVE_Type*)                NRF_CELLCORE_PCGCS3_S_BASE)
#define NRF_CELLCORE_PCGCM3_NS            ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM3_NS_BASE)
#define NRF_CELLCORE_PCGCM3_S             ((NRF_PCGCMASTER_Type*)               NRF_CELLCORE_PCGCM3_S_BASE)
#define NRF_CELLCORE_TIMEMARKMUX2_NS      ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX2_NS_BASE)
#define NRF_CELLCORE_TIMEMARKMUX2_S       ((NRF_TIMEMARKMUX_Type*)              NRF_CELLCORE_TIMEMARKMUX2_S_BASE)
#define NRF_CELLCORE_PPIB2_NS             ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB2_NS_BASE)
#define NRF_CELLCORE_PPIB2_S              ((NRF_PPIB_Type*)                     NRF_CELLCORE_PPIB2_S_BASE)
#define NRF_CELLCORE_SYSTEMTIMER_NS       ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_SYSTEMTIMER_NS_BASE)
#define NRF_CELLCORE_SYSTEMTIMER_S        ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_SYSTEMTIMER_S_BASE)
#define NRF_CELLCORE_LTETIMER_NS          ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_LTETIMER_NS_BASE)
#define NRF_CELLCORE_LTETIMER_S           ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_LTETIMER_S_BASE)
#define NRF_CELLCORE_GNSSTIMER_NS         ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_GNSSTIMER_NS_BASE)
#define NRF_CELLCORE_GNSSTIMER_S          ((NRF_MODEMTIMER_Type*)               NRF_CELLCORE_GNSSTIMER_S_BASE)
#define NRF_CELLCORE_IPCT_NS              ((NRF_IPCT_Type*)                     NRF_CELLCORE_IPCT_NS_BASE)
#define NRF_CELLCORE_IPCT_S               ((NRF_IPCT_Type*)                     NRF_CELLCORE_IPCT_S_BASE)
#define NRF_CELLCORE_SWI0_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI0_NS_BASE)
#define NRF_CELLCORE_SWI1_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI1_NS_BASE)
#define NRF_CELLCORE_SWI2_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI2_NS_BASE)
#define NRF_CELLCORE_SWI3_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI3_NS_BASE)
#define NRF_CELLCORE_SWI4_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI4_NS_BASE)
#define NRF_CELLCORE_SWI5_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI5_NS_BASE)
#define NRF_CELLCORE_SWI6_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI6_NS_BASE)
#define NRF_CELLCORE_SWI7_NS              ((NRF_SWI_Type*)                      NRF_CELLCORE_SWI7_NS_BASE)
#define NRF_CELLCORE_BELLBOARD_NS         ((NRF_BELLBOARD_Type*)                NRF_CELLCORE_BELLBOARD_NS_BASE)
#define NRF_CELLCORE_BELLBOARD_S          ((NRF_BELLBOARD_Type*)                NRF_CELLCORE_BELLBOARD_S_BASE)

/* =========================================================================================================================== */
/* ================                                    TrustZone Remapping                                    ================ */
/* =========================================================================================================================== */

#ifdef NRF_TRUSTZONE_NONSECURE                       /*!< Remap NRF_X_NS instances to NRF_X symbol for ease of use.            */
  #define NRF_CELLCORE_UICR                       NRF_CELLCORE_UICR_NS
  #define NRF_CELLCORE_ETM                        NRF_CELLCORE_ETM_NS
  #define NRF_CELLCORE_HSFLL                      NRF_CELLCORE_HSFLL_NS
  #define NRF_CELLCORE_LRCCONF0                   NRF_CELLCORE_LRCCONF0_NS
  #define NRF_CELLCORE_MVDMA                      NRF_CELLCORE_MVDMA_NS
  #define NRF_CELLCORE_RAMC00                     NRF_CELLCORE_RAMC00_NS
  #define NRF_CELLCORE_AESLTE                     NRF_CELLCORE_AESLTE_NS
  #define NRF_CELLCORE_SNOW                       NRF_CELLCORE_SNOW_NS
  #define NRF_CELLCORE_ZUC                        NRF_CELLCORE_ZUC_NS
  #define NRF_CELLCORE_TRACEDELAYREG              NRF_CELLCORE_TRACEDELAYREG_NS
  #define NRF_CELLCORE_PCGCS0                     NRF_CELLCORE_PCGCS0_NS
  #define NRF_CELLCORE_PCGCM0                     NRF_CELLCORE_PCGCM0_NS
  #define NRF_CELLCORE_LRCCONF1                   NRF_CELLCORE_LRCCONF1_NS
  #define NRF_CELLCORE_CPUCONF                    NRF_CELLCORE_CPUCONF_NS
  #define NRF_CELLCORE_MEMCONF                    NRF_CELLCORE_MEMCONF_NS
  #define NRF_CELLCORE_WDT0                       NRF_CELLCORE_WDT0_NS
  #define NRF_CELLCORE_WDT1                       NRF_CELLCORE_WDT1_NS
  #define NRF_CELLCORE_RTC                        NRF_CELLCORE_RTC_NS
  #define NRF_CELLCORE_PCGCS1                     NRF_CELLCORE_PCGCS1_NS
  #define NRF_CELLCORE_PCGCM1                     NRF_CELLCORE_PCGCM1_NS
  #define NRF_CELLCORE_PPIB0                      NRF_CELLCORE_PPIB0_NS
  #define NRF_CELLCORE_DPPIC0                     NRF_CELLCORE_DPPIC0_NS
  #define NRF_CELLCORE_LFCLKCALIBMEAS             NRF_CELLCORE_LFCLKCALIBMEAS_NS
  #define NRF_CELLCORE_TIMEREVENTSYNCH            NRF_CELLCORE_TIMEREVENTSYNCH_NS
  #define NRF_CELLCORE_TIMEMARKMUX0               NRF_CELLCORE_TIMEMARKMUX0_NS
  #define NRF_CELLCORE_PPIB1                      NRF_CELLCORE_PPIB1_NS
  #define NRF_CELLCORE_PCGCS2                     NRF_CELLCORE_PCGCS2_NS
  #define NRF_CELLCORE_LRCCONF3                   NRF_CELLCORE_LRCCONF3_NS
  #define NRF_CELLCORE_DPPIC1                     NRF_CELLCORE_DPPIC1_NS
  #define NRF_CELLCORE_TIMEMARKMUX1               NRF_CELLCORE_TIMEMARKMUX1_NS
  #define NRF_CELLCORE_MCPLL                      NRF_CELLCORE_MCPLL_NS
  #define NRF_CELLCORE_PCGCS3                     NRF_CELLCORE_PCGCS3_NS
  #define NRF_CELLCORE_PCGCM3                     NRF_CELLCORE_PCGCM3_NS
  #define NRF_CELLCORE_TIMEMARKMUX2               NRF_CELLCORE_TIMEMARKMUX2_NS
  #define NRF_CELLCORE_PPIB2                      NRF_CELLCORE_PPIB2_NS
  #define NRF_CELLCORE_SYSTEMTIMER                NRF_CELLCORE_SYSTEMTIMER_NS
  #define NRF_CELLCORE_LTETIMER                   NRF_CELLCORE_LTETIMER_NS
  #define NRF_CELLCORE_GNSSTIMER                  NRF_CELLCORE_GNSSTIMER_NS
  #define NRF_CELLCORE_IPCT                       NRF_CELLCORE_IPCT_NS
  #define NRF_CELLCORE_SWI0                       NRF_CELLCORE_SWI0_NS
  #define NRF_CELLCORE_SWI1                       NRF_CELLCORE_SWI1_NS
  #define NRF_CELLCORE_SWI2                       NRF_CELLCORE_SWI2_NS
  #define NRF_CELLCORE_SWI3                       NRF_CELLCORE_SWI3_NS
  #define NRF_CELLCORE_SWI4                       NRF_CELLCORE_SWI4_NS
  #define NRF_CELLCORE_SWI5                       NRF_CELLCORE_SWI5_NS
  #define NRF_CELLCORE_SWI6                       NRF_CELLCORE_SWI6_NS
  #define NRF_CELLCORE_SWI7                       NRF_CELLCORE_SWI7_NS
  #define NRF_CELLCORE_BELLBOARD                  NRF_CELLCORE_BELLBOARD_NS
#else                                                /*!< Remap NRF_X_S instances to NRF_X symbol for ease of use.             */
  #define NRF_CELLCORE_UICR                       NRF_CELLCORE_UICR_NS
  #define NRF_CELLCORE_ICACHEDATA                 NRF_CELLCORE_ICACHEDATA_S
  #define NRF_CELLCORE_ICACHEINFO                 NRF_CELLCORE_ICACHEINFO_S
  #define NRF_CELLCORE_DCACHEDATA                 NRF_CELLCORE_DCACHEDATA_S
  #define NRF_CELLCORE_DCACHEINFO                 NRF_CELLCORE_DCACHEINFO_S
  #define NRF_CELLCORE_ETM                        NRF_CELLCORE_ETM_NS
  #define NRF_CELLCORE_CTI                        NRF_CELLCORE_CTI_S
  #define NRF_CELLCORE_CPUC                       NRF_CELLCORE_CPUC_S
  #define NRF_CELLCORE_ICACHE                     NRF_CELLCORE_ICACHE_S
  #define NRF_CELLCORE_DCACHE                     NRF_CELLCORE_DCACHE_S
  #define NRF_CELLCORE_SPU0                       NRF_CELLCORE_SPU0_S
  #define NRF_CELLCORE_HSFLL                      NRF_CELLCORE_HSFLL_S
  #define NRF_CELLCORE_LRCCONF0                   NRF_CELLCORE_LRCCONF0_S
  #define NRF_CELLCORE_MPC                        NRF_CELLCORE_MPC_S
  #define NRF_CELLCORE_MVDMA                      NRF_CELLCORE_MVDMA_S
  #define NRF_CELLCORE_RAMC00                     NRF_CELLCORE_RAMC00_S
  #define NRF_CELLCORE_AESLTE                     NRF_CELLCORE_AESLTE_S
  #define NRF_CELLCORE_SNOW                       NRF_CELLCORE_SNOW_S
  #define NRF_CELLCORE_ZUC                        NRF_CELLCORE_ZUC_S
  #define NRF_CELLCORE_TRACEDELAYREG              NRF_CELLCORE_TRACEDELAYREG_S
  #define NRF_CELLCORE_PCGCS0                     NRF_CELLCORE_PCGCS0_S
  #define NRF_CELLCORE_PCGCM0                     NRF_CELLCORE_PCGCM0_S
  #define NRF_CELLCORE_SPU1                       NRF_CELLCORE_SPU1_S
  #define NRF_CELLCORE_LRCCONF1                   NRF_CELLCORE_LRCCONF1_S
  #define NRF_CELLCORE_RESETINFO                  NRF_CELLCORE_RESETINFO_S
  #define NRF_CELLCORE_CPUCONF                    NRF_CELLCORE_CPUCONF_S
  #define NRF_CELLCORE_MEMCONF                    NRF_CELLCORE_MEMCONF_S
  #define NRF_CELLCORE_WDT0                       NRF_CELLCORE_WDT0_S
  #define NRF_CELLCORE_WDT1                       NRF_CELLCORE_WDT1_S
  #define NRF_CELLCORE_RTC                        NRF_CELLCORE_RTC_S
  #define NRF_CELLCORE_PCGCS1                     NRF_CELLCORE_PCGCS1_S
  #define NRF_CELLCORE_PCGCM1                     NRF_CELLCORE_PCGCM1_S
  #define NRF_CELLCORE_PPIB0                      NRF_CELLCORE_PPIB0_S
  #define NRF_CELLCORE_BILS                       NRF_CELLCORE_BILS_S
  #define NRF_CELLCORE_SPU2                       NRF_CELLCORE_SPU2_S
  #define NRF_CELLCORE_DPPIC0                     NRF_CELLCORE_DPPIC0_S
  #define NRF_CELLCORE_LFCLKCALIBMEAS             NRF_CELLCORE_LFCLKCALIBMEAS_S
  #define NRF_CELLCORE_TIMEREVENTSYNCH            NRF_CELLCORE_TIMEREVENTSYNCH_S
  #define NRF_CELLCORE_TIMEMARKMUX0               NRF_CELLCORE_TIMEMARKMUX0_S
  #define NRF_CELLCORE_PPIB1                      NRF_CELLCORE_PPIB1_S
  #define NRF_CELLCORE_PCGCS2                     NRF_CELLCORE_PCGCS2_S
  #define NRF_CELLCORE_SPU3                       NRF_CELLCORE_SPU3_S
  #define NRF_CELLCORE_LRCCONF3                   NRF_CELLCORE_LRCCONF3_S
  #define NRF_CELLCORE_DPPIC1                     NRF_CELLCORE_DPPIC1_S
  #define NRF_CELLCORE_TIMEMARKMUX1               NRF_CELLCORE_TIMEMARKMUX1_S
  #define NRF_CELLCORE_MCPLL                      NRF_CELLCORE_MCPLL_S
  #define NRF_CELLCORE_PCGCS3                     NRF_CELLCORE_PCGCS3_S
  #define NRF_CELLCORE_PCGCM3                     NRF_CELLCORE_PCGCM3_S
  #define NRF_CELLCORE_TIMEMARKMUX2               NRF_CELLCORE_TIMEMARKMUX2_S
  #define NRF_CELLCORE_PPIB2                      NRF_CELLCORE_PPIB2_S
  #define NRF_CELLCORE_SYSTEMTIMER                NRF_CELLCORE_SYSTEMTIMER_S
  #define NRF_CELLCORE_LTETIMER                   NRF_CELLCORE_LTETIMER_S
  #define NRF_CELLCORE_GNSSTIMER                  NRF_CELLCORE_GNSSTIMER_S
  #define NRF_CELLCORE_IPCT                       NRF_CELLCORE_IPCT_S
  #define NRF_CELLCORE_SWI0                       NRF_CELLCORE_SWI0_NS
  #define NRF_CELLCORE_SWI1                       NRF_CELLCORE_SWI1_NS
  #define NRF_CELLCORE_SWI2                       NRF_CELLCORE_SWI2_NS
  #define NRF_CELLCORE_SWI3                       NRF_CELLCORE_SWI3_NS
  #define NRF_CELLCORE_SWI4                       NRF_CELLCORE_SWI4_NS
  #define NRF_CELLCORE_SWI5                       NRF_CELLCORE_SWI5_NS
  #define NRF_CELLCORE_SWI6                       NRF_CELLCORE_SWI6_NS
  #define NRF_CELLCORE_SWI7                       NRF_CELLCORE_SWI7_NS
  #define NRF_CELLCORE_BELLBOARD                  NRF_CELLCORE_BELLBOARD_S
#endif                                               /*!<  NRF_TRUSTZONE_NONSECURE                                             */

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_CELLCORE                                  /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_UICR                                NRF_CELLCORE_UICR
  #define NRF_ICACHEDATA                          NRF_CELLCORE_ICACHEDATA
  #define NRF_ICACHEINFO                          NRF_CELLCORE_ICACHEINFO
  #define NRF_DCACHEDATA                          NRF_CELLCORE_DCACHEDATA
  #define NRF_DCACHEINFO                          NRF_CELLCORE_DCACHEINFO
  #define NRF_ETM                                 NRF_CELLCORE_ETM
  #define NRF_CTI                                 NRF_CELLCORE_CTI
  #define NRF_CPUC                                NRF_CELLCORE_CPUC
  #define NRF_ICACHE                              NRF_CELLCORE_ICACHE
  #define NRF_DCACHE                              NRF_CELLCORE_DCACHE
  #define NRF_SPU0                                NRF_CELLCORE_SPU0
  #define NRF_HSFLL                               NRF_CELLCORE_HSFLL
  #define NRF_LRCCONF0                            NRF_CELLCORE_LRCCONF0
  #define NRF_MPC                                 NRF_CELLCORE_MPC
  #define NRF_MVDMA                               NRF_CELLCORE_MVDMA
  #define NRF_RAMC00                              NRF_CELLCORE_RAMC00
  #define NRF_AESLTE                              NRF_CELLCORE_AESLTE
  #define NRF_SNOW                                NRF_CELLCORE_SNOW
  #define NRF_ZUC                                 NRF_CELLCORE_ZUC
  #define NRF_TRACEDELAYREG                       NRF_CELLCORE_TRACEDELAYREG
  #define NRF_PCGCS0                              NRF_CELLCORE_PCGCS0
  #define NRF_PCGCM0                              NRF_CELLCORE_PCGCM0
  #define NRF_SPU1                                NRF_CELLCORE_SPU1
  #define NRF_LRCCONF1                            NRF_CELLCORE_LRCCONF1
  #define NRF_RESETINFO                           NRF_CELLCORE_RESETINFO
  #define NRF_CPUCONF                             NRF_CELLCORE_CPUCONF
  #define NRF_MEMCONF                             NRF_CELLCORE_MEMCONF
  #define NRF_WDT0                                NRF_CELLCORE_WDT0
  #define NRF_WDT1                                NRF_CELLCORE_WDT1
  #define NRF_RTC                                 NRF_CELLCORE_RTC
  #define NRF_PCGCS1                              NRF_CELLCORE_PCGCS1
  #define NRF_PCGCM1                              NRF_CELLCORE_PCGCM1
  #define NRF_PPIB0                               NRF_CELLCORE_PPIB0
  #define NRF_BILS                                NRF_CELLCORE_BILS
  #define NRF_SPU2                                NRF_CELLCORE_SPU2
  #define NRF_DPPIC0                              NRF_CELLCORE_DPPIC0
  #define NRF_LFCLKCALIBMEAS                      NRF_CELLCORE_LFCLKCALIBMEAS
  #define NRF_TIMEREVENTSYNCH                     NRF_CELLCORE_TIMEREVENTSYNCH
  #define NRF_TIMEMARKMUX0                        NRF_CELLCORE_TIMEMARKMUX0
  #define NRF_PPIB1                               NRF_CELLCORE_PPIB1
  #define NRF_PCGCS2                              NRF_CELLCORE_PCGCS2
  #define NRF_SPU3                                NRF_CELLCORE_SPU3
  #define NRF_LRCCONF3                            NRF_CELLCORE_LRCCONF3
  #define NRF_DPPIC1                              NRF_CELLCORE_DPPIC1
  #define NRF_TIMEMARKMUX1                        NRF_CELLCORE_TIMEMARKMUX1
  #define NRF_MCPLL                               NRF_CELLCORE_MCPLL
  #define NRF_PCGCS3                              NRF_CELLCORE_PCGCS3
  #define NRF_PCGCM3                              NRF_CELLCORE_PCGCM3
  #define NRF_TIMEMARKMUX2                        NRF_CELLCORE_TIMEMARKMUX2
  #define NRF_PPIB2                               NRF_CELLCORE_PPIB2
  #define NRF_SYSTEMTIMER                         NRF_CELLCORE_SYSTEMTIMER
  #define NRF_LTETIMER                            NRF_CELLCORE_LTETIMER
  #define NRF_GNSSTIMER                           NRF_CELLCORE_GNSSTIMER
  #define NRF_IPCT                                NRF_CELLCORE_IPCT
  #define NRF_SWI0                                NRF_CELLCORE_SWI0
  #define NRF_SWI1                                NRF_CELLCORE_SWI1
  #define NRF_SWI2                                NRF_CELLCORE_SWI2
  #define NRF_SWI3                                NRF_CELLCORE_SWI3
  #define NRF_SWI4                                NRF_CELLCORE_SWI4
  #define NRF_SWI5                                NRF_CELLCORE_SWI5
  #define NRF_SWI6                                NRF_CELLCORE_SWI6
  #define NRF_SWI7                                NRF_CELLCORE_SWI7
  #define NRF_BELLBOARD                           NRF_CELLCORE_BELLBOARD
#endif                                               /*!< NRF_CELLCORE                                                         */

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
#endif /* NRF9230_CELLCORE_H */

