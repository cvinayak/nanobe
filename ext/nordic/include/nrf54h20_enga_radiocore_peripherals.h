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

#ifndef NRF54H20_ENGA_RADIOCORE_PERIPHERALS_H
#define NRF54H20_ENGA_RADIOCORE_PERIPHERALS_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdbool.h>
/*User information configuration registers*/
#define UICR_PRESENT 1
#define UICR_COUNT 1

/*CACHEDATA*/
#define CACHEDATA_PRESENT 1
#define CACHEDATA_COUNT 2

/*CACHEINFO*/
#define CACHEINFO_PRESENT 1
#define CACHEINFO_COUNT 2

/*Embedded Trace Macrocell*/
#define ETM_PRESENT 1
#define ETM_COUNT 1

/*Cross-Trigger Interface control*/
#define CTI_PRESENT 1
#define CTI_COUNT 3

/*CM33 SubSystem*/
#define CM33SS_PRESENT 1
#define CM33SS_COUNT 1

#define CPUC_FPUAVAILABLE 1                          /*!< (unspecified)                                                        */

/*Cache*/
#define CACHE_PRESENT 1
#define CACHE_COUNT 2

#define ICACHE_VIRTUALCACHE 0                        /*!< (unspecified)                                                        */
#define ICACHE_FLUSH 1                               /*!< (unspecified)                                                        */
#define ICACHE_CLEAN 0                               /*!< (unspecified)                                                        */

#define DCACHE_VIRTUALCACHE 0                        /*!< (unspecified)                                                        */
#define DCACHE_FLUSH 1                               /*!< (unspecified)                                                        */
#define DCACHE_CLEAN 1                               /*!< (unspecified)                                                        */

/*System protection unit*/
#define SPU_PRESENT 1
#define SPU_COUNT 4

#define SPU000_BELLS 0                               /*!< (unspecified)                                                        */
#define SPU000_IPCT 0                                /*!< (unspecified)                                                        */
#define SPU000_DPPI 0                                /*!< (unspecified)                                                        */
#define SPU000_GPIOTE 0                              /*!< (unspecified)                                                        */
#define SPU000_GRTC 1                                /*!< (unspecified)                                                        */
#define SPU000_GPIO 0                                /*!< (unspecified)                                                        */

#define SPU010_BELLS 0                               /*!< (unspecified)                                                        */
#define SPU010_IPCT 0                                /*!< (unspecified)                                                        */
#define SPU010_DPPI 0                                /*!< (unspecified)                                                        */
#define SPU010_GPIOTE 0                              /*!< (unspecified)                                                        */
#define SPU010_GRTC 1                                /*!< (unspecified)                                                        */
#define SPU010_GPIO 0                                /*!< (unspecified)                                                        */

#define SPU020_BELLS 0                               /*!< (unspecified)                                                        */
#define SPU020_IPCT 1                                /*!< (unspecified)                                                        */
#define SPU020_DPPI 1                                /*!< (unspecified)                                                        */
#define SPU020_GPIOTE 0                              /*!< (unspecified)                                                        */
#define SPU020_GRTC 1                                /*!< (unspecified)                                                        */
#define SPU020_GPIO 0                                /*!< (unspecified)                                                        */

#define SPU030_BELLS 0                               /*!< (unspecified)                                                        */
#define SPU030_IPCT 0                                /*!< (unspecified)                                                        */
#define SPU030_DPPI 1                                /*!< (unspecified)                                                        */
#define SPU030_GPIOTE 0                              /*!< (unspecified)                                                        */
#define SPU030_GRTC 1                                /*!< (unspecified)                                                        */
#define SPU030_GPIO 0                                /*!< (unspecified)                                                        */

/*Memory Privilege Controller*/
#define MPC_PRESENT 1
#define MPC_COUNT 1

#define MPC_EXTEND_CLOCK_REQ 0                       /*!< (unspecified)                                                        */
#define MPC_OVERRIDE_GRAN 4                          /*!< The override region granularity is 4 bytes                           */

/*MVDMA performs direct-memory-accesses between memories. Data is transferred according to job descriptor lists. Each transfer has corresponding source and sink descriptor lists with matching data amounts. The lists are in memory and they contain data buffer information, address pointers, buffer sizes and data type attributes.*/

#define MVDMA_PRESENT 1
#define MVDMA_COUNT 1

/*RAM Controller*/
#define RAMC_PRESENT 1
#define RAMC_COUNT 2

#define RAMC000_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC000_SEC 1                                /*!< (unspecified)                                                        */

#define RAMC001_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC001_SEC 0                                /*!< (unspecified)                                                        */

/*PCGCSlave*/
#define PCGCSLAVE_PRESENT 1
#define PCGCSLAVE_COUNT 4

#define PCGCS000_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS010_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS020_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS030_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

/*HSFLL*/
#define HSFLL_PRESENT 1
#define HSFLL_COUNT 1

#define HSFLL_DITHER_32B 0                           /*!< (unspecified)                                                        */

/*LRCCONF*/
#define LRCCONF_PRESENT 1
#define LRCCONF_COUNT 3

