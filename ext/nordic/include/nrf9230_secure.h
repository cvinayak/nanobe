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

#ifndef NRF9230_SECURE_H
#define NRF9230_SECURE_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_SECURE                                    /*!< Processor information is domain local.                               */


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
  SPU000_IRQn                            = 0,        /*!< 0 SPU000                                                             */
  MPC000_IRQn                            = 1,        /*!< 1 MPC000                                                             */
  MVDMA_IRQn                             = 3,        /*!< 3 MVDMA                                                              */
  CRACEN_IRQn                            = 6,        /*!< 6 CRACEN                                                             */
  SPU010_IRQn                            = 16,       /*!< 16 SPU010                                                            */
  WDT010_IRQn                            = 20,       /*!< 20 WDT010                                                            */
  WDT011_IRQn                            = 21,       /*!< 21 WDT011                                                            */
  TAMPC_IRQn                             = 22,       /*!< 22 TAMPC                                                             */
  IPCT_0_IRQn                            = 64,       /*!< 64 IPCT_0                                                            */
  IPCT_1_IRQn                            = 65,       /*!< 65 IPCT_1                                                            */
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
  MPC200_IRQn                            = 124,      /*!< 124 MPC200                                                           */
  SPU200_SPU210_IRQn                     = 125,      /*!< 125 SPU200_SPU210                                                    */
  CTRLAP_IRQn                            = 126,      /*!< 126 CTRLAP                                                           */
  TBM_IRQn                               = 127,      /*!< 127 TBM                                                              */
  SPU110_IRQn                            = 128,      /*!< 128 SPU110                                                           */
  MPC110_IRQn                            = 129,      /*!< 129 MPC110                                                           */
  USBHS_IRQn                             = 134,      /*!< 134 USBHS                                                            */
  SPU111_IRQn                            = 144,      /*!< 144 SPU111                                                           */
  MPC111_IRQn                            = 145,      /*!< 145 MPC111                                                           */
  MRAMC110_IRQn                          = 146,      /*!< 146 MRAMC110                                                         */
  MRAMC111_IRQn                          = 147,      /*!< 147 MRAMC111                                                         */
  EXMIF_IRQn                             = 149,      /*!< 149 EXMIF                                                            */
  SPU120_IRQn                            = 192,      /*!< 192 SPU120                                                           */
  MPC120_IRQn                            = 193,      /*!< 193 MPC120                                                           */
  OTPC_IRQn                              = 197,      /*!< 197 OTPC                                                             */
  VPR120_IRQn                            = 200,      /*!< 200 VPR120                                                           */
  SPU121_IRQn                            = 208,      /*!< 208 SPU121                                                           */
  IPCT120_0_IRQn                         = 209,      /*!< 209 IPCT120_0                                                        */
  I3C120_IRQn                            = 211,      /*!< 211 I3C120                                                           */
  VPR121_IRQn                            = 212,      /*!< 212 VPR121                                                           */
  CAN120_IRQn                            = 216,      /*!< 216 CAN120                                                           */
  MVDMA120_IRQn                          = 217,      /*!< 217 MVDMA120                                                         */
  CAN121_IRQn                            = 219,      /*!< 219 CAN121                                                           */
  MVDMA121_IRQn                          = 220,      /*!< 220 MVDMA121                                                         */
  I3C121_IRQn                            = 222,      /*!< 222 I3C121                                                           */
  SPU122_IRQn                            = 224,      /*!< 224 SPU122                                                           */
  TIMER120_IRQn                          = 226,      /*!< 226 TIMER120                                                         */
  TIMER121_IRQn                          = 227,      /*!< 227 TIMER121                                                         */
  PWM120_IRQn                            = 228,      /*!< 228 PWM120                                                           */
  SPIS120_IRQn                           = 229,      /*!< 229 SPIS120                                                          */
  SPIM120_UARTE120_IRQn                  = 230,      /*!< 230 SPIM120_UARTE120                                                 */
  SPIM121_IRQn                           = 231,      /*!< 231 SPIM121                                                          */
  TWIM120_IRQn                           = 232,      /*!< 232 TWIM120                                                          */
  SACR_IRQn                              = 233,      /*!< 233 SACR                                                             */
  SPU130_IRQn                            = 256,      /*!< 256 SPU130                                                           */
  MPC130_IRQn                            = 257,      /*!< 257 MPC130                                                           */
  VPR130_IRQn                            = 264,      /*!< 264 VPR130                                                           */
  SPU131_IRQn                            = 288,      /*!< 288 SPU131                                                           */
  IPCT130_0_IRQn                         = 289,      /*!< 289 IPCT130_0                                                        */
  RTC130_IRQn                            = 296,      /*!< 296 RTC130                                                           */
  RTC131_IRQn                            = 297,      /*!< 297 RTC131                                                           */
  WDT131_IRQn                            = 299,      /*!< 299 WDT131                                                           */
  WDT132_IRQn                            = 300,      /*!< 300 WDT132                                                           */
  EGU130_IRQn                            = 301,      /*!< 301 EGU130                                                           */
  RESETHUB_IRQn                          = 329,      /*!< 329 RESETHUB                                                         */
  SPU132_IRQn                            = 384,      /*!< 384 SPU132                                                           */
  SAADC_IRQn                             = 386,      /*!< 386 SAADC                                                            */
  COMP_LPCOMP_IRQn                       = 387,      /*!< 387 COMP_LPCOMP                                                      */
  TEMP_IRQn                              = 388,      /*!< 388 TEMP                                                             */
  SPU133_IRQn                            = 400,      /*!< 400 SPU133                                                           */
  I2S130_IRQn                            = 402,      /*!< 402 I2S130                                                           */
  PDM_IRQn                               = 403,      /*!< 403 PDM                                                              */
  QDEC130_IRQn                           = 404,      /*!< 404 QDEC130                                                          */
  QDEC131_IRQn                           = 405,      /*!< 405 QDEC131                                                          */
  SIMIF130_IRQn                          = 406,      /*!< 406 SIMIF130                                                         */
  I2S131_IRQn                            = 407,      /*!< 407 I2S131                                                           */
  SIMIF131_IRQn                          = 410,      /*!< 410 SIMIF131                                                         */
  MIPIRFFE_IRQn                          = 411,      /*!< 411 MIPIRFFE                                                         */
  SPU134_IRQn                            = 416,      /*!< 416 SPU134                                                           */
  TIMER130_IRQn                          = 418,      /*!< 418 TIMER130                                                         */
  TIMER131_IRQn                          = 419,      /*!< 419 TIMER131                                                         */
  PWM130_IRQn                            = 420,      /*!< 420 PWM130                                                           */
  SERIAL0_IRQn                           = 421,      /*!< 421 SERIAL0                                                          */
  SERIAL1_IRQn                           = 422,      /*!< 422 SERIAL1                                                          */
  SPU135_IRQn                            = 432,      /*!< 432 SPU135                                                           */
  TIMER132_IRQn                          = 434,      /*!< 434 TIMER132                                                         */
  TIMER133_IRQn                          = 435,      /*!< 435 TIMER133                                                         */
  PWM131_IRQn                            = 436,      /*!< 436 PWM131                                                           */
  SERIAL2_IRQn                           = 437,      /*!< 437 SERIAL2                                                          */
  SERIAL3_IRQn                           = 438,      /*!< 438 SERIAL3                                                          */
  SPU136_IRQn                            = 448,      /*!< 448 SPU136                                                           */
  TIMER134_IRQn                          = 450,      /*!< 450 TIMER134                                                         */
  TIMER135_IRQn                          = 451,      /*!< 451 TIMER135                                                         */
  PWM132_IRQn                            = 452,      /*!< 452 PWM132                                                           */
  SERIAL4_IRQn                           = 453,      /*!< 453 SERIAL4                                                          */
  SERIAL5_IRQn                           = 454,      /*!< 454 SERIAL5                                                          */
  SPU137_IRQn                            = 464,      /*!< 464 SPU137                                                           */
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
#define __FPU_PRESENT                  0             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX             480             /*!< Size of interrupt vector table                                       */
#define __Vendor_SysTickConfig         0             /*!< Vendor SysTick Config implementation is used                         */
#define __SAUREGION_PRESENT            1             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               4             /*!< Number of regions                                                    */

