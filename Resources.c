#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int
main() {
  int resources[] = { RLIMIT_CORE, RLIMIT_CPU, 
		      RLIMIT_DATA, RLIMIT_FSIZE,
		      RLIMIT_MEMLOCK, RLIMIT_NOFILE,
		      RLIMIT_NPROC, RLIMIT_OFILE,
		      RLIMIT_STACK
  };
  struct rlimit data;
  struct rusage usage;
  int i;

  for (i = 0; i < sizeof(resources) / sizeof(int); i++) {
    if (getrlimit(RLIMIT_CORE, &data) == 0) {
      fprintf(stdout, "i: %ld current: %d max: %ld\n", i, data.rlim_cur,
	     data.rlim_max);
    }
  }

  if (getrusage(RUSAGE_SELF, &usage) == 0) {
    fprintf(stdout, "%ld\n", usage.ru_nvcsw);
  }
  
  return 0;
}
