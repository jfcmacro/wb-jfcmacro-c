#include <math.h>
#include <stdio.h>

int
main() {
   double x = 34.30;

   double res;
   double res2;
   double res3;
   int value;
   long value1;

   res = frexp(x, &value);

   fprintf(stdout, "res: %lf x: %lf value: %d\n", res, x, value);
   fprintf(stdout, "%lf\n", ldexp(res, value));
   res2 = modf(x, &res3);
   fprintf(stdout, "%lf %lf\n", res2, res3);
   value1 = (long) res3;
   fprintf(stdout, "value1: %lf\n", ((double)(value1 % 3)) + res2);

   return 0;
}
