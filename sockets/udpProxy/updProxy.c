#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

#define MAX_BUFFER   8192
#define MAX_OUT      256
#define DIR_MULTICAST "225.0.0.1"

void
printError(char *errorMsg, int codError, int codExit)
{
  fprintf(stderr, "%s %d\n", errorMsg, codError);
  exit(codExit);
}

int
main(int argc, char* argv[])
{
  int s;
  char out[MAX_OUT];
  char buffer[MAX_BUFFER];
  char hostName[MAX_OUT];
  struct sockaddr_in sin;
  struct sockaddr_in safrom;
  struct hostent *hostInfo;
  struct in_addr maddr;
  struct ip_mreq mreq;
  int port;
  int nfd;
  fd_set readSet;
  int onoff;
  int c;

  if (argc != 2) {
    sprintf(out, "Usage: %s port", argv[0]);
    printError(out, 0, 1);
  }

  port = strtol(argv[1], (char **)NULL, 10);

  if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    sprintf(out, "No pudo abrir el socket");
    printError(out, errno, 1);
  }

  bzero(&sin, sizeof(struct sockaddr_in));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PUERTO_PROXY);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(s, (struct sockaddr *) &sin, sizeof(struct sockaddr_in)) < 0) {
    sprintf(out, "Error al tratar nombrar el socket %s\n",
	    strerror(errno));
    printError(out, errno, 1);
  }

  while (1) {
     
    FD_ZERO(&readSet);
    FD_SET(s, &readSet);
    FD_SET(fileno(stdin), &readSet);

    nfd = select(s + 1, &readSet, (fd_set *) NULL, (fd_set *) NULL,
		 (struct timeval *) NULL);

    if (FD_ISSET(s, &readSet)) {

      c = sizeof(struct sockaddr_in);
      recvfrom(s, buffer, MAX_BUFFER, 0,
	       (struct sockaddr *) &safrom, &c);
      fputs(buffer, stdout);
      fflush(stdout);
    }

    if (FD_ISSET(fileno(stdin), &readSet)) {

      if (fgets(buffer, MAX_BUFFER, stdin) == NULL)
	break;

      bzero(&sin, sizeof(struct sockaddr_in));
      sin.sin_family = AF_INET;
      bcopy(&maddr, &sin.sin_addr, sizeof(struct in_addr));
      sin.sin_port = htons(port);

      sendto(s, buffer, strlen(buffer),
	     0, (struct sockaddr *) &sin, sizeof(sin));
    }
  }

  if (setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
    sprintf(out, "No pudo borrar la membresia %s",
	    strerror(errno));
    printError(out, errno, 1);
  }

  close(s);
  exit(0);
}
