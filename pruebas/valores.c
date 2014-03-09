#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int 
main() {
	char *arc = (char *) malloc(1); ;

	if (write(1,arc,1) < 0) {
		fprintf(stderr, "Error: %d\n", errno);
	}

	exit(0);
}
