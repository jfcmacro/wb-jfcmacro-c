#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define TAM_BUFFER 256

int
main(int argc, char *argv[]) {
  
  int ret;
  int fd[2];

  ret = fork();

  if (ret == -1) {

    fprintf(stderr, "Error abriendo realizando fork: %d %s",
	    errno, strerror(errno));
    exit(1);
  }
  
  if (ret == 0) {
    
    execl("/usr/bin/ssh", "ssh", "fcardona@sigma", "cat", 
	  "/var/mail/fcardona", NULL);
    fprintf(stderr, "No se pudo abrir la conexión a red %d %s\n",
	    errno, strerror(errno));
    exit(1);

  }
  else {
    int status;

    wait(&status);

    if (!WIFEXITED(status)) {
      fprintf(stderr, "Error ejecutando el hijo %d\n",
	      WIFEXITED(status));
      exit(1);
    }
  }
}
