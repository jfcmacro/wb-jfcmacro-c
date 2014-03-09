#include "../include/vector.h"

int
main() {

  Vector *vector;

  crearVector(&vector);
  modificarVector(vector, 20); 
  imprimirVector(vector);

  return 0;
}
