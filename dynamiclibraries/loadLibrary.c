#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <dlfcn.h>

int
main(int argc, char *argv[]) {

  void* hBiblioteca;
  void (*funcion)(void);
  int (*funcion1)(void);
  char *error;

  hBiblioteca = dlopen("holamundo.so", RTLD_NOW);

  if (!hBiblioteca) {
    fprintf(stderr, "Error cargando la biblioteca: %d\n", errno);
    exit(1);
  }

  funcion = dlsym(hBiblioteca, "holamundo");

  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(1);
  }

  funcion();
  funcion();
  funcion();

  funcion1 = dlsym(hBiblioteca, "vecesValor");

  printf("Veces: %d\n", funcion1());
  dlclose(hBiblioteca);

  for(;;) ;
  return 0;
}
