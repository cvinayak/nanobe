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

#ifndef NRF54H20_ENGA_SYSCTRL_PERIPHERALS_H
#define NRF54H20_ENGA_SYSCTRL_PERIPHERALS_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdbool.h>
/*VPR CSR registers*/
#define VPRCSR_PRESENT 1
#define VPRCSR_COUNT 1

#define VPRCSR_HARTNUM 12                            /*!< HARTNUM: 12                                                          */
#define VPRCSR_MCLICBASERESET 0x5f8c9000             /*!< MCLICBASE: 0x5F8C9000                                                */
#define VPRCSR_MULDIV 1                              /*!< MULDIV: 1                                                            */
#define VPRCSR_HIBERNATE 1                           /*!< HIBERNATE: 1                                                         */
#define VPRCSR_DBG 1                                 /*!< DBG: 1                                                               */
#define VPRCSR_REMAP 1                               /*!< Code patching (REMAP): 1                                             */
#define VPRCSR_BUSWIDTH 64                           /*!< BUSWIDTH: 64                                                         */
#define VPRCSR_BKPT 1                                /*!< BKPT: 1                                                              */
#define VPRCSR_VIOPINS 0x0000000f                    /*!< CSR VIOPINS value: 0x0000000F                                        */
#define VPRCSR_RT_SPLIT_SEC 1                        /*!< RT_SPLIT_SEC: 1                                                      */
#define VPRCSR_RT_SHIFT_PRESENT 0                    /*!< RT_SHIFT_PRESENT: 0                                                  */
#define VPRCSR_RT_SHIFT_START 0                      /*!< RT_SHIFT_START: 0                                                    */
#define VPRCSR_RT_SHIFT_LENGTH 32                    /*!< RT_SHIFT_LENGTH: rt_shift_length                                     */
#define VPRCSR_VEVIF_NTASKS_MIN 0                    /*!< VEVIF tasks: 0..31                                                   */
#define VPRCSR_VEVIF_NTASKS_MAX 31                   /*!< VEVIF tasks: 0..31                                                   */
#define VPRCSR_VEVIF_TASKS_MASK 0xfffff0ff           /*!< Mask of supported VEVIF tasks: 0xFFFFF0FF                            */
#define VPRCSR_VEVIF_NDPPI_MIN 24                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPRCSR_VEVIF_NDPPI_MAX 27                    /*!< VEVIF DPPI channels: 24..27                                          */
#define VPRCSR_VEVIF_NEVENTS_MIN 28                  /*!< VEVIF events: 28..31                                                 */
#define VPRCSR_VEVIF_NEVENTS_MAX 31                  /*!< VEVIF events: 28..31                                                 */
#define VPRCSR_RST_UNRECOV 0                         /*!< Unrecoverable state forces syncronous reset: 0                       */
#define VPRCSR_BEXT 0                                /*!< Bit-Manipulation extension: 0                                        */
#define VPRCSR_CACHE_EN 0                            /*!< (unspecified)                                                        */
#define VPRCSR_OUTMODE_VPR1_2 0                      /*!< (unspecified)                                                        */
#define VPRCSR_VPR_BUS_PRIO 0                        /*!< (unspecified)                                                        */

/*One time programmable Information Configuration Registers*/
#define OICR_PRESENT 1
#define OICR_COUNT 1

/*CACHEDATA*/
#define CACHEDATA_PRESENT 1
#define CACHEDATA_COUNT 1

/*CACHEINFO*/
#define CACHEINFO_PRESENT 1
#define CACHEINFO_COUNT 1

/*CRACENCORE*/
#define CRACENCORE_PRESENT 1
#define CRACENCORE_COUNT 1

