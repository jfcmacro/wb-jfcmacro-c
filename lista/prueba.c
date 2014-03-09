#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void
f(const char *nombre, char **listaPar) {

  int status;

  if (fork() == 0) {
    execv(nombre, listaPar);
    exit(1);
  }
  else {
    wait(&status);
  }
}

int
main() {
  char **lista;

  lista = (char **) malloc(sizeof(char *) * 4);

  *(lista) = "ls";
  *(lista + 1) = "-l";
  *(lista + 2) = "-a";
  *(lista + 3) = NULL;
  
  f("/bin/ls", lista);

  free(lista);

  exit(0);
}
