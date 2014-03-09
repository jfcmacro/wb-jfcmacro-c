#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define CLAVE_MEMORIA 2000

struct InfoMuerte {
  long int seq;
  int nDecesos;
};

struct MemoriaCompartida {
  int n;
  long int valSeq;
  struct InfoMuerte muertes[254];
};

typedef struct MemoriaCompartida MemoriaCompartida;

int main() {
  int segId;
  int pagesize;
  int memId;
  MemoriaCompartida *pMem;

  pagesize = getpagesize();

  if ((memId = shmget(CLAVE_MEMORIA, pagesize, IPC_CREAT | S_IRUSR | S_IWUSR)) < 0) {
    fprintf(stderr, "Error: %d \n", errno);
    exit(1);
  }

  if ((pMem = (MemoriaCompartida*) shmat(memId, NULL, 0)) == NULL) {
    fprintf(stderr, "Error: %d \n", errno);
    exit(2);
  }
  pMem->n = 10;
  pMem->valSeq = 0;
  pMem->muertes[0].seq = pMem->valSeq;
  pMem->muertes[0].nDecesos = 0;
  printf("%d\n", pagesize);
  exit(0);
}
