OUTPUT_ARCH( "riscv" )
ENTRY( _entry )

SECTIONS
{
  /*
   * ensure that entry.S / _entry is at 0x80000000,
   * where qemu's -kernel jumps.
   */
  . = 0x80000000;

  .text : {
    *(.text .text.*).  /* map text segments to text */
    . = ALIGN(0x1000); /* align on a 4K boundary */
    _trampoline = .;   /* the trampoline part occurs after the text */
    *(trampsec).       /* HUH: not sure what this is */
    . = ALIGN(0x1000); /* again, align on 4K boundary */
    ASSERT(. - _trampoline == 0x1000, "error: trampoline larger than one page");

    /* 
     * I believe this "provides" a symbol to the location right after the
     * text segment in the kernel.
    PROVIDE(etext = .);
  }

  .rodata : {
    . = ALIGN(16);
    *(.srodata .srodata.*) /* do not need to distinguish this from .rodata */
    . = ALIGN(16);
    *(.rodata .rodata.*)
  }

  .data : {
    . = ALIGN(16);
    *(.sdata .sdata.*) /* do not need to distinguish this from .data */
    . = ALIGN(16);
    *(.data .data.*)
  }

  .bss : {
    . = ALIGN(16);
    *(.sbss .sbss.*) /* do not need to distinguish this from .bss */
    . = ALIGN(16);
    *(.bss .bss.*)
  }

  PROVIDE(end = .);
}
