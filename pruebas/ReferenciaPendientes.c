#include <stdio.h>

int *p;

void f1(int x) {

	p = (int *) malloc(sizeof(int));
	*p = x;
}


void f2(int x) {

	int w = x;

	p = &w;
}


int
main(void) {

	f1(10);
	char *s = "%d\n";

	printf("%d\n", *p);
	printf("%d\n", *p);
	printf("s: %x p: %x\n", s, p);
	printf("s: %x p: %x s: %x p: %x \n", s, p, s , p);
	printf("%d\n", *p);
	

	return 0;
}
