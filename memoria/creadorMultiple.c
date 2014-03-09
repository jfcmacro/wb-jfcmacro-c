#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/user.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int
main(int argc, char *argv[]) {

  int idSeg;
  int idSem;
  char *bufferSh;
  int i;
  int key;
  struct sembuf semaforos[1];

  if (argc != 2) {
    fprintf(stderr, "Uso: %s \n", argv[0]);
    exit(1);
  }

  key = strtol(argv[1], NULL, 10);

  for (i = 0; i < 10; i++) {
    fprintf(stdout, "Clave: %d\n ", (key + i));
    if ((idSeg = shmget(key + i, PAGE_SIZE, IPC_CREAT | IPC_EXCL)) < 0) {
      fprintf(stderr, 
	      "Fallo al crear el segmento de memoria debido a: %d %s\n",
	      errno, strerror(errno));
      exit(1);
    }
  }

  sleep(30);
}
