#include <stdio.h>

static FILE* logfile = NULL;

void
Log(const char *info) { 
  
  if (logfile == NULL) {
    logfile = fopen("logfile.log", "a");
  }

  if (logfile != NULL) {
    fprintf(logfile, "%s\n", info);
  }
}
