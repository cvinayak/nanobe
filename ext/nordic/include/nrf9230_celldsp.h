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

#ifndef NRF9230_CELLDSP_H
#define NRF9230_CELLDSP_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_CELLDSP                                   /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
/* ============================================== Processor Specific Interrupts ============================================== */
  MPC_IRQn                               = 2,        /*!< 2 MPC                                                                */
  MVDMA_IRQn                             = 3,        /*!< 3 MVDMA                                                              */
  GENERIC2_IRQn                          = 7,        /*!< 7 GENERIC2                                                           */
  LTEFE_0_IRQn                           = 10,       /*!< 10 LTEFE_0                                                           */
  LTEFE_1_IRQn                           = 11,       /*!< 11 LTEFE_1                                                           */
  HARQ_0_LTEFE_2_IRQn                    = 12,       /*!< 12 HARQ_0_LTEFE_2                                                    */
  HARQ_1_LTEFE_3_VITERBI_0_IRQn          = 13,       /*!< 13 HARQ_1_LTEFE_3_VITERBI_0                                          */
  HARQ_2_LTEFE_4_VITERBI_1_IRQn          = 14,       /*!< 14 HARQ_2_LTEFE_4_VITERBI_1                                          */
  HARQ_3_LTEFE_5_VITERBI_2_IRQn          = 15,       /*!< 15 HARQ_3_LTEFE_5_VITERBI_2                                          */
  HARQ_4_LTEFE_6_VITERBI_3_IRQn          = 16,       /*!< 16 HARQ_4_LTEFE_6_VITERBI_3                                          */
  HARQ_5_LTEFE_7_IRQn                    = 17,       /*!< 17 HARQ_5_LTEFE_7                                                    */
  HARQ_6_LTEFE_8_IRQn                    = 18,       /*!< 18 HARQ_6_LTEFE_8                                                    */
  HARQ_7_IPCT_0_LTEFE_9_IRQn             = 19,       /*!< 19 HARQ_7_IPCT_0_LTEFE_9                                             */
  IPCT_1_LTEFE_10_IRQn                   = 20,       /*!< 20 IPCT_1_LTEFE_10                                                   */
  IPCT_2_LTEFE_11_IRQn                   = 21,       /*!< 21 IPCT_2_LTEFE_11                                                   */
  LTEFE_12_IRQn                          = 22,       /*!< 22 LTEFE_12                                                          */
  ABB_LTEFE_13_IRQn                      = 23,       /*!< 23 ABB_LTEFE_13                                                      */
  LTEFE_14_IRQn                          = 24,       /*!< 24 LTEFE_14                                                          */
  LTEFE_15_IRQn                          = 25,       /*!< 25 LTEFE_15                                                          */
  GNSSFE_0_IRQn                          = 40,       /*!< 40 GNSSFE_0                                                          */
  GNSSFE_1_WIFIBFE_0_IRQn                = 41,       /*!< 41 GNSSFE_1_WIFIBFE_0                                                */
  GNSSFE_2_WIFIBFE_1_WIFIGNFE_0_IRQn     = 42,       /*!< 42 GNSSFE_2_WIFIBFE_1_WIFIGNFE_0                                     */
  GNSSFE_3_WIFIBFE_2_WIFIGNFE_1_IRQn     = 43,       /*!< 43 GNSSFE_3_WIFIBFE_2_WIFIGNFE_1                                     */
  GNSSFE_4_WIFIBFE_3_WIFIGNFE_2_IRQn     = 44,       /*!< 44 GNSSFE_4_WIFIBFE_3_WIFIGNFE_2                                     */
  GNSSFE_5_WIFIBFE_4_WIFIGNFE_3_IRQn     = 45,       /*!< 45 GNSSFE_5_WIFIBFE_4_WIFIGNFE_3                                     */
  WIFIBFE_5_WIFIGNFE_4_IRQn              = 46,       /*!< 46 WIFIBFE_5_WIFIGNFE_4                                              */
  WIFIGNFE_5_IRQn                        = 47,       /*!< 47 WIFIGNFE_5                                                        */
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