#define SHA3CORE_CRYPTMSTRDMAREGS 1                  /*!< (unspecified)                                                        */
#define SHA3CORE_CRYPTMSTRHWREGS 1                   /*!< (unspecified)                                                        */
#define SHA3CORE_RNGCONTROLREGS 0                    /*!< (unspecified)                                                        */
#define SHA3CORE_PKREGS 0                            /*!< (unspecified)                                                        */
#define SHA3CORE_IKGREGS 0                           /*!< (unspecified)                                                        */
#define SHA3CORE_RNGDATAREGS 0                       /*!< (unspecified)                                                        */
#define SHA3CORE_PKDATAMEMORYREGS 0                  /*!< (unspecified)                                                        */
#define SHA3CORE_PKUCODEREGS 0                       /*!< (unspecified)                                                        */
#define SHA3CORE_CRACENRESETVALUES 0                 /*!< (unspecified)                                                        */
#define SHA3CORE_SHA3RESETVALUES 0                   /*!< (unspecified)                                                        */

/*HSFLL*/
#define HSFLL_PRESENT 1
#define HSFLL_COUNT 3

#define HSFLL200_DITHER_32B 0                        /*!< (unspecified)                                                        */

#define HSFLL121_DITHER_32B 0                        /*!< (unspecified)                                                        */

#define HSFLL120_DITHER_32B 0                        /*!< (unspecified)                                                        */

/*LRCCONF*/
#define LRCCONF_PRESENT 1
#define LRCCONF_COUNT 3

#define LRCCONF200_POWERON 1                         /*!< (unspecified)                                                        */
#define LRCCONF200_RETAIN 0                          /*!< (unspecified)                                                        */
#define LRCCONF200_SYSTEMOFF 0                       /*!< (unspecified)                                                        */
#define LRCCONF200_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF200_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF200_NCLK_MAX 0                        /*!< (unspecified)                                                        */
#define LRCCONF200_CLKCTRL 1                         /*!< (unspecified)                                                        */
#define LRCCONF200_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF200_NACTPD_MAX 7                      /*!< (unspecified)                                                        */
#define LRCCONF200_PDACT 0                           /*!< (unspecified)                                                        */
#define LRCCONF200_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF200_NPD_MAX 7                         /*!< (unspecified)                                                        */
#define LRCCONF200_OTHERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF200_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF200_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF200_AX2XWAITSTATES 0                  /*!< (unspecified)                                                        */
#define LRCCONF200_POWERON_MAIN_RESET 0              /*!< Reset value of register POWERON.MAIN: 0                              */
#define LRCCONF200_POWERON_ACT_RESET 0               /*!< Reset value of register POWERON.ACT: 0                               */
#define LRCCONF200_RETAIN_MAIN_RESET 1               /*!< Reset value of register RETAIN.MAIN: 1                               */
#define LRCCONF200_RETAIN_ACT_RESET 1                /*!< Reset value of register RETAIN.ACT: 1                                */

#define LRCCONF120_POWERON 1                         /*!< (unspecified)                                                        */
#define LRCCONF120_RETAIN 1                          /*!< (unspecified)                                                        */
#define LRCCONF120_SYSTEMOFF 0                       /*!< (unspecified)                                                        */
#define LRCCONF120_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF120_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF120_NCLK_MAX 1                        /*!< (unspecified)                                                        */
#define LRCCONF120_CLKCTRL 1                         /*!< (unspecified)                                                        */
#define LRCCONF120_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF120_NACTPD_MAX 1                      /*!< (unspecified)                                                        */
#define LRCCONF120_PDACT 1                           /*!< (unspecified)                                                        */
#define LRCCONF120_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF120_NPD_MAX 7                         /*!< (unspecified)                                                        */
#define LRCCONF120_OTHERON 0                         /*!< (unspecified)                                                        */
#define LRCCONF120_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF120_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF120_AX2XWAITSTATES 1                  /*!< (unspecified)                                                        */
#define LRCCONF120_POWERON_MAIN_RESET 1              /*!< Reset value of register POWERON.MAIN: 1                              */
#define LRCCONF120_POWERON_ACT_RESET 1               /*!< Reset value of register POWERON.ACT: 1                               */
#define LRCCONF120_RETAIN_MAIN_RESET 1               /*!< Reset value of register RETAIN.MAIN: 1                               */
#define LRCCONF120_RETAIN_ACT_RESET 1                /*!< Reset value of register RETAIN.ACT: 1                                */

