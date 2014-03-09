#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int
main(int argc, char *argv[]) {

	char clave[] = "ab";
	char *nueva;

	if (argc != 2) {
		fprintf(stderr, "Uso: %s <clave>\n", argv[0]);
		exit(1);
	}

	nueva = crypt(argv[1], clave);

	fprintf(stdout, "%s\n", nueva);
	exit(0);
}
