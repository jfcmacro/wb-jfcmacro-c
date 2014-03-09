#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/time.h>

void
noBloqueante(int fd)
{
   int on = 1;

   ioctl(fd, FIONBIO, &on);
}

void
examinarEImprimir(int c, char *buffer)
{
  extern int errno;
		 	if (c < 0) {
					  if (errno != EWOULDBLOCK) {
								 	fprintf(stderr, "Error: %d %s\n", errno, strerror(errno));
									exit(1);
						}
			} else {
					  	buffer[c] = '\0';
						printf("%s\n", buffer);
			}
}

int
main()
{
  char buffer[256];
  int c;
  int tuberia1[2];
  int tuberia2[2];

  pipe(tuberia1);
  pipe(tuberia2);

  if (fork() == 0) { // Hijo
			 close(tuberia1[0]);
			 close(tuberia2[0]);
			 close(tuberia2[1]);
			 
			 while (1) {
						sprintf(buffer, "Yo soy el hijo perdido %d del padre: %d\n", getpid(), getppid());
						write(tuberia1[1], buffer, strlen(buffer));
						sleep(3);
	       }	
  }

  if (fork() == 0) { // Hijo
			 close(tuberia2[0]);
			 close(tuberia1[0]);
			 close(tuberia1[1]);
			 
			 while (1) {
						sprintf(buffer, "Yo soy el hijo perdido %d del padre: %d\n", getpid(), getppid());
						write(tuberia2[1], buffer, strlen(buffer));
						sleep(5);
	       }	
  }

  close(tuberia1[1]);
  close(tuberia2[1]);

  noBloqueante(tuberia1[0]);
  noBloqueante(tuberia2[0]);
  noBloqueante(0);

  while (1) {

     c = read(tuberia1[0], buffer, 256);
	  examinarEImprimir(c, buffer);
	  c = read(tuberia2[0], buffer, 256);
	  examinarEImprimir(c, buffer);
	  c = read(0, buffer, 256);
  }
}
