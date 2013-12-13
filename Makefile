TEMPLATEROOT = .

# CFLAGS = -g -Wall -Wcpp -DUSE_FULL_ASSERT -D__FPU_PRESENT=1 -D__FPU_USED=1
CFLAGS   = -O2 -Wall -Wcpp -DUSE_FULL_ASSERT -D__FPU_PRESENT=1 -D__FPU_USED=1
CXXFLAGS = -fno-rtti -fno-exceptions -std=c++11 $(CFLAGS) 
# ASFLAGS  = -g
LDLIBS   =
LDSCRIPT = Source/flash.ld

C_SRC  = main.c gpio.c system_hse.c bootloader.c
OBJS =  $(C_SRC:%.c=Build/%.o)

# object files
# OBJS += $(PERIPH) 
OBJS += $(BUILD)/stm32f4xx_flash.o
OBJS += $(BUILD)/stm32f4xx_gpio.o
OBJS += $(BUILD)/stm32f4xx_rcc.o
OBJS += $(BUILD)/startup.o
# OBJS += $(BUILD)/startup_stm32f4xx.o
OBJS += $(SYSCALLS)

# include common make file
include $(TEMPLATEROOT)/Makefile.f4
