#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main() {
  pid_t process;
  pid_t curProcess;

  curProcess = getpid();

  process = setsid();
  return printf("%i %i %i\n", curProcess, process, getpid());
}
