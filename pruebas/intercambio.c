#include<stdio.h>

void
intercambio(int *x, int *y) {

	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

int
main(int argc, char *argv[]) {

	int w, z;

	w = 5;
	z = 6;

	fprintf(stdout, "Valor w = %d z = %d\n", w, z);

	intercambio(&w, &z);

	fprintf(stdout, "Valor w = %d z = %d\n", w, z);

	return 0;
}
