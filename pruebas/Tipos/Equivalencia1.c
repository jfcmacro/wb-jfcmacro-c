#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int A1[10];
typedef int A2[20];

#define TAM_A1 (sizeof(A1) / sizeof(int))
#define TAM_A2 (sizeof(A2) / sizeof(int))

int
main(int argc, char *argv[]) {

	A1 a1;
	A2 a2;
	A1 a1_1;
	int i;

	srand(time(NULL));

	for (i = 0; i < TAM_A1; i++) {

		a1[i] = rand();
		printf("a[%d]=%d\n", i, a1[i]);
	}

	srand(time(NULL));

	for (i = 0; i < TAM_A2; i++) {

		a2[i] = rand();
		printf("a[%d]=%d\n", i, a2[i]);
	}

	return 0;
}
