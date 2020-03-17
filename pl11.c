/* -*- mode: c; c-basic-offset: 8; tab-width: 8; indent-tabs-mode: t -*- */

#include "mmio.h"

/**
 *  https://github.com/ARM-software/arm-trusted-firmware/blob/v2.2/drivers/arm/pl011/aarch64/pl011_console.S
 *  https://github.com/ARM-software/arm-trusted-firmware/blob/v2.2/include/drivers/arm/pl011.h
 */
#define PL011_BASE		0x09000000UL
#define PL011_UARTDR		0x000
#define PL011_UARTFR		0x018
#define PL011_UARTFR_TXFF_BIT	5

int putchar(int c) {
	if (c == '\n') {
		putchar('\r');
	}

	/* while (mmio_read32(PL011_BASE + PL011_UARTFR) & 0x20) ; */
	mmio_write32(PL011_BASE + PL011_UARTDR, c);
	return c;
}
