#include <stdio.h>

enum Tipos { INT, SHORT };

struct unX {
	enum Tipos tipo;

	union X {
		int a;
		short b;
	} x;

};

void imprimirUnX(struct unX unx) {

	if (unx.tipo == INT)
		printf("%d\n", unx.x.a);

	if (unx.tipo == SHORT)
		printf("%d\n", unx.x.b);
}

int
main(int argc, char *argv[]) {
	
	struct  unX w;

	w.x.a = 79090;
	w.tipo = INT;

	imprimirUnX(w);

	w.x.b = 345;
	w.tipo = SHORT;
	imprimirUnX(w);
	w.x.a = 80000;
	imprimirUnX(w);


	return 0;

}
