#include <stdio.h>

void 
funcion1() { 
 f1:
  printf("funcion1\n");
  return;
}

void
funcion2() {
 f2:
  printf("funcion2\n");
  return;
}

int
main() {

  void (*f)();

  f = funcion1;
  (*f)();
  f = funcion2;
  (*f)();
  printf("%p %p\n", &funcion1, funcion1);
  return 0;
}
