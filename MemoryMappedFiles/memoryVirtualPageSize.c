#include <stdio.h>
#include <unistd.h>

int
main()
{
  fprintf(stdout, "Page Size: %d\n", getpagesize());

  return 0;
}
