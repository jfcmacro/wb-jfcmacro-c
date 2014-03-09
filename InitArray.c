#include <stdio.h>

#define TAMANO 10

int
main(int argc, char *argv[]) {

  int vector1[TAMANO]  = { 1, 2, 3 };
  int vector2[]        = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  char vector3[]       = { 'H', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o' };
  char vector4[TAMANO] = { 'H', 'o', 'l', 'a' };
  // int vector5[TAMANO]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int i;

  for (i = 0; i < TAMANO; i++) {
    fprintf(stdout, "vector1[%d]=%d vector2[%d]=%d vector3[%d]=%c vector4[%d]=%d\n", 
	    i, vector1[i],
	    i, vector2[i],
	    i, vector3[i],
	    i, vector4[i]);
  }
  return 0;
}
