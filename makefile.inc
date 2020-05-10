ifeq ($(ARCH), riscv)
	include $(NANOBE_BASE)/makefile.riscv
else ifeq ($(ARCH), arm)
	include $(NANOBE_BASE)/makefile.arm
endif

ASFLAGS += \

CFLAGS += \
	-Os \
	-nostdlib \
	-ffreestanding \
	-fdata-sections \
	-ffunction-sections \
	-flto \
	-g \
	-Wall \
	-Wextra \
	-Wcast-align \
	-I ./ \
	$(INCLUDES) \
	-DVERSION=\"$(VERSION)\" \

OBJS += $(SRCS:.c=.o) $(ASMS:.s=.o)
DEPS += $(SRCS:.c=.d) $(ASMS:.s=.d)

VERSION = $(shell git rev-parse --short HEAD)

all : $(TARGETS)

info :
	@echo NANOBE_BASE = $(NANOBE_BASE)
	@echo TARGETS = $(TARGETS)
	@echo ASFLAGS = $(ASFLAGS)
	@echo CFLAGS = $(CFLAGS)
	@echo OBJS = $(OBJS)
	@echo DEPS = $(DEPS)

$(TARGETS) :
	$(CC) $(CFLAGS) -Wl,--gc-sections,--defsym=FLASH_ORIGIN=$(FLASH_START),--defsym=FLASH_LENGTH=$(FLASH_SIZE),--defsym=RAM_ORIGIN=$(RAM_START),--defsym=RAM_LENGTH=$(RAM_SIZE),--script=$(LDSCRIPT),-Map=$(basename $@).map -o $@ $^ -lgcc
	$(OBJDUMP) $(OBJDUMP_FLAGS) -D -S $@ > $(basename $@).lst
	$(OBJCOPY) -O ihex $@ $(basename $@).hex
	$(OBJCOPY) -O binary $@ $(basename $@).bin
	$(SIZE) $@

%.s : %.S
	$(CC) $(CFLAGS) -E $< > $@

%.d : %.s
	@echo Dependencies for $<
	$(AS) $(ASFLAGS) --MD $@ -o $(@:.d=.o) $<

%.o : %.s
	@echo Assembly for $<
	$(AS) $(ASFLAGS) -o $@ $<

%.d : %.c
	@echo Dependencies for $<
	$(CC) $(CFLAGS) -M -o $@ $<

%.o : %.c
	@echo Compilation for $<
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(DEPS) $(OBJS) $(TARGETS) $(TARGETS:.elf=.map) $(TARGETS:.elf=.hex) $(TARGETS:.elf=.bin) $(TARGETS:.elf=.lst)

.PHONY : all info clean

-include $(DEPS)
