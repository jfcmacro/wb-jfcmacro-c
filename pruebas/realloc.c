#include <stdio.h>
#include <stdlib.h>

int
main() {


	int *p;

	p = malloc(sizeof(int) * 40);

	*p = 100;
	*(p+1) = 101;

	printf("%p\n", p);

	p = realloc(p, sizeof(int) * 100);

	printf("%p\n", p);
	printf("%d %d\n", *p, *(p+1));
	printf("%d %d\n", *p, *(p+1));


	_exit(0);

}
