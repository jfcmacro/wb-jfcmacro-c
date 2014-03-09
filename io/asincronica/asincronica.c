#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <stdio.h>

void
noBloqueante(int fd) 
{
  int on = 1;

  ioctl(fd, FIONBIO, &on);
}

int
main()
{
  char buffer[256];
  int c;
  extern int errno;

  noBloqueante(0);

  while (1) {
   
    c = read(0, buffer, 256);
   
    if (c < 0) {
       if (errno != EWOULDBLOCK) {
	  fprintf(stderr, "Error: %d %s\n", errno, strerror(errno));
	  exit(1);
       }	  
       printf("No ha llegado nada\n");
       sleep(1);
    }
    else {
	    	
       buffer[c] = '\0';

       printf("%s\n", buffer);
    }
  }
}