#define LRCCONF000_POWERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF000_RETAIN 0                          /*!< (unspecified)                                                        */
#define LRCCONF000_SYSTEMOFF 0                       /*!< (unspecified)                                                        */
#define LRCCONF000_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF000_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF000_NCLK_MAX 0                        /*!< (unspecified)                                                        */
#define LRCCONF000_CLKCTRL 1                         /*!< (unspecified)                                                        */
#define LRCCONF000_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF000_NACTPD_MAX 7                      /*!< (unspecified)                                                        */
#define LRCCONF000_PDACT 0                           /*!< (unspecified)                                                        */
#define LRCCONF000_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF000_NPD_MAX 7                         /*!< (unspecified)                                                        */
#define LRCCONF000_OTHERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF000_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF000_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF000_AX2XWAITSTATES 0                  /*!< (unspecified)                                                        */
#define LRCCONF000_POWERON_MAIN_RESET 0              /*!< Reset value of register POWERON.MAIN: 0                              */
#define LRCCONF000_POWERON_ACT_RESET 0               /*!< Reset value of register POWERON.ACT: 0                               */
#define LRCCONF000_RETAIN_MAIN_RESET 1               /*!< Reset value of register RETAIN.MAIN: 1                               */
#define LRCCONF000_RETAIN_ACT_RESET 1                /*!< Reset value of register RETAIN.ACT: 1                                */

#define LRCCONF010_POWERON 1                         /*!< (unspecified)                                                        */
#define LRCCONF010_RETAIN 1                          /*!< (unspecified)                                                        */
#define LRCCONF010_SYSTEMOFF 1                       /*!< (unspecified)                                                        */
#define LRCCONF010_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF010_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF010_NCLK_MAX 7                        /*!< (unspecified)                                                        */
#define LRCCONF010_CLKCTRL 0                         /*!< (unspecified)                                                        */
#define LRCCONF010_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF010_NACTPD_MAX 1                      /*!< (unspecified)                                                        */
#define LRCCONF010_PDACT 1                           /*!< (unspecified)                                                        */
#define LRCCONF010_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF010_NPD_MAX 7                         /*!< (unspecified)                                                        */
#define LRCCONF010_OTHERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF010_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF010_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF010_AX2XWAITSTATES 0                  /*!< (unspecified)                                                        */
#define LRCCONF010_POWERON_MAIN_RESET 1              /*!< Reset value of register POWERON.MAIN: 1                              */
#define LRCCONF010_POWERON_ACT_RESET 0               /*!< Reset value of register POWERON.ACT: 0                               */
#define LRCCONF010_RETAIN_MAIN_RESET 0               /*!< Reset value of register RETAIN.MAIN: 0                               */
#define LRCCONF010_RETAIN_ACT_RESET 0                /*!< Reset value of register RETAIN.ACT: 0                                */

#define LRCCONF020_POWERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF020_RETAIN 0                          /*!< (unspecified)                                                        */
#define LRCCONF020_SYSTEMOFF 0                       /*!< (unspecified)                                                        */
#define LRCCONF020_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF020_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF020_NCLK_MAX 7                        /*!< (unspecified)                                                        */
#define LRCCONF020_CLKCTRL 0                         /*!< (unspecified)                                                        */
#define LRCCONF020_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF020_NACTPD_MAX 7                      /*!< (unspecified)                                                        */
#define LRCCONF020_PDACT 0                           /*!< (unspecified)                                                        */
#define LRCCONF020_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF020_NPD_MAX 7                         /*!< (unspecified)                                                        */
#define LRCCONF020_OTHERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF020_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF020_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF020_AX2XWAITSTATES 0                  /*!< (unspecified)                                                        */
#define LRCCONF020_POWERON_MAIN_RESET 0              /*!< Reset value of register POWERON.MAIN: 0                              */
#define LRCCONF020_POWERON_ACT_RESET 0               /*!< Reset value of register POWERON.ACT: 0                               */
#define LRCCONF020_RETAIN_MAIN_RESET 1               /*!< Reset value of register RETAIN.MAIN: 1                               */
#define LRCCONF020_RETAIN_ACT_RESET 1                /*!< Reset value of register RETAIN.ACT: 1                                */

/*PCGC Master*/
#define PCGCMASTER_PRESENT 1
#define PCGCMASTER_COUNT 4

#define PCGCM000_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM000_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM000_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM000_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM010_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM010_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM010_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM010_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM020_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM020_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM020_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM020_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM030_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM030_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM030_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM030_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

/*CPU Configuration*/
#define CPUCONF_PRESENT 1
#define CPUCONF_COUNT 1

#define CPUCONF_HASTASKERASECACHE 1                  /*!< (unspecified)                                                        */
#define CPUCONF_HASINITSVTOR 1                       /*!< (unspecified)                                                        */
#define CPUCONF_HASINITNSVTOR 1                      /*!< (unspecified)                                                        */
#define CPUCONF_HASCPUSTART 1                        /*!< (unspecified)                                                        */
#define CPUCONF_HASCPUWAIT 1                         /*!< (unspecified)                                                        */

/*Memory configuration*/
#define MEMCONF_PRESENT 1
#define MEMCONF_COUNT 1

#define MEMCONF_RETTRIM 1                            /*!< (unspecified)                                                        */
#define MEMCONF_REPAIR 0                             /*!< (unspecified)                                                        */
#define MEMCONF_POWER 1                              /*!< (unspecified)                                                        */
#define MEMCONF_RET2 1                               /*!< (unspecified)                                                        */

/*Watchdog Timer*/
#define WDT_PRESENT 1
#define WDT_COUNT 4

/*The Built-in Leakage Sensor (BILS) module.*/
#define BILS_PRESENT 1
#define BILS_COUNT 1

/*RESETINFO*/
#define RESETINFO_PRESENT 1
#define RESETINFO_COUNT 1

#define RESETINFO_HASRESETREAS 1                     /*!< (unspecified)                                                        */

/*Distributed programmable peripheral interconnect controller*/
#define DPPIC_PRESENT 1
#define DPPIC_COUNT 10

#define DPPIC020_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC020_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC020_CH_NUM_MAX 15                       /*!< (unspecified)                                                        */
#define DPPIC020_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC020_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC030_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC030_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC030_CH_NUM_MAX 8                        /*!< (unspecified)                                                        */
#define DPPIC030_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC030_GROUP_NUM_MAX 0                     /*!< (unspecified)                                                        */

