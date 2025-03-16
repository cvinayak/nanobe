#ifndef __ASSEMBLY__
	#define __ASSEMBLY__
#endif
#include "core_vpr.h"

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

	/* Setup interrupt vector */
	la t0, interrupt_vector
	csrw CSR_MTVT, t0

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
	.long   UserSoftware_Handler
	.long   SuperVisorSoftware_Handler
	.long   MachineSoftware_Handler
	.long   0                           /*Reserved */
	.long   UserTimer_Handler
	.long   SuperVisorTimer_Handler
	.long   0                           /*Reserved */
	.long   MachineTimer_Handler
	.long   UserExternal_Handler
	.long   SuperVisorExternal_Handler
	.long   0                           /*Reserved */
	.long   MachineExternal_Handler
	.long   CLICSoftware_Handler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */

	/* External Interrupts */
	.long   VPRCLIC_0_IRQHandler
	.long   VPRCLIC_1_IRQHandler
	.long   VPRCLIC_2_IRQHandler
	.long   VPRCLIC_3_IRQHandler
	.long   VPRCLIC_4_IRQHandler
	.long   VPRCLIC_5_IRQHandler
	.long   VPRCLIC_6_IRQHandler
	.long   VPRCLIC_7_IRQHandler
	.long   VPRCLIC_8_IRQHandler
	.long   VPRCLIC_9_IRQHandler
	.long   VPRCLIC_10_IRQHandler
	.long   VPRCLIC_11_IRQHandler
	.long   VPRCLIC_12_IRQHandler
	.long   VPRCLIC_13_IRQHandler
	.long   VPRCLIC_14_IRQHandler
	.long   VPRCLIC_15_IRQHandler
	.long   VPRCLIC_16_IRQHandler
	.long   VPRCLIC_17_IRQHandler
	.long   VPRCLIC_18_IRQHandler
	.long   VPRCLIC_19_IRQHandler
	.long   VPRCLIC_20_IRQHandler
	.long   VPRCLIC_21_IRQHandler
	.long   VPRCLIC_22_IRQHandler
	.long   VPRCLIC_23_IRQHandler
	.long   VPRCLIC_24_IRQHandler
	.long   VPRCLIC_25_IRQHandler
	.long   VPRCLIC_26_IRQHandler
	.long   VPRCLIC_27_IRQHandler
	.long   VPRCLIC_28_IRQHandler
	.long   VPRCLIC_29_IRQHandler
	.long   VPRCLIC_30_IRQHandler
	.long   VPRCLIC_31_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SPU00_IRQHandler
	.long   MPC00_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   AAR00_CCM00_IRQHandler
	.long   ECB00_IRQHandler
	.long   CRACEN_IRQHandler
	.long   0                           /*Reserved */
	.long   SERIAL00_IRQHandler
	.long   RRAMC_IRQHandler
	.long   VPR00_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   CTRLAP_IRQHandler
	.long   0                           /*Reserved */
	.long   CM33SS_IRQHandler
	.long   TIMER00_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   ECCRAMC_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SPU10_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   TIMER10_IRQHandler
	.long   0                           /*Reserved */
	.long   EGU10_IRQHandler
	.long   AAR10_CCM10_IRQHandler
	.long   ECB10_IRQHandler
	.long   RADIO_0_IRQHandler
	.long   RADIO_1_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SPU20_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SERIAL20_IRQHandler
	.long   SERIAL21_IRQHandler
	.long   SERIAL22_IRQHandler
	.long   EGU20_IRQHandler
	.long   TIMER20_IRQHandler
	.long   TIMER21_IRQHandler
	.long   TIMER22_IRQHandler
	.long   TIMER23_IRQHandler
	.long   TIMER24_IRQHandler
	.long   0                           /*Reserved */
	.long   PDM20_IRQHandler
	.long   PDM21_IRQHandler
	.long   PWM20_IRQHandler
	.long   PWM21_IRQHandler
	.long   PWM22_IRQHandler
	.long   SAADC_IRQHandler
	.long   NFCT_IRQHandler
	.long   TEMP_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   GPIOTE20_0_IRQHandler
	.long   GPIOTE20_1_IRQHandler
	.long   TAMPC_IRQHandler
	.long   I2S20_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   QDEC20_IRQHandler
	.long   QDEC21_IRQHandler
	.long   GRTC_0_IRQHandler
	.long   GRTC_1_IRQHandler
	.long   GRTC_2_IRQHandler
	.long   GRTC_3_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SPU30_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   SERIAL30_IRQHandler
	.long   CLOCK_POWER_IRQHandler
	.long   COMP_LPCOMP_IRQHandler
	.long   0                           /*Reserved */
	.long   WDT30_IRQHandler
	.long   WDT31_IRQHandler
	.long   0                           /*Reserved */
	.long   0                           /*Reserved */
	.long   GPIOTE30_0_IRQHandler
	.long   GPIOTE30_1_IRQHandler
	.size   interrupt_vector, . - interrupt_vector

	.section .text

	/* Dummy Exception Handlers (infinite loops which can be modified) */

	.weak   UserSoftware_Handler
	.type   UserSoftware_Handler, %function
