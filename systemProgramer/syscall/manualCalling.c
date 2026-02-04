#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

int
main() {

  pid_t pid;

  pid = syscall(SYS_getpid);

  printf("PID: %d\n", pid);

  syscall(SYS_alarm,5);
  syscall(SYS_pause);

  syscall(SYS_exit,0);
}
