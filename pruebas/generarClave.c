#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>


int
main(void) {

	printf("%s\n", crypt("yagopigoanza", "ab"));
	return 0;
}