#include "core_cm33.h"                               /*!< ARM Cortex-M33 processor and core peripherals                        */
#include "system_nrf.h"                              /*!< nrf9230_secure System Library                                        */

#endif                                               /*!< NRF_SECURE                                                           */


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

#define NRF_SECURE_SICR_S_BASE            0x0E000000UL
#define NRF_SECURE_RICR_S_BASE            0x0FFFC000UL
#define NRF_SECURE_ICACHEDATA_S_BASE      0x11F00000UL
#define NRF_SECURE_ICACHEINFO_S_BASE      0x11F10000UL
#define NRF_SECURE_DCACHEDATA_S_BASE      0x31F00000UL
#define NRF_SECURE_DCACHEINFO_S_BASE      0x31F10000UL
#define NRF_SECURE_CRACENCORE_NS_BASE     0x41800000UL
#define NRF_SECURE_CRACENCORE_S_BASE      0x51800000UL
#define NRF_SECURE_MEMCONF200_NS_BASE     0xBF014000UL
#define NRF_SECURE_ETM_NS_BASE            0xE0041000UL
#define NRF_SECURE_CTI_S_BASE             0xE0042000UL
#define NRF_SECURE_CPUC_S_BASE            0xE0080000UL
#define NRF_SECURE_ICACHE_S_BASE          0xE0082000UL
#define NRF_SECURE_DCACHE_S_BASE          0xE0083000UL
#define NRF_SECURE_SPU000_S_BASE          0x51000000UL
#define NRF_SECURE_MPC000_S_BASE          0x51001000UL
#define NRF_SECURE_MVDMA_NS_BASE          0x41003000UL
#define NRF_SECURE_MVDMA_S_BASE           0x51003000UL
#define NRF_SECURE_RAMC000_NS_BASE        0x41004000UL
#define NRF_SECURE_RAMC000_S_BASE         0x51004000UL
#define NRF_SECURE_ROMC_NS_BASE           0x41005000UL
#define NRF_SECURE_ROMC_S_BASE            0x51005000UL
#define NRF_SECURE_CRACEN_NS_BASE         0x41006000UL
#define NRF_SECURE_CRACEN_S_BASE          0x51006000UL
#define NRF_SECURE_RAMC001_NS_BASE        0x41007000UL
#define NRF_SECURE_RAMC001_S_BASE         0x51007000UL
#define NRF_SECURE_PCGCS000_S_BASE        0x5100A000UL
#define NRF_SECURE_PCGCM000_S_BASE        0x5100B000UL
#define NRF_SECURE_HSFLL_S_BASE           0x5100D000UL
#define NRF_SECURE_LRCCONF000_S_BASE      0x5100E000UL
#define NRF_SECURE_PCGCM001_S_BASE        0x5100F000UL
#define NRF_SECURE_SPU010_S_BASE          0x51010000UL
#define NRF_SECURE_CPUCONF_NS_BASE        0x41011000UL
#define NRF_SECURE_CPUCONF_S_BASE         0x51011000UL
#define NRF_SECURE_MEMCONF_NS_BASE        0x41012000UL
#define NRF_SECURE_MEMCONF_S_BASE         0x51012000UL
#define NRF_SECURE_WDT010_NS_BASE         0x41014000UL
#define NRF_SECURE_WDT010_S_BASE          0x51014000UL
#define NRF_SECURE_WDT011_NS_BASE         0x41015000UL
#define NRF_SECURE_WDT011_S_BASE          0x51015000UL
#define NRF_SECURE_TAMPC_S_BASE           0x51016000UL
#define NRF_SECURE_MUTEX_NS_BASE          0x41017000UL
#define NRF_SECURE_MUTEX_S_BASE           0x51017000UL
#define NRF_SECURE_BILS_S_BASE            0x51019000UL
#define NRF_SECURE_PCGCS010_S_BASE        0x5101A000UL
#define NRF_SECURE_PCGCM010_S_BASE        0x5101B000UL
#define NRF_SECURE_ABB_S_BASE             0x5101C000UL
#define NRF_SECURE_LRCCONF010_S_BASE      0x5101E000UL
#define NRF_SECURE_RESETINFO_S_BASE       0x5101E000UL
#define NRF_SECURE_PCGCM011_S_BASE        0x5101F000UL
#define NRF_SECURE_IPCT_NS_BASE           0x41013000UL
#define NRF_SECURE_IPCT_S_BASE            0x51013000UL
#define NRF_SECURE_SWI0_NS_BASE           0x42058000UL
#define NRF_SECURE_SWI1_NS_BASE           0x42059000UL
#define NRF_SECURE_SWI2_NS_BASE           0x4205A000UL
#define NRF_SECURE_SWI3_NS_BASE           0x4205B000UL
#define NRF_SECURE_SWI4_NS_BASE           0x4205C000UL
#define NRF_SECURE_SWI5_NS_BASE           0x4205D000UL
#define NRF_SECURE_SWI6_NS_BASE           0x4205E000UL
#define NRF_SECURE_SWI7_NS_BASE           0x4205F000UL
#define NRF_SECURE_BELLBOARD_NS_BASE      0x4F099000UL
#define NRF_SECURE_BELLBOARD_S_BASE       0x5F099000UL
#define NRF_SECURE_MPC200_NS_BASE         0xBF007000UL
#define NRF_SECURE_SPU200_NS_BASE         0xBF000000UL
#define NRF_SECURE_SPU210_NS_BASE         0xBF010000UL
#define NRF_SECURE_CTRLAP_NS_BASE         0xBF015000UL
#define NRF_SECURE_SPU110_S_BASE          0x5F080000UL
#define NRF_SECURE_MPC110_S_BASE          0x5F081000UL
#define NRF_SECURE_SPU111_S_BASE          0x5F090000UL
#define NRF_SECURE_MPC111_S_BASE          0x5F091000UL
#define NRF_SECURE_SPU120_S_BASE          0x5F8C0000UL
#define NRF_SECURE_MPC120_S_BASE          0x5F8C1000UL
#define NRF_SECURE_SPU121_S_BASE          0x5F8D0000UL
#define NRF_SECURE_SPU122_S_BASE          0x5F8E0000UL
#define NRF_SECURE_SPU130_S_BASE          0x5F900000UL
#define NRF_SECURE_MPC130_S_BASE          0x5F901000UL
#define NRF_SECURE_SPU131_S_BASE          0x5F920000UL
#define NRF_SECURE_IPCMAP_S_BASE          0x5F923000UL
#define NRF_SECURE_IRQMAP_S_BASE          0x5F924000UL
#define NRF_SECURE_SPU132_S_BASE          0x5F980000UL
#define NRF_SECURE_SPU133_S_BASE          0x5F990000UL
#define NRF_SECURE_SPU134_S_BASE          0x5F9A0000UL
#define NRF_SECURE_SPU135_S_BASE          0x5F9B0000UL
#define NRF_SECURE_SPU136_S_BASE          0x5F9C0000UL
#define NRF_SECURE_SPU137_S_BASE          0x5F9D0000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_SECURE_SICR_S                 ((NRF_SICR_Type*)                     NRF_SECURE_SICR_S_BASE)
#define NRF_SECURE_RICR_S                 ((NRF_RICR_Type*)                     NRF_SECURE_RICR_S_BASE)
#define NRF_SECURE_ICACHEDATA_S           ((NRF_ICACHEDATA_Type*)               NRF_SECURE_ICACHEDATA_S_BASE)
#define NRF_SECURE_ICACHEINFO_S           ((NRF_ICACHEINFO_Type*)               NRF_SECURE_ICACHEINFO_S_BASE)
#define NRF_SECURE_DCACHEDATA_S           ((NRF_DCACHEDATA_Type*)               NRF_SECURE_DCACHEDATA_S_BASE)
#define NRF_SECURE_DCACHEINFO_S           ((NRF_DCACHEINFO_Type*)               NRF_SECURE_DCACHEINFO_S_BASE)
#define NRF_SECURE_CRACENCORE_NS          ((NRF_CRACENCORE_Type*)               NRF_SECURE_CRACENCORE_NS_BASE)
#define NRF_SECURE_CRACENCORE_S           ((NRF_CRACENCORE_Type*)               NRF_SECURE_CRACENCORE_S_BASE)
#define NRF_SECURE_MEMCONF200_NS          ((NRF_MEMCONF_Type*)                  NRF_SECURE_MEMCONF200_NS_BASE)
#define NRF_SECURE_ETM_NS                 ((NRF_ETM_Type*)                      NRF_SECURE_ETM_NS_BASE)
#define NRF_SECURE_CTI_S                  ((NRF_CTI_Type*)                      NRF_SECURE_CTI_S_BASE)
#define NRF_SECURE_CPUC_S                 ((NRF_CM33SS_Type*)                   NRF_SECURE_CPUC_S_BASE)
#define NRF_SECURE_ICACHE_S               ((NRF_CACHE_Type*)                    NRF_SECURE_ICACHE_S_BASE)
#define NRF_SECURE_DCACHE_S               ((NRF_CACHE_Type*)                    NRF_SECURE_DCACHE_S_BASE)
#define NRF_SECURE_SPU000_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU000_S_BASE)
#define NRF_SECURE_MPC000_S               ((NRF_MPC_Type*)                      NRF_SECURE_MPC000_S_BASE)
#define NRF_SECURE_MVDMA_NS               ((NRF_MVDMA_Type*)                    NRF_SECURE_MVDMA_NS_BASE)
#define NRF_SECURE_MVDMA_S                ((NRF_MVDMA_Type*)                    NRF_SECURE_MVDMA_S_BASE)
#define NRF_SECURE_RAMC000_NS             ((NRF_RAMC_Type*)                     NRF_SECURE_RAMC000_NS_BASE)
#define NRF_SECURE_RAMC000_S              ((NRF_RAMC_Type*)                     NRF_SECURE_RAMC000_S_BASE)
#define NRF_SECURE_ROMC_NS                ((NRF_ROMC_Type*)                     NRF_SECURE_ROMC_NS_BASE)
#define NRF_SECURE_ROMC_S                 ((NRF_ROMC_Type*)                     NRF_SECURE_ROMC_S_BASE)
#define NRF_SECURE_CRACEN_NS              ((NRF_CRACEN_Type*)                   NRF_SECURE_CRACEN_NS_BASE)
#define NRF_SECURE_CRACEN_S               ((NRF_CRACEN_Type*)                   NRF_SECURE_CRACEN_S_BASE)
#define NRF_SECURE_RAMC001_NS             ((NRF_RAMC_Type*)                     NRF_SECURE_RAMC001_NS_BASE)
#define NRF_SECURE_RAMC001_S              ((NRF_RAMC_Type*)                     NRF_SECURE_RAMC001_S_BASE)
#define NRF_SECURE_PCGCS000_S             ((NRF_PCGCSLAVE_Type*)                NRF_SECURE_PCGCS000_S_BASE)
#define NRF_SECURE_PCGCM000_S             ((NRF_PCGCMASTER_Type*)               NRF_SECURE_PCGCM000_S_BASE)
#define NRF_SECURE_HSFLL_S                ((NRF_HSFLL_Type*)                    NRF_SECURE_HSFLL_S_BASE)
#define NRF_SECURE_LRCCONF000_S           ((NRF_LRCCONF_Type*)                  NRF_SECURE_LRCCONF000_S_BASE)
#define NRF_SECURE_PCGCM001_S             ((NRF_PCGCMASTER_Type*)               NRF_SECURE_PCGCM001_S_BASE)
#define NRF_SECURE_SPU010_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU010_S_BASE)
#define NRF_SECURE_CPUCONF_NS             ((NRF_CPUCONF_Type*)                  NRF_SECURE_CPUCONF_NS_BASE)
#define NRF_SECURE_CPUCONF_S              ((NRF_CPUCONF_Type*)                  NRF_SECURE_CPUCONF_S_BASE)
#define NRF_SECURE_MEMCONF_NS             ((NRF_MEMCONF_Type*)                  NRF_SECURE_MEMCONF_NS_BASE)
#define NRF_SECURE_MEMCONF_S              ((NRF_MEMCONF_Type*)                  NRF_SECURE_MEMCONF_S_BASE)
#define NRF_SECURE_WDT010_NS              ((NRF_WDT_Type*)                      NRF_SECURE_WDT010_NS_BASE)
#define NRF_SECURE_WDT010_S               ((NRF_WDT_Type*)                      NRF_SECURE_WDT010_S_BASE)
#define NRF_SECURE_WDT011_NS              ((NRF_WDT_Type*)                      NRF_SECURE_WDT011_NS_BASE)
#define NRF_SECURE_WDT011_S               ((NRF_WDT_Type*)                      NRF_SECURE_WDT011_S_BASE)
#define NRF_SECURE_TAMPC_S                ((NRF_TAMPC_Type*)                    NRF_SECURE_TAMPC_S_BASE)
#define NRF_SECURE_MUTEX_NS               ((NRF_MUTEX_Type*)                    NRF_SECURE_MUTEX_NS_BASE)
#define NRF_SECURE_MUTEX_S                ((NRF_MUTEX_Type*)                    NRF_SECURE_MUTEX_S_BASE)
#define NRF_SECURE_BILS_S                 ((NRF_BILS_Type*)                     NRF_SECURE_BILS_S_BASE)
#define NRF_SECURE_PCGCS010_S             ((NRF_PCGCSLAVE_Type*)                NRF_SECURE_PCGCS010_S_BASE)
#define NRF_SECURE_PCGCM010_S             ((NRF_PCGCMASTER_Type*)               NRF_SECURE_PCGCM010_S_BASE)
#define NRF_SECURE_ABB_S                  ((NRF_ABB_Type*)                      NRF_SECURE_ABB_S_BASE)
#define NRF_SECURE_LRCCONF010_S           ((NRF_LRCCONF_Type*)                  NRF_SECURE_LRCCONF010_S_BASE)
#define NRF_SECURE_RESETINFO_S            ((NRF_RESETINFO_Type*)                NRF_SECURE_RESETINFO_S_BASE)
#define NRF_SECURE_PCGCM011_S             ((NRF_PCGCMASTER_Type*)               NRF_SECURE_PCGCM011_S_BASE)
#define NRF_SECURE_IPCT_NS                ((NRF_IPCT_Type*)                     NRF_SECURE_IPCT_NS_BASE)
#define NRF_SECURE_IPCT_S                 ((NRF_IPCT_Type*)                     NRF_SECURE_IPCT_S_BASE)
#define NRF_SECURE_SWI0_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI0_NS_BASE)
#define NRF_SECURE_SWI1_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI1_NS_BASE)
#define NRF_SECURE_SWI2_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI2_NS_BASE)
#define NRF_SECURE_SWI3_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI3_NS_BASE)
#define NRF_SECURE_SWI4_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI4_NS_BASE)
#define NRF_SECURE_SWI5_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI5_NS_BASE)
#define NRF_SECURE_SWI6_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI6_NS_BASE)
#define NRF_SECURE_SWI7_NS                ((NRF_SWI_Type*)                      NRF_SECURE_SWI7_NS_BASE)
#define NRF_SECURE_BELLBOARD_NS           ((NRF_BELLBOARD_Type*)                NRF_SECURE_BELLBOARD_NS_BASE)
#define NRF_SECURE_BELLBOARD_S            ((NRF_BELLBOARD_Type*)                NRF_SECURE_BELLBOARD_S_BASE)
#define NRF_SECURE_MPC200_NS              ((NRF_MPC_Type*)                      NRF_SECURE_MPC200_NS_BASE)
#define NRF_SECURE_SPU200_NS              ((NRF_SPU_Type*)                      NRF_SECURE_SPU200_NS_BASE)
#define NRF_SECURE_SPU210_NS              ((NRF_SPU_Type*)                      NRF_SECURE_SPU210_NS_BASE)
#define NRF_SECURE_CTRLAP_NS              ((NRF_CTRLAPPERI_Type*)               NRF_SECURE_CTRLAP_NS_BASE)
#define NRF_SECURE_SPU110_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU110_S_BASE)
#define NRF_SECURE_MPC110_S               ((NRF_MPC_Type*)                      NRF_SECURE_MPC110_S_BASE)
#define NRF_SECURE_SPU111_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU111_S_BASE)
#define NRF_SECURE_MPC111_S               ((NRF_MPC_Type*)                      NRF_SECURE_MPC111_S_BASE)
#define NRF_SECURE_SPU120_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU120_S_BASE)
#define NRF_SECURE_MPC120_S               ((NRF_MPC_Type*)                      NRF_SECURE_MPC120_S_BASE)
#define NRF_SECURE_SPU121_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU121_S_BASE)
#define NRF_SECURE_SPU122_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU122_S_BASE)
#define NRF_SECURE_SPU130_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU130_S_BASE)
#define NRF_SECURE_MPC130_S               ((NRF_MPC_Type*)                      NRF_SECURE_MPC130_S_BASE)
#define NRF_SECURE_SPU131_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU131_S_BASE)
#define NRF_SECURE_IPCMAP_S               ((NRF_IPCMAP_Type*)                   NRF_SECURE_IPCMAP_S_BASE)
#define NRF_SECURE_IRQMAP_S               ((NRF_IRQMAP_Type*)                   NRF_SECURE_IRQMAP_S_BASE)
#define NRF_SECURE_SPU132_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU132_S_BASE)
#define NRF_SECURE_SPU133_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU133_S_BASE)
#define NRF_SECURE_SPU134_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU134_S_BASE)
#define NRF_SECURE_SPU135_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU135_S_BASE)
#define NRF_SECURE_SPU136_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU136_S_BASE)
#define NRF_SECURE_SPU137_S               ((NRF_SPU_Type*)                      NRF_SECURE_SPU137_S_BASE)

