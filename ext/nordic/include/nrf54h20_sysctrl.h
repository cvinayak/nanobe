/*

Copyright (c) 2010 - 2023, Nordic Semiconductor ASA All rights reserved.

SPDX-License-Identifier: BSD-3-Clause

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef NRF54H20_SYSCTRL_H
#define NRF54H20_SYSCTRL_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_SYSCTRL                                   /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
/* ============================================== Processor Specific Interrupts ============================================== */
  VPRCLIC_0_IRQn                         = 0,        /*!< 0 VPRCLIC_0                                                          */
  VPRCLIC_1_IRQn                         = 1,        /*!< 1 VPRCLIC_1                                                          */
  VPRCLIC_2_IRQn                         = 2,        /*!< 2 VPRCLIC_2                                                          */
  VPRCLIC_3_IRQn                         = 3,        /*!< 3 VPRCLIC_3                                                          */
  VPRCLIC_4_IRQn                         = 4,        /*!< 4 VPRCLIC_4                                                          */
  VPRCLIC_5_IRQn                         = 5,        /*!< 5 VPRCLIC_5                                                          */
  VPRCLIC_6_IRQn                         = 6,        /*!< 6 VPRCLIC_6                                                          */
  VPRCLIC_7_IRQn                         = 7,        /*!< 7 VPRCLIC_7                                                          */
  VPRCLIC_8_IRQn                         = 8,        /*!< 8 VPRCLIC_8                                                          */
  VPRCLIC_9_IRQn                         = 9,        /*!< 9 VPRCLIC_9                                                          */
  VPRCLIC_10_IRQn                        = 10,       /*!< 10 VPRCLIC_10                                                        */
  VPRCLIC_11_IRQn                        = 11,       /*!< 11 VPRCLIC_11                                                        */
  VPRCLIC_12_IRQn                        = 12,       /*!< 12 VPRCLIC_12                                                        */
  VPRCLIC_13_IRQn                        = 13,       /*!< 13 VPRCLIC_13                                                        */
  VPRCLIC_14_IRQn                        = 14,       /*!< 14 VPRCLIC_14                                                        */
  VPRCLIC_15_IRQn                        = 15,       /*!< 15 VPRCLIC_15                                                        */
  VPRCLIC_16_IRQn                        = 16,       /*!< 16 VPRCLIC_16                                                        */
  VPRCLIC_17_IRQn                        = 17,       /*!< 17 VPRCLIC_17                                                        */
  VPRCLIC_18_IRQn                        = 18,       /*!< 18 VPRCLIC_18                                                        */
  VPRCLIC_19_IRQn                        = 19,       /*!< 19 VPRCLIC_19                                                        */
  VPRCLIC_20_IRQn                        = 20,       /*!< 20 VPRCLIC_20                                                        */
  VPRCLIC_21_IRQn                        = 21,       /*!< 21 VPRCLIC_21                                                        */
  VPRCLIC_22_IRQn                        = 22,       /*!< 22 VPRCLIC_22                                                        */
  VPRCLIC_23_IRQn                        = 23,       /*!< 23 VPRCLIC_23                                                        */
  VPRCLIC_24_IRQn                        = 24,       /*!< 24 VPRCLIC_24                                                        */
  VPRCLIC_25_IRQn                        = 25,       /*!< 25 VPRCLIC_25                                                        */
  VPRCLIC_26_IRQn                        = 26,       /*!< 26 VPRCLIC_26                                                        */
  VPRCLIC_27_IRQn                        = 27,       /*!< 27 VPRCLIC_27                                                        */
  VPRCLIC_28_IRQn                        = 28,       /*!< 28 VPRCLIC_28                                                        */
  VPRCLIC_29_IRQn                        = 29,       /*!< 29 VPRCLIC_29                                                        */
  VPRCLIC_30_IRQn                        = 30,       /*!< 30 VPRCLIC_30                                                        */
  VPRCLIC_31_IRQn                        = 31,       /*!< 31 VPRCLIC_31                                                        */
  VPRTIM_IRQn                            = 32,       /*!< 32 VPRTIM                                                            */
  GPIOTE130_0_IRQn                       = 104,      /*!< 104 GPIOTE130_0                                                      */
  GPIOTE130_1_IRQn                       = 105,      /*!< 105 GPIOTE130_1                                                      */
  GRTC_0_IRQn                            = 108,      /*!< 108 GRTC_0                                                           */
  GRTC_1_IRQn                            = 109,      /*!< 109 GRTC_1                                                           */
  GRTC_2_IRQn                            = 110,      /*!< 110 GRTC_2                                                           */
  TBM_IRQn                               = 127,      /*!< 127 TBM                                                              */
  L2CACHE_IRQn                           = 130,      /*!< 130 L2CACHE                                                          */
  USBHS_IRQn                             = 134,      /*!< 134 USBHS                                                            */
  SHA3_IRQn                              = 136,      /*!< 136 SHA3                                                             */
  MRAMC110_IRQn                          = 146,      /*!< 146 MRAMC110                                                         */
  MRAMC111_IRQn                          = 147,      /*!< 147 MRAMC111                                                         */
  EXMEE_IRQn                             = 148,      /*!< 148 EXMEE                                                            */
  EXMIF_IRQn                             = 149,      /*!< 149 EXMIF                                                            */
  MVDMA110_IRQn                          = 151,      /*!< 151 MVDMA110                                                         */
  OTPC_IRQn                              = 197,      /*!< 197 OTPC                                                             */
  VPR120_IRQn                            = 200,      /*!< 200 VPR120                                                           */
  IPCT120_0_IRQn                         = 209,      /*!< 209 IPCT120_0                                                        */
  I3C120_IRQn                            = 211,      /*!< 211 I3C120                                                           */
  VPR121_IRQn                            = 212,      /*!< 212 VPR121                                                           */
  CAN120_IRQn                            = 216,      /*!< 216 CAN120                                                           */
  MVDMA120_IRQn                          = 217,      /*!< 217 MVDMA120                                                         */
  I3C121_IRQn                            = 222,      /*!< 222 I3C121                                                           */
  TIMER120_IRQn                          = 226,      /*!< 226 TIMER120                                                         */
  TIMER121_IRQn                          = 227,      /*!< 227 TIMER121                                                         */
  PWM120_IRQn                            = 228,      /*!< 228 PWM120                                                           */
  SPIS120_IRQn                           = 229,      /*!< 229 SPIS120                                                          */
  SPIM120_UARTE120_IRQn                  = 230,      /*!< 230 SPIM120_UARTE120                                                 */
  SPIM121_IRQn                           = 231,      /*!< 231 SPIM121                                                          */
  VPR130_IRQn                            = 264,      /*!< 264 VPR130                                                           */
  IPCT130_0_IRQn                         = 289,      /*!< 289 IPCT130_0                                                        */
  RTC130_IRQn                            = 296,      /*!< 296 RTC130                                                           */
  RTC131_IRQn                            = 297,      /*!< 297 RTC131                                                           */
  WDT130_IRQn                            = 298,      /*!< 298 WDT130                                                           */
  WDT131_IRQn                            = 299,      /*!< 299 WDT131                                                           */
  WDT132_IRQn                            = 300,      /*!< 300 WDT132                                                           */
  EGU130_IRQn                            = 301,      /*!< 301 EGU130                                                           */
  GRCCONF_0_IRQn                         = 320,      /*!< 320 GRCCONF_0                                                        */
  GRCCONF_1_IRQn                         = 321,      /*!< 321 GRCCONF_1                                                        */
  GRCCONF_2_IRQn                         = 322,      /*!< 322 GRCCONF_2                                                        */
  PCRM_IRQn                              = 323,      /*!< 323 PCRM                                                             */
  RESETHUB_IRQn                          = 329,      /*!< 329 RESETHUB                                                         */
  VREGUSB_IRQn                           = 359,      /*!< 359 VREGUSB                                                          */
  SAADC_IRQn                             = 386,      /*!< 386 SAADC                                                            */
  COMP_LPCOMP_IRQn                       = 387,      /*!< 387 COMP_LPCOMP                                                      */
  TEMP_IRQn                              = 388,      /*!< 388 TEMP                                                             */
  NFCT_IRQn                              = 389,      /*!< 389 NFCT                                                             */
  TDM130_IRQn                            = 402,      /*!< 402 TDM130                                                           */
  PDM_IRQn                               = 403,      /*!< 403 PDM                                                              */
  QDEC130_IRQn                           = 404,      /*!< 404 QDEC130                                                          */
  QDEC131_IRQn                           = 405,      /*!< 405 QDEC131                                                          */
  SIMIF130_IRQn                          = 406,      /*!< 406 SIMIF130                                                         */
  TDM131_IRQn                            = 407,      /*!< 407 TDM131                                                           */
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

