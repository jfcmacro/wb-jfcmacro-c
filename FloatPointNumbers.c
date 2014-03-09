#include <stdio.h>
#include <limits.h>
#include <float.h>

int
main(int argc, char *argv[]) {
  float f = 10.0f;
  double d = 10.;
  int i;

  printf("%+##.3a %+##.3A\n", f, d);
  printf("%f %g\n", f/0, -d/0);

  for (i = 0; i < 100; i++) {
    f = f * 100.0f;
  }

  printf("FLT_MIN: %e FLT_RADIX: %d FLT_MAX: %e \n", FLT_MIN, FLT_RADIX, FLT_MAX);
  return 0;
}
