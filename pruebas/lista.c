#include <stdio.h>

int lista[] = { 0x200, 0x204, 0x208, 0x20C, 0x2F4, 0x2F0, 
		0x200, 0x204, 0x218, 0x21C, 0x24C, 0x2F4 };

int
main() {

	int i = 0;

	for (i = 0; i < sizeof(lista) / sizeof(int); i++) {

		printf("Valor: %d Residuo: %d\n", lista[i], lista[i] % 8);

	}

	return 0;
}
