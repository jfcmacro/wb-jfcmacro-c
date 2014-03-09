#include <stdio.h>

int
main(int c, char *argv[]) {

	int i;
	long j;
	long sum = 0;
	

	for (i = 0, j = 1; i < 8; i++, j *= 2) {
		sum = sum + j;
	}

	printf("sum: %ld ultimo: %ld \n", sum, j);

	return 0;

}