UserSoftware_Handler:
	j       .
	.size   UserSoftware_Handler, . - UserSoftware_Handler


	.weak   SuperVisorSoftware_Handler
	.type   SuperVisorSoftware_Handler, %function
SuperVisorSoftware_Handler:
	j       .
	.size   SuperVisorSoftware_Handler, . - SuperVisorSoftware_Handler


	.weak   MachineSoftware_Handler
	.type   MachineSoftware_Handler, %function
MachineSoftware_Handler:
	j       .
	.size   MachineSoftware_Handler, . - MachineSoftware_Handler


	.weak   UserTimer_Handler
	.type   UserTimer_Handler, %function
UserTimer_Handler:
	j       .
	.size   UserTimer_Handler, . - UserTimer_Handler


	.weak   SuperVisorTimer_Handler
	.type   SuperVisorTimer_Handler, %function
SuperVisorTimer_Handler:
	j       .
	.size   SuperVisorTimer_Handler, . - SuperVisorTimer_Handler


	.weak   MachineTimer_Handler
	.type   MachineTimer_Handler, %function
MachineTimer_Handler:
	j       .
	.size   MachineTimer_Handler, . - MachineTimer_Handler


	.weak   UserExternal_Handler
	.type   UserExternal_Handler, %function
UserExternal_Handler:
	j       .
	.size   UserExternal_Handler, . - UserExternal_Handler


	.weak   SuperVisorExternal_Handler
	.type   SuperVisorExternal_Handler, %function
SuperVisorExternal_Handler:
	j       .
	.size   SuperVisorExternal_Handler, . - SuperVisorExternal_Handler


	.weak   MachineExternal_Handler
	.type   MachineExternal_Handler, %function
MachineExternal_Handler:
	j       .
	.size   MachineExternal_Handler, . - MachineExternal_Handler


	.weak   CLICSoftware_Handler
	.type   CLICSoftware_Handler, %function
CLICSoftware_Handler:
	j       .
	.size   CLICSoftware_Handler, . - CLICSoftware_Handler


	/* IRQ Handlers */

	.globl  Default_Handler
	.type   Default_Handler, %function