/* =========================================================================================================================== */
/* ================                                    TrustZone Remapping                                    ================ */
/* =========================================================================================================================== */

#ifdef NRF_TRUSTZONE_NONSECURE                       /*!< Remap NRF_X_NS instances to NRF_X symbol for ease of use.            */
  #define NRF_SECURE_CRACENCORE                   NRF_SECURE_CRACENCORE_NS
  #define NRF_SECURE_MEMCONF200                   NRF_SECURE_MEMCONF200_NS
  #define NRF_SECURE_ETM                          NRF_SECURE_ETM_NS
  #define NRF_SECURE_MVDMA                        NRF_SECURE_MVDMA_NS
  #define NRF_SECURE_RAMC000                      NRF_SECURE_RAMC000_NS
  #define NRF_SECURE_ROMC                         NRF_SECURE_ROMC_NS
  #define NRF_SECURE_CRACEN                       NRF_SECURE_CRACEN_NS
  #define NRF_SECURE_RAMC001                      NRF_SECURE_RAMC001_NS
  #define NRF_SECURE_CPUCONF                      NRF_SECURE_CPUCONF_NS
  #define NRF_SECURE_MEMCONF                      NRF_SECURE_MEMCONF_NS
  #define NRF_SECURE_WDT010                       NRF_SECURE_WDT010_NS
  #define NRF_SECURE_WDT011                       NRF_SECURE_WDT011_NS
  #define NRF_SECURE_MUTEX                        NRF_SECURE_MUTEX_NS
  #define NRF_SECURE_IPCT                         NRF_SECURE_IPCT_NS
  #define NRF_SECURE_SWI0                         NRF_SECURE_SWI0_NS
  #define NRF_SECURE_SWI1                         NRF_SECURE_SWI1_NS
  #define NRF_SECURE_SWI2                         NRF_SECURE_SWI2_NS
  #define NRF_SECURE_SWI3                         NRF_SECURE_SWI3_NS
  #define NRF_SECURE_SWI4                         NRF_SECURE_SWI4_NS
  #define NRF_SECURE_SWI5                         NRF_SECURE_SWI5_NS
  #define NRF_SECURE_SWI6                         NRF_SECURE_SWI6_NS
  #define NRF_SECURE_SWI7                         NRF_SECURE_SWI7_NS
  #define NRF_SECURE_BELLBOARD                    NRF_SECURE_BELLBOARD_NS
  #define NRF_SECURE_MPC200                       NRF_SECURE_MPC200_NS
  #define NRF_SECURE_SPU200                       NRF_SECURE_SPU200_NS
  #define NRF_SECURE_SPU210                       NRF_SECURE_SPU210_NS
  #define NRF_SECURE_CTRLAP                       NRF_SECURE_CTRLAP_NS
