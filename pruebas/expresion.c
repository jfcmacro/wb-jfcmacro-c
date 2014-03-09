#include <stdio.h>

int
main() {

	int a = 2;

	a += a++;

	printf("a= %d\n", a);

	return 0;

}
