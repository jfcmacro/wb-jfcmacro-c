#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	extern int optind, opterr, optopt;
	extern char* optarg;
	int c;
	struct option opciones[] = {	{ "in", required_argument, NULL, 1},
			  								{ "out", required_argument, NULL, 2},
  											{ NULL, no_argument, NULL, 0	}};

	while ((c = getopt_long(argc, argv, "i:o:", opciones, NULL)) != -1) {

		fprintf(stdout, "c:%c optind:%d opterr:%d optopt:%d optchar:%s\n", 
							 c, optind, opterr, optopt, optarg);
		fprintf(stdout, "Siguiente argumento: %s %d\n", argv[optind], atoi(argv [optind]));
	}

	exit(0);
}
