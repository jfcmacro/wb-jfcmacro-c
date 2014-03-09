#include <stdio.h>
#include <stdlib.h>

int* direccion(int *matriz, int fil, int col, int offset) {
  return matriz + (fil * offset) + (col);
}

int 
main(int argc, char *argv[]) {

  FILE *fd;
  FILE *fd2;

  int fil, col;
  char buffer[256];
  int *matriz;
  int i;
  int j;

  if (!(fd = fopen("matriz.txt", "r"))) {
    perror("Fallo por: ");
    exit(1);
  }

  fgets(buffer,sizeof(buffer),fd);

  sscanf(buffer, "%d %d\n", &fil, &col);
  printf("Fila: %d Columna: %d\n", fil, col);

  matriz = (int*) malloc(sizeof(int)*fil*col);

  if (matriz == 0) {
    perror("Fallo por: ");
    exit(2);
  }

 
  for (i = 0; i < fil; i++) {
    char *pB; 

    fgets(buffer, sizeof(buffer), fd);
    j = 0;
    pB = (char *) strtok(buffer, ",\n");
    while (pB != 0) {
      int tmp;
      sscanf(pB, "%d", &tmp);
      *(direccion(matriz,i,j,col)) = tmp;
      pB = (char *) strtok(NULL, ",\n");
      j++;
    }
  }

  if (!(fd2 = fopen("salida.txt", "w"))) {
    perror("Fallo: ");
    exit(3);
  }

  for (i = 0; i < fil; i++) {
    for (j = 0; j < col; j++) {
      fprintf(fd2, "%d ", *(direccion(matriz, i, j, col)));
    }
    fprintf(fd2, "\n");
  }
  free(matriz); 

  fclose(fd);
  fclose(fd2);
}
