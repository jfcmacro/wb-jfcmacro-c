#include <stdio.h>
#include <unistd.h>
#include "Encabezado.h"

int
main(int argc, char *argv[]) {

  int desc, salida;
  struct Encabezado enc;
  int nC;

  if (argc != 3) {

    exit(1);
  }

  desc = atoi(argv[1]);
  salida = atoi(argv[2]);

  printf("Voy a leer de %d\n", desc);
  printf("Voy a escribir en %d\n", salida);

  nC = read(desc, &enc, sizeof(struct Encabezado));
  
  enc.numero += enc.numero;
  enc.valor *= 20;
  
  write(salida, &enc, sizeof(struct Encabezado));

  nC = read(desc, &enc, sizeof(struct Encabezado));
  
  enc.numero += enc.numero;
  enc.valor *= 20;
  
  write(salida, &enc, sizeof(struct Encabezado));

  exit(0);
}
