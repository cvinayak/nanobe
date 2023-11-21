/*

Copyright (c) 2010 - 2022, Nordic Semiconductor ASA

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

#ifndef NRF7140_GRAPHICS_H
#define NRF7140_GRAPHICS_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_GRAPHICS                                  /*!< Processor information is domain local.                               */


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
  SPU000_IRQn                            = 16,       /*!< 16 SPU000                                                            */
  GPIOTE130_0_IRQn                       = 104,      /*!< 104 GPIOTE130_0                                                      */
  GPIOTE130_1_IRQn                       = 105,      /*!< 105 GPIOTE130_1                                                      */
  GRTC_0_IRQn                            = 108,      /*!< 108 GRTC_0                                                           */
  GRTC_1_IRQn                            = 109,      /*!< 109 GRTC_1                                                           */
  GRTC_2_IRQn                            = 110,      /*!< 110 GRTC_2                                                           */
  TBM_IRQn                               = 127,      /*!< 127 TBM                                                              */
  USBHS_IRQn                             = 134,      /*!< 134 USBHS                                                            */
  MRAMC110_IRQn                          = 146,      /*!< 146 MRAMC110                                                         */
  MRAMC111_IRQn                          = 147,      /*!< 147 MRAMC111                                                         */
  EXMIF_IRQn                             = 149,      /*!< 149 EXMIF                                                            */
  QSPI110_IRQn                           = 163,      /*!< 163 QSPI110                                                          */
  QSPI111_IRQn                           = 165,      /*!< 165 QSPI111                                                          */
  OTPC_IRQn                              = 197,      /*!< 197 OTPC                                                             */
  VPR120_IRQn                            = 200,      /*!< 200 VPR120                                                           */
  IPCT120_0_IRQn                         = 209,      /*!< 209 IPCT120_0                                                        */
  I3C120_IRQn                            = 211,      /*!< 211 I3C120                                                           */
  VPR121_IRQn                            = 212,      /*!< 212 VPR121                                                           */
  CAN120_IRQn                            = 216,      /*!< 216 CAN120                                                           */
  MVDMA120_IRQn                          = 217,      /*!< 217 MVDMA120                                                         */
  CAN121_IRQn                            = 219,      /*!< 219 CAN121                                                           */
  I3C121_IRQn                            = 222,      /*!< 222 I3C121                                                           */
  TIMER120_IRQn                          = 226,      /*!< 226 TIMER120                                                         */
  TIMER121_IRQn                          = 227,      /*!< 227 TIMER121                                                         */
  PWM120_IRQn                            = 228,      /*!< 228 PWM120                                                           */
  SPIS120_IRQn                           = 229,      /*!< 229 SPIS120                                                          */
  SPIM120_UARTE120_IRQn                  = 230,      /*!< 230 SPIM120_UARTE120                                                 */
  SPIM121_IRQn                           = 231,      /*!< 231 SPIM121                                                          */
  SPIM122_IRQn                           = 241,      /*!< 241 SPIM122                                                          */
  SPIM123_IRQn                           = 242,      /*!< 242 SPIM123                                                          */
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
  NFCT_IRQn                              = 389,      /*!< 389 NFCT                                                             */
  I2S130_IRQn                            = 402,      /*!< 402 I2S130                                                           */
  QDEC130_IRQn                           = 404,      /*!< 404 QDEC130                                                          */
  QDEC131_IRQn                           = 405,      /*!< 405 QDEC131                                                          */
  SIMIF130_IRQn                          = 406,      /*!< 406 SIMIF130                                                         */
  I2S131_IRQn                            = 407,      /*!< 407 I2S131                                                           */
  TDM_IRQn                               = 409,      /*!< 409 TDM                                                              */
  TIMER130_IRQn                          = 418,      /*!< 418 TIMER130                                                         */
  TIMER131_IRQn                          = 419,      /*!< 419 TIMER131                                                         */
  PWM130_IRQn                            = 420,      /*!< 420 PWM130                                                           */
  SERIAL0_IRQn                           = 421,      /*!< 421 SERIAL0                                                          */
  SERIAL1_IRQn                           = 422,      /*!< 422 SERIAL1                                                          */
  PDM130_IRQn                            = 423,      /*!< 423 PDM130                                                           */
  TIMER132_IRQn                          = 434,      /*!< 434 TIMER132                                                         */
  TIMER133_IRQn                          = 435,      /*!< 435 TIMER133                                                         */
  PWM131_IRQn                            = 436,      /*!< 436 PWM131                                                           */
  SERIAL2_IRQn                           = 437,      /*!< 437 SERIAL2                                                          */
  SERIAL3_IRQn                           = 438,      /*!< 438 SERIAL3                                                          */
  PDM131_IRQn                            = 439,      /*!< 439 PDM131                                                           */
  TIMER134_IRQn                          = 450,      /*!< 450 TIMER134                                                         */
  TIMER135_IRQn                          = 451,      /*!< 451 TIMER135                                                         */
  PWM132_IRQn                            = 452,      /*!< 452 PWM132                                                           */
  SERIAL4_IRQn                           = 453,      /*!< 453 SERIAL4                                                          */
  SERIAL5_IRQn                           = 454,      /*!< 454 SERIAL5                                                          */
  PDM132_IRQn                            = 455,      /*!< 455 PDM132                                                           */
  TIMER136_IRQn                          = 466,      /*!< 466 TIMER136                                                         */
  TIMER137_IRQn                          = 467,      /*!< 467 TIMER137                                                         */
  PWM133_IRQn                            = 468,      /*!< 468 PWM133                                                           */
  SERIAL6_IRQn                           = 469,      /*!< 469 SERIAL6                                                          */
  SERIAL7_IRQn                           = 470,      /*!< 470 SERIAL7                                                          */
  PDM133_IRQn                            = 471,      /*!< 471 PDM133                                                           */
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
#define __SAUREGION_PRESENT            0             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               0             /*!< Number of regions                                                    */

