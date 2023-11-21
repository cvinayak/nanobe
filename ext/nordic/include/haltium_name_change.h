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

#ifndef HALTIUM_NAME_CHANGE_H
#define HALTIUM_NAME_CHANGE_H

/*lint ++flb "Enter library region */

/* This file is given to prevent your SW from not compiling with the updates made to haltium.h and 
 * haltium_bitfields.h. The macros defined in this file were available previously. Do not use these
 * macros on purpose. Use the ones defined in the corresponding device header file instead.
 * This header file will not be part of the MDK of the final product, user-facing code will need to update.
 */
 
 /* POWER */ 
 #define POWER_ULPENABLE_ResetValue         POWER_BLOCKULPMODE_ResetValue 
 #define POWER_ULPENABLE_ENABLE_Pos         POWER_BLOCKULPMODE_ENABLE_Pos 
 #define POWER_ULPENABLE_ENABLE_Msk         POWER_BLOCKULPMODE_ENABLE_Msk 
 #define POWER_ULPENABLE_ENABLE_Min         POWER_BLOCKULPMODE_ENABLE_Min 
 #define POWER_ULPENABLE_ENABLE_Max         POWER_BLOCKULPMODE_ENABLE_Max 
 #define POWER_ULPENABLE_ENABLE_Disabled    POWER_BLOCKULPMODE_ENABLE_Disabled
 #define POWER_ULPENABLE_ENABLE_Enabled     POWER_BLOCKULPMODE_ENABLE_Enabled 
                                            
 #define POWER_ULVENABLE_ResetValue         POWER_BLOCKULVMODE_ResetValue 
 #define POWER_ULVENABLE_ENABLE_Pos         POWER_BLOCKULVMODE_ENABLE_Pos 
 #define POWER_ULVENABLE_ENABLE_Msk         POWER_BLOCKULVMODE_ENABLE_Msk 
 #define POWER_ULVENABLE_ENABLE_Min         POWER_BLOCKULVMODE_ENABLE_Min 
 #define POWER_ULVENABLE_ENABLE_Max         POWER_BLOCKULVMODE_ENABLE_Max 
 #define POWER_ULVENABLE_ENABLE_Disabled    POWER_BLOCKULVMODE_ENABLE_Disabled
 #define POWER_ULVENABLE_ENABLE_Enabled     POWER_BLOCKULVMODE_ENABLE_Enabled 
 
 /* MRAMC */
 #define MRAMC_CONFIGNVR_PAGE_Lock_Pos           MRAMC_CONFIGNVR_PAGE_LOCK_Pos           
 #define MRAMC_CONFIGNVR_PAGE_Lock_Msk           MRAMC_CONFIGNVR_PAGE_LOCK_Msk 
 #define MRAMC_CONFIGNVR_PAGE_Lock_Min           MRAMC_CONFIGNVR_PAGE_LOCK_Min
 #define MRAMC_CONFIGNVR_PAGE_Lock_Max           MRAMC_CONFIGNVR_PAGE_LOCK_Max 
 #define MRAMC_CONFIGNVR_PAGE_Lock_LockDisabled  MRAMC_CONFIGNVR_PAGE_LOCK_LockDisabled
 #define MRAMC_CONFIGNVR_PAGE_Lock_LockEnabled   MRAMC_CONFIGNVR_PAGE_LOCK_LockEnabled
 #define MRAMC_CONFIGNVR_PAGE_Lock_EnableLock    MRAMC_CONFIGNVR_PAGE_LOCK_EnableLock

/* CACHE */
#ifndef CACHE_STATUS_READY_Pos
    #define CACHE_STATUS_READY_Pos    CACHE_STATUS_BUSY_Pos 
    #define CACHE_STATUS_READY_Msk    CACHE_STATUS_BUSY_Msk 
    #define CACHE_STATUS_READY_Min    CACHE_STATUS_BUSY_Min 
    #define CACHE_STATUS_READY_Max    CACHE_STATUS_BUSY_Max 
    #define CACHE_STATUS_READY_Ready  CACHE_STATUS_BUSY_Ready     
    #define CACHE_STATUS_READY_Busy   CACHE_STATUS_BUSY_Busy     
