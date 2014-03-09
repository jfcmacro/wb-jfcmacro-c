/* Control.c */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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
      cLeidos = read(0, buffer, sizeof(buffer));
      buffer[cLeidos] = '\0';
      fprintf(stdout, "Numero de caracteres leidos: %d Buffer: %s\n", 
	      cLeidos, buffer);
    } while (cLeidos > 0);
  }
  else {
    close(tuberias[0]);
    close(1);
    dup2(tuberias[1], 1);
    close(tuberias[1]);
    sprintf(buffer, "Hola Mundo: 1");
    write(1, buffer, strlen(buffer));
    sleep(3);
    sprintf(buffer, "Hola Mundo: 2");
    write(1, buffer, strlen(buffer));
    sleep(10);
  }

}