#define DPPIC120_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC120_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC120_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC120_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC120_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC130_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC130_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC130_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC130_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC130_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC131_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC131_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC131_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC131_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC131_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC132_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC132_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC132_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC132_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC132_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC133_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC133_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC133_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC133_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC133_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC134_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC134_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC134_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC134_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC134_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC135_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC135_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC135_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC135_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC135_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

#define DPPIC136_HASCHANNELGROUPS 1                  /*!< (unspecified)                                                        */
#define DPPIC136_CH_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define DPPIC136_CH_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define DPPIC136_GROUP_NUM_MIN 0                     /*!< (unspecified)                                                        */
#define DPPIC136_GROUP_NUM_MAX 1                     /*!< (unspecified)                                                        */

/*PPIB APB registers*/
#define PPIB_PRESENT 1
#define PPIB_COUNT 2

/*Event generator unit*/
#define EGU_PRESENT 1
#define EGU_COUNT 1

#define EGU020_PEND 0                                /*!< (unspecified)                                                        */
#define EGU020_CH_NUM_MIN 0                          /*!< (unspecified)                                                        */
#define EGU020_CH_NUM_MAX 15                         /*!< (unspecified)                                                        */

/*Accelerated Address Resolver*/
#define AAR_PRESENT 1
#define AAR_COUNT 2

/*AES CCM Mode Encryption*/
#define CCM_PRESENT 1
#define CCM_COUNT 2

/*AES ECB Mode Encryption*/
#define ECB_PRESENT 1
#define ECB_COUNT 2

#define ECB020_AMOUNTREG 1                           /*!< (unspecified)                                                        */

#define ECB030_AMOUNTREG 1                           /*!< (unspecified)                                                        */

/*Timer/Counter*/
#define TIMER_PRESENT 1
#define TIMER_COUNT 13

#define TIMER020_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER020_CC_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define TIMER020_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER020_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER021_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER021_CC_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define TIMER021_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER021_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER022_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER022_CC_NUM_MAX 7                        /*!< (unspecified)                                                        */
#define TIMER022_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER022_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER120_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER120_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER120_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER120_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER121_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER121_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER121_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER121_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER130_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER130_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER130_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER130_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER131_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER131_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER131_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER131_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER132_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER132_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER132_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER132_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER133_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER133_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER133_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER133_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER134_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER134_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER134_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER134_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER135_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER135_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER135_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER135_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER136_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER136_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER136_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER136_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

#define TIMER137_CC_NUM_MIN 0                        /*!< (unspecified)                                                        */
#define TIMER137_CC_NUM_MAX 5                        /*!< (unspecified)                                                        */
#define TIMER137_MAX_SIZE_MIN 0                      /*!< (unspecified)                                                        */
#define TIMER137_MAX_SIZE_MAX 31                     /*!< (unspecified)                                                        */

/*Real-time counter*/
#define RTC_PRESENT 1
#define RTC_COUNT 3

/*2.4 GHz radio*/
#define RADIO_PRESENT 1
#define RADIO_COUNT 1

#define RADIO_ADPLLCOMPANION_INCLUDE_DMA 0           /*!< (unspecified)                                                        */
#define RADIO_PERPOWER 0                             /*!< (unspecified)                                                        */

/*RADIOACC peripheral*/
#define RADIOACC_PRESENT 1
#define RADIOACC_COUNT 1

/*VPR peripheral registers*/
#define VPR_PRESENT 1
#define VPR_COUNT 4

#define VPR_INIT_PC_RESET_VALUE 0x00000000           /*!< Boot vector (INIT_PC_RESET_VALUE): 0x00000000                        */
#define VPR_VPR_START_RESET_VALUE 0                  /*!< Self-booting (VPR_START_RESET_VALUE): 0                              */
#define VPR_RAM_BASE_ADDR 0x23010000                 /*!< VPR RAM base address (RAM_BASE_ADDR): 0x23010000                     */
#define VPR_RAM_SZ 15                                /*!< VPR RAM size (RAM_SZ): 15 (Value in bytes is computed as 2^(RAM
                                                          size))*/
#define VPR_RETAINED 1                               /*!< Retain registers in Deep Sleep mode: 1                               */
#define VPR_VPRSAVEDCTX 0                            /*!< (unspecified)                                                        */
#define VPR_VPRSAVEADDR 0x00000000                   /*!< VPR context save address: 0x00000000                                 */
#define VPR_VPRREMAPADDRVTOB 0x00000000              /*!< VPR remap address: 0x00000000                                        */
#define VPR_VEVIF_NTASKS_MIN 0                       /*!< VEVIF tasks: 0..15                                                   */
#define VPR_VEVIF_NTASKS_MAX 15                      /*!< VEVIF tasks: 0..15                                                   */
#define VPR_VEVIF_TASKS_MASK 0x0000ff00              /*!< Mask of supported VEVIF tasks: 0x0000FF00                            */
#define VPR_VEVIF_NDPPI_MIN 8                        /*!< VEVIF DPPI channels: 8..10                                           */
#define VPR_VEVIF_NDPPI_MAX 10                       /*!< VEVIF DPPI channels: 8..10                                           */
#define VPR_VEVIF_NEVENTS_MIN 12                     /*!< VEVIF events: 12..15                                                 */
#define VPR_VEVIF_NEVENTS_MAX 15                     /*!< VEVIF events: 12..15                                                 */
#define VPR_DEBUGGER_OFFSET 1024                     /*!< Debugger interface register offset: 0x53034400                       */

