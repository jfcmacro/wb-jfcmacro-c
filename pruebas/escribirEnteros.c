/* Control.c */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
main() {

  int tuberias[2];
  char buffer[256];

  if (pipe(tuberias) < 0) {
    fprintf(stderr, "Error: al crear las tuberias  %d\n", errno);
    exit(0);
  }

  if (fork() != 0) { /* Hijo */
    int cLeidos;
    
    close(tuberias[1]);
    close(0);
    dup2(tuberias[0], 0);
    close(tuberias[0]);

    do {
      int i;
      cLeidos = read(0, &i, sizeof(int));
      buffer[cLeidos] = '\0';
      fprintf(stdout, "Numero de caracteres leidos: %d Buffer: %d\n", 
	      cLeidos, i);
    } while (cLeidos > 0);
  }
  else {
    int i;
    close(tuberias[0]);
    close(1);
    dup2(tuberias[1], 1);
    close(tuberias[1]);
    
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
      int valor;
      valor = rand();
      write(1, &valor, sizeof(int));
      fprintf(stderr, "Valor: %d\n", valor);
    }
  }

}
