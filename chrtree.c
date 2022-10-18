#include <math.h>
#include <stdio.h>


int
main(void) {
  const int MAX = 8;
  const int SIZE = 92;
  const double OFFSET = 11.5;
  int i = 0;
  double base = OFFSET;
  double angle = atan(((double)SIZE / 2.0)/SIZE);

  for (i = 0; i < MAX; i++, base += OFFSET) {
    printf("iteration: %i base: %f size: %f total: %f\n", i, base, tan(angle) * base, tan(angle) * base * 2.0);
  }

  return 0;
}
