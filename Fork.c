#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int
main() {

  pid_t r;
  int status;

  r = fork();
  if (r == 0) { /* Hijo */
    int retValue;
    retValue = execl("/bin/psxx", "ps", "-l", "-a",  NULL);
    printf("%d\n", retValue);
    return retValue;
  }
  else { /* Padre */
    waitpid(r, &status, 0);
    if (WIFEXITED(status)) {
      printf("Mi hijo: %d termino con estado: %d\n", 
	     r, WEXITSTATUS(status));
    }
    else {
      printf("Mi hijo: %d termino con estado: %d\n", 
	     r, status);
    }
  }
  return 0;
}