Default_Handler:
	j       .
	.size   Default_Handler, . - Default_Handler

	.macro  IRQ handler
	.weak   \handler
	.set    \handler, Default_Handler
	.endm

	IRQ  VPRCLIC_0_IRQHandler
	IRQ  VPRCLIC_1_IRQHandler
	IRQ  VPRCLIC_2_IRQHandler
	IRQ  VPRCLIC_3_IRQHandler
	IRQ  VPRCLIC_4_IRQHandler
	IRQ  VPRCLIC_5_IRQHandler
	IRQ  VPRCLIC_6_IRQHandler
	IRQ  VPRCLIC_7_IRQHandler
	IRQ  VPRCLIC_8_IRQHandler
	IRQ  VPRCLIC_9_IRQHandler
	IRQ  VPRCLIC_10_IRQHandler
	IRQ  VPRCLIC_11_IRQHandler
	IRQ  VPRCLIC_12_IRQHandler
	IRQ  VPRCLIC_13_IRQHandler
	IRQ  VPRCLIC_14_IRQHandler
	IRQ  VPRCLIC_15_IRQHandler
	IRQ  VPRCLIC_16_IRQHandler
	IRQ  VPRCLIC_17_IRQHandler
	IRQ  VPRCLIC_18_IRQHandler
	IRQ  VPRCLIC_19_IRQHandler
	IRQ  VPRCLIC_20_IRQHandler
	IRQ  VPRCLIC_21_IRQHandler
	IRQ  VPRCLIC_22_IRQHandler
	IRQ  VPRCLIC_23_IRQHandler
	IRQ  VPRCLIC_24_IRQHandler
	IRQ  VPRCLIC_25_IRQHandler
	IRQ  VPRCLIC_26_IRQHandler
	IRQ  VPRCLIC_27_IRQHandler
	IRQ  VPRCLIC_28_IRQHandler
	IRQ  VPRCLIC_29_IRQHandler
	IRQ  VPRCLIC_30_IRQHandler
	IRQ  VPRCLIC_31_IRQHandler
	IRQ  SPU00_IRQHandler
	IRQ  MPC00_IRQHandler
	IRQ  AAR00_CCM00_IRQHandler
	IRQ  ECB00_IRQHandler
	IRQ  CRACEN_IRQHandler
	IRQ  SERIAL00_IRQHandler
	IRQ  RRAMC_IRQHandler
	IRQ  VPR00_IRQHandler
	IRQ  CTRLAP_IRQHandler
	IRQ  CM33SS_IRQHandler
	IRQ  TIMER00_IRQHandler
	IRQ  ECCRAMC_IRQHandler
	IRQ  SPU10_IRQHandler
	IRQ  TIMER10_IRQHandler
	IRQ  EGU10_IRQHandler
	IRQ  AAR10_CCM10_IRQHandler
	IRQ  ECB10_IRQHandler
	IRQ  RADIO_0_IRQHandler
	IRQ  RADIO_1_IRQHandler
	IRQ  SPU20_IRQHandler
	IRQ  SERIAL20_IRQHandler
	IRQ  SERIAL21_IRQHandler
	IRQ  SERIAL22_IRQHandler
	IRQ  EGU20_IRQHandler
	IRQ  TIMER20_IRQHandler
	IRQ  TIMER21_IRQHandler
	IRQ  TIMER22_IRQHandler
	IRQ  TIMER23_IRQHandler
	IRQ  TIMER24_IRQHandler
	IRQ  PDM20_IRQHandler
	IRQ  PDM21_IRQHandler
	IRQ  PWM20_IRQHandler
	IRQ  PWM21_IRQHandler
	IRQ  PWM22_IRQHandler
	IRQ  SAADC_IRQHandler
	IRQ  NFCT_IRQHandler
	IRQ  TEMP_IRQHandler
	IRQ  GPIOTE20_0_IRQHandler
	IRQ  GPIOTE20_1_IRQHandler
	IRQ  TAMPC_IRQHandler
	IRQ  I2S20_IRQHandler
	IRQ  QDEC20_IRQHandler
	IRQ  QDEC21_IRQHandler
	IRQ  GRTC_0_IRQHandler
	IRQ  GRTC_1_IRQHandler
	IRQ  GRTC_2_IRQHandler
	IRQ  GRTC_3_IRQHandler
	IRQ  SPU30_IRQHandler
	IRQ  SERIAL30_IRQHandler
	IRQ  CLOCK_POWER_IRQHandler
	IRQ  COMP_LPCOMP_IRQHandler
	IRQ  WDT30_IRQHandler
	IRQ  WDT31_IRQHandler
	IRQ  GPIOTE30_0_IRQHandler
	IRQ  GPIOTE30_1_IRQHandler

	.section .noinit
	.align 4
	.fill 256, 1, 0
_sp:
	.end
