#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../kernel/pstat.h"
#include "user.h"

int main(int argc, char const *argv[]) {
  // printf("My first xv6 program!\n");
  // printf("I implemented my own system call: the current year is %d\n", getyear());
  // struct pstat *ps = malloc(sizeof(struct pstat));
  // getpinfo(ps);

  int pid = fork();
  if (pid < 0) {
    printf("failed 1\n");
  } else if (pid == 0) {
    for (int j = 0; j < 1000; j++) printf("");
    printf("\nChild 1 Done\n");
    exit(0);
  }

  int pid2 = fork();
  if (pid2 < 0) {
    printf("failed 2\n");
  } else if (pid2 == 0) {
    for (int j = 0; j < 1000; j++) printf("");
    printf("\nChild 2 Done\n");
    exit(0);
  }

  wait(&pid);
  wait(&pid2);
  printf("parent done!\n");

  return 0;
}