/* ============================== Configuration of the CEVA XC5 Processor and Core Peripherals =============================== */
#define __XC5_REV               v1.1.0.F             /*!< XC5 Core Revision                                                    */
#define __DSP_PRESENT                  1             /*!< DSP present or not                                                   */
#define __MPU_PRESENT                  0             /*!< MPU present                                                          */
#define __FPU_PRESENT                  0             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX              55             /*!< Size of interrupt vector table                                       */

#include "system_nrf.h"                              /*!< nrf9230_celldsp System Library                                       */

#endif                                               /*!< NRF_CELLDSP                                                          */


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

#define NRF_CELLDSP_LSTMDATA_BASE         0x2A000000UL
#define NRF_CELLDSP_HSFLL_BASE            0x45000000UL
#define NRF_CELLDSP_LRCCONF0_BASE         0x45001000UL
#define NRF_CELLDSP_MPC_BASE              0x45002000UL
#define NRF_CELLDSP_MVDMA_BASE            0x45003000UL
#define NRF_CELLDSP_RAMC00_BASE           0x45004000UL
#define NRF_CELLDSP_RAMC10_BASE           0x45005000UL
#define NRF_CELLDSP_RAMC20_BASE           0x45006000UL
#define NRF_CELLDSP_GENERIC2_BASE         0x45007000UL
#define NRF_CELLDSP_DSPINTMAP_BASE        0x45008000UL
#define NRF_CELLDSP_LTEFE_BASE            0x4500A000UL
#define NRF_CELLDSP_TURBO_BASE            0x4500B000UL
#define NRF_CELLDSP_HARQ_BASE             0x4500C000UL
#define NRF_CELLDSP_VITERBI_BASE          0x4500D000UL
#define NRF_CELLDSP_PPIB0_BASE            0x4500E000UL
#define NRF_CELLDSP_LRCCONF1_BASE         0x45010000UL
#define NRF_CELLDSP_CPUCONF_BASE          0x45011000UL
#define NRF_CELLDSP_MEMCONF_BASE          0x45012000UL
#define NRF_CELLDSP_IPCT_BASE             0x45013000UL
#define NRF_CELLDSP_DSPCTRL_BASE          0x45014000UL
#define NRF_CELLDSP_PCGCM0_BASE           0x45015000UL
#define NRF_CELLDSP_PPIB1_BASE            0x45016000UL
#define NRF_CELLDSP_ABB_BASE              0x45017000UL
#define NRF_CELLDSP_BILS_BASE             0x45018000UL
#define NRF_CELLDSP_CTI0_BASE             0x45020000UL
#define NRF_CELLDSP_DPPIC_BASE            0x45021000UL
#define NRF_CELLDSP_PCGCS0_BASE           0x45022000UL
#define NRF_CELLDSP_PCGCM1_BASE           0x45023000UL
#define NRF_CELLDSP_LSTM_BASE             0x45024000UL
#define NRF_CELLDSP_ETM_BASE              0x45025000UL
#define NRF_CELLDSP_CTI1_BASE             0x45026000UL
#define NRF_CELLDSP_TRACEDELAYREG_BASE    0x45027000UL
#define NRF_CELLDSP_GNSSFE_BASE           0x45028000UL
#define NRF_CELLDSP_WIFIBFE_BASE          0x45029000UL
#define NRF_CELLDSP_WIFIGNFE_BASE         0x4502A000UL
#define NRF_CELLDSP_BELLBOARD_BASE        0x4F09D000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_CELLDSP_LSTMDATA              ((NRF_STMDATA_Type*)                  NRF_CELLDSP_LSTMDATA_BASE)
#define NRF_CELLDSP_HSFLL                 ((NRF_HSFLL_Type*)                    NRF_CELLDSP_HSFLL_BASE)
#define NRF_CELLDSP_LRCCONF0              ((NRF_LRCCONF_Type*)                  NRF_CELLDSP_LRCCONF0_BASE)
#define NRF_CELLDSP_MPC                   ((NRF_MPC_Type*)                      NRF_CELLDSP_MPC_BASE)
#define NRF_CELLDSP_MVDMA                 ((NRF_MVDMA_Type*)                    NRF_CELLDSP_MVDMA_BASE)
#define NRF_CELLDSP_RAMC00                ((NRF_RAMC_Type*)                     NRF_CELLDSP_RAMC00_BASE)
#define NRF_CELLDSP_RAMC10                ((NRF_RAMC_Type*)                     NRF_CELLDSP_RAMC10_BASE)
#define NRF_CELLDSP_RAMC20                ((NRF_RAMC_Type*)                     NRF_CELLDSP_RAMC20_BASE)
#define NRF_CELLDSP_GENERIC2              ((NRF_GENERIC_Type*)                  NRF_CELLDSP_GENERIC2_BASE)
#define NRF_CELLDSP_DSPINTMAP             ((NRF_DSPINTMAP_Type*)                NRF_CELLDSP_DSPINTMAP_BASE)
#define NRF_CELLDSP_LTEFE                 ((NRF_LTEFE_Type*)                    NRF_CELLDSP_LTEFE_BASE)
#define NRF_CELLDSP_TURBO                 ((NRF_TURBO_Type*)                    NRF_CELLDSP_TURBO_BASE)
#define NRF_CELLDSP_HARQ                  ((NRF_HARQ_Type*)                     NRF_CELLDSP_HARQ_BASE)
#define NRF_CELLDSP_VITERBI               ((NRF_VITERBI_Type*)                  NRF_CELLDSP_VITERBI_BASE)
#define NRF_CELLDSP_PPIB0                 ((NRF_PPIB_Type*)                     NRF_CELLDSP_PPIB0_BASE)
#define NRF_CELLDSP_LRCCONF1              ((NRF_LRCCONF_Type*)                  NRF_CELLDSP_LRCCONF1_BASE)
#define NRF_CELLDSP_CPUCONF               ((NRF_CPUCONF_Type*)                  NRF_CELLDSP_CPUCONF_BASE)
#define NRF_CELLDSP_MEMCONF               ((NRF_MEMCONF_Type*)                  NRF_CELLDSP_MEMCONF_BASE)
#define NRF_CELLDSP_IPCT                  ((NRF_IPCT_Type*)                     NRF_CELLDSP_IPCT_BASE)
#define NRF_CELLDSP_DSPCTRL               ((NRF_DSPCTRL_Type*)                  NRF_CELLDSP_DSPCTRL_BASE)
#define NRF_CELLDSP_PCGCM0                ((NRF_PCGCMASTER_Type*)               NRF_CELLDSP_PCGCM0_BASE)
#define NRF_CELLDSP_PPIB1                 ((NRF_PPIB_Type*)                     NRF_CELLDSP_PPIB1_BASE)
#define NRF_CELLDSP_ABB                   ((NRF_ABB_Type*)                      NRF_CELLDSP_ABB_BASE)
#define NRF_CELLDSP_BILS                  ((NRF_BILS_Type*)                     NRF_CELLDSP_BILS_BASE)
#define NRF_CELLDSP_CTI0                  ((NRF_CTI_Type*)                      NRF_CELLDSP_CTI0_BASE)
#define NRF_CELLDSP_DPPIC                 ((NRF_DPPIC_Type*)                    NRF_CELLDSP_DPPIC_BASE)
#define NRF_CELLDSP_PCGCS0                ((NRF_PCGCSLAVE_Type*)                NRF_CELLDSP_PCGCS0_BASE)
#define NRF_CELLDSP_PCGCM1                ((NRF_PCGCMASTER_Type*)               NRF_CELLDSP_PCGCM1_BASE)
#define NRF_CELLDSP_LSTM                  ((NRF_STM_Type*)                      NRF_CELLDSP_LSTM_BASE)
#define NRF_CELLDSP_ETM                   ((NRF_ETM_Type*)                      NRF_CELLDSP_ETM_BASE)
#define NRF_CELLDSP_CTI1                  ((NRF_CTI_Type*)                      NRF_CELLDSP_CTI1_BASE)
#define NRF_CELLDSP_TRACEDELAYREG         ((NRF_TRACEDELAYREG_Type*)            NRF_CELLDSP_TRACEDELAYREG_BASE)
#define NRF_CELLDSP_GNSSFE                ((NRF_POSFE_Type*)                    NRF_CELLDSP_GNSSFE_BASE)
#define NRF_CELLDSP_WIFIBFE               ((NRF_POSFE_Type*)                    NRF_CELLDSP_WIFIBFE_BASE)
#define NRF_CELLDSP_WIFIGNFE              ((NRF_POSFE_Type*)                    NRF_CELLDSP_WIFIGNFE_BASE)
#define NRF_CELLDSP_BELLBOARD             ((NRF_BELLBOARD_Type*)                NRF_CELLDSP_BELLBOARD_BASE)

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_CELLDSP                                   /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_LSTMDATA                            NRF_CELLDSP_LSTMDATA
  #define NRF_HSFLL                               NRF_CELLDSP_HSFLL
  #define NRF_LRCCONF0                            NRF_CELLDSP_LRCCONF0
  #define NRF_MPC                                 NRF_CELLDSP_MPC
  #define NRF_MVDMA                               NRF_CELLDSP_MVDMA
  #define NRF_RAMC00                              NRF_CELLDSP_RAMC00
  #define NRF_RAMC10                              NRF_CELLDSP_RAMC10
  #define NRF_RAMC20                              NRF_CELLDSP_RAMC20
  #define NRF_GENERIC2                            NRF_CELLDSP_GENERIC2
  #define NRF_DSPINTMAP                           NRF_CELLDSP_DSPINTMAP
  #define NRF_LTEFE                               NRF_CELLDSP_LTEFE
  #define NRF_TURBO                               NRF_CELLDSP_TURBO
  #define NRF_HARQ                                NRF_CELLDSP_HARQ
  #define NRF_VITERBI                             NRF_CELLDSP_VITERBI
  #define NRF_PPIB0                               NRF_CELLDSP_PPIB0
  #define NRF_LRCCONF1                            NRF_CELLDSP_LRCCONF1
  #define NRF_CPUCONF                             NRF_CELLDSP_CPUCONF
  #define NRF_MEMCONF                             NRF_CELLDSP_MEMCONF
  #define NRF_IPCT                                NRF_CELLDSP_IPCT
  #define NRF_DSPCTRL                             NRF_CELLDSP_DSPCTRL
  #define NRF_PCGCM0                              NRF_CELLDSP_PCGCM0
  #define NRF_PPIB1                               NRF_CELLDSP_PPIB1
  #define NRF_ABB                                 NRF_CELLDSP_ABB
  #define NRF_BILS                                NRF_CELLDSP_BILS
  #define NRF_CTI0                                NRF_CELLDSP_CTI0
  #define NRF_DPPIC                               NRF_CELLDSP_DPPIC
  #define NRF_PCGCS0                              NRF_CELLDSP_PCGCS0
  #define NRF_PCGCM1                              NRF_CELLDSP_PCGCM1
  #define NRF_LSTM                                NRF_CELLDSP_LSTM
  #define NRF_ETM                                 NRF_CELLDSP_ETM
  #define NRF_CTI1                                NRF_CELLDSP_CTI1
  #define NRF_TRACEDELAYREG                       NRF_CELLDSP_TRACEDELAYREG
  #define NRF_GNSSFE                              NRF_CELLDSP_GNSSFE
  #define NRF_WIFIBFE                             NRF_CELLDSP_WIFIBFE
  #define NRF_WIFIGNFE                            NRF_CELLDSP_WIFIGNFE
  #define NRF_BELLBOARD                           NRF_CELLDSP_BELLBOARD
#endif                                               /*!< NRF_CELLDSP                                                          */

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
#endif /* NRF9230_CELLDSP_H */

