#include <stdio.h>

int
bitcount(unsigned n)
{
  int b;
  for ( b = 0; n != 0; n &= (n + (~1+1)))
    b++;
  return b;
}

int
main()
{
  unsigned n;
  n = 1984;
  printf("%d \n", bitcount(n));
  printf("%x\n", n);ç
}
      
