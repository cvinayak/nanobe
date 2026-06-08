/*
Copyright (c) 2016, Vinayak Kariappa Chettimada
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

	.section .text.entry
	.globl _start
	.type _start, %function
_start:
	/* Initialise global pointer */
	.option push
	.option norelax
	la gp, __global_pointer$
	.option pop

	/* Initialise stack pointer */
	la sp, isr_stack_top
	lw sp, 0(sp)

	/* Setup trap vector (non-vectored mode) */
	la t0, _isr_wrapper
	csrw mtvec, t0

	/* Disable all interrupts */
	csrci mstatus, 0x8

	/* load data memory */
	la t0, __text_end
	la t1, __data_start
	la t2, __data_end

	sub t2, t2, t1
	ble t2, zero, no_data

	li t3, 0
data_loop:
	add t4, t0, t3
	lw t5, 0(t4)
	add t4, t1, t3
	sw t5, 0(t4)
	addi t3, t3, 4
	blt t3, t2, data_loop
no_data:

	/* zero bss memory */
	la t1, __bss_start
	la t2, __bss_end

	sub t2, t2, t1
	ble t2, zero, no_bss

	li t3, 0
bss_loop:
	add t4, t1, t3
	sw zero, 0(t4)
	addi t3, t3, 4
	blt t3, t2, bss_loop
no_bss:

	/* Switch to main stack (PSP equivalent) */
	la sp, main_stack_top
	lw sp, 0(sp)

	/* Enable interrupts */
	csrsi mstatus, 0x8

	/* Jump to c main */
	jal main

sleep:
	wfi
	j sleep

	.section .text
	.weak early_trap_vector
	.type early_trap_vector, %function
	.align 2
early_trap_vector:
	csrr t0, mcause
	csrr t1, mepc
	csrr t2, mtval
	j early_trap_vector

	.end