#else                                                /*!< Remap NRF_X_S instances to NRF_X symbol for ease of use.             */
  #define NRF_SECURE_SICR                         NRF_SECURE_SICR_S
  #define NRF_SECURE_RICR                         NRF_SECURE_RICR_S
  #define NRF_SECURE_ICACHEDATA                   NRF_SECURE_ICACHEDATA_S
  #define NRF_SECURE_ICACHEINFO                   NRF_SECURE_ICACHEINFO_S
  #define NRF_SECURE_DCACHEDATA                   NRF_SECURE_DCACHEDATA_S
  #define NRF_SECURE_DCACHEINFO                   NRF_SECURE_DCACHEINFO_S
  #define NRF_SECURE_CRACENCORE                   NRF_SECURE_CRACENCORE_S
  #define NRF_SECURE_MEMCONF200                   NRF_SECURE_MEMCONF200_NS
  #define NRF_SECURE_ETM                          NRF_SECURE_ETM_NS
  #define NRF_SECURE_CTI                          NRF_SECURE_CTI_S
  #define NRF_SECURE_CPUC                         NRF_SECURE_CPUC_S
  #define NRF_SECURE_ICACHE                       NRF_SECURE_ICACHE_S
  #define NRF_SECURE_DCACHE                       NRF_SECURE_DCACHE_S
  #define NRF_SECURE_SPU000                       NRF_SECURE_SPU000_S
  #define NRF_SECURE_MPC000                       NRF_SECURE_MPC000_S
  #define NRF_SECURE_MVDMA                        NRF_SECURE_MVDMA_S
  #define NRF_SECURE_RAMC000                      NRF_SECURE_RAMC000_S
  #define NRF_SECURE_ROMC                         NRF_SECURE_ROMC_S
  #define NRF_SECURE_CRACEN                       NRF_SECURE_CRACEN_S
  #define NRF_SECURE_RAMC001                      NRF_SECURE_RAMC001_S
  #define NRF_SECURE_PCGCS000                     NRF_SECURE_PCGCS000_S
  #define NRF_SECURE_PCGCM000                     NRF_SECURE_PCGCM000_S
  #define NRF_SECURE_HSFLL                        NRF_SECURE_HSFLL_S
  #define NRF_SECURE_LRCCONF000                   NRF_SECURE_LRCCONF000_S
  #define NRF_SECURE_PCGCM001                     NRF_SECURE_PCGCM001_S
  #define NRF_SECURE_SPU010                       NRF_SECURE_SPU010_S
  #define NRF_SECURE_CPUCONF                      NRF_SECURE_CPUCONF_S
  #define NRF_SECURE_MEMCONF                      NRF_SECURE_MEMCONF_S
  #define NRF_SECURE_WDT010                       NRF_SECURE_WDT010_S
  #define NRF_SECURE_WDT011                       NRF_SECURE_WDT011_S
  #define NRF_SECURE_TAMPC                        NRF_SECURE_TAMPC_S
  #define NRF_SECURE_MUTEX                        NRF_SECURE_MUTEX_S
  #define NRF_SECURE_BILS                         NRF_SECURE_BILS_S
  #define NRF_SECURE_PCGCS010                     NRF_SECURE_PCGCS010_S
  #define NRF_SECURE_PCGCM010                     NRF_SECURE_PCGCM010_S
  #define NRF_SECURE_ABB                          NRF_SECURE_ABB_S
  #define NRF_SECURE_LRCCONF010                   NRF_SECURE_LRCCONF010_S
  #define NRF_SECURE_RESETINFO                    NRF_SECURE_RESETINFO_S
  #define NRF_SECURE_PCGCM011                     NRF_SECURE_PCGCM011_S
  #define NRF_SECURE_IPCT                         NRF_SECURE_IPCT_S
  #define NRF_SECURE_SWI0                         NRF_SECURE_SWI0_NS
  #define NRF_SECURE_SWI1                         NRF_SECURE_SWI1_NS
  #define NRF_SECURE_SWI2                         NRF_SECURE_SWI2_NS
  #define NRF_SECURE_SWI3                         NRF_SECURE_SWI3_NS
  #define NRF_SECURE_SWI4                         NRF_SECURE_SWI4_NS
  #define NRF_SECURE_SWI5                         NRF_SECURE_SWI5_NS
  #define NRF_SECURE_SWI6                         NRF_SECURE_SWI6_NS
  #define NRF_SECURE_SWI7                         NRF_SECURE_SWI7_NS
  #define NRF_SECURE_BELLBOARD                    NRF_SECURE_BELLBOARD_S
  #define NRF_SECURE_MPC200                       NRF_SECURE_MPC200_NS
  #define NRF_SECURE_SPU200                       NRF_SECURE_SPU200_NS
  #define NRF_SECURE_SPU210                       NRF_SECURE_SPU210_NS
  #define NRF_SECURE_CTRLAP                       NRF_SECURE_CTRLAP_NS
  #define NRF_SECURE_SPU110                       NRF_SECURE_SPU110_S
  #define NRF_SECURE_MPC110                       NRF_SECURE_MPC110_S
  #define NRF_SECURE_SPU111                       NRF_SECURE_SPU111_S
  #define NRF_SECURE_MPC111                       NRF_SECURE_MPC111_S
  #define NRF_SECURE_SPU120                       NRF_SECURE_SPU120_S
  #define NRF_SECURE_MPC120                       NRF_SECURE_MPC120_S
  #define NRF_SECURE_SPU121                       NRF_SECURE_SPU121_S
  #define NRF_SECURE_SPU122                       NRF_SECURE_SPU122_S
  #define NRF_SECURE_SPU130                       NRF_SECURE_SPU130_S
  #define NRF_SECURE_MPC130                       NRF_SECURE_MPC130_S
  #define NRF_SECURE_SPU131                       NRF_SECURE_SPU131_S
  #define NRF_SECURE_IPCMAP                       NRF_SECURE_IPCMAP_S
  #define NRF_SECURE_IRQMAP                       NRF_SECURE_IRQMAP_S
  #define NRF_SECURE_SPU132                       NRF_SECURE_SPU132_S
  #define NRF_SECURE_SPU133                       NRF_SECURE_SPU133_S
  #define NRF_SECURE_SPU134                       NRF_SECURE_SPU134_S
  #define NRF_SECURE_SPU135                       NRF_SECURE_SPU135_S
  #define NRF_SECURE_SPU136                       NRF_SECURE_SPU136_S
  #define NRF_SECURE_SPU137                       NRF_SECURE_SPU137_S
