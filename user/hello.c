#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int main(int argc, char const *argv[]) {
  printf("My first xv6 program!\n");
  printf("I implemented my own system call: the current year is %d\n", getyear());
  return 0;
}

