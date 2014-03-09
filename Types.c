#include <stdio.h>

int
main() {;
  long y;
  int z;
  
  printf("sizeof(long long) = %d sizeof(long) = %d sizeof(int) = %d \n", 
	 sizeof(x), sizeof(y), sizeof(z));
  x = (unsigned long long) -1;
  do {
    printf("%lu\n", x);
  } while (x >>= 1);
  return 0;
}
