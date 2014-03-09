#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

static char *errorFileName = (char *) NULL;
static FILE* errorFILE = (FILE *) NULL;
static char *logFileName = (char *) NULL;
static int logFileFd = -1;

FILE*
getErrorFILE() {

  if (!errorFILE) {
    if (errorFileName)
      errorFILE = fopen(errorFileName, "a+");
    else 
      return stderr;
  }

  return errorFILE;
}

static void
setName(char **dest, char *org) {
  
  if (org) {
    int length = strlen(org);

    if (length > 0) { 

      if (*dest) 
	free(*dest);

      *dest = (char *) malloc(length + 1);

      strncpy(*dest, org, length);
    }
  }
}

void
setErrorFileName(char *name) {

  setName(&errorFileName, name);
  
}

int
createLogFile(char *name) {
  int fd;

  setName(&logFileName, name);

  fd = open(logFileName, O_WRONLY | O_CREAT | O_TRUNC, 0600);

  if (fd < 0)
    return -1;

  logFileFd = fd;
  
  return 0;
}

void
writeLogFile(char *message) {

  char *buffer;
  time_t currentTime;

  if (message) {

    buffer = malloc(strlen(message) + 40);
    currentTime = time((time_t *)NULL);
    sprintf(buffer, "%s %s\n", ctime(&currentTime), message);
    write(logFileFd, buffer, strlen(buffer));
    free(buffer);
  }
}
