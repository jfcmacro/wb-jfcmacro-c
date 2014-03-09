#include <time.h>
#include <stdlib.h>

int
main()
{
	time_t t;

	t = time(NULL);

	srand((int) t);

	printf("%d\n", (int) rand());

	return 0;
}
