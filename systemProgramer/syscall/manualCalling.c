#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

int
main() {

  int pid;

  pid = syscall(20);

  printf("PID: %d\n", pid);

  syscall(27,5);
  syscall(29);

  syscall(1,0);
}
