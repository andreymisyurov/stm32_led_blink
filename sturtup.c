extern void *_estack;
extern void *_sidata, *_sdata, *_edata, *_sbss, *_ebss;

void Reset_Handler();
void Default_Handler();
int  main();

void NMI_Handler()                    __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler()              __attribute__ ((weak, alias ("Default_Handler")));

void *vectors[] __attribute__((section(".isr_vector"), used)) = {
    &_estack,
	&Reset_Handler,
	&NMI_Handler,
	&HardFault_Handler
};

void __attribute__((naked, noreturn)) Reset_Handler() {

    // copy data from ROM to SRAM
	void **pSource, **pDest;
	for (pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++)
		*pDest = *pSource;

    // zeroing data in the bss block
	for (pDest = &_sbss; pDest != &_ebss; pDest++)
		*pDest = 0;

    main();

	while(1);
}

void __attribute__((naked, noreturn)) Default_Handler() {
    while(1);
}
