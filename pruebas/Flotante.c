#include <stdio.h>

int
main(int argc, char *argv[]) {

	int valor1 = 0x7F805354;
	int valor2 = 0x7F800000;

	float *f1 = (float *) &valor1;
	float *f2 = (float *) &valor2;
	float f3 = *f1 + *f2;

	printf("%d\n", valor1);
	printf("%f\n", *f1);
	printf("%d\n", valor2);
	printf("%f\n", *f2);
	printf("%f\n", f3);
	return 0;
}
