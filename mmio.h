/* -*- mode: c; c-basic-offset: 8; tab-width: 8; indent-tabs-mode: t -*- */

#ifndef __MMIO_H__
#define __MMIO_H__

static inline unsigned int mmio_read32(unsigned long addr) {
	return *(volatile unsigned int *)addr;
}

static inline void mmio_write32(unsigned long addr, unsigned int value) {
	*(volatile unsigned int *)addr = value;
}

#endif
