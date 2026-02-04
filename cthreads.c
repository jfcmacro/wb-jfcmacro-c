#include <stdio.h>
#include <threads.h>

thrd_start_t funcion;

int
main(int argc, char *argv[]) {
  thrd_t id;
  int value = 10;
  if (thrd_create(&id, funcion, (void *) &value) == thrd_success) {
    
    thrd_join(id, &value);
    printf("Thread %d ends: %d\n", id, value);
  }
  else {
    fprintf(stderr, "Create Thread fails");
  }

  return 0;
}

thrd_start_t
function(void *arg) {
  int value = (int) arg;

  for (int i = 0; i < value; i++) {
    printf("Thread running: %d\n", i);
  }

  return 10;
}
