#include <stdio.h>

struct Estructura_2 {
	int x;
	int y;
	struct Estructura_2_1 {
		int x;
		int y;
	} campo3;
};

void
CopiarVectorEstructura(struct Estructura_2 x[], struct Estructura_2 y[]) {

	int i;
	int length;

	length = sizeof(x)/sizeof(struct Estructura_2);
	printf("%d\n", length);

	for (i = 0; i < length; i++) {
		x[i] = y[i];
	}

}

int
main() {

	struct Estructura_2 x[2], y[2];

	CopiarVectorEstructura(x,y);
}