#define VPR120_INIT_PC_RESET_VALUE 0x2f800000        /*!< Boot vector (INIT_PC_RESET_VALUE): 0x2F800000                        */
#define VPR120_VPR_START_RESET_VALUE 1               /*!< Self-booting (VPR_START_RESET_VALUE): 1                              */
#define VPR120_RAM_BASE_ADDR 0x2f800000              /*!< VPR RAM base address (RAM_BASE_ADDR): 0x2F800000                     */
#define VPR120_RAM_SZ 16                             /*!< VPR RAM size (RAM_SZ): 16 (Value in bytes is computed as 2^(RAM
                                                          size))*/
#define VPR120_VPRSAVEDCTX_REGNAME nrf_memconf120->power[0].ret /*!< (unspecified)                                             */
#define VPR120_VPRSAVEDCTX_REGBIT 22                 /*!< (unspecified)                                                        */
#define VPR120_RETAINED 0                            /*!< Retain registers in Deep Sleep mode: 0                               */
#define VPR120_VPRSAVEDCTX 1                         /*!< (unspecified)                                                        */
#define VPR120_VPRSAVEADDR 0x2f800000                /*!< VPR context save address: 0x2F800000                                 */
#define VPR120_VPRREMAPADDRVTOB 0x2f840000           /*!< VPR remap address: 0x2F840000                                        */
#define VPR120_VEVIF_NTASKS_MIN 0                    /*!< VEVIF tasks: 0..31                                                   */
#define VPR120_VEVIF_NTASKS_MAX 31                   /*!< VEVIF tasks: 0..31                                                   */
#define VPR120_VEVIF_TASKS_MASK 0xfffff0ff           /*!< Mask of supported VEVIF tasks: 0xFFFFF0FF                            */
#define VPR120_VEVIF_NDPPI_MIN 24                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPR120_VEVIF_NDPPI_MAX 27                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPR120_VEVIF_NEVENTS_MIN 28                  /*!< VEVIF events: 28..31                                                 */
#define VPR120_VEVIF_NEVENTS_MAX 31                  /*!< VEVIF events: 28..31                                                 */
#define VPR120_DEBUGGER_OFFSET 1024                  /*!< Debugger interface register offset: 0x5F8C8400                       */

#define VPR121_INIT_PC_RESET_VALUE 0x00000000        /*!< Boot vector (INIT_PC_RESET_VALUE): 0x00000000                        */
#define VPR121_VPR_START_RESET_VALUE 0               /*!< Self-booting (VPR_START_RESET_VALUE): 0                              */
#define VPR121_RAM_BASE_ADDR 0x2f890000              /*!< VPR RAM base address (RAM_BASE_ADDR): 0x2F890000                     */
#define VPR121_RAM_SZ 15                             /*!< VPR RAM size (RAM_SZ): 15 (Value in bytes is computed as 2^(RAM
                                                          size))*/
#define VPR121_VPRSAVEDCTX_REGNAME nrf_memconf120->power[0].ret /*!< (unspecified)                                             */
#define VPR121_VPRSAVEDCTX_REGBIT 23                 /*!< (unspecified)                                                        */
#define VPR121_RETAINED 0                            /*!< Retain registers in Deep Sleep mode: 0                               */
#define VPR121_VPRSAVEDCTX 1                         /*!< (unspecified)                                                        */
#define VPR121_VPRSAVEADDR 0x2f800000                /*!< VPR context save address: 0x2F800000                                 */
#define VPR121_VPRREMAPADDRVTOB 0x00000000           /*!< VPR remap address: 0x00000000                                        */
#define VPR121_VEVIF_NTASKS_MIN 0                    /*!< VEVIF tasks: 0..31                                                   */
#define VPR121_VEVIF_NTASKS_MAX 31                   /*!< VEVIF tasks: 0..31                                                   */
#define VPR121_VEVIF_TASKS_MASK 0xffff0000           /*!< Mask of supported VEVIF tasks: 0xFFFF0000                            */
#define VPR121_VEVIF_NDPPI_MIN 24                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPR121_VEVIF_NDPPI_MAX 27                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPR121_VEVIF_NEVENTS_MIN 28                  /*!< VEVIF events: 28..31                                                 */
#define VPR121_VEVIF_NEVENTS_MAX 31                  /*!< VEVIF events: 28..31                                                 */
#define VPR121_DEBUGGER_OFFSET 1024                  /*!< Debugger interface register offset: 0x5F8D4400                       */

#define VPR130_INIT_PC_RESET_VALUE 0x00000000        /*!< Boot vector (INIT_PC_RESET_VALUE): 0x00000000                        */
#define VPR130_VPR_START_RESET_VALUE 0               /*!< Self-booting (VPR_START_RESET_VALUE): 0                              */
#define VPR130_RAM_BASE_ADDR 0x2fc00000              /*!< VPR RAM base address (RAM_BASE_ADDR): 0x2FC00000                     */
#define VPR130_RAM_SZ 15                             /*!< VPR RAM size (RAM_SZ): 15 (Value in bytes is computed as 2^(RAM
                                                          size))*/
