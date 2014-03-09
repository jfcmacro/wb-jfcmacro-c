#include <stdio.h>
#define _USE_XOPEN
#include <unistd.h>

int
main(int argc, char *argv[]) {

	char clave[] = "ab";
	char *nueva;

	if (argc != 2) {
		fprintf(stderr, "Uso: %s <clave>\n", argv[0]);
		_exit(1);
	}

	nueva = crypt(argv[1], clave);

	fprintf(stdout, "%s\n", nueva);
	_exit(0);
}
