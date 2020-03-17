/* -*- mode: c; c-basic-offset: 8; tab-width: 8; indent-tabs-mode: t -*- */

__attribute__ ((section (".stack")))
__attribute__((unused))
static char stack[1024*1024];

int printf(const char *fmt, ...);
int putchar(int);

void semihosting_putc(int c) {
	asm volatile (
		"mov	x1, %0\n\t"
		"mov	x0, #3\n\t"
		"hlt	0xf000\n\t"
		:
		: "r" (&c)
		: "x0", "x1", "memory"
	);
}

void semihosting_shutdown() {
	asm volatile (
		"mov	w0, 0x18\n"
		"mov	x1, #0x20000\n"
		"add	x1, x1, #0x26\n"
		"hlt	#0xF000\n"
		:
		:
		: "x0", "x1", "memory"
	);
}

void main() {
	printf("Hello world!\n");
	semihosting_shutdown();
}