#define VPR130_VPRSAVEDCTX_REGNAME nrf_memconf130->power[0].ret /*!< (unspecified)                                             */
#define VPR130_VPRSAVEDCTX_REGBIT 5                  /*!< (unspecified)                                                        */
#define VPR130_RETAINED 0                            /*!< Retain registers in Deep Sleep mode: 0                               */
#define VPR130_VPRSAVEDCTX 1                         /*!< (unspecified)                                                        */
#define VPR130_VPRSAVEADDR 0x2f800000                /*!< VPR context save address: 0x2F800000                                 */
#define VPR130_VPRREMAPADDRVTOB 0x00000000           /*!< VPR remap address: 0x00000000                                        */
#define VPR130_VEVIF_NTASKS_MIN 0                    /*!< VEVIF tasks: 0..15                                                   */
#define VPR130_VEVIF_NTASKS_MAX 15                   /*!< VEVIF tasks: 0..15                                                   */
#define VPR130_VEVIF_TASKS_MASK 0xfffffff0           /*!< Mask of supported VEVIF tasks: 0xFFFFFFF0                            */
#define VPR130_VEVIF_NDPPI_MIN 8                     /*!< VEVIF DPPI channels: 8..11                                           */
#define VPR130_VEVIF_NDPPI_MAX 11                    /*!< VEVIF DPPI channels: 8..11                                           */
#define VPR130_VEVIF_NEVENTS_MIN 12                  /*!< VEVIF events: 12..15                                                 */
#define VPR130_VEVIF_NEVENTS_MAX 15                  /*!< VEVIF events: 12..15                                                 */
#define VPR130_DEBUGGER_OFFSET 1024                  /*!< Debugger interface register offset: 0x5F908400                       */

/*IPCT APB registers*/
#define IPCT_PRESENT 1
#define IPCT_COUNT 3

/*BELLBOARD APB registers*/
#define BELLBOARD_PRESENT 1
#define BELLBOARD_COUNT 1

/*Factory Information Configuration Registers*/
#define FICR_PRESENT 1
#define FICR_COUNT 1

#define FICR_LTE_ON 0                                /*!< (unspecified)                                                        */
#define FICR_WIFI_ON 0                               /*!< (unspecified)                                                        */
#define FICR_NFC_ON 1                                /*!< (unspecified)                                                        */

/*USBHSCORE*/
#define USBHSCORE_PRESENT 1
#define USBHSCORE_COUNT 1

/*I3CCORE*/
#define I3CCORE_PRESENT 1
#define I3CCORE_COUNT 2

/*DMU*/
#define DMU_PRESENT 1
#define DMU_COUNT 1

/*MCAN*/
#define MCAN_PRESENT 1
#define MCAN_COUNT 1

/*System Trace Macrocell data buffer*/
#define STMDATA_PRESENT 1
#define STMDATA_COUNT 1

/*TDDCONF*/
#define TDDCONF_PRESENT 1
#define TDDCONF_COUNT 1

/*GENERIC*/
#define GENERIC_PRESENT 1
#define GENERIC_COUNT 3

/*System Trace Macrocell*/
#define STM_PRESENT 1
#define STM_COUNT 1

/*Trace Port Interface Unit*/
#define TPIU_PRESENT 1
#define TPIU_COUNT 1

/*ATB Replicator module*/
#define ATBREPLICATOR_PRESENT 1
#define ATBREPLICATOR_COUNT 4

/*ATB funnel module*/
#define ATBFUNNEL_PRESENT 1
#define ATBFUNNEL_COUNT 4

/*GPIO Tasks and Events*/
#define GPIOTE_PRESENT 1
#define GPIOTE_COUNT 1

#define GPIOTE130_GPIOTE_NCHANNELS_MIN 0             /*!< Number of GPIOTE channels: 0..7                                      */
#define GPIOTE130_GPIOTE_NCHANNELS_MAX 7             /*!< Number of GPIOTE channels: 0..7                                      */
#define GPIOTE130_GPIOTE_NPORTEVENTS_MIN 0           /*!< Number of GPIOTE port events: 0..3                                   */
#define GPIOTE130_GPIOTE_NPORTEVENTS_MAX 3           /*!< Number of GPIOTE port events: 0..3                                   */
#define GPIOTE130_GPIOTE_NINTERRUPTS_MIN 0           /*!< Number of GPIOTE interrupts: 0..1                                    */
#define GPIOTE130_GPIOTE_NINTERRUPTS_MAX 1           /*!< Number of GPIOTE interrupts: 0..1                                    */

/*Global Real-time counter*/
#define GRTC_PRESENT 1
#define GRTC_COUNT 1

#define GRTC_MSBWIDTH_MIN 0                          /*!< Width of the RTCOUNTERH, RTCOMPAREH and RTCOMPARESYNCH registers :
                                                          0..14*/
#define GRTC_MSBWIDTH_MAX 14                         /*!< Width of the RTCOUNTERH, RTCOMPAREH and RTCOMPARESYNCH registers :
                                                          0..14*/
#define GRTC_NCC_MIN 0                               /*!< Number of compare/capture registers : 0..15                          */
#define GRTC_NCC_MAX 15                              /*!< Number of compare/capture registers : 0..15                          */
#define GRTC_NTIMEOUT_MIN 0                          /*!< Width of the TIMEOUT register : 0..15                                */
#define GRTC_NTIMEOUT_MAX 15                         /*!< Width of the TIMEOUT register : 0..15                                */
#define GRTC_NDOMAIN_MIN 0                           /*!< Number of domains at the KEEPRUNNING register: 0..15                 */
#define GRTC_NDOMAIN_MAX 15                          /*!< Number of domains at the KEEPRUNNING register: 0..15                 */
#define GRTC_GRTC_NINTERRUPTS_MIN 0                  /*!< Number of GRTC interrupts : 0..1                                     */
#define GRTC_GRTC_NINTERRUPTS_MAX 1                  /*!< Number of GRTC interrupts : 0..1                                     */
#define GRTC_PWMREGS 0                               /*!< (unspecified)                                                        */
#define GRTC_CLKOUTREG 0                             /*!< (unspecified)                                                        */

/*Trace buffer monitor*/
#define TBM_PRESENT 1
#define TBM_COUNT 1

/*USBHS*/
#define USBHS_PRESENT 1
#define USBHS_COUNT 1

/*MRAM controller*/
#define MRAMC_PRESENT 1
#define MRAMC_COUNT 2

