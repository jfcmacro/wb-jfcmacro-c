#include <stdio.h>
#include <time.h>

static FILE* logfile = NULL;

void
logPVM(int tid, const char *info) { 
  
  if (logfile == NULL) {
    logfile = fopen("/tmp/logfile.log", "a");
  }

  if (logfile != NULL) {
    fprintf(logfile, "%s %d %s\n", ctime(time(NULL)), tid);
  }
}
