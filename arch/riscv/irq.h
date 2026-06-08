/*
Copyright (c) 2016, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _IRQ_H_
#define _IRQ_H_

/* CLIC register base - SoC specific, override in board/soc header */
#ifndef CLIC_BASE
#define CLIC_BASE 0xF0000000UL
#endif

/* CLIC per-interrupt registers at CLIC_BASE + 0x1000 + irq*4 */
#define CLIC_INT_IP(n)   (*(volatile uint8_t *)(CLIC_BASE + 0x1000U + (n) * 4U + 0U))
#define CLIC_INT_IE(n)   (*(volatile uint8_t *)(CLIC_BASE + 0x1000U + (n) * 4U + 1U))
#define CLIC_INT_ATTR(n) (*(volatile uint8_t *)(CLIC_BASE + 0x1000U + (n) * 4U + 2U))
#define CLIC_INT_CTL(n)  (*(volatile uint8_t *)(CLIC_BASE + 0x1000U + (n) * 4U + 3U))

/* mstatus bits */
#ifndef MSTATUS_MIE
#define MSTATUS_MIE  (1U << 3)
#endif

static inline uint32_t irq_lock(void)
{
	uint32_t mstatus;

	__asm__ volatile ("csrrc %0, mstatus, %1"
			  : "=r" (mstatus)
			  : "r" (MSTATUS_MIE)
			  : "memory");

	return (mstatus & MSTATUS_MIE);
}

static inline void irq_unlock(uint32_t mask)
{
	if (!mask) {
		return;
	}
	__asm__ volatile ("csrs mstatus, %0"
			  :
			  : "r" (MSTATUS_MIE)
			  : "memory");
}

static inline void irq_enable(uint32_t irq)
{
	CLIC_INT_IE(irq) = 1;
}

static inline void irq_disable(uint32_t irq)
{
	CLIC_INT_IE(irq) = 0;
}

static inline uint32_t irq_is_enabled(uint32_t irq)
{
	return CLIC_INT_IE(irq);
}

static inline void irq_pending_set(uint32_t irq)
{
	CLIC_INT_IP(irq) = 1;
}

static inline void irq_pending_clear(uint32_t irq)
{
	CLIC_INT_IP(irq) = 0;
}

static inline void irq_priority_set(uint32_t irq, int priority)
{
	CLIC_INT_CTL(irq) = (uint8_t)priority;
}

#endif /* _IRQ_H_ */