#include "core_cm33.h"                               /*!< ARM Cortex-M33 processor and core peripherals                        */
#include "system_nrf.h"                              /*!< nrf7140_graphics System Library                                      */

#endif                                               /*!< NRF_GRAPHICS                                                         */


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

#define NRF_GRAPHICS_AUXPLL_NS_BASE       0x4900B000UL
#define NRF_GRAPHICS_HSFLL_NS_BASE        0x4900D000UL
#define NRF_GRAPHICS_LRCCONF0_NS_BASE     0x4900E000UL
#define NRF_GRAPHICS_PCGCM0_NS_BASE       0x4900F000UL
#define NRF_GRAPHICS_SPU000_S_BASE        0x49010000UL
#define NRF_GRAPHICS_MEMCONF_NS_BASE      0x49011000UL
#define NRF_GRAPHICS_PCGCS_NS_BASE        0x4901D000UL
#define NRF_GRAPHICS_LRCCONF1_NS_BASE     0x4901E000UL
#define NRF_GRAPHICS_PCGCM1_NS_BASE       0x4901F000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_GRAPHICS_AUXPLL_NS            ((NRF_AUXPLL_Type*)                   NRF_GRAPHICS_AUXPLL_NS_BASE)
#define NRF_GRAPHICS_HSFLL_NS             ((NRF_HSFLL_Type*)                    NRF_GRAPHICS_HSFLL_NS_BASE)
#define NRF_GRAPHICS_LRCCONF0_NS          ((NRF_LRCCONF_Type*)                  NRF_GRAPHICS_LRCCONF0_NS_BASE)
#define NRF_GRAPHICS_PCGCM0_NS            ((NRF_PCGCMASTER_Type*)               NRF_GRAPHICS_PCGCM0_NS_BASE)
#define NRF_GRAPHICS_SPU000_S             ((NRF_SPU_Type*)                      NRF_GRAPHICS_SPU000_S_BASE)
#define NRF_GRAPHICS_MEMCONF_NS           ((NRF_MEMCONF_Type*)                  NRF_GRAPHICS_MEMCONF_NS_BASE)
#define NRF_GRAPHICS_PCGCS_NS             ((NRF_PCGCSLAVE_Type*)                NRF_GRAPHICS_PCGCS_NS_BASE)
#define NRF_GRAPHICS_LRCCONF1_NS          ((NRF_LRCCONF_Type*)                  NRF_GRAPHICS_LRCCONF1_NS_BASE)
#define NRF_GRAPHICS_PCGCM1_NS            ((NRF_PCGCMASTER_Type*)               NRF_GRAPHICS_PCGCM1_NS_BASE)

