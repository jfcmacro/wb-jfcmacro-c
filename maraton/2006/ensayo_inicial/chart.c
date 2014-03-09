#include <stdio.h>
#include <string.h>

#define TAMANO 256

int
buscar(char* buffer, char letra, int tamano) {

  int i = 0;

  while (i < tamano) {
    if (buffer[i] == letra) 
      return i;
    i++;
  }

  return -1;
}

int
main(int argc, char *argv[]) {

  FILE *fdInput, *fdOutput;
  char buffer[TAMANO];
  char bufferError[TAMANO];
  char base[TAMANO];
  char traduccion[TAMANO];
  int totalElementos;
  int n;
  int i;
  int c;

  sprintf(bufferError, "Numero de argumentos: %d\n", argc);

  fputs(bufferError, stderr);

  if (argc == 1) {
    fdInput = fopen("chart.in", "r");
    fdOutput = stdout;
  }
  else {
    fdInput = fopen(argv[1], "r");
    fdOutput = stdout;
  }

  // Leer N
  fgets(buffer, TAMANO, fdInput);
  n = strtol(buffer, NULL, 10);

  for (i = 0; i < n; i++) {
    int j;
    // Lee base
    fgets(base, TAMANO, fdInput);
    totalElementos = strlen(base);
    // Lee traduccion
    fgets(traduccion, TAMANO, fdInput);
    

    fgets(buffer, TAMANO, fdInput);
    c = strlen(buffer);
    for (j = 0; j < c; j++) {
      int indice;
      indice = buscar(base, buffer[j], totalElementos);
      if (indice != -1) 
	fputc(traduccion[indice], fdOutput);
      else
	fputc(buffer[j], fdOutput);
    }
    fflush(fdOutput);
  }
}
   
