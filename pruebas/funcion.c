#include <stdio.h>
#include <stdlib.h>

int
g(int x) {

  int v[x];
  int i;
  int sum = 0;

  srand(time(NULL));
  for (i = 0; i < x; i++) {
    v[i] = rand();
    sum += v[i];
  }
  
  printf("%p %p\n", &v[0], ((&v[x])-1));

  return sum;
}

int f(int y)
{
  
   int g(int x) { return x * y * 2; }

   printf("%d %d\n", y, g(y));

   return g(y);
}


int
main(void) {

   f(3);
   f(4);

   srand(time(NULL));
   g(20);
   g(14);
   g(40);
   g(555);
   g(1234242322);
}
