#include <sched.h>
#include <stdio.h>

char pila[256];

int
hilo(void *arg) {
  (void) arg;
  int i;

  for (i = 0; i < 10; i++) {
    printf("Hola hilo: %d \n", i);
  }
  return 0;
}

int
main() {
  int i = 0;
  clone(hilo, &pila, 0, NULL);
  for (i = 0; i < 1000000; i++);
  printf("Padre ha terminado\n");
  // sleep(10);
}
