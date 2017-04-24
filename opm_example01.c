#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int npoints, iam, np, mypoints;
double *x;

int main() {
  scanf("%d", &npoints);

  x = (double *) malloc(npoints * sizeof(double));

  initialize();
#pragma omp parallel shared(x,npoints) private(iam, np, mypoints)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    mypoints = npoints / np;
    compute_subdomain(x, iam, mypoints);
  }

  return 0;
}
