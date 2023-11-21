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

#ifndef NRF7140_PERIPHERALS_H
#define NRF7140_PERIPHERALS_H

#ifdef __cplusplus
    extern "C" {
#endif

#if defined(NRF_APPLICATION)
  #include "nrf7140_application_peripherals.h"
#elif defined(NRF_BBPR)
  #include "nrf7140_bbpr_peripherals.h"
#elif defined(NRF_FLPR)
  #include "nrf7140_flpr_peripherals.h"
#elif defined(NRF_LMAC)
  #include "nrf7140_lmac_peripherals.h"
#elif defined(NRF_PPR)
  #include "nrf7140_ppr_peripherals.h"
#elif defined(NRF_RADIOCORE)
  #include "nrf7140_radiocore_peripherals.h"
#elif defined(NRF_SECURE)
  #include "nrf7140_secure_peripherals.h"
#elif defined(NRF_SYSCTRL)
  #include "nrf7140_sysctrl_peripherals.h"
#elif defined(NRF_UMAC)
  #include "nrf7140_umac_peripherals.h"
#elif defined(NRF_WIFICORE)
  #include "nrf7140_wificore_peripherals.h"
#else
  #error No processor selected
#endif

#ifdef __cplusplus
}
#endif
#endif /* NRF7140_PERIPHERALS_H */

