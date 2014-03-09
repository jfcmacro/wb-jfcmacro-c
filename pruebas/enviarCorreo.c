#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int
main(int argc, char *argv[]) {

	FILE *fd;

	fd = popen("mail -s \"Prueba\" fcardona@eafit.edu.co", "w");

	if (fd == NULL) {
		fprintf(stderr, "No se pudo abrir el archivo %d\n", errno);
		exit(1);
	}

	fputs( "Hola Mundo\n", fd);
	fputs( "Esto es una prueba automatica\n" , fd);
	fclose(fd);

	exit(0);
}