#define MRAMC110_NMRAMWORDSIZE 128                   /*!< (unspecified)                                                        */
#define MRAMC110_NMRAMPAGESIZE 4                     /*!< (unspecified)                                                        */
#define MRAMC110_NNVRPAGESIZE 2                      /*!< (unspecified)                                                        */
#define MRAMC110_NMAINMEMORYSIZE 1                   /*!< MRAM main memory size: 1 MB                                          */
#define MRAMC110_NNVRPAGES_MIN 0                     /*!< Number of MRAM NVR pages: 0..3                                       */
#define MRAMC110_NNVRPAGES_MAX 3                     /*!< Number of MRAM NVR pages: 0..3                                       */
#define MRAMC110_NSIZEMRAMWORDS_MIN 1                /*!< Register ERASE.SIZE.SIZE range: 1..65536                             */
#define MRAMC110_NSIZEMRAMWORDS_MAX 65536            /*!< Register ERASE.SIZE.SIZE range: 1..65536                             */
#define MRAMC110_MARMDATAWIDTHWORDS_MIN 0            /*!< Register TESTMODE2.MRAM.DATA/DATAINC size: 0..3                      */
#define MRAMC110_MARMDATAWIDTHWORDS_MAX 3            /*!< Register TESTMODE2.MRAM.DATA/DATAINC size: 0..3                      */
#define MRAMC110_NVRPAGEUPPER 0                      /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELOWER 0                      /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGEENABLENORMALWRITE 1          /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELRSIZEBITS_MIN 24            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELRSIZEBITS_MAX 27            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELRSIZERESET 15               /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELRSIZEVALUE_MIN 0            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELRSIZEVALUE_MAX 15           /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELWSIZEBITS_MIN 28            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELWSIZEBITS_MAX 31            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELWSIZERESET 15               /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELWSIZEVALUE_MIN 0            /*!< (unspecified)                                                        */
#define MRAMC110_NVRPAGELWSIZEVALUE_MAX 15           /*!< (unspecified)                                                        */

#define MRAMC111_NMRAMWORDSIZE 128                   /*!< (unspecified)                                                        */
#define MRAMC111_NMRAMPAGESIZE 4                     /*!< (unspecified)                                                        */
#define MRAMC111_NNVRPAGESIZE 2                      /*!< (unspecified)                                                        */
#define MRAMC111_NMAINMEMORYSIZE 1                   /*!< MRAM main memory size: 1 MB                                          */
#define MRAMC111_NNVRPAGES_MIN 0                     /*!< Number of MRAM NVR pages: 0..3                                       */
#define MRAMC111_NNVRPAGES_MAX 3                     /*!< Number of MRAM NVR pages: 0..3                                       */
#define MRAMC111_NSIZEMRAMWORDS_MIN 1                /*!< Register ERASE.SIZE.SIZE range: 1..65536                             */
#define MRAMC111_NSIZEMRAMWORDS_MAX 65536            /*!< Register ERASE.SIZE.SIZE range: 1..65536                             */
#define MRAMC111_MARMDATAWIDTHWORDS_MIN 0            /*!< Register TESTMODE2.MRAM.DATA/DATAINC size: 0..3                      */
#define MRAMC111_MARMDATAWIDTHWORDS_MAX 3            /*!< Register TESTMODE2.MRAM.DATA/DATAINC size: 0..3                      */
#define MRAMC111_NVRPAGEUPPER 0                      /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELOWER 0                      /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGEENABLENORMALWRITE 1          /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELRSIZEBITS_MIN 24            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELRSIZEBITS_MAX 27            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELRSIZERESET 15               /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELRSIZEVALUE_MIN 0            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELRSIZEVALUE_MAX 15           /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELWSIZEBITS_MIN 28            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELWSIZEBITS_MAX 31            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELWSIZERESET 15               /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELWSIZEVALUE_MIN 0            /*!< (unspecified)                                                        */
#define MRAMC111_NVRPAGELWSIZEVALUE_MAX 15           /*!< (unspecified)                                                        */

/*External Memory Interface*/
#define EXMIF_PRESENT 1
#define EXMIF_COUNT 1

/*AUXPLL*/
#define AUXPLL_PRESENT 1
#define AUXPLL_COUNT 1

/*AUXPM*/
#define AUXPM_PRESENT 1
#define AUXPM_COUNT 1

/*OTP controller*/
#define OTPC_PRESENT 1
#define OTPC_COUNT 1

#define OTPC_REGION_NO_EXTENSION 1                   /*!< (unspecified)                                                        */
#define OTPC_REGION_EXTENSION 0                      /*!< (unspecified)                                                        */
#define OTPC_NREGIONS_MIN 0                          /*!< (unspecified)                                                        */
#define OTPC_NREGIONS_MAX 5                          /*!< (unspecified)                                                        */
#define OTPC_REGION0ADDR 797179904                   /*!< Region 0 address : 797179904, size: 1024 Bytes                       */
#define OTPC_REGION0SIZE 1024                        /*!< (unspecified)                                                        */
#define OTPC_REGION1ADDR 797180928                   /*!< Region 1 address : 797180928, size: 15360 Bytes                      */
#define OTPC_REGION1SIZE 15360                       /*!< (unspecified)                                                        */
#define OTPC_REGION2ADDR 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION2SIZE 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION3ADDR 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION3SIZE 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION4ADDR 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION4SIZE 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION5ADDR 0                           /*!< (unspecified)                                                        */
#define OTPC_REGION5SIZE 0                           /*!< (unspecified)                                                        */

/*MUTEX*/
#define MUTEX_PRESENT 1
#define MUTEX_COUNT 2

/*I3C*/
#define I3C_PRESENT 1
#define I3C_COUNT 2

