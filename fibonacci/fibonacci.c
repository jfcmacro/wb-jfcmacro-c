#include <stdio.h>

int
fibonacci(int n) {

	if (n == 0) 
		return 0;
	if (n == 1) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}


int
main(int argc, char *argv[]) {


	int i = 0;

	for (; i < 10; i++) {	
		printf("fibonacci(%d): %d\n", i, fibonacci(i));
	}

	return 0;

}
