.global _reset
.global __stack_end__
_reset:	ldr	x0, =__stack_end__
	mov	sp, x0
	bl	main
	bl	.
