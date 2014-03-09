#include <stdio.h>

int
main() {

	int i;

	{

		printf("Esto es un bloque\n");
	}

	for (i = 0; i < 10; i++);

	{

		printf("Esto esto es otro bloque\n");

	}


}