#define LRCCONF130_POWERON 1                         /*!< (unspecified)                                                        */
#define LRCCONF130_RETAIN 1                          /*!< (unspecified)                                                        */
#define LRCCONF130_SYSTEMOFF 1                       /*!< (unspecified)                                                        */
#define LRCCONF130_LRCREQHFXO 0                      /*!< (unspecified)                                                        */
#define LRCCONF130_NCLK_MIN 0                        /*!< (unspecified)                                                        */
#define LRCCONF130_NCLK_MAX 7                        /*!< (unspecified)                                                        */
#define LRCCONF130_CLKCTRL 0                         /*!< (unspecified)                                                        */
#define LRCCONF130_NACTPD_MIN 0                      /*!< (unspecified)                                                        */
#define LRCCONF130_NACTPD_MAX 0                      /*!< (unspecified)                                                        */
#define LRCCONF130_PDACT 1                           /*!< (unspecified)                                                        */
#define LRCCONF130_NPD_MIN 0                         /*!< (unspecified)                                                        */
#define LRCCONF130_NPD_MAX 10                        /*!< (unspecified)                                                        */
#define LRCCONF130_OTHERON 1                         /*!< (unspecified)                                                        */
#define LRCCONF130_NDOMAINS_MIN 0                    /*!< (unspecified)                                                        */
#define LRCCONF130_NDOMAINS_MAX 15                   /*!< (unspecified)                                                        */
#define LRCCONF130_AX2XWAITSTATES 0                  /*!< (unspecified)                                                        */
#define LRCCONF130_POWERON_MAIN_RESET 1              /*!< Reset value of register POWERON.MAIN: 1                              */
#define LRCCONF130_POWERON_ACT_RESET 1               /*!< Reset value of register POWERON.ACT: 1                               */
#define LRCCONF130_RETAIN_MAIN_RESET 1               /*!< Reset value of register RETAIN.MAIN: 1                               */
#define LRCCONF130_RETAIN_ACT_RESET 1                /*!< Reset value of register RETAIN.ACT: 1                                */

/*VPR CLIC registers*/
#define CLIC_PRESENT 1
#define CLIC_COUNT 1

#define VPRCLIC_IRQNUM_MIN 0                         /*!< Supported interrupts (IRQNUM): 0..479                                */
#define VPRCLIC_IRQNUM_MAX 479                       /*!< Supported interrupts (IRQNUM): 0..479                                */
#define VPRCLIC_CLIC_NTASKS_MIN 0                    /*!< VEVIF tasks: 0..31                                                   */
#define VPRCLIC_CLIC_NTASKS_MAX 31                   /*!< VEVIF tasks: 0..31                                                   */
#define VPRCLIC_CLIC_TASKS_MASK 0xfffff0ff           /*!< Mask of supported VEVIF tasks: 0xFFFFF0FF                            */
#define VPRCLIC_COUNTER_IRQ_NUM 32                   /*!< VPR counter (CNT0) interrupt handler number (COUNTER_IRQ_NUM): 32    */
#define VPRCLIC_CLIC_VPR_1_2 0                       /*!< (unspecified)                                                        */

/*VTIM CSR registers*/
#define VTIM_PRESENT 1
#define VTIM_COUNT 1

/*Cache*/
#define CACHE_PRESENT 1
#define CACHE_COUNT 1

#define L2CACHE_VIRTUALCACHE 1                       /*!< (unspecified)                                                        */
#define L2CACHE_FLUSH 0                              /*!< (unspecified)                                                        */
#define L2CACHE_CLEAN 0                              /*!< (unspecified)                                                        */

/*RAM Controller*/
#define RAMC_PRESENT 1
#define RAMC_COUNT 6

#define RAMC110_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC110_SEC 0                                /*!< (unspecified)                                                        */

#define RAMC111_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC111_SEC 0                                /*!< (unspecified)                                                        */

#define RAMC120_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC120_SEC 0                                /*!< (unspecified)                                                        */

#define RAMC121_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC121_SEC 0                                /*!< (unspecified)                                                        */

#define RAMC130_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC130_SEC 0                                /*!< (unspecified)                                                        */

#define RAMC131_ECC 0                                /*!< (unspecified)                                                        */
#define RAMC131_SEC 0                                /*!< (unspecified)                                                        */

