#include <stdio.h>


__attribute__ ((section (".shrdata"))) int vector[] = { 1, 2, 3, 4, 5 };

int
main() {

	printf("%p\n", &vector);

	return 0;
}
