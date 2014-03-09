#include <stdio.h>

int
main(int argc, char *argv[]) {
	
	char s[] = "Hola Mundo\n";
	
	s[0] = 'h';
	s[5] = 'm';

	printf("%s\n", s);
	return 0;
}