#endif                                               /*!<  NRF_TRUSTZONE_NONSECURE                                             */

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_SECURE                                    /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_SICR                                NRF_SECURE_SICR
  #define NRF_RICR                                NRF_SECURE_RICR
  #define NRF_ICACHEDATA                          NRF_SECURE_ICACHEDATA
  #define NRF_ICACHEINFO                          NRF_SECURE_ICACHEINFO
  #define NRF_DCACHEDATA                          NRF_SECURE_DCACHEDATA
  #define NRF_DCACHEINFO                          NRF_SECURE_DCACHEINFO
  #define NRF_CRACENCORE                          NRF_SECURE_CRACENCORE
  #define NRF_MEMCONF200                          NRF_SECURE_MEMCONF200
  #define NRF_ETM                                 NRF_SECURE_ETM
  #define NRF_CTI                                 NRF_SECURE_CTI
  #define NRF_CPUC                                NRF_SECURE_CPUC
  #define NRF_ICACHE                              NRF_SECURE_ICACHE
  #define NRF_DCACHE                              NRF_SECURE_DCACHE
  #define NRF_SPU000                              NRF_SECURE_SPU000
  #define NRF_MPC000                              NRF_SECURE_MPC000
  #define NRF_MVDMA                               NRF_SECURE_MVDMA
  #define NRF_RAMC000                             NRF_SECURE_RAMC000
  #define NRF_ROMC                                NRF_SECURE_ROMC
  #define NRF_CRACEN                              NRF_SECURE_CRACEN
  #define NRF_RAMC001                             NRF_SECURE_RAMC001
  #define NRF_PCGCS000                            NRF_SECURE_PCGCS000
  #define NRF_PCGCM000                            NRF_SECURE_PCGCM000
  #define NRF_HSFLL                               NRF_SECURE_HSFLL
  #define NRF_LRCCONF000                          NRF_SECURE_LRCCONF000
  #define NRF_PCGCM001                            NRF_SECURE_PCGCM001
  #define NRF_SPU010                              NRF_SECURE_SPU010
  #define NRF_CPUCONF                             NRF_SECURE_CPUCONF
  #define NRF_MEMCONF                             NRF_SECURE_MEMCONF
  #define NRF_WDT010                              NRF_SECURE_WDT010
  #define NRF_WDT011                              NRF_SECURE_WDT011
  #define NRF_TAMPC                               NRF_SECURE_TAMPC
  #define NRF_MUTEX                               NRF_SECURE_MUTEX
  #define NRF_BILS                                NRF_SECURE_BILS
  #define NRF_PCGCS010                            NRF_SECURE_PCGCS010
  #define NRF_PCGCM010                            NRF_SECURE_PCGCM010
  #define NRF_ABB                                 NRF_SECURE_ABB
  #define NRF_LRCCONF010                          NRF_SECURE_LRCCONF010
  #define NRF_RESETINFO                           NRF_SECURE_RESETINFO
  #define NRF_PCGCM011                            NRF_SECURE_PCGCM011
  #define NRF_IPCT                                NRF_SECURE_IPCT
  #define NRF_SWI0                                NRF_SECURE_SWI0
  #define NRF_SWI1                                NRF_SECURE_SWI1
  #define NRF_SWI2                                NRF_SECURE_SWI2
  #define NRF_SWI3                                NRF_SECURE_SWI3
  #define NRF_SWI4                                NRF_SECURE_SWI4
  #define NRF_SWI5                                NRF_SECURE_SWI5
  #define NRF_SWI6                                NRF_SECURE_SWI6
  #define NRF_SWI7                                NRF_SECURE_SWI7
  #define NRF_BELLBOARD                           NRF_SECURE_BELLBOARD
  #define NRF_MPC200                              NRF_SECURE_MPC200
  #define NRF_SPU200                              NRF_SECURE_SPU200
  #define NRF_SPU210                              NRF_SECURE_SPU210
  #define NRF_CTRLAP                              NRF_SECURE_CTRLAP
  #define NRF_SPU110                              NRF_SECURE_SPU110
  #define NRF_MPC110                              NRF_SECURE_MPC110
  #define NRF_SPU111                              NRF_SECURE_SPU111
  #define NRF_MPC111                              NRF_SECURE_MPC111
  #define NRF_SPU120                              NRF_SECURE_SPU120
  #define NRF_MPC120                              NRF_SECURE_MPC120
  #define NRF_SPU121                              NRF_SECURE_SPU121
  #define NRF_SPU122                              NRF_SECURE_SPU122
  #define NRF_SPU130                              NRF_SECURE_SPU130
  #define NRF_MPC130                              NRF_SECURE_MPC130
  #define NRF_SPU131                              NRF_SECURE_SPU131
  #define NRF_IPCMAP                              NRF_SECURE_IPCMAP
  #define NRF_IRQMAP                              NRF_SECURE_IRQMAP
  #define NRF_SPU132                              NRF_SECURE_SPU132
  #define NRF_SPU133                              NRF_SECURE_SPU133
  #define NRF_SPU134                              NRF_SECURE_SPU134
  #define NRF_SPU135                              NRF_SECURE_SPU135
  #define NRF_SPU136                              NRF_SECURE_SPU136
  #define NRF_SPU137                              NRF_SECURE_SPU137
#endif                                               /*!< NRF_SECURE                                                           */

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
#endif /* NRF9230_SECURE_H */

