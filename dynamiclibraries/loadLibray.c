#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <dlfcn.h>

int
main(int argc, char *argv[]) {

  void* hBiblioteca;

  hBiblioteca = dlopen("holamundo.so", RTLD_NOW);

  if (hBiblioteca == (char *) 0) {
    fprintf(stderr, "Error cargando la biblioteca: %d\n", errno);
    exit(0);
  }

  return 0;
}
