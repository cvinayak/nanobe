	.section .text.entry
	.globl _start
_start:
	.option push
	.option norelax
	/* Initialise global pointer */
	la gp, __global_pointer$
	.option pop

	/* Initialise stack pointer */
	la sp, _sp
	add s0, sp, zero

	/* Setup an early trap routine */
	la t0, early_trap_vector
	csrw mtvec, t0
	csrw mcause, x0

	/* Disable Software, Timer and External interrupt */
	li t0, 0x888
	csrrc zero, mie, t0

.ifdef TEST_IRQ
	/* Machine Interrupt Enable */
	li t0, 0x8
	csrrs zero, mstatus, t0
.endif /* TEST_IRQ */

.ifdef TEST_SWI
	/* Software Interrupt Enable */
	li t0, 0x8
	csrrs zero, mie, t0

	/* Software Interrupt Pend */
	li t0, 0x02000000
	li t1, 0x1
	sw t1, 0(t0)
.endif /* TEST_SWI */

	/* TODO: Jump to _soc_init */
soc_init_return:

	/* TODO: Load data memory */

	/* TODO: Zero bss memory */

	/* Switch to User Mode? */
	lla t0, 1f
	csrw mepc, t0
	mret

1:
	/* Branch to main */
	jal main

sleep:
	jal _cpu_sleep
	j sleep

	.globl _cpu_sleep
_cpu_sleep:
	wfi
	ret

	.section .text
	.align 2
	.type early_trap_vector, %function
	.weak early_trap_vector
early_trap_vector:
	csrrw sp, mscratch, sp /* Save current sp in mscratch register */
	csrr t0, mcause /* Read the machine cause register */
	csrr t1, mepc   /* Read the machine exception current PC */
	csrr t2, mtval  /* Read the machine trap value */
	bltz t0, interrupt_handler
	j exception_handler

exception_handler:
	j exception_loop

exception_loop:
.ifdef TEST_SWI
	/* Software Interrupt Clear */
	li t0, 0x02000000
	li t1, 0x0
	sw t1, 0(t0)
.endif /* TEST_SWI */

	jal machine_exception
	wfi
	j exception_loop

interrupt_handler:
	j interrupt_loop

interrupt_loop:
	jal machine_interrupt
	wfi
	j interrupt_loop

	/* Dummy Exception Handlers (weak) */

	.weak   machine_exception
	.type   machine_exception, %function
machine_exception:
	j       .

	.weak   machine_interrupt
	.type   machine_interrupt, %function
machine_interrupt:
	j       .

	.section .isr_return, "ax"
	.align 2
	.globl __isr_return
__isr_return:
	mret

	.section .int_vector, "ax"
	.type vector, %object
	.balign 64
	.globl interrupt_vector
interrupt_vector:
	.word interrupt_handler_0
	.word interrupt_handler_1
	.word interrupt_handler_2

interrupt_handle_0:
	mret

interrupt_handle_1:
	mret

interrupt_handle_2:
	mret

	.section .noinit
	.align 4
	.fill 256, 1, 0
_sp:
	.end
