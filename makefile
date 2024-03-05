NANOBE_BASE = $(shell pwd)
export NANOBE_BASE

ifeq ($(BOARD), HiFive1)
	SOC = fe310

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/HiFive1 \

else ifeq ($(BOARD), nrf54l15dk_nrf54l15_cpuvpr)
	SOC = nrf54l15_cpuvpr

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf54l15dk_nrf54l15 \

else ifeq ($(BOARD), nrf54l15dk_nrf54l15_cpuapp)
	SOC = nrf54l15_cpuapp

	ASFLAGS = \

	CFLAGS = \
		-DCONFIG_BOARD_NRF54L15DK_NRF54L15_CPUAPP \
		-DCONFIG_GRTC \

	INCLUDES = \
		-I board/nrf54l15dk_nrf54l15 \

else ifeq ($(BOARD), nrf5340dk_nrf5340_cpuapp)
	SOC = nrf5340_cpuapp

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf5340dk_nrf5340 \

else ifeq ($(BOARD), nrf5340dk_nrf5340_cpunet)
	SOC = nrf5340_cpunet

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf5340dk_nrf5340 \

else ifeq ($(BOARD), nrf52840dongle_nrf52840)
	SOC = nrf52840

	FLASH_START = 0x00001000
	FLASH_SIZE  = 0x000ff000
	RAM_START   = 0x20000008
	RAM_SIZE    = 0x0003fff8

	ASFLAGS = \

	CFLAGS = \
		-DDEBUG=1 \

	INCLUDES = \
		-I board/nrf52840dongle_nrf52840 \

else ifeq ($(BOARD), nrf52840dk_nrf52840)
	SOC = nrf52840

	FLASH_START = 0x00000000
	FLASH_SIZE  = 0x00100000
	RAM_START   = 0x20000000
	RAM_SIZE    = 0x00040000

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf52840dk_nrf52840 \

else ifeq ($(BOARD), nrf52dk_nrf52832)
	SOC = nrf52832

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf52dk_nrf52832 \

else ifeq ($(BOARD), nrf51dk_nrf51822)
	SOC = nrf51822

	ASFLAGS = \

	CFLAGS = \

	INCLUDES = \
		-I board/nrf51dk_nrf51822 \

endif

ifeq ($(SOC), fe310)
	ARCH = riscv

	FLASH_START = 0x20000000
	FLASH_SIZE  = 0x00020000
	RAM_START   = 0x80000000
	RAM_SIZE    = 0x00004000

	ASFLAGS += \
		-mabi=ilp32 \
		-march=rv32imac_zicsr \

	CFLAGS += \
		-mabi=ilp32 \
		-march=rv32imac_zicsr \

	SRCS_HAL_FE310 = \
		hal/fe310/gpio.c \

	SRCS_HAL = $(SRCS_HAL_FE310)

else ifeq ($(SOC), nrf54l15_cpuvpr)
	ARCH = riscv

	FLASH_START = 0x00100000
	FLASH_SIZE  = 0x00080000
	RAM_START   = 0x20020000
	RAM_SIZE    = 0x00020000

	ASFLAGS += \
		-mabi=ilp32e \
		-march=rv32emc_zicsr_zifencei \

	CFLAGS += \
		-mabi=ilp32e \
		-march=rv32emc_zicsr_zifencei \
		-DNRF54L15_ENGA_XXAA \
		-DNRF_FLPR \

	ASMS_SOC_NRF5 = \

	SRCS_SOC_NRF5 = \

	SRCS_HAL_NRF5 = \
		hal/nrf5/gpio.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf54l15_cpuapp)
	ARCH = arm

	FLASH_START = 0x00000000
	FLASH_SIZE  = 0x00100000
	RAM_START   = 0x20000000
	RAM_SIZE    = 0x00020000

	ASFLAGS += \
		-mcpu=cortex-m33 \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m33 \
		-mthumb \
		-DNUM_IRQS=271 \
		-DNRF54L15_ENGA_XXAA \
		-DNRF_APPLICATION \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf5340_cpuapp)
	ARCH = arm

	FLASH_START = 0x00000000
	FLASH_SIZE  = 0x00100000
	RAM_START   = 0x20000000
	RAM_SIZE    = 0x00080000

	ASFLAGS += \
		-mcpu=cortex-m33 \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m33 \
		-mthumb \
		-DNUM_IRQS=69 \
		-DNRF5340_XXAA_APPLICATION \
		-DNRF5340_CPUNET_ON \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf5340_cpunet)
	ARCH = arm

	FLASH_START = 0x01000000
	FLASH_SIZE  = 0x00040000
	RAM_START   = 0x21000000
	RAM_SIZE    = 0x00010000

	ASFLAGS += \
		-mcpu=cortex-m33+nodsp \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m33+nodsp \
		-mthumb \
		-DNUM_IRQS=30 \
		-DNRF5340_XXAA_NETWORK \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf52840)
	ARCH = arm

	ASFLAGS += \
		-mcpu=cortex-m4 \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m4 \
		-mthumb \
		-DNUM_IRQS=48 \
		-DNRF52840_XXAA \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf52832)
	ARCH = arm

	FLASH_START = 0x00000000
	FLASH_SIZE  = 0x00040000
	RAM_START   = 0x20000000
	RAM_SIZE    = 0x00004000

	ASFLAGS += \
		-mcpu=cortex-m4 \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m4 \
		-mthumb \
		-DNUM_IRQS=37 \
		-DNRF52832_XXAB \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

