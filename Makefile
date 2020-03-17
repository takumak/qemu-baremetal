CROSS_COMPILE = aarch64-linux-gnu-
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld

CFLAGS = -Wall -Wextra -Werror -Wno-main -nostdlib -fno-builtin -mcpu=cortex-a53 -mgeneral-regs-only
LDFLAGS =

.SUFFIXES: .elf .bin
.PHONY: all clean

all: image.bin

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.s.o:
	$(AS) -g $< -o $@

image.elf: startup.o pl11.o printf.o main.o
	$(LD) $(LDFLAGS) -Map image.map -T link.ld $^ -o $@

.elf.bin:
	$(CROSS_COMPILE)objcopy -O binary $< $@

clean:
	rm -f *.o *.elf *.bin
