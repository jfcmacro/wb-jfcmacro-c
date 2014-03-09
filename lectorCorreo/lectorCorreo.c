#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM_BUFFER 256

void
leerCopiar(int fd1, int fd2) {

  char buffer[TAM_BUFFER];
  int nCarLeidos = 0;

  do {
    nCarLeidos = read(fd1, buffer, TAM_BUFFER);

    if (nCarLeidos > 0) 
      write(fd2, buffer, nCarLeidos);
  } while (nCarLeidos == TAM_BUFFER); 
}

int
main(int argc, char *argv[]) {
  
  int ret;
  int fd[2];
  
  if (pipe(fd) < 0) {
    fprintf(stderr, "No se pudo crear las tuberias: %d %s",
	    errno, strerror(errno));
    exit(1);
  }
  
  ret = fork();

  if (ret == -1) {

    fprintf(stderr, "Error abriendo realizando fork: %d %s",
	    errno, strerror(errno));
    exit(1);
  }
 
  if (ret == 0) {
    
    close(1);
    dup2(fd[1], 1);
    close(fd[1]);
    close(fd[0]);
    
    execl("/usr/bin/ssh", "ssh", "fcardona@sigma", "./lectorCorreoEnSolaris", 
	  NULL);
    fprintf(stderr, "No se pudo abrir la conexión a red %d %s\n",
	    errno, strerror(errno));
    exit(1);

  }
  else {
    int status;
    int fileFd;
    struct flock f_lock;

    close(fd[1]);

    fileFd = open("/var/mail/fcardona", O_APPEND | O_RDWR);

    if (fileFd < 0) {
      fprintf(stderr, "No se pudo abrir archivo de salida\n", 
	      errno, strerror(errno));
      exit(1);
    }

    f_lock.l_start = (off_t) 0;
    f_lock.l_len = (off_t) 0;
    f_lock.l_type = F_WRLCK;
    f_lock.l_whence = SEEK_SET;
    
    if (fcntl(fileFd, F_SETLKW, &f_lock) < 0) {
      fprintf(stderr, "No se pudo establecer cerrojo: %d %s\n",
	      errno, strerror(errno));

      close(fd[0]);
      close(fileFd);
      return 0;
    }

    leerCopiar(fd[0], fileFd);

    close(fd[0]);
    close(fileFd);

    if (WIFEXITED(status) != 0) {
      fprintf(stderr, "Error ejecutando el hijo %d\n",
	      WIFEXITED(status));
      exit(1);
    }

  }
  return 0;
}
