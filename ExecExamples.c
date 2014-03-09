#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int
main(int argc, char* argv[], char *env[]) {

  pid_t pid;
  int status;

  if ((pid = fork()) == 0) { /* Hijo */
    execl("ls", "ls", "-l", "/tmp", NULL);
    return 1;
  }
  wait(&status);
  printf("WIFEXISTED(status)=%d\n", WIFEXITED(status));
  if (WIFEXITED(status) == 0) {
    return 1;
  } 
  else {
    return 0;
  }
}
