#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int
main() {

  pid_t pid;

  pid = getpid();

  printf("PID: %d\n", pid);

  alarm(5);
  pause();

  _exit(0);
  return 1;
}
