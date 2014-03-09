#include "../include/vector.h"
#include <unistd.h>
#include <stdio.h>

struct vector {
  int dimension;
};

static int x = 5;

int
crearVector(Vector** vector) {

  *vector = (struct vector *) malloc(sizeof(struct vector));
  return 0;
}

void
imprimirVector(Vector *vector) {

  printf("%d\n", vector->dimension);
}

void
modificarVector(Vector *vector, int valor) {
  vector->dimension = valor + x;
}
