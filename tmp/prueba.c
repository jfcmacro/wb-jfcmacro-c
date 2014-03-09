#include <stdio.h>

int
main()
{
   struct valor { int a; char c; } a;
   struct valor2 { int a; char c; int d; } b;

   a.a = 5;
   a.c = 'a';

   printf("b.a: %d b.c: %c\n", b.a, b.c);
   return 0;
}