/*CRACEN*/
#define CRACEN_PRESENT 1
#define CRACEN_COUNT 1

#define SHA3_CRYPTOACCELERATOR 0                     /*!< (unspecified)                                                        */

/*PCGCSlave*/
#define PCGCSLAVE_PRESENT 1
#define PCGCSLAVE_COUNT 13

#define PCGCS110_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS120_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS121_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS122_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS130_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS131_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS132_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS133_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS134_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS135_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS136_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS137_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

#define PCGCS138_PENALTYTASKS 0                      /*!< (unspecified)                                                        */

/*PCGC Master*/
#define PCGCMASTER_PRESENT 1
#define PCGCMASTER_COUNT 12

#define PCGCM110_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM110_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM110_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM110_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM120_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM120_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM120_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM120_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM121_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM121_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM121_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM121_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM130_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM130_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM130_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM130_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM131_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM131_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM131_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM131_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM132_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM132_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM132_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM132_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM133_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM133_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM133_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM133_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM134_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM134_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM134_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM134_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM135_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM135_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM135_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM135_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM136_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM136_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM136_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM136_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM137_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM137_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM137_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM137_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

#define PCGCM138_POWERCONSUMPTIONCALC 1              /*!< (unspecified)                                                        */
#define PCGCM138_SETPWRCONTHRESHOLDBASE 1            /*!< (unspecified)                                                        */
#define PCGCM138_CLOCKFORCEREG 1                     /*!< (unspecified)                                                        */
#define PCGCM138_MASTERFORCEREG 1                    /*!< (unspecified)                                                        */

/*EXternal Memory Encryption Engine*/
#define EXMEE_PRESENT 1
#define EXMEE_COUNT 1

/*MVDMA performs direct-memory-accesses between memories. Data is transferred according to job descriptor lists. Each transfer has corresponding source and sink descriptor lists with matching data amounts. The lists are in memory and they contain data buffer information, address pointers, buffer sizes and data type attributes.*/

#define MVDMA_PRESENT 1
#define MVDMA_COUNT 1

/*PPIB APB registers*/
#define PPIB_PRESENT 1
#define PPIB_COUNT 11

/*ROM Controller*/
#define ROMC_PRESENT 1
#define ROMC_COUNT 1

/*Memory configuration*/
#define MEMCONF_PRESENT 1
#define MEMCONF_COUNT 2

#define MEMCONF120_RETTRIM 1                         /*!< (unspecified)                                                        */
#define MEMCONF120_REPAIR 1                          /*!< (unspecified)                                                        */
#define MEMCONF120_POWER 1                           /*!< (unspecified)                                                        */
#define MEMCONF120_RET2 1                            /*!< (unspecified)                                                        */

#define MEMCONF130_RETTRIM 1                         /*!< (unspecified)                                                        */
#define MEMCONF130_REPAIR 1                          /*!< (unspecified)                                                        */
#define MEMCONF130_POWER 1                           /*!< (unspecified)                                                        */
#define MEMCONF130_RET2 1                            /*!< (unspecified)                                                        */

/*Watchdog Timer*/
#define WDT_PRESENT 1
#define WDT_COUNT 3

/*GRCCONF*/
#define GRCCONF_PRESENT 1
#define GRCCONF_COUNT 1

/*PCRM*/
#define PCRM_PRESENT 1
#define PCRM_COUNT 1

/*CLOCK*/
#define CLOCK_PRESENT 1
#define CLOCK_COUNT 1

/*LFRC peripheral*/
#define LFRC_PRESENT 1
#define LFRC_COUNT 1

/*GENERIC*/
#define GENERIC_PRESENT 1
#define GENERIC_COUNT 4

/*LFXO peripheral*/
#define LFXO_PRESENT 1
#define LFXO_COUNT 1

/*FLL16M*/
#define FLL16M_PRESENT 1
#define FLL16M_COUNT 1

/*HFXO peripheral*/
#define HFXO_PRESENT 1
#define HFXO_COUNT 1

/*AUXPLL*/
#define AUXPLL_PRESENT 1
#define AUXPLL_COUNT 3

