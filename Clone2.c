#include <sched.h>
#include <stdio.h>

char pila1[256];
char pila2[256];

int variable = 0;

int
hilo1(void *arg) {
  (void) arg;
  int i;

  for (i = 0; i < 1000; i++) {
    variable++;
    printf("Hola hilo 1: %d \n", i);
  }
  printf("Hilo 1 variable: %d\n", variable);

  return 0;
}

int
hilo2(void *arg) {
  (void) arg;
  int i;

  for (i = 0; i < 1000; i++) {
    variable--;
    printf("Hola hilo 2: %d \n", i);
  }
  printf("Hilo 2 variable: %d\n", variable);

  return 0;
}


int
main() {
  int i = 0;
  pid_t hilo1;
  pid_t hilo2;
  int status;

  hilo1 = clone(hilo1, &pila1, 0, NULL);
  hilo2 = clone(hilo2, &pila2, 0, NULL);
  wait(&status);
  printf("Hijo termino: %d\n", status);
  wait(&status);
  printf("Hijo termino: %d\n", status);
  printf("Padre ha terminado con la variable: %d\n", variable);
  // sleep(10);
}
