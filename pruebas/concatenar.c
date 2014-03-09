#include <stdio.h>

void
concatenar(char *s, char *t) {

  while (*s != '\0') s++;

  while (*t != '\0') {
    
    *s = * t;
    s++; t++;
  }

  *s = '\0';
}

int
main() {

  char palabra1[30] = "Hola ";
  char palabra2[] = "Mundo";

  concatenar(palabra1, palabra2);

  printf("%s\n", palabra1);

  return 0;
}
