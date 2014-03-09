/* ursig1.c */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static int count = 0;

void
handler(int signo) 
{
	signal(SIGINT, handler);
	++count;
	write(1, "Got SIGINT\n", 11);
}

int
main(int argc, char *argv[])
{
	signal(SIGINT, handler);
		

	while (count < 2) {
		puts("Waiting for SIGINT..");
		sleep(4);
	}

	puts("Ends.");
	return 0;
}

