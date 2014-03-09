#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Tomado de Ricard Stevens Advanced Programming in the Unix environment */

int
ptym_open(char *pts_name) {

  char *ptr;
  int fdm;

  if ((fdm = getpt()) < 0) {
    return -1;
  }

  if (grantpt(fdm) < 0) {
    close(fdm);
    return -1;
  }

  if (unlockpt(fdm) < 0) {
    close(fdm);
    return -1;
  }

  if ((ptr = ptsname(fdm)) == NULL) {
    close(fdm);
    return -1;
  }

  strcpy(pts_name, ptr);
  return fdm;
}

int
ptys_open(int fdm, char *pts_name) {

  int fds;

  if ((fds = open(pts_name, O_RDWR)) < 0) {
    close(fdm);
    return -5;
  }

  return fds;
}

