#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void* funcion_hilo_1(void *);
void* funcion_hilo_2(void *);

int
main(int argc, char *argv[]) {

  pthread_t hilo_1;
  pthread_t hilo_2;

  pthread_create(&hilo_1,
		 NULL,
		 funcion_hilo_1,
		 NULL);

  pthread_create(&hilo_2,
		 NULL,
		 funcion_hilo_2,
		 NULL);

  printf("main va a terminar\n");
  pthread_exit(NULL);
  
  return EXIT_SUCCESS;
}

void*
funcion_hilo_1(void *) {
  sleep(3);
  printf("Hilo 1 terminando\n");

  return NULL;
}

void*
funcion_hilo_2(void *) {
  sleep(10);
  printf("Hilo 2 terminando\n");

  return NULL;
}
