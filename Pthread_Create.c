#include <stdio.h>
#include <pthread.h>

void*
hilo1(void *arg) {
  int i;
  (void) arg;

  for (i = 0; i < 100; i++) {
    printf("%d\n", i); 
  }
  return NULL;
} 

int
main() {
  pthread_t hilo;

  pthread_create(&hilo, NULL, hilo1, NULL);

  pthread_join(hilo, NULL);
  printf("Padre termino\n");
}
