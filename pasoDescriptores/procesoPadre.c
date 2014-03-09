#include <unistd.h>
#include <stropts.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int
main() {

  int tuberia[2];
  int archivo;
  int status;

  if (pipe(tuberia) < 0) {
    perror("pipe");
    exit(1);
  }

  if (fork() == 0) {
    struct strrecvfd recv;

    char mensaje[] = "Este es un nuevo mensaje";


    close(tuberia[1]);
    close(0);
    dup2(tuberia[0], 0);
    close(tuberia[0]);

    fprintf(stderr, "Sizeof: %d %d\n", 
	    sizeof(mensaje), strlen(mensaje));
     
    if (ioctl(tuberia[0], I_RECVFD, &recv) < 0) {
      perror("child ioctl");
      exit(1);
    }

    write(recv.fd, mensaje, strlen(mensaje));

    close(recv.fd);
    exit(0);
  }
  else {
    
    close(tuberia[0]);

    if ((archivo = open("/tmp/datos", O_CREAT | O_WRONLY | O_TRUNC | 0600)) < 0) {
      perror("open");
      exit(1);
    }
    
    if (ioctl(tuberia[1], I_SENDFD, archivo) < 0) {
      perror("father: ioctl");
      exit(1);
    }

    wait(&status);
    exit(0);
  }
} 
