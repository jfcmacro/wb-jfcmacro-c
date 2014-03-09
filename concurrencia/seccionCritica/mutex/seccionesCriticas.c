#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t seccionCritica = PTHREAD_MUTEX_INITIALIZER;

void*
hilo1(void *arg)
{
  // Obtiene el mensaje a imprimir
  char *mensaje = (char *) arg;
  int i;

  while (1) {

    
    for (i = 0; i < strlen(mensaje); i++)
      write(0, &mensaje[i], 1);
    
  }
  return (void *) 0;
}

void*
hilo2(void *arg)
{
  // Obtiene el mensaje a imprimir
  char *mensaje = (char *) arg;
  int i;

  while (1) {

    
    for (i = 0; i < strlen(mensaje); i++)
      write(0, &mensaje[i], 1);
    
  }

  return (void *) 0;
}

int
main(int argc, char *argv[])
{

  pthread_t hilo1ID, hilo2ID;

  if (argc != 3) {
    fprintf(stderr, "Uso: %s mensaje1 mensaje2\n", argv[0]);
    exit(0);
  }

  pthread_create(&hilo1ID, NULL, hilo1, (void *) argv[1]);

  pthread_create(&hilo2ID, NULL, hilo2, (void *) argv[2]);

  pthread_join(hilo1ID, NULL);
  pthread_join(hilo2ID, NULL);

}
