#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

#define MAX_BUFFER   8192
#define MAX_OUT      256
#define BROADCAST_ADDR	"255.255.255.255"

/* Imprimi un mensaje de error en stderr */
void
printError(char *errorMsg, int codError, int codExit)
{
  fprintf(stderr, "%s\n%d: %s\n", errorMsg, codError, strerror(codError));
  exit(codExit);
}

/* Funcion principal */
int
main(int argc, char* argv[])
{
  int s;
  char out[MAX_OUT];       /* Buffer de entrada */
  char buffer[MAX_BUFFER]; /* Buffer de salida */
  struct sockaddr_in sin;  /* Direccion de entrada */
  struct sockaddr_in sout; /* Direccion de salida */
  int port;                /* Puerto de entrada */
  int portRemoto;          /* Puerto remoto */
  int nfd;                 /* Numero de descriptores */
  fd_set readSet;          /* Conjunto de entrada */
  int c;

  if (argc != 3) {
    sprintf(out, "Usage: %s localPort remotePort", argv[0]);
    printError(out, 0, 1);
  }

  /* Obtiene puerto local */
  port = strtol(argv[1], (char **)NULL, 10);

  /* Obtiene puerto remot */
  portRemoto = strtol(argv[2], (char **)NULL, 10);

  /* Crea socket */
  if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    sprintf(out, "No pudo abrir el socket");
    printError(out, errno, 1);
  }

  /* Establece direccion local */
  bzero(&sin, sizeof(sin));

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(s, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
    sprintf(out, "Error when trying to bind a socket");
    printError(out, errno, 1);
  }

  /* Establece conexion remota */
  bzero(&sout, sizeof(sin));

  sout.sin_family = AF_INET;
  sout.sin_port = htons(portRemoto);

  if (!inet_aton(BROADCAST_ADDR, &sout.sin_addr)) {
     sprintf(out, "Error al obtener direccion de broadcast");
     printError(out, errno, 1);
  }

  while (1) {

    FD_ZERO(&readSet);
    FD_SET(s, &readSet);
    FD_SET(fileno(stdin), &readSet);

    nfd = select(s + 1, &readSet, (fd_set *) NULL, (fd_set *) NULL,
		 (struct timeval *) NULL);

    if (FD_ISSET(s, &readSet)) {

      recv(s, buffer, MAX_BUFFER, 0);
      fputs(buffer, stdout);
      fflush(stdout);
    }

    if (FD_ISSET(fileno(stdin), &readSet)) {

      if (fgets(buffer, MAX_BUFFER, stdin) == NULL)
	break;

      sendto(s, buffer, strlen(buffer), 0, (struct sockaddr*) &sout, sizeof(sout));
      bzero(buffer, strlen(buffer));
    }
  }

  close(s);
  exit(0);
}