#endif

 /* Extra symbols: */

/* Haltium domain IDs */
 typedef enum {
    NRF_DOMAIN_SECURE      = 1,  /* Secure Domain */
    NRF_DOMAIN_APPLICATION = 2,  /* Application Core */
    NRF_DOMAIN_RADIOCORE   = 3,  /* Radio Core */
    NRF_DOMAIN_CELLCORE    = 4,  /* Cellular Core */
    NRF_DOMAIN_CELLDSP     = 5,  /* Cellular DSP Domain */
    NRF_DOMAIN_CELLRF      = 6,  /* Cellular RF Domain */
    NRF_DOMAIN_ISIMCORE    = 7,  /* ISIM Core */
    NRF_DOMAIN_WIFICORE    = 8,  /* Wi-Fi core */
    NRF_DOMAIN_GLOBALFAST  = 12, /* Global Domain - Fast clock domain */
    NRF_DOMAIN_GLOBALSLOW  = 13, /* Global Domain - Slow clock domain */
    NRF_DOMAIN_GLOBAL      = 15, /* Global Domain */
 } NRF_DOMAINID_Type;
 
 #define NRF_DOMAINS_t NRF_DOMAINID_Type

/* Haltium owner IDs */
 typedef enum {
    NRF_OWNER_NONE            = 0,  /* Used to denote that ownership is not enforced */
    NRF_OWNER_SECURE          = 1,  /* Secure Domain */
    NRF_OWNER_APPLICATION     = 2,  /* Application Core */
    NRF_OWNER_RADIOCORE       = 3,  /* Radio Core */
    NRF_OWNER_CELL            = 4,  /* Cellular Core, Cellular DSP Domain and Cellular RF Domain */
    NRF_OWNER_ISIMCORE        = 5,  /* ISIM Core */
    NRF_OWNER_WIFICORE        = 6,  /* WIFI Core */
    NRF_OWNER_SYSCTRL         = 8,  /* System Controller, owned by the Secure Domain */
    NRF_OWNER_DBG_SECURE      = 9,  /* AHB-AP for Secure Domain CPU */
    NRF_OWNER_DBG_APPLICATION = 10, /* AHB-AP for Application Core CPU */
    NRF_OWNER_DBG_RADIOCORE   = 11, /* AHB-AP for Radio core CPU */
    NRF_OWNER_DBG_CELLCORE    = 12, /* AHB-AP for Cellular Core CPU */
    NRF_OWNER_DBG_CELLRF      = 13, /* AHB-AP for Cellular RF Domain CPU */
    NRF_OWNER_DBG_ISIMCORE    = 15 /* AHB-AP for ISIM Core CPU */
 } NRF_OWNERID_Type;

/* Haltium processor IDs */
 typedef enum {
    NRF_PROCESSOR_SECURE      = 1,  /* Secure Domain Processor */
    NRF_PROCESSOR_APPLICATION = 2,  /* Application Core Processor */
    NRF_PROCESSOR_RADIOCORE   = 3,  /* Radio Core Processor */
    NRF_PROCESSOR_CELLCORE    = 4,  /* Cellular Core Processor */
    NRF_PROCESSOR_CELLDSP     = 5,  /* Cellular DSP Domain Processor */
    NRF_PROCESSOR_CELLRF      = 6,  /* Cellular RF Domain Processor */
    NRF_PROCESSOR_ISIMCORE    = 7,  /* ISIM Core Processor */
    NRF_PROCESSOR_WIFILMAC    = 8,  /* Wi-Fi Core Processor */
    NRF_PROCESSOR_WIFIUMAC    = 9,  /* Wi-Fi Core Processor */
    NRF_PROCESSOR_BBPR        = 11, /* Baseband Processor */
    NRF_PROCESSOR_SYSCTRL     = 12, /* System Controller Processor */
    NRF_PROCESSOR_PPR         = 13, /* Peripheral Processor */
    NRF_PROCESSOR_FLPR        = 14, /* Fast Lightweight Processor */
 } NRF_PROCESSORID_Type;
 
 /*lint --flb "Leave library region" */

#endif /* HALTIUM_NAME_CHANGE_H */
