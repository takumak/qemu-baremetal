SECTIONS
{
	. = 0x40080000;
	.text	: {*(.text*)}
	.rodata	: {
		*(.strings*)
		*(.rodata*)
		*(.rodata.*)
	}
	.data	: {*(.data*)}
	.bss	: {*(.bss*)}
	.stack	: {
		__stack_start__ = .;
		*(.stack)
		__stack_end__ = .;
	}
}
