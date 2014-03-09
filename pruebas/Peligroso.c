#include <stdio.h>

int
main() {

	float f = 3.0f;
	int x = 0;
	void *p = &f;
	int *pInt;
	

	pInt = (int *) p;
	x = (int) *pInt;

	x++; // 4?

	printf("%d\n", x);

	
	return 0;
}