/*Controller Area Network*/
#define CAN_PRESENT 1
#define CAN_COUNT 1

/*Pulse width modulation unit*/
#define PWM_PRESENT 1
#define PWM_COUNT 5

#define PWM120_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define PWM120_EASYDMATEMP 1                         /*!< (unspecified)                                                        */

#define PWM130_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define PWM130_EASYDMATEMP 1                         /*!< (unspecified)                                                        */

#define PWM131_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define PWM131_EASYDMATEMP 1                         /*!< (unspecified)                                                        */

#define PWM132_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define PWM132_EASYDMATEMP 1                         /*!< (unspecified)                                                        */

#define PWM133_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define PWM133_EASYDMATEMP 1                         /*!< (unspecified)                                                        */

/*SPI Slave*/
#define SPIS_PRESENT 1
#define SPIS_COUNT 9

#define SPIS120_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS120_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS120_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS120_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS120_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS120_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS120_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS130_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS130_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS130_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS130_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS130_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS130_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS130_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS131_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS131_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS131_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS131_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS131_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS131_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS131_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS132_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS132_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS132_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS132_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS132_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS132_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS132_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS133_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS133_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS133_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS133_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS133_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS133_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS133_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS134_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS134_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS134_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS134_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS134_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS134_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS134_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS135_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS135_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS135_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS135_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS135_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS135_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS135_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS136_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS136_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS136_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS136_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS136_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS136_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS136_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define SPIS137_LEGACYPSEL 0                         /*!< (unspecified)                                                        */
#define SPIS137_LEGACYEDMA 0                         /*!< (unspecified)                                                        */
#define SPIS137_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIS137_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIS137_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS137_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIS137_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

/*UART with EasyDMA*/
#define UARTE_PRESENT 1
#define UARTE_COUNT 9

#define UARTE120_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE120_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE120_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE120_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE120_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE120_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE120_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE130_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE130_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE130_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE130_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE130_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE130_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE130_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE131_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE131_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE131_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE131_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE131_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE131_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE131_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE132_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE132_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE132_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE132_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE132_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE132_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE132_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE133_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE133_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE133_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE133_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE133_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE133_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE133_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE134_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE134_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE134_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE134_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE134_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE134_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE134_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE135_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE135_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE135_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE135_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE135_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE135_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE135_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE136_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE136_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE136_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE136_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE136_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE136_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE136_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

#define UARTE137_EASYDMA_MAXCNT_SIZE_MIN 0           /*!< (unspecified)                                                        */
#define UARTE137_EASYDMA_MAXCNT_SIZE_MAX 7           /*!< (unspecified)                                                        */
#define UARTE137_EASYDMA5 0                          /*!< (unspecified)                                                        */
#define UARTE137_EASYDMATEMP 1                       /*!< (unspecified)                                                        */
#define UARTE137_EASYDMALISTINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE137_EASYDMAMODEINCLUDED 0               /*!< (unspecified)                                                        */
#define UARTE137_EASYDMAFULLLPMODEINCLUDED 0         /*!< (unspecified)                                                        */

/*Serial Peripheral Interface Master with EasyDMA*/
#define SPIM_PRESENT 1
#define SPIM_COUNT 10

#define SPIM120_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM120_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM120_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM120_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM120_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM120_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM121_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM121_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM121_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM121_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM121_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM121_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM130_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM130_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM130_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM130_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM130_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM130_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM131_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM131_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM131_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM131_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM131_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM131_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM132_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM132_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM132_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM132_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM132_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM132_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM133_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM133_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM133_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM133_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM133_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM133_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM134_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM134_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM134_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM134_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM134_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM134_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM135_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM135_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM135_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM135_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM135_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM135_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM136_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM136_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM136_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM136_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM136_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM136_HSSPI 1                              /*!< (unspecified)                                                        */

#define SPIM137_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define SPIM137_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define SPIM137_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM137_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define SPIM137_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */
#define SPIM137_HSSPI 1                              /*!< (unspecified)                                                        */

/*GPIO Port*/
#define GPIO_PRESENT 1
#define GPIO_COUNT 6

#define P0_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P0_PIN_NUM_MAX 11                            /*!< (unspecified)                                                        */
#define P0_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P0_DRIVECTRL 0                               /*!< (unspecified)                                                        */
#define P0_PWRCTRL 0                                 /*!< (unspecified)                                                        */
#define P0_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P0_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P0_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P0_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

#define P1_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P1_PIN_NUM_MAX 11                            /*!< (unspecified)                                                        */
#define P1_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P1_DRIVECTRL 0                               /*!< (unspecified)                                                        */
#define P1_PWRCTRL 0                                 /*!< (unspecified)                                                        */
#define P1_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P1_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P1_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P1_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

#define P2_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P2_PIN_NUM_MAX 11                            /*!< (unspecified)                                                        */
#define P2_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P2_DRIVECTRL 0                               /*!< (unspecified)                                                        */
#define P2_PWRCTRL 0                                 /*!< (unspecified)                                                        */
#define P2_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P2_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P2_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P2_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

#define P6_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P6_PIN_NUM_MAX 13                            /*!< (unspecified)                                                        */
#define P6_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P6_DRIVECTRL 1                               /*!< (unspecified)                                                        */
#define P6_PWRCTRL 0                                 /*!< (unspecified)                                                        */
#define P6_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P6_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P6_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P6_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

#define P7_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P7_PIN_NUM_MAX 7                             /*!< (unspecified)                                                        */
#define P7_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P7_DRIVECTRL 1                               /*!< (unspecified)                                                        */
#define P7_PWRCTRL 0                                 /*!< (unspecified)                                                        */
#define P7_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P7_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P7_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P7_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

