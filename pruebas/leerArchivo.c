#include <stdio.h>
#include <stdlib.h>

void
f() {}

void 
g() {}

void 
h() {}

void 
w() {}

int
main(int argc, char* argv[])
{
	FILE *fd;
	char *nomFuncion;
	struct A {
	   char *elemento1;
	   int  a1;
	   char *elemento2;
	   int  a2;
	} aA;
	struct nombreFuncion {
		char *nombre;
		void (*k)();
	} listaFuncion[] = { { "g", g } , { "f", f }, { "h", h }, { "w", w }, 
			{ "Nofuncion", NULL }, {NULL, NULL} };
			

	aA.elemento1 = (char *) malloc(256);
	aA.elemento2 = (char *) malloc(256);
	nomFuncion = (char *) malloc(256);

	fd = fopen("./datos.txt", "r");
	
	while (fscanf(fd, "%s %d %s %d %s", 
				aA.elemento1, &aA.a1, aA.elemento2, &aA.a2, nomFuncion ) != EOF)
		printf("%s %d %s %d\n", aA.elemento1, aA.a1, aA.elemento2, aA.a2);

	return 0;
}
