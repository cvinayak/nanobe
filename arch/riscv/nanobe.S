/*
Copyright (c) 2016, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * Lean RISC-V VPR Nanobe Port
 *
 * RV32E context (callee-saved): ra, s0, s1 + igrd = 4 words = 16 bytes
 *
 * Stack frame layout for nanobe context:
 *   sp + 12: ra  (return address / nanobe function)
 *   sp +  8: s0
 *   sp +  4: s1
 *   sp +  0: igrd (injection guard)
 */

	.section .text
	.global _nanobe_init
	.type _nanobe_init, %function
/* void *_nanobe_init(nanobe_t nanobe, void *stack)
 * a0 = nanobe function pointer
 * a1 = stack top
 * Returns: nanobe stack pointer (in a0)
 */
_nanobe_init:
	/* Save callee-saved registers on current stack */
	addi sp, sp, -12
	sw ra, 8(sp)
	sw s0, 4(sp)
	sw s1, 0(sp)

	/* Remember current sp */
	mv t0, sp

	/* Switch to new nanobe stack */
	mv sp, a1

	/* Create initial context frame on new stack */
	addi sp, sp, -16
	sw a0, 12(sp)		/* ra = nanobe function */
	sw zero, 8(sp)		/* s0 = 0 */
	sw zero, 4(sp)		/* s1 = 0 */
	sw zero, 0(sp)		/* igrd = 0 */

	/* Return value = new nanobe stack pointer */
	mv a0, sp

	/* Restore original stack */
	mv sp, t0
	lw ra, 8(sp)
	lw s0, 4(sp)
	lw s1, 0(sp)
	addi sp, sp, 12

	ret

	.section .text
	.global _nanobe_switch
	.type _nanobe_switch, %function
/* void _nanobe_switch(void *next_stack, void **curr_stack)
 * a0 = next nanobe stack pointer
 * a1 = pointer to store current stack pointer
 */
_nanobe_switch:
	/* Save callee-saved registers on current stack */
	addi sp, sp, -16
	sw ra, 12(sp)
	sw s0, 8(sp)
	sw s1, 4(sp)

	/* Save/set injection guard */
	la t0, __igrd
	lb t1, 0(t0)
	sw t1, 0(sp)		/* push current igrd */
	li t1, 1
	sb t1, 0(t0)		/* igrd = 1 (guard while switching) */

	/* Save current sp to *curr_stack */
	sw sp, 0(a1)

	/* Switch to next nanobe stack */
	mv sp, a0

	/* Restore injection guard from next context */
	lw t1, 0(sp)
	sb t1, 0(t0)		/* restore igrd */

	/* Clear sched guard */
	la t0, _sgrd
	sb zero, 0(t0)

	/* Restore callee-saved registers from next stack */
	lw ra, 12(sp)
	lw s0, 8(sp)
	lw s1, 4(sp)
	addi sp, sp, 16

	ret

	.section .text
	.global _nanobe_isr_inject
	.type _nanobe_isr_inject, %function
/* void _nanobe_isr_inject(void *esf, nanobe_t nanobe)
 * Called from _isr_wrapper after ISR handler returns.
 * a0 = exception stack frame pointer (sp at ISR entry)
 * a1 = injection callee (nanobe_injection)
 *
 * The ISR stack frame has mepc saved at offset 0.
 * If injection is possible, modify mepc to __syringe.
 */
_nanobe_isr_inject:
	/* Check _sgrd (sched guard) */
	la t0, _sgrd
	lb t1, 0(t0)
	bnez t1, __slocked

	/* Check __igrd (injection guard) */
	la t0, __igrd
	lb t1, 0(t0)
	bnez t1, __ilocked

	/* Set injection guard */
	li t1, 1
	sb t1, 0(t0)

	/* Get saved mepc from ISR stack frame */
	lw t1, 0(a0)		/* t1 = original mepc (return PC) */

	/* Store original return address */
	la t0, __iret
	sw t1, 0(t0)

	/* Store injection callee */
	la t0, __ical
	sw a1, 0(t0)

	/* Redirect return to syringe */
	la t1, __syringe
	sw t1, 0(a0)		/* mepc = __syringe */

	ret

__ilocked:
	la t0, __itrg
	li t1, 1
	sb t1, 0(t0)
	ret

__slocked:
	la t0, _strg
	li t1, 1
	sb t1, 0(t0)
	ret

/* Injection syringe - runs in thread context after mret from ISR.
 * Interrupts are enabled (MIE restored from MPIE by mret).
 * Must preserve all registers of the interrupted thread.
 */
