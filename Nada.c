#include <stdio.h>

int
main() {

  printf("int: %d float: %d double: %d char: %d\n",
	 sizeof(unsigned long),
	 sizeof(float),
	 sizeof(double),
	 sizeof(char));

  return 0;
}
