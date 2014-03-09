#include <stdio.h>

int
main() {

	int n = 0;
	
	int q = (n + 3) / 4;

	switch (n % 4)
	{
		case 0: do { n++;
		case 3: n++;
		case 2: n++;
		case 1: n++;
		} while (--q > 0) ;
	}

	printf("n=0:%d\n", n);

	n = 1;
	
	q = (n + 3) / 4;

	switch (n % 4)
	{
		case 0: do { n++;
		case 3: n++;
		case 2: n++;
		case 1: n++;
		} while (--q > 0) ;
	}

	printf("n=1:%d\n", n);

	n = 5;
	
	q = (n + 3) / 4;

	switch (n % 4)
	{
		case 0: do { n++;
		case 3: n++;
		case 2: n++;
		case 1: n++;
		} while (--q > 0) ;
	}

	printf("n=5:%d\n", n);

	n = 8;
	
	q = (n + 3) / 4;

	switch (n % 4)
	{
		case 0: do { n++;
		case 3: n++;
		case 2: n++;
		case 1: n++;
		} while (--q > 0) ;
	}

	printf("n=8:%d\n", n);
	
}