/*POWER*/
#define POWER_PRESENT 1
#define POWER_COUNT 1

#define POWER_NABBDOMAIN_MIN 0                       /*!< Number of ABB domains: 0..1                                          */
#define POWER_NABBDOMAIN_MAX 1                       /*!< Number of ABB domains: 0..1                                          */
#define POWER_NATBGNDCLAMP_MIN 0                     /*!< Number of ATB ground clamps: 0..13                                   */
#define POWER_NATBGNDCLAMP_MAX 13                    /*!< Number of ATB ground clamps: 0..13                                   */
#define POWER_pmicenable 0                           /*!< (unspecified)                                                        */

/*VREGMAIN peripheral*/
#define VREGMAIN_PRESENT 1
#define VREGMAIN_COUNT 1

/*VREGAO1V8 peripheral*/
#define VREGAO1V8_PRESENT 1
#define VREGAO1V8_COUNT 1

/*VREG1V0*/
#define VREG1V0_PRESENT 1
#define VREG1V0_COUNT 1

/*VREGAO0V8 peripheral*/
#define VREGAO0V8_PRESENT 1
#define VREGAO0V8_COUNT 1

/*VREGVS0V8 peripheral*/
#define VREGVS0V8_PRESENT 1
#define VREGVS0V8_COUNT 1

/*VREGSU peripheral*/
#define VREGSU_PRESENT 1
#define VREGSU_COUNT 1

/*VREGUSB peripheral*/
#define VREGUSB_PRESENT 1
#define VREGUSB_COUNT 1

/*AUXPM*/
#define AUXPM_PRESENT 1
#define AUXPM_COUNT 2

/*VREGMRAM peripheral*/
#define VREGMRAM_PRESENT 1
#define VREGMRAM_COUNT 2

/*OSCRFR peripheral*/
#define OSCRFR_PRESENT 1
#define OSCRFR_COUNT 1

/*SWEXT peripheral*/
#define SWEXT_PRESENT 1
#define SWEXT_COUNT 1

/*MBIAS peripheral*/
#define MBIAS_PRESENT 1
#define MBIAS_COUNT 1

/*VDETAO1V8 peripheral*/
#define VDETAO1V8_PRESENT 1
#define VDETAO1V8_COUNT 1

/*VDETAO0V8 peripheral*/
#define VDETAO0V8_PRESENT 1
#define VDETAO0V8_COUNT 1

/*VDETVS0V8 peripheral*/
#define VDETVS0V8_PRESENT 1
#define VDETVS0V8_COUNT 1

/*VDETIO peripheral*/
#define VDETIO_PRESENT 1
#define VDETIO_COUNT 1

/*VDETAO5V0 peripheral*/
#define VDETAO5V0_PRESENT 1
#define VDETAO5V0_COUNT 1

/*VDET1V0 peripheral*/
#define VDET1V0_PRESENT 1
#define VDET1V0_COUNT 1

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

/*System Trace Macrocell*/
#define STM_PRESENT 1
#define STM_COUNT 1

/*Trace Port Interface Unit*/
#define TPIU_PRESENT 1
#define TPIU_COUNT 1

/*Cross-Trigger Interface control*/
#define CTI_PRESENT 1
#define CTI_COUNT 2

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

/*VPR peripheral registers*/
#define VPR_PRESENT 1
#define VPR_COUNT 3

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
#define IPCT_COUNT 2

/*MUTEX*/
#define MUTEX_PRESENT 1
#define MUTEX_COUNT 2

/*I3C*/
#define I3C_PRESENT 1
#define I3C_COUNT 2

/*Controller Area Network*/
#define CAN_PRESENT 1
#define CAN_COUNT 1

/*Distributed programmable peripheral interconnect controller*/
#define DPPIC_PRESENT 1
#define DPPIC_COUNT 8

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

/*Timer/Counter*/
#define TIMER_PRESENT 1
#define TIMER_COUNT 10

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

/*Real-time counter*/
#define RTC_PRESENT 1
#define RTC_COUNT 2

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
#endif /* NRF54H20_ENGA_SYSCTRL_PERIPHERALS_H */