/* ====================== Configuration of the Nordic Semiconductor VPR Processor and Core Peripherals ======================= */
#define __VPR_REV                    1.1             /*!< VPR Core Revision                                                    */
#define __DSP_PRESENT                  0             /*!< DSP present or not                                                   */
#define __CLIC_PRIO_BITS               3             /*!< Number of Bits used for Priority Levels                              */
#define __MTVT_PRESENT                 1             /*!< CPU supports alternate Vector Table address                          */
#define __MPU_PRESENT                  1             /*!< MPU present                                                          */
#define __FPU_PRESENT                  0             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX             480             /*!< Size of interrupt vector table                                       */

#include "core_vpr.h"                                /*!< Nordic Semiconductor VPR processor and core peripherals              */
#include "system_nrf.h"                              /*!< nrf54h20_sysctrl System Library                                      */

#endif                                               /*!< NRF_SYSCTRL                                                          */


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
#else
  #warning Unsupported compiler type
#endif

/* =========================================================================================================================== */
/* ================                                  Peripheral Address Map                                  ================ */
/* =========================================================================================================================== */

#define NRF_SYSCTRL_OICR_BASE             0x2F840000UL
#define NRF_SYSCTRL_L2CACHEDATA_BASE      0x3F640000UL
#define NRF_SYSCTRL_L2CACHEINFO_BASE      0x3F680000UL
#define NRF_SYSCTRL_SHA3CORE_BASE         0x5F089000UL
#define NRF_SYSCTRL_HSFLL200_BASE         0xBF004000UL
#define NRF_SYSCTRL_LRCCONF200_BASE       0xBF005000UL
#define NRF_SYSCTRL_PCGCM200_BASE         0xBF006000UL
#define NRF_SYSCTRL_PCGCS200_BASE         0xBF011000UL
#define NRF_SYSCTRL_LRCCONF210_BASE       0xBF012000UL
#define NRF_SYSCTRL_PCGCM210_BASE         0xBF013000UL
#define NRF_SYSCTRL_VPRCLIC_BASE          0xF0000000UL
#define NRF_SYSCTRL_L2CACHE_BASE          0x5F082000UL
#define NRF_SYSCTRL_RAMC110_BASE          0x5F083000UL
#define NRF_SYSCTRL_RAMC111_BASE          0x5F084000UL
#define NRF_SYSCTRL_SHA3_BASE             0x5F088000UL
#define NRF_SYSCTRL_PCGCS110_BASE         0x5F08E000UL
#define NRF_SYSCTRL_PCGCM110_BASE         0x5F08F000UL
#define NRF_SYSCTRL_EXMEE_BASE            0x5F094000UL
#define NRF_SYSCTRL_MVDMA110_BASE         0x5F097000UL
#define NRF_SYSCTRL_PPIB110_BASE          0x5F098000UL
#define NRF_SYSCTRL_RAMC120_BASE          0x5F8C3000UL
#define NRF_SYSCTRL_RAMC121_BASE          0x5F8C4000UL
#define NRF_SYSCTRL_ROMC_BASE             0x5F8C6000UL
#define NRF_SYSCTRL_MEMCONF120_BASE       0x5F8C7000UL
#define NRF_SYSCTRL_HSFLL121_BASE         0x5F8CC000UL
#define NRF_SYSCTRL_HSFLL120_BASE         0x5F8CD000UL
#define NRF_SYSCTRL_LRCCONF120_BASE       0x5F8CE000UL
#define NRF_SYSCTRL_PCGCM120_BASE         0x5F8CF000UL
#define NRF_SYSCTRL_PCGCS120_BASE         0x5F8EA000UL
#define NRF_SYSCTRL_PCGCS121_BASE         0x5F8EB000UL
#define NRF_SYSCTRL_PCGCS122_BASE         0x5F8EC000UL
#define NRF_SYSCTRL_PCGCM121_BASE         0x5F8ED000UL
#define NRF_SYSCTRL_PPIB120_BASE          0x5F8EE000UL
#define NRF_SYSCTRL_PPIB121_BASE          0x5F8EF000UL
#define NRF_SYSCTRL_RAMC130_BASE          0x5F903000UL
#define NRF_SYSCTRL_RAMC131_BASE          0x5F904000UL
#define NRF_SYSCTRL_MEMCONF130_BASE       0x5F905000UL
#define NRF_SYSCTRL_PCGCS130_BASE         0x5F90E000UL
#define NRF_SYSCTRL_PPIB130_BASE          0x5F925000UL
#define NRF_SYSCTRL_PPIB131_BASE          0x5F926000UL
#define NRF_SYSCTRL_WDT130_BASE           0x5F92A000UL
#define NRF_SYSCTRL_PCGCS131_BASE         0x5F93C000UL
#define NRF_SYSCTRL_PCGCM130_BASE         0x5F93D000UL
#define NRF_SYSCTRL_LRCCONF130_BASE       0x5F93E000UL
#define NRF_SYSCTRL_PCGCM131_BASE         0x5F93F000UL
#define NRF_SYSCTRL_GRCCONF_BASE          0x5F940000UL
#define NRF_SYSCTRL_PCRM_BASE             0x5F943000UL
#define NRF_SYSCTRL_PCGCS132_BASE         0x5F94E000UL
#define NRF_SYSCTRL_PCGCM132_BASE         0x5F94F000UL
#define NRF_SYSCTRL_CLOCK_BASE            0x5F950000UL
#define NRF_SYSCTRL_LFRC_BASE             0x5F951000UL
#define NRF_SYSCTRL_LFLPRC_BASE           0x5F952000UL
#define NRF_SYSCTRL_LFXO_BASE             0x5F953000UL
#define NRF_SYSCTRL_FLL16M_BASE           0x5F954000UL
#define NRF_SYSCTRL_HFXO_BASE             0x5F955000UL
#define NRF_SYSCTRL_CLKMON_BASE           0x5F956000UL
#define NRF_SYSCTRL_AUDIOPLL_BASE         0x5F957000UL
#define NRF_SYSCTRL_USBHSPLL_BASE         0x5F958000UL
#define NRF_SYSCTRL_POWER_BASE            0x5F960000UL
#define NRF_SYSCTRL_VREGMAIN_BASE         0x5F961000UL
#define NRF_SYSCTRL_VREGAO1V8_BASE        0x5F962000UL
#define NRF_SYSCTRL_VREG1V0_BASE          0x5F963000UL
#define NRF_SYSCTRL_VREGAO0V8_BASE        0x5F964000UL
#define NRF_SYSCTRL_VREGVS0V8_BASE        0x5F965000UL
#define NRF_SYSCTRL_VREGSU_BASE           0x5F966000UL
#define NRF_SYSCTRL_VREGUSB_BASE          0x5F967000UL
#define NRF_SYSCTRL_AUDIOPLLPM_BASE       0x5F968000UL
#define NRF_SYSCTRL_VREGMRAM130_BASE      0x5F969000UL
#define NRF_SYSCTRL_VREGMRAM131_BASE      0x5F96A000UL
#define NRF_SYSCTRL_OSCRFR_BASE           0x5F96B000UL
#define NRF_SYSCTRL_SWEXT_BASE            0x5F96C000UL
#define NRF_SYSCTRL_MBIAS_BASE            0x5F96D000UL
#define NRF_SYSCTRL_VDETAO1V8_BASE        0x5F970000UL
#define NRF_SYSCTRL_VDETAO0V8_BASE        0x5F971000UL
#define NRF_SYSCTRL_VDETVS0V8_BASE        0x5F972000UL
#define NRF_SYSCTRL_VDETIO_BASE           0x5F974000UL
#define NRF_SYSCTRL_VDETAO5V0_BASE        0x5F975000UL
#define NRF_SYSCTRL_VDET1V0_BASE          0x5F976000UL
#define NRF_SYSCTRL_VDETPOF5V0_BASE       0x5F979000UL
#define NRF_SYSCTRL_PPIB132_BASE          0x5F98D000UL
#define NRF_SYSCTRL_PCGCS133_BASE         0x5F98E000UL
#define NRF_SYSCTRL_PCGCM133_BASE         0x5F98F000UL
#define NRF_SYSCTRL_PPIB133_BASE          0x5F99D000UL
#define NRF_SYSCTRL_PCGCS134_BASE         0x5F99E000UL
#define NRF_SYSCTRL_PCGCM134_BASE         0x5F99F000UL
#define NRF_SYSCTRL_PPIB134_BASE          0x5F9AD000UL
#define NRF_SYSCTRL_PCGCS135_BASE         0x5F9AE000UL
#define NRF_SYSCTRL_PCGCM135_BASE         0x5F9AF000UL
#define NRF_SYSCTRL_PPIB135_BASE          0x5F9BD000UL
#define NRF_SYSCTRL_PCGCS136_BASE         0x5F9BE000UL
#define NRF_SYSCTRL_PCGCM136_BASE         0x5F9BF000UL
#define NRF_SYSCTRL_PPIB136_BASE          0x5F9CD000UL
#define NRF_SYSCTRL_PCGCS137_BASE         0x5F9CE000UL
#define NRF_SYSCTRL_PCGCM137_BASE         0x5F9CF000UL
#define NRF_SYSCTRL_PPIB137_BASE          0x5F9DD000UL
#define NRF_SYSCTRL_PCGCS138_BASE         0x5F9DE000UL
#define NRF_SYSCTRL_PCGCM138_BASE         0x5F9DF000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_SYSCTRL_OICR                  ((NRF_OICR_Type*)                     NRF_SYSCTRL_OICR_BASE)
#define NRF_SYSCTRL_L2CACHEDATA           ((NRF_L2CACHEDATA_Type*)              NRF_SYSCTRL_L2CACHEDATA_BASE)
#define NRF_SYSCTRL_L2CACHEINFO           ((NRF_L2CACHEINFO_Type*)              NRF_SYSCTRL_L2CACHEINFO_BASE)
#define NRF_SYSCTRL_SHA3CORE              ((NRF_SHA3CORE_Type*)                 NRF_SYSCTRL_SHA3CORE_BASE)
#define NRF_SYSCTRL_HSFLL200              ((NRF_HSFLL_Type*)                    NRF_SYSCTRL_HSFLL200_BASE)
#define NRF_SYSCTRL_LRCCONF200            ((NRF_LRCCONF_Type*)                  NRF_SYSCTRL_LRCCONF200_BASE)
#define NRF_SYSCTRL_PCGCM200              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM200_BASE)
#define NRF_SYSCTRL_PCGCS200              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS200_BASE)
#define NRF_SYSCTRL_LRCCONF210            ((NRF_LRCCONF_Type*)                  NRF_SYSCTRL_LRCCONF210_BASE)
#define NRF_SYSCTRL_PCGCM210              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM210_BASE)
#define NRF_SYSCTRL_VPRCLIC               ((NRF_CLIC_Type*)                     NRF_SYSCTRL_VPRCLIC_BASE)
#define NRF_SYSCTRL_L2CACHE               ((NRF_CACHE_Type*)                    NRF_SYSCTRL_L2CACHE_BASE)
#define NRF_SYSCTRL_RAMC110               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC110_BASE)
#define NRF_SYSCTRL_RAMC111               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC111_BASE)
#define NRF_SYSCTRL_SHA3                  ((NRF_SHA3_Type*)                     NRF_SYSCTRL_SHA3_BASE)
#define NRF_SYSCTRL_PCGCS110              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS110_BASE)
#define NRF_SYSCTRL_PCGCM110              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM110_BASE)
#define NRF_SYSCTRL_EXMEE                 ((NRF_EXMEE_Type*)                    NRF_SYSCTRL_EXMEE_BASE)
#define NRF_SYSCTRL_MVDMA110              ((NRF_MVDMA_Type*)                    NRF_SYSCTRL_MVDMA110_BASE)
#define NRF_SYSCTRL_PPIB110               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB110_BASE)
#define NRF_SYSCTRL_RAMC120               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC120_BASE)
#define NRF_SYSCTRL_RAMC121               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC121_BASE)
#define NRF_SYSCTRL_ROMC                  ((NRF_ROMC_Type*)                     NRF_SYSCTRL_ROMC_BASE)
#define NRF_SYSCTRL_MEMCONF120            ((NRF_MEMCONF_Type*)                  NRF_SYSCTRL_MEMCONF120_BASE)
#define NRF_SYSCTRL_HSFLL121              ((NRF_HSFLL_Type*)                    NRF_SYSCTRL_HSFLL121_BASE)
#define NRF_SYSCTRL_HSFLL120              ((NRF_HSFLL_Type*)                    NRF_SYSCTRL_HSFLL120_BASE)
#define NRF_SYSCTRL_LRCCONF120            ((NRF_LRCCONF_Type*)                  NRF_SYSCTRL_LRCCONF120_BASE)
#define NRF_SYSCTRL_PCGCM120              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM120_BASE)
#define NRF_SYSCTRL_PCGCS120              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS120_BASE)
#define NRF_SYSCTRL_PCGCS121              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS121_BASE)
#define NRF_SYSCTRL_PCGCS122              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS122_BASE)
#define NRF_SYSCTRL_PCGCM121              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM121_BASE)
#define NRF_SYSCTRL_PPIB120               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB120_BASE)
#define NRF_SYSCTRL_PPIB121               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB121_BASE)
#define NRF_SYSCTRL_RAMC130               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC130_BASE)
#define NRF_SYSCTRL_RAMC131               ((NRF_RAMC_Type*)                     NRF_SYSCTRL_RAMC131_BASE)
#define NRF_SYSCTRL_MEMCONF130            ((NRF_MEMCONF_Type*)                  NRF_SYSCTRL_MEMCONF130_BASE)
#define NRF_SYSCTRL_PCGCS130              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS130_BASE)
#define NRF_SYSCTRL_PPIB130               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB130_BASE)
#define NRF_SYSCTRL_PPIB131               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB131_BASE)
#define NRF_SYSCTRL_WDT130                ((NRF_WDT_Type*)                      NRF_SYSCTRL_WDT130_BASE)
#define NRF_SYSCTRL_PCGCS131              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS131_BASE)
#define NRF_SYSCTRL_PCGCM130              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM130_BASE)
#define NRF_SYSCTRL_LRCCONF130            ((NRF_LRCCONF_Type*)                  NRF_SYSCTRL_LRCCONF130_BASE)
#define NRF_SYSCTRL_PCGCM131              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM131_BASE)
#define NRF_SYSCTRL_GRCCONF               ((NRF_GRCCONF_Type*)                  NRF_SYSCTRL_GRCCONF_BASE)
#define NRF_SYSCTRL_PCRM                  ((NRF_PCRM_Type*)                     NRF_SYSCTRL_PCRM_BASE)
#define NRF_SYSCTRL_PCGCS132              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS132_BASE)
#define NRF_SYSCTRL_PCGCM132              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM132_BASE)
#define NRF_SYSCTRL_CLOCK                 ((NRF_CLOCK_Type*)                    NRF_SYSCTRL_CLOCK_BASE)
#define NRF_SYSCTRL_LFRC                  ((NRF_LFRC_Type*)                     NRF_SYSCTRL_LFRC_BASE)
#define NRF_SYSCTRL_LFLPRC                ((NRF_LFLPRC_Type*)                   NRF_SYSCTRL_LFLPRC_BASE)
#define NRF_SYSCTRL_LFXO                  ((NRF_LFXO_Type*)                     NRF_SYSCTRL_LFXO_BASE)
#define NRF_SYSCTRL_FLL16M                ((NRF_FLL16M_Type*)                   NRF_SYSCTRL_FLL16M_BASE)
#define NRF_SYSCTRL_HFXO                  ((NRF_HFXO_Type*)                     NRF_SYSCTRL_HFXO_BASE)
#define NRF_SYSCTRL_CLKMON                ((NRF_CLKMON_Type*)                   NRF_SYSCTRL_CLKMON_BASE)
#define NRF_SYSCTRL_AUDIOPLL              ((NRF_AUXPLL_Type*)                   NRF_SYSCTRL_AUDIOPLL_BASE)
#define NRF_SYSCTRL_USBHSPLL              ((NRF_AUXPLL_Type*)                   NRF_SYSCTRL_USBHSPLL_BASE)
#define NRF_SYSCTRL_POWER                 ((NRF_POWER_Type*)                    NRF_SYSCTRL_POWER_BASE)
#define NRF_SYSCTRL_VREGMAIN              ((NRF_VREGMAIN_Type*)                 NRF_SYSCTRL_VREGMAIN_BASE)
#define NRF_SYSCTRL_VREGAO1V8             ((NRF_VREGAO1V8_Type*)                NRF_SYSCTRL_VREGAO1V8_BASE)
#define NRF_SYSCTRL_VREG1V0               ((NRF_VREG1V0_Type*)                  NRF_SYSCTRL_VREG1V0_BASE)
#define NRF_SYSCTRL_VREGAO0V8             ((NRF_VREGAO0V8_Type*)                NRF_SYSCTRL_VREGAO0V8_BASE)
#define NRF_SYSCTRL_VREGVS0V8             ((NRF_VREGVS0V8_Type*)                NRF_SYSCTRL_VREGVS0V8_BASE)
#define NRF_SYSCTRL_VREGSU                ((NRF_VREGSU_Type*)                   NRF_SYSCTRL_VREGSU_BASE)
#define NRF_SYSCTRL_VREGUSB               ((NRF_VREGUSB_Type*)                  NRF_SYSCTRL_VREGUSB_BASE)
#define NRF_SYSCTRL_AUDIOPLLPM            ((NRF_AUXPM_Type*)                    NRF_SYSCTRL_AUDIOPLLPM_BASE)
#define NRF_SYSCTRL_VREGMRAM130           ((NRF_VREGMRAM_Type*)                 NRF_SYSCTRL_VREGMRAM130_BASE)
#define NRF_SYSCTRL_VREGMRAM131           ((NRF_VREGMRAM_Type*)                 NRF_SYSCTRL_VREGMRAM131_BASE)
#define NRF_SYSCTRL_OSCRFR                ((NRF_OSCRFR_Type*)                   NRF_SYSCTRL_OSCRFR_BASE)
#define NRF_SYSCTRL_SWEXT                 ((NRF_SWEXT_Type*)                    NRF_SYSCTRL_SWEXT_BASE)
#define NRF_SYSCTRL_MBIAS                 ((NRF_MBIAS_Type*)                    NRF_SYSCTRL_MBIAS_BASE)
#define NRF_SYSCTRL_VDETAO1V8             ((NRF_VDETAO1V8_Type*)                NRF_SYSCTRL_VDETAO1V8_BASE)
#define NRF_SYSCTRL_VDETAO0V8             ((NRF_VDETAO0V8_Type*)                NRF_SYSCTRL_VDETAO0V8_BASE)
#define NRF_SYSCTRL_VDETVS0V8             ((NRF_VDETVS0V8_Type*)                NRF_SYSCTRL_VDETVS0V8_BASE)
#define NRF_SYSCTRL_VDETIO                ((NRF_VDETIO_Type*)                   NRF_SYSCTRL_VDETIO_BASE)
#define NRF_SYSCTRL_VDETAO5V0             ((NRF_VDETAO5V0_Type*)                NRF_SYSCTRL_VDETAO5V0_BASE)
#define NRF_SYSCTRL_VDET1V0               ((NRF_VDET1V0_Type*)                  NRF_SYSCTRL_VDET1V0_BASE)
#define NRF_SYSCTRL_VDETPOF5V0            ((NRF_VDETPOF5V0_Type*)               NRF_SYSCTRL_VDETPOF5V0_BASE)
#define NRF_SYSCTRL_PPIB132               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB132_BASE)
#define NRF_SYSCTRL_PCGCS133              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS133_BASE)
#define NRF_SYSCTRL_PCGCM133              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM133_BASE)
#define NRF_SYSCTRL_PPIB133               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB133_BASE)
#define NRF_SYSCTRL_PCGCS134              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS134_BASE)
#define NRF_SYSCTRL_PCGCM134              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM134_BASE)
#define NRF_SYSCTRL_PPIB134               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB134_BASE)
#define NRF_SYSCTRL_PCGCS135              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS135_BASE)
#define NRF_SYSCTRL_PCGCM135              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM135_BASE)
#define NRF_SYSCTRL_PPIB135               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB135_BASE)
#define NRF_SYSCTRL_PCGCS136              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS136_BASE)
#define NRF_SYSCTRL_PCGCM136              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM136_BASE)
#define NRF_SYSCTRL_PPIB136               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB136_BASE)
#define NRF_SYSCTRL_PCGCS137              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS137_BASE)
#define NRF_SYSCTRL_PCGCM137              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM137_BASE)
#define NRF_SYSCTRL_PPIB137               ((NRF_PPIB_Type*)                     NRF_SYSCTRL_PPIB137_BASE)
#define NRF_SYSCTRL_PCGCS138              ((NRF_PCGCSLAVE_Type*)                NRF_SYSCTRL_PCGCS138_BASE)
#define NRF_SYSCTRL_PCGCM138              ((NRF_PCGCMASTER_Type*)               NRF_SYSCTRL_PCGCM138_BASE)

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_SYSCTRL                                   /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_OICR                                NRF_SYSCTRL_OICR
  #define NRF_L2CACHEDATA                         NRF_SYSCTRL_L2CACHEDATA
  #define NRF_L2CACHEINFO                         NRF_SYSCTRL_L2CACHEINFO
  #define NRF_SHA3CORE                            NRF_SYSCTRL_SHA3CORE
  #define NRF_HSFLL200                            NRF_SYSCTRL_HSFLL200
  #define NRF_LRCCONF200                          NRF_SYSCTRL_LRCCONF200
  #define NRF_PCGCM200                            NRF_SYSCTRL_PCGCM200
  #define NRF_PCGCS200                            NRF_SYSCTRL_PCGCS200
  #define NRF_LRCCONF210                          NRF_SYSCTRL_LRCCONF210
  #define NRF_PCGCM210                            NRF_SYSCTRL_PCGCM210
  #define NRF_VPRCLIC                             NRF_SYSCTRL_VPRCLIC
  #define NRF_L2CACHE                             NRF_SYSCTRL_L2CACHE
  #define NRF_RAMC110                             NRF_SYSCTRL_RAMC110
  #define NRF_RAMC111                             NRF_SYSCTRL_RAMC111
  #define NRF_SHA3                                NRF_SYSCTRL_SHA3
  #define NRF_PCGCS110                            NRF_SYSCTRL_PCGCS110
  #define NRF_PCGCM110                            NRF_SYSCTRL_PCGCM110
  #define NRF_EXMEE                               NRF_SYSCTRL_EXMEE
  #define NRF_MVDMA110                            NRF_SYSCTRL_MVDMA110
  #define NRF_PPIB110                             NRF_SYSCTRL_PPIB110
  #define NRF_RAMC120                             NRF_SYSCTRL_RAMC120
  #define NRF_RAMC121                             NRF_SYSCTRL_RAMC121
  #define NRF_ROMC                                NRF_SYSCTRL_ROMC
  #define NRF_MEMCONF120                          NRF_SYSCTRL_MEMCONF120
  #define NRF_HSFLL121                            NRF_SYSCTRL_HSFLL121
  #define NRF_HSFLL120                            NRF_SYSCTRL_HSFLL120
  #define NRF_LRCCONF120                          NRF_SYSCTRL_LRCCONF120
  #define NRF_PCGCM120                            NRF_SYSCTRL_PCGCM120
  #define NRF_PCGCS120                            NRF_SYSCTRL_PCGCS120
  #define NRF_PCGCS121                            NRF_SYSCTRL_PCGCS121
  #define NRF_PCGCS122                            NRF_SYSCTRL_PCGCS122
  #define NRF_PCGCM121                            NRF_SYSCTRL_PCGCM121
  #define NRF_PPIB120                             NRF_SYSCTRL_PPIB120
  #define NRF_PPIB121                             NRF_SYSCTRL_PPIB121
  #define NRF_RAMC130                             NRF_SYSCTRL_RAMC130
  #define NRF_RAMC131                             NRF_SYSCTRL_RAMC131
  #define NRF_MEMCONF130                          NRF_SYSCTRL_MEMCONF130
  #define NRF_PCGCS130                            NRF_SYSCTRL_PCGCS130
  #define NRF_PPIB130                             NRF_SYSCTRL_PPIB130
  #define NRF_PPIB131                             NRF_SYSCTRL_PPIB131
  #define NRF_WDT130                              NRF_SYSCTRL_WDT130
  #define NRF_PCGCS131                            NRF_SYSCTRL_PCGCS131
  #define NRF_PCGCM130                            NRF_SYSCTRL_PCGCM130
  #define NRF_LRCCONF130                          NRF_SYSCTRL_LRCCONF130
  #define NRF_PCGCM131                            NRF_SYSCTRL_PCGCM131
  #define NRF_GRCCONF                             NRF_SYSCTRL_GRCCONF
  #define NRF_PCRM                                NRF_SYSCTRL_PCRM
  #define NRF_PCGCS132                            NRF_SYSCTRL_PCGCS132
  #define NRF_PCGCM132                            NRF_SYSCTRL_PCGCM132
  #define NRF_CLOCK                               NRF_SYSCTRL_CLOCK
  #define NRF_LFRC                                NRF_SYSCTRL_LFRC
  #define NRF_LFLPRC                              NRF_SYSCTRL_LFLPRC
  #define NRF_LFXO                                NRF_SYSCTRL_LFXO
  #define NRF_FLL16M                              NRF_SYSCTRL_FLL16M
  #define NRF_HFXO                                NRF_SYSCTRL_HFXO
  #define NRF_CLKMON                              NRF_SYSCTRL_CLKMON
  #define NRF_AUDIOPLL                            NRF_SYSCTRL_AUDIOPLL
  #define NRF_USBHSPLL                            NRF_SYSCTRL_USBHSPLL
  #define NRF_POWER                               NRF_SYSCTRL_POWER
  #define NRF_VREGMAIN                            NRF_SYSCTRL_VREGMAIN
  #define NRF_VREGAO1V8                           NRF_SYSCTRL_VREGAO1V8
  #define NRF_VREG1V0                             NRF_SYSCTRL_VREG1V0
  #define NRF_VREGAO0V8                           NRF_SYSCTRL_VREGAO0V8
  #define NRF_VREGVS0V8                           NRF_SYSCTRL_VREGVS0V8
  #define NRF_VREGSU                              NRF_SYSCTRL_VREGSU
  #define NRF_VREGUSB                             NRF_SYSCTRL_VREGUSB
  #define NRF_AUDIOPLLPM                          NRF_SYSCTRL_AUDIOPLLPM
  #define NRF_VREGMRAM130                         NRF_SYSCTRL_VREGMRAM130
  #define NRF_VREGMRAM131                         NRF_SYSCTRL_VREGMRAM131
  #define NRF_OSCRFR                              NRF_SYSCTRL_OSCRFR
  #define NRF_SWEXT                               NRF_SYSCTRL_SWEXT
  #define NRF_MBIAS                               NRF_SYSCTRL_MBIAS
  #define NRF_VDETAO1V8                           NRF_SYSCTRL_VDETAO1V8
  #define NRF_VDETAO0V8                           NRF_SYSCTRL_VDETAO0V8
  #define NRF_VDETVS0V8                           NRF_SYSCTRL_VDETVS0V8
  #define NRF_VDETIO                              NRF_SYSCTRL_VDETIO
  #define NRF_VDETAO5V0                           NRF_SYSCTRL_VDETAO5V0
  #define NRF_VDET1V0                             NRF_SYSCTRL_VDET1V0
  #define NRF_VDETPOF5V0                          NRF_SYSCTRL_VDETPOF5V0
  #define NRF_PPIB132                             NRF_SYSCTRL_PPIB132
  #define NRF_PCGCS133                            NRF_SYSCTRL_PCGCS133
  #define NRF_PCGCM133                            NRF_SYSCTRL_PCGCM133
  #define NRF_PPIB133                             NRF_SYSCTRL_PPIB133
  #define NRF_PCGCS134                            NRF_SYSCTRL_PCGCS134
  #define NRF_PCGCM134                            NRF_SYSCTRL_PCGCM134
  #define NRF_PPIB134                             NRF_SYSCTRL_PPIB134
  #define NRF_PCGCS135                            NRF_SYSCTRL_PCGCS135
  #define NRF_PCGCM135                            NRF_SYSCTRL_PCGCM135
  #define NRF_PPIB135                             NRF_SYSCTRL_PPIB135
  #define NRF_PCGCS136                            NRF_SYSCTRL_PCGCS136
  #define NRF_PCGCM136                            NRF_SYSCTRL_PCGCM136
  #define NRF_PPIB136                             NRF_SYSCTRL_PPIB136
  #define NRF_PCGCS137                            NRF_SYSCTRL_PCGCS137
  #define NRF_PCGCM137                            NRF_SYSCTRL_PCGCM137
  #define NRF_PPIB137                             NRF_SYSCTRL_PPIB137
  #define NRF_PCGCS138                            NRF_SYSCTRL_PCGCS138
  #define NRF_PCGCM138                            NRF_SYSCTRL_PCGCM138
#endif                                               /*!< NRF_SYSCTRL                                                          */

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
#endif


#ifdef __cplusplus
}
#endif
#endif /* NRF54H20_SYSCTRL_H */

