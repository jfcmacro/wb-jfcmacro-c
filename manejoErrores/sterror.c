#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int sys_nerr;

int
main(int argc, char **argv) {

  int x;
  static int ecodes[] = { -1, EIO, 0 };

  /* Obtiene el código máximo y adiciona 4096 */
  ecodes[2] = sys_nerr + 4096;

  for (x = 0; x < 3; ++x) {
    errno = ecodes[x];
    printf("%4d = '%s'\n", ecodes[x], strerror(errno));
  }

  return 0;
} 
