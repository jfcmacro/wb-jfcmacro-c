#include <stdio.h>

struct RecA {
	char x;
	int y;
} a;

typedef struct RecA RecA;

typedef struct {
	char x;
	int y;
} RecB;

RecB b;

struct {
	char x;
	int y;
} c;

int
main() {

	b = a;
	c = a;
	b = c;

	return 0;
}
