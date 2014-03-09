#include <stdio.h>
#include <string.h>

int
buscarPalabraMasCercana(const char *palabraABuscar, char *palabraEncontrada,
			int *tamanoPalabraEncontrada, int nParticiones,
			const char *nombreArchivoParticion) {

	strcpy(palabraEncontrada, "Ya la encontramos");
	*tamanoPalabraEncontrada = strlen(palabraEncontrada);
	return 0;
}


int
main() {

	char palabraEncontrada[256];
	int tamanoPalabraEncontrada;

	buscarPalabraMasCercana("Tomar", palabraEncontrada, 
		&tamanoPalabraEncontrada, 10, "no se");

	fprintf(stdout, "Palabra encontrada: %s tamano: %d\n", palabraEncontrada,
		tamanoPalabraEncontrada);

	return 0;
}
