#include <string.h>
#include <stdio.h>

int
main(int argc, char *argv[]) {
  char frase[] = "Hola    a    todos  en  el     mundo";
  char *posicion;
  int np = 0;
  posicion = strtok(frase, " ");
  while (posicion != NULL) {
    np++;
    posicion = strtok(NULL, " ");
  }
  fprintf(stdout, "Numero de palabras en frase: %d\n", np);
  return 0;
}
