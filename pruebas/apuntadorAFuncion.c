#include <stdio.h>

struct Funcion {
  void* (*f)(void *);
  void* arg;
};

void*
f1(void *args) {
	char *s = (char *) args;

	printf("Hola mundo %s\n", args);
        return (void *) NULL;
}

void* f2(void*);

void ejecutador(struct Funcion *aFuncion) {

	aFuncion->f(aFuncion->arg);
}

int
main() {

	struct Funcion funcion;

	funcion.f = f1;
	funcion.arg = "cruel";

	ejecutador(&funcion);

	funcion.f = f2;
	funcion.arg = "amigos";

	ejecutador(&funcion);

	return 0;

}
 

void*
f2(void *args) {
	char *s = (char *) args;

	printf("Hola a todos %s\n", args);
	return (void *) NULL;
}
