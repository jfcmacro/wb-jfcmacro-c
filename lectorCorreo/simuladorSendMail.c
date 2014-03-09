#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "utilidades.h"

#define DEBUG

#include "debug.h"

#define TAM_BUFFER 256
#define LOG_FILE_SIZE 256

#define MAX(a,b) a >= b ? a : b

#define VERDADERO 1
#define FALSO     0

static int
crearArchivo(char *nombre) {

  int fileFd;

  fileFd = open(nombre, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);

  if (fileFd < 0) {
    fprintf(GET_ERROR_FILE, 
	    "No se pudo abrir archivo de salida %d %s\n", 
	    errno, strerror(errno));
    return -1;
  }
  
  return fileFd;
}

void
leerCopiar(int fdIn1, int fdOut1, 
	   int fdIn2, int fdOut2,
	   int fdOut3, int fdOut4) {

  
  char buffer[TAM_BUFFER];
  int nCarLeidos = 0;
  fd_set readfd, exceptfds;
  int nFd;
  int continuar = VERDADERO;

  debug("Esta listo para entrar");

  do {
    int max = 0;

    FD_ZERO(&readfd);
    FD_ZERO(&exceptfds);

    FD_SET(fdIn1, &readfd);
    FD_SET(fdIn1, &exceptfds);
    max = MAX(max, fdIn1);
    FD_SET(fdIn2, &readfd);
    FD_SET(fdIn2, &exceptfds);
    max = MAX(max, fdIn2);

    FD_SET(fdOut1, &exceptfds);
    max = MAX(max, fdOut1);

    FD_SET(fdOut2, &exceptfds);
    max = MAX(max, fdOut2);

    nFd = select(max + 1, &readfd, NULL, &exceptfds, NULL);

    debug("Paso select");

    if (nFd < 0) {
      fprintf(GET_ERROR_FILE, 
	      "Error en el select: %d %s\n",
	      errno, strerror(errno));
      exit(1);
    }
    
    switch (nFd) {

    case 0:

      debug("O parametros");

      fprintf(GET_ERROR_FILE,
	      "Error en el select retorno 0 %d %s\n",
	      errno, strerror(errno));
      exit(1);
      break;

    case 1:

      debug("Un parametro");

      /* Revisa en error */
      if (FD_ISSET(fdIn1, &exceptfds) ||
	  FD_ISSET(fdOut1, &exceptfds) ||
	  FD_ISSET(fdIn2, &exceptfds) ||
	  FD_ISSET(fdOut2, &exceptfds)) {

	debug("Un descriptor tiene un error");

	fprintf(GET_ERROR_FILE,
	      "Error en uno de los descriptores %d %s\n",
	      errno, strerror(errno));
	exit(1);
	
      }

      if (FD_ISSET(fdIn1, &readfd)) {

	debug("Definido fdIn1");

	nCarLeidos = read(fdIn1, buffer, TAM_BUFFER);
	if (nCarLeidos > 0) {
	  debug("Carateres leidos > 0");

	  write(fdOut2, buffer, nCarLeidos);
	  write(fdOut3, buffer, nCarLeidos);
	}
	else 
	  continuar = FALSO;
      }

      if (FD_ISSET(fdIn2, &readfd)) {

	debug("Definido fdIn2");

	nCarLeidos = read(fdIn2, buffer, TAM_BUFFER);

	if (nCarLeidos > 0) {
	  debug("Carateres leidos > 0");

	  write(fdOut1, buffer, nCarLeidos);
	  write(fdOut4, buffer, nCarLeidos);
	}
	else 
	  continuar = FALSO;
      }

      break;

    case 2:
      /* Revisa en error */
      if (FD_ISSET(fdIn1, &exceptfds) ||
	  FD_ISSET(fdOut1, &exceptfds) ||
	  FD_ISSET(fdIn2, &exceptfds) ||
	  FD_ISSET(fdOut2, &exceptfds)) {

	debug("Error en uno de los descriptores");
	
	fprintf(GET_ERROR_FILE,
	      "Error en uno de los descriptores %d %s\n",
	      errno, strerror(errno));
	exit(1);
	
      }

      if (FD_ISSET(fdIn1, &readfd)) {

	debug("Descriptor fdIn1");

	nCarLeidos = read(fdIn1, buffer, TAM_BUFFER);

	if (nCarLeidos > 0) {
	  debug("Carateres leidos > 0");

	  write(fdOut2, buffer, nCarLeidos);
	  write(fdOut3, buffer, nCarLeidos);
	}
	else 
	  continuar = FALSO;
      }

      if (FD_ISSET(fdIn2, &readfd)) {

	debug("Descriptor fdIn2");

	nCarLeidos = read(fdIn2, buffer, TAM_BUFFER);

	if (nCarLeidos > 0) {
	  debug("Carateres leidos > 0");
	  
	  write(fdOut1, buffer, nCarLeidos);
	  write(fdOut4, buffer, nCarLeidos);
	}
	else
	  continuar = FALSO;
      }

      break;

    }
  } while (continuar);
}

int
main(int argc, char *argv[]) {
  
  int ret;
  int fdIn[2];
  int fdOut[2];

  createLogFile("/tmp/debug.tmp");
  setErrorFileName("/tmp/errores");

  if (pipe(fdIn) < 0) {
    fprintf(GET_ERROR_FILE, 
	    "No se pudo crear las tuberias fdIn: %d %s\n",
	    errno, strerror(errno));
    exit(1);
  }

  if (pipe(fdOut) < 0) {
    fprintf(GET_ERROR_FILE, 
	    "No se pudo crear las tuberias fdOut: %d %s\n",
	    errno, strerror(errno));
    exit(1);
  }
  
  ret = fork();

  if (ret == -1) {

    fprintf(GET_ERROR_FILE, 
	    "Error abriendo realizando fork: %d %s\n",
	    errno, strerror(errno));
    exit(1);
  }
 
  if (ret == 0) { /* Child */
    int i;
    char buffer[256];

    close(0);
    dup2(fdOut[0], 0);
    close(1);
    dup2(fdIn[1], 1);
    close(fdOut[0]);
    close(fdOut[1]);
    close(fdIn[0]);
    close(fdIn[1]);

    fprintf(GET_ERROR_FILE, "Ejecutar lista parámetros: %d\n", 
	    argc);

    sprintf(buffer, "Ejecutar lista parametros: %d\n", argc);
    debug(buffer);

    debug("Listo a ejecutar");

    // execl("/usr/sbin/sendmail.sendmail", "sendmail", "-t", NULL);
    execl("/usr/bin/ssh", "ssh", "fcardona@sigma", 
	  "/usr/lib/sendmail", "-t", NULL);
    // execl("/bin/ed", "ed", "/tmp/archivo", NULL);
    // execl("/bin/ls", "ls", "-l", NULL);

    debug("Error al ejecutar");

    exit(1);

  }
  else {
    int status;
    int fdDataOut;
    int fdDataIn;
    
    close(fdOut[0]);
    close(fdIn[1]);

    fdDataOut = crearArchivo("/tmp/dataOut");
    fdDataIn  = crearArchivo("/tmp/dataIn");

    leerCopiar(0, 1, fdIn[0], fdOut[1], fdDataIn, fdDataOut);

    if (WIFEXITED(status) != 0) {
      fprintf(GET_ERROR_FILE, 
	      "Error ejecutando el hijo %d\n",
	      WIFEXITED(status));
      exit(1);
    }
  }
  return 0;
}
