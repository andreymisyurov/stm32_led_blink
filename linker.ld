MEMORY{
	ROM(rx)    : ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = LENGTH(SRAM) + ORIGIN(SRAM);

SECTIONS{
	.isr_vector : {
	KEEP(*(.isr_vector))
	} >ROM
	
	.text : {
        . = ALIGN(4);
        *(.text)
    } >ROM

    .data : {
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	} >SRAM AT>ROM
	
	_sidata = LOADADDR(.data);

	.bss : {
		. = ALIGN(4);
		_sbss = .;
		*(.bss)
		. = ALIGN(4);
		_ebss = .;
	} >SRAM
}