#define P9_PIN_NUM_MIN 0                             /*!< (unspecified)                                                        */
#define P9_PIN_NUM_MAX 5                             /*!< (unspecified)                                                        */
#define P9_PINS_PRESENT 0xfffffffful                 /*!< (unspecified)                                                        */
#define P9_DRIVECTRL 0                               /*!< (unspecified)                                                        */
#define P9_PWRCTRL 1                                 /*!< (unspecified)                                                        */
#define P9_PWRCTRL_SEPARATE_REG 0                    /*!< (unspecified)                                                        */
#define P9_VSS_FLOAT_DFT 0                           /*!< (unspecified)                                                        */
#define P9_PIN_OWNER_SEC 0                           /*!< (unspecified)                                                        */
#define P9_WIFI_CORE_PRESENT 0                       /*!< (unspecified)                                                        */

/*GPIO Internal*/
#define GPIOINTERNAL_PRESENT 1
#define GPIOINTERNAL_COUNT 1

/*Reset hub*/
#define RESETHUB_PRESENT 1
#define RESETHUB_COUNT 1

/*Analog to Digital Converter*/
#define SAADC_PRESENT 1
#define SAADC_COUNT 1

#define SAADC_EASYDMA5 0                             /*!< (unspecified)                                                        */
#define SAADC_EASYDMATEMP 1                          /*!< (unspecified)                                                        */
#define SAADC_EASYDMALISTINCLUDED 0                  /*!< (unspecified)                                                        */
#define SAADC_EASYDMAMODEINCLUDED 0                  /*!< (unspecified)                                                        */
#define SAADC_EASYDMAFULLLPMODEINCLUDED 0            /*!< (unspecified)                                                        */

/*Comparator*/
#define COMP_PRESENT 1
#define COMP_COUNT 1

/*Low-power comparator*/
#define LPCOMP_PRESENT 1
#define LPCOMP_COUNT 1

/*Temperature Sensor*/
#define TEMP_PRESENT 1
#define TEMP_COUNT 1

/*NFC-A compatible radio NFC-A compatible radio*/
#define NFCT_PRESENT 1
#define NFCT_COUNT 1

#define NFCT_EASYDMA5 0                              /*!< (unspecified)                                                        */
#define NFCT_EASYDMATEMP 0                           /*!< (unspecified)                                                        */

/*Inter-IC Sound*/
#define I2S_PRESENT 1
#define I2S_COUNT 2

#define I2S130_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define I2S130_EASYDMATEMP 1                         /*!< (unspecified)                                                        */
#define I2S130_EASYDMA_MAXCNT_SIZE_MIN 0             /*!< (unspecified)                                                        */
#define I2S130_EASYDMA_MAXCNT_SIZE_MAX 13            /*!< (unspecified)                                                        */

#define I2S131_EASYDMA5 0                            /*!< (unspecified)                                                        */
#define I2S131_EASYDMATEMP 1                         /*!< (unspecified)                                                        */
#define I2S131_EASYDMA_MAXCNT_SIZE_MIN 0             /*!< (unspecified)                                                        */
#define I2S131_EASYDMA_MAXCNT_SIZE_MAX 13            /*!< (unspecified)                                                        */

/*Pulse Density Modulation (Digital Microphone) Interface*/
#define PDM_PRESENT 1
#define PDM_COUNT 1

#define PDM_EASYDMA5 0                               /*!< (unspecified)                                                        */
#define PDM_EASYDMATEMP 1                            /*!< (unspecified)                                                        */
#define PDM_EASYDMALISTINCLUDED 0                    /*!< (unspecified)                                                        */
#define PDM_EASYDMAMODEINCLUDED 0                    /*!< (unspecified)                                                        */
#define PDM_EASYDMAFULLLPMODEINCLUDED 0              /*!< (unspecified)                                                        */

/*Quadrature Decoder*/
#define QDEC_PRESENT 1
#define QDEC_COUNT 2

#define QDEC130_LEGACYPSEL 0                         /*!< (unspecified)                                                        */

#define QDEC131_LEGACYPSEL 0                         /*!< (unspecified)                                                        */

/*SIM card interface*/
#define SIMIF_PRESENT 1
#define SIMIF_COUNT 1

/*I2C compatible Two-Wire Master Interface with EasyDMA*/
#define TWIM_PRESENT 1
#define TWIM_COUNT 8

#define TWIM130_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM130_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM130_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM130_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM130_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM131_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM131_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM131_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM131_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM131_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM132_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM132_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM132_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM132_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM132_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM133_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM133_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM133_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM133_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM133_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM134_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM134_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM134_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM134_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM134_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM135_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM135_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM135_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM135_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM135_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM136_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM136_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM136_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM136_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM136_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIM137_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIM137_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIM137_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM137_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIM137_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

/*I2C compatible Two-Wire Slave Interface with EasyDMA*/
#define TWIS_PRESENT 1
#define TWIS_COUNT 8

#define TWIS130_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS130_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS130_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS130_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS130_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS131_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS131_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS131_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS131_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS131_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS132_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS132_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS132_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS132_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS132_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS133_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS133_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS133_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS133_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS133_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS134_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS134_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS134_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS134_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS134_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS135_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS135_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS135_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS135_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS135_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS136_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS136_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS136_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS136_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS136_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */

#define TWIS137_EASYDMA5 0                           /*!< (unspecified)                                                        */
#define TWIS137_EASYDMATEMP 1                        /*!< (unspecified)                                                        */
#define TWIS137_EASYDMALISTINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS137_EASYDMAMODEINCLUDED 0                /*!< (unspecified)                                                        */
#define TWIS137_EASYDMAFULLLPMODEINCLUDED 0          /*!< (unspecified)                                                        */


#ifdef __cplusplus
}
#endif
#endif /* NRF54H20_ENGA_RADIOCORE_PERIPHERALS_H */

