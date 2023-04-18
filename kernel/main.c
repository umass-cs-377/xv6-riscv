#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"

// This is used as a synchronization variable.
volatile static int started = 0;

// start() jumps here in supervisor mode on all CPUs.
void main() {
  if (cpuid() == 0) {
    consoleinit();
    printfinit();
    printf("\n");
    printf("xv6 kernel is booting\n");
    printf("\n");
    kinit();    // physical page allocator
    kvminit();  // create kernel page table
    kvminithart();   // turn on paging
    procinit();      // process table
    trapinit();      // trap vectors
    trapinithart();  // install kernel trap vector
    plicinit();      // set up interrupt controller
    plicinithart();  // ask PLIC for device interrupts
    binit();         // buffer cache
    iinit();         // inode table
    fileinit();          // file table
    virtio_disk_init();  // emulated hard disk
    userinit();          // first user process

    // https://stackoverflow.com/questions/982129/what-does-sync-synchronize-do
    // This basically ensures that the compiler does not move the assignment
    // to started anywhere. In short, everything above is done and saved in
    // memory before setting the `started` variable to 1. This is a compiler
    // thing.
    __sync_synchronize();
    started = 1;

  } else {
    // All other harts spin until hart 0 is finished initializing above.
    while (started == 0)
      ;
    __sync_synchronize();

    printf("hart %d starting\n", cpuid());
    kvminithart();   // turn on paging
    trapinithart();  // install kernel trap vector
    plicinithart();  // ask PLIC for device interrupts
  }

  scheduler();
}
