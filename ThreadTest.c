// #include <thread.h>
#include <stdio.h>

int
main() {

#ifdef __STDC_NO_THREADS__ 
  printf("No definidos los hilos\n");
#else
  printf("No definida la constante\n");
#endif
  return 0;
}