__syringe:
	/* Save all caller-saved registers of interrupted thread */
	addi sp, sp, -44
	sw ra, 40(sp)
	sw t0, 36(sp)
	sw t1, 32(sp)
	sw t2, 28(sp)
	sw a0, 24(sp)
	sw a1, 20(sp)
	sw a2, 16(sp)
	sw a3, 12(sp)
	sw a4, 8(sp)
	sw a5, 4(sp)

__loop:
	/* Call injection callee (nanobe_injection) */
	la t0, __ical
	lw t0, 0(t0)
	jalr ra, t0, 0

	/* Clear injection guard */
	la t0, __igrd
	sb zero, 0(t0)

	/* Check if re-injection triggered */
	la t0, __itrg
	lb t1, 0(t0)
	bnez t1, __again

	/* Restore caller-saved registers */
	lw a5, 4(sp)
	lw a4, 8(sp)
	lw a3, 12(sp)
	lw a2, 16(sp)
	lw a1, 20(sp)
	lw a0, 24(sp)
	lw t2, 28(sp)
	lw t1, 32(sp)

	/* Load original return address to mepc, disable interrupts,
	 * restore remaining registers, then mret to return atomically
	 * with interrupts re-enabled.
	 */
	la t0, __iret
	lw t0, 0(t0)
	csrw mepc, t0

	/* Set MPIE so MIE is restored on mret */
	li t0, 0x80
	csrs mstatus, t0

	/* Disable MIE for atomic restore+return */
	csrci mstatus, 0x8

	/* Restore remaining caller-saved registers */
	lw t0, 36(sp)
	lw ra, 40(sp)
	addi sp, sp, 44

	mret

__again:
	sb zero, 0(t0)		/* clear __itrg */
	la t0, __igrd
	li t1, 1
	sb t1, 0(t0)		/* set __igrd */
	j __loop

	.section .text
	.weak _isr_wrapper
	.type _isr_wrapper, %function
	.align 2
/* ISR wrapper - single trap entry point (non-vectored mode).
 * Saves caller-saved registers, dispatches via _isr_table,
 * then checks for nanobe injection before returning.
 *
 * RV32E ISR frame (11 words = 44 bytes):
 *   sp + 40: mepc
 *   sp + 36: ra
 *   sp + 32: t0
 *   sp + 28: t1
 *   sp + 24: t2
 *   sp + 20: a0
 *   sp + 16: a1
 *   sp + 12: a2
 *   sp +  8: a3
 *   sp +  4: a4
 *   sp +  0: a5
 */
_isr_wrapper:
	/* Save caller-saved registers */
	addi sp, sp, -44
	sw ra, 36(sp)
	sw t0, 32(sp)
	sw t1, 28(sp)
	sw t2, 24(sp)
	sw a0, 20(sp)
	sw a1, 16(sp)
	sw a2, 12(sp)
	sw a3, 8(sp)
	sw a4, 4(sp)
	sw a5, 0(sp)

	/* Save mepc */
	csrr t0, mepc
	sw t0, 40(sp)

	/* Read mcause */
	csrr t0, mcause

	/* Check if interrupt (MSB=1) or exception (MSB=0) */
	bge t0, zero, __exception

	/* Extract interrupt number (lower bits) */
	andi t0, t0, 0x1FF

	/* Dispatch via ISR table: _isr_table[irq].param, .isr */
	la t1, _isr_table
	slli t0, t0, 3		/* irq * 8 (sizeof _isr_table_entry_t) */
	add t1, t1, t0
	lw a0, 0(t1)		/* param */
	lw t2, 4(t1)		/* isr function pointer */
	jalr ra, t2, 0		/* call isr(param) */

	/* Attempt nanobe injection */
	mv a0, sp		/* ISR stack frame pointer */
	la a1, nanobe_injection
	jal _nanobe_isr_inject

__isr_return:
	/* Restore mepc */
	lw t0, 40(sp)
	csrw mepc, t0

	/* Restore caller-saved registers */
	lw a5, 0(sp)
	lw a4, 4(sp)
	lw a3, 8(sp)
	lw a2, 12(sp)
	lw a1, 16(sp)
	lw a0, 20(sp)
	lw t2, 24(sp)
	lw t1, 28(sp)
	lw t0, 32(sp)
	lw ra, 36(sp)
	addi sp, sp, 44

	mret

__exception:
	/* Exception handling - read mepc and mtval for debug */
	csrr t1, mepc
	csrr t2, mtval
	j __exception		/* hang on exception */

	.section .bss.__nanobe
__iret:
	.word 0
__ical:
	.word 0
__igrd:
	.byte 0
__itrg:
	.byte 0

	.section .bss._nanobe_sched
	.global _sgrd
	.global _strg
_sgrd:
	.byte 0
_strg:
	.byte 0

	.end
