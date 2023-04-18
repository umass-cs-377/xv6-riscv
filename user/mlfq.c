#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
#include "../kernel/fcntl.h"
#include <stddef.h>
//#include<stdlib.h>
//#include<sys/wait.h>
//#include<unistd.h>


int main() {
 int rc[2] = {fork(),fork()};
 if (rc[0] > 0 && rc[1] > 0) {
   wait(NULL);
   wait(NULL);
   wait(NULL);
   printf("%d\n", 4);
 } else if (rc[0] == 0 && rc[1] > 0) {
   wait(NULL);
   wait(NULL);
   printf("%d\n", 3);
 } else if (rc[0] > 0 && rc[1] == 0) {
   printf("%d\n", 1);
 }
 else {
   wait(NULL);
   printf("%d\n", 2);
 }
 return 0;
}



