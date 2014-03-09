#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {

	char path[] = "/home/fcardona/programas/c/pruebas/";
	char buffer[256];

	strcpy(buffer, path);
	strcat(buffer, argv[1]);

	execl(buffer, argv[1], NULL);

}
