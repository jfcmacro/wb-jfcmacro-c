#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>

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
  fd_set conjuntoLectura;

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

  while (1) {

			 int n;
			 
			 FD_ZERO(&conjuntoLectura);
			 FD_SET(tuberia1[0], &conjuntoLectura);
			 FD_SET(tuberia2[0], &conjuntoLectura);
			 FD_SET(0, &conjuntoLectura);
	
			 n = select(tuberia2[0] + 1, &conjuntoLectura, NULL, NULL, NULL);
			  
			 if (n > 0) {

						if (FD_ISSET(tuberia1[0], &conjuntoLectura)) {

                           c = read(tuberia1[0], buffer, 256);
	                        examinarEImprimir(c, buffer);
						}

						if (FD_ISSET(tuberia2[0], &conjuntoLectura)) {

	                        c = read(tuberia2[0], buffer, 256);
	                        examinarEImprimir(c, buffer);
						}

						if (FD_ISSET(0, &conjuntoLectura)) {

	                        c = read(0, buffer, 256);
	                        examinarEImprimir(c, buffer);
                  }
 			 }
	  }
}

