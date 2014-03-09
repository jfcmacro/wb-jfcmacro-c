#include <stdio.h>

int mask(int n, int p) {

	int mascara = 1;
	int i = 0;
	
	while (i <= n + 1) {

		mascara = mascara << 1;

		if (i == n + 1) {

			while (p > 0) {
				mascara = (mascara>>1); 
				p--;
			}
		}
		i++;
	}
	return mascara;
}


int
main() {

	printf("%x\n", mask(3,4));
}
