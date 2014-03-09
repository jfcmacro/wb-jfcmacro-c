#include <stdio.h>
#include <time.h>

static FILE* logfile = NULL;

void
logPVM(int tid, const char *info) { 
  time_t horaActual;

  if (logfile == NULL) {
    logfile = fopen("/tmp/logfile.log", "a");
  }

  if (logfile != NULL) {
    time(&horaActual);
    fprintf(logfile, "%s %d %s\n", ctime(&horaActual), tid, info);
  }
}