/* =========================================================================================================================== */
/* ================                                    TrustZone Remapping                                    ================ */
/* =========================================================================================================================== */

#ifdef NRF_TRUSTZONE_NONSECURE                       /*!< Remap NRF_X_NS instances to NRF_X symbol for ease of use.            */
  #define NRF_GRAPHICS_AUXPLL                     NRF_GRAPHICS_AUXPLL_NS
  #define NRF_GRAPHICS_HSFLL                      NRF_GRAPHICS_HSFLL_NS
  #define NRF_GRAPHICS_LRCCONF0                   NRF_GRAPHICS_LRCCONF0_NS
  #define NRF_GRAPHICS_PCGCM0                     NRF_GRAPHICS_PCGCM0_NS
  #define NRF_GRAPHICS_MEMCONF                    NRF_GRAPHICS_MEMCONF_NS
  #define NRF_GRAPHICS_PCGCS                      NRF_GRAPHICS_PCGCS_NS
  #define NRF_GRAPHICS_LRCCONF1                   NRF_GRAPHICS_LRCCONF1_NS
  #define NRF_GRAPHICS_PCGCM1                     NRF_GRAPHICS_PCGCM1_NS
#else                                                /*!< Remap NRF_X_S instances to NRF_X symbol for ease of use.             */
  #define NRF_GRAPHICS_AUXPLL                     NRF_GRAPHICS_AUXPLL_NS
  #define NRF_GRAPHICS_HSFLL                      NRF_GRAPHICS_HSFLL_NS
  #define NRF_GRAPHICS_LRCCONF0                   NRF_GRAPHICS_LRCCONF0_NS
  #define NRF_GRAPHICS_PCGCM0                     NRF_GRAPHICS_PCGCM0_NS
  #define NRF_GRAPHICS_SPU000                     NRF_GRAPHICS_SPU000_S
  #define NRF_GRAPHICS_MEMCONF                    NRF_GRAPHICS_MEMCONF_NS
  #define NRF_GRAPHICS_PCGCS                      NRF_GRAPHICS_PCGCS_NS
  #define NRF_GRAPHICS_LRCCONF1                   NRF_GRAPHICS_LRCCONF1_NS
  #define NRF_GRAPHICS_PCGCM1                     NRF_GRAPHICS_PCGCM1_NS
#endif                                               /*!<  NRF_TRUSTZONE_NONSECURE                                             */

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_GRAPHICS                                  /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_AUXPLL                              NRF_GRAPHICS_AUXPLL
  #define NRF_HSFLL                               NRF_GRAPHICS_HSFLL
  #define NRF_LRCCONF0                            NRF_GRAPHICS_LRCCONF0
  #define NRF_PCGCM0                              NRF_GRAPHICS_PCGCM0
  #define NRF_SPU000                              NRF_GRAPHICS_SPU000
  #define NRF_MEMCONF                             NRF_GRAPHICS_MEMCONF
  #define NRF_PCGCS                               NRF_GRAPHICS_PCGCS
  #define NRF_LRCCONF1                            NRF_GRAPHICS_LRCCONF1
  #define NRF_PCGCM1                              NRF_GRAPHICS_PCGCM1
#endif                                               /*!< NRF_GRAPHICS                                                         */

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
#endif /* NRF7140_GRAPHICS_H */

