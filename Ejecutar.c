#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pty.h>
#include <utmp.h>

#define BUFFER_SIZE 512
#define TRUE        1
#define FALSE       0

int
main(int argc, char *argv[])
{

  pid_t ptChild1, ptChild2;       /* identificadores de los procesos */
  int valRetChild1, valRetChild2; /* Valores de retorno de los hijos */
  fd_set readSet;
  int n;
  char buffer[BUFFER_SIZE];
  int end;
  int master, slave;
  char namePTY[BUFFER_SIZE];
 
  if (argc != 3) {
    fprintf(stderr, "Uso: Ejecutar <comando> <archivo> \n");
    exit(1);
  }

  if (openpty(&master,&slave, namePTY, NULL, NULL) < 0) {
    fprintf(stderr, "No se pudo abrir las terminales");
    exit(1);
  }

  /* Crea el primer hijo */
  if ((ptChild1 = fork()) == 0) {

    int inTerm, outTerm, errTerm;

    /* Cierra la entrada estándar (stdin) y la asocia
       a través de dup2 con el descriptor de lectura de la tuberia */
    close(master);

    /* Ejecuta el primer programa wc, en este punto el programa
       ya hereda como entrara estándar el descriptor de lectura
       de la tuberia */

    inTerm  = open(namePTY, O_RDONLY);
    dup2(inTerm, 0);
    outTerm = open(namePTY, O_WRONLY);
    dup2(outTerm, 1);
    errTerm = open(namePTY, O_WRONLY);
    dup2(errTerm, 2);
    close(inTerm);
    close(outTerm);
    close(errTerm);
    close(slave);
    
    execlp(argv[1], argv[1], argv[2], NULL);

    /* Algo malo ocurrió  */
    fprintf(stderr, "Error: no pudo ejecutar programa\n");
    exit(2);
  }

  close(slave);

  end = FALSE;

  while (!end) {

    // Estableciendo el conjunto de lectura y escritura
    FD_ZERO(&readSet);
    FD_SET(master, &readSet);

    // Esperando que los conjuntos se encuentren listos.
    n = select(master+1, &readSet, NULL, NULL, (void *) 0);

    if (n < 0) {
      fprintf(stderr, "Error: %d\n", errno);
      exit(2);
    }
    else {
      int nc = 0;

      if (FD_ISSET(master, &readSet)) {

	nc = read(master, buffer, BUFFER_SIZE);
	buffer[nc];
	fprintf(stdout, buffer);
      }

      if (nc < 0) {
	end = TRUE;
      }
    }

  }
  waitpid(ptChild1, &valRetChild1, 0);

  exit(0);
}