else ifeq ($(SOC), nrf51822)
	ARCH = arm

	FLASH_START = 0x00000000
	FLASH_SIZE  = 0x00020000
	RAM_START   = 0x20000000
	RAM_SIZE    = 0x00004000

	ASFLAGS += \
		-mcpu=cortex-m0 \
		-mthumb

	CFLAGS += \
		-mcpu=cortex-m0 \
		-mthumb \
		-DNUM_IRQS=32 \
		-DNRF51_SERIES \
		-DNRF51 \

	ASMS_SOC_NRF5 = \
		soc/nrf5/soc.s \

	SRCS_SOC_NRF5 = \
		soc/nrf5/soc_c.c \

	SRCS_HAL_NRF5 = \
		hal/nrf5/ticker.c \
		hal/nrf5/cntr.c \
		hal/nrf5/clock.c \
		hal/nrf5/mayfly.c \
		hal/nrf5/gpio.c \
		hal/nrf5/timer.c \
		hal/nrf5/uart.c \

	ASMS_SOC = $(ASMS_SOC_NRF5)
	SRCS_SOC = $(SRCS_SOC_NRF5)
	SRCS_HAL = $(SRCS_HAL_NRF5)

	INCLUDES += \
		-I ext/nordic/include \
		-I soc/nrf5 \

endif

ifeq ($(ARCH), riscv)
  ASMS_COMMON = \
	arch/riscv/startup.s \

  ASMS_NANOBE = \

  INCLUDES += \
	-I . \

else ifeq ($(ARCH), arm)
  ASMS_COMMON = \
	arch/arm/cortex_m/startup.s \
	arch/arm/cortex_m/soc.s \

  ASMS_NANOBE = \
	arch/arm/cortex_m/nanobe.s \
	arch/arm/cortex_m/pendsv_ninject.s \

  INCLUDES += \
	-I ext/arm/cmsis/include \
	-I arch/arm/cortex_m \
	-I . \

endif

SRCS_NANOBE = \
	nanobe/isr_table.c \
	nanobe/nanobe_sched.c \

SRCS_UTIL = \
	util/util.c \
	util/dbuf.c \
	util/mem.c \
	util/memq.c \
	util/mayfly.c \
	ticker/ticker.c \

ASMS_APP_METAL = \
	$(ASMS_COMMON) \
	$(ASMS_SOC) \

SRCS_APP_METAL = \
	$(SRCS_SOC) \
	$(SRCS_HAL) \
	app/app_metal.c \

OBJS_APP_METAL = $(ASMS_APP_METAL:.s=.o) $(SRCS_APP_METAL:.c=.o)
ASMS += $(ASMS_APP_METAL)
SRCS += $(SRCS_APP_METAL)
TARGETS += app/app_metal.elf

ifeq ($(ARCH), arm)
  ASMS_APP_PROFILE = \
	$(ASMS_COMMON) \
	$(ASMS_NANOBE) \
	$(ASMS_SOC_NRF5) \

  SRCS_APP_PROFILE = \
	$(SRCS_NANOBE) \
	$(SRCS_SOC_NRF5) \
	$(SRCS_HAL_NRF5) \
	$(SRCS_UTIL) \
	app/app_profile.c \

  INCLUDES += \
	-I nanobe \

  OBJS_APP_PROFILE = $(ASMS_APP_PROFILE:.s=.o) $(SRCS_APP_PROFILE:.c=.o)
  ASMS += $(ASMS_APP_PROFILE)
  SRCS += $(SRCS_APP_PROFILE)
  TARGETS += app/app_profile.elf

  ASMS_APP_MAYFLY = \
	$(ASMS_COMMON) \
	$(ASMS_NANOBE) \
	$(ASMS_SOC_NRF5) \

  SRCS_APP_MAYFLY = \
	$(SRCS_NANOBE) \
	$(SRCS_SOC_NRF5) \
	$(SRCS_HAL_NRF5) \
	$(SRCS_UTIL) \
	app/app_mayfly.c \

  OBJS_APP_MAYFLY = $(ASMS_APP_MAYFLY:.s=.o) $(SRCS_APP_MAYFLY:.c=.o)
  ASMS += $(ASMS_APP_MAYFLY)
  SRCS += $(SRCS_APP_MAYFLY)
  TARGETS += app/app_mayfly.elf

  ASMS_APP_TICKER = \
	$(ASMS_COMMON) \
	$(ASMS_NANOBE) \
	$(ASMS_SOC_NRF5) \

  SRCS_APP_TICKER = \
	$(SRCS_NANOBE) \
	$(SRCS_SOC_NRF5) \
	$(SRCS_HAL_NRF5) \
	$(SRCS_UTIL) \
	app/app_ticker.c \

  CFLAGS_APP_TICKER = \
	-DDEBUG=1 \
	-DCONFIG_BT_TICKER_LOW_LAT \

  OBJS_APP_TICKER = $(ASMS_APP_TICKER:.s=.o) $(SRCS_APP_TICKER:.c=.o)
  ASMS += $(ASMS_APP_TICKER)
  SRCS += $(SRCS_APP_TICKER)
  TARGETS += app/app_ticker.elf
endif


all : $(TARGETS)

all : CFLAGS += $(CFLAGS_APP_TICKER)


app/app_metal.elf : $(OBJS_APP_METAL)

app/app_profile.elf : $(OBJS_APP_PROFILE)

app/app_mayfly.elf : $(OBJS_APP_MAYFLY)


app/app_ticker.elf : CFLAGS += $(CFLAGS_APP_TICKER)

app/app_ticker.elf : $(OBJS_APP_TICKER)

include makefile.inc
