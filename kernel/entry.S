        # qemu -kernel loads the kernel at 0x80000000
        # and causes each hart (i.e. CPU) to jump there.
        # kernel.ld causes the following code to
        # be placed at 0x80000000.
.section .text
.global _entry
_entry:
        # set up a stack for C.
        # stack0 is declared in start.c,
        # with a 4096-byte stack per CPU.
        # sp = stack0 + (hartid * 4096)
        
        la sp, stack0                   # load address of stack0 into sp
        li a0, 1024*4                   # load a0 with the value 4096
        csrr a1, mhartid                # copy thread ID from CSR into a1
        addi a1, a1, 1                  # increment thread ID (to compute index)
        mul a0, a0, a1                  # compute index into start0
        add sp, sp, a0                  # set CPU local sp to stack start addr
        # jump to start() in start.c
        call start
spin:
        j spin
