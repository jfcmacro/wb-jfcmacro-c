#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(void) {

  struct termios state1, state2;
  char c;
  int p;

  if (!isatty(STDOUT_FILENO)) {
    fprintf(stderr, "Error output is not standard\n");
    exit(2);
  }

  ioctl(STDOUT_FILENO, TIOCGPGRP, &p);

  if (getpgid(STDIN_FILENO) != p) {
    fprintf(stderr, "Process in background\n");
    exit(2);
  }

  if (!isatty(STDIN_FILENO)) {
    fprintf(stderr, "Error input is not standard");
    exit(2);
  }

  if (ioctl(STDIN_FILENO, TCGETS, &state1) == -1) {
    perror("iotcl\n");
    exit(4);
  }

  state2 = state1;
  state2.c_cc[VMIN] = 1;
  state2.c_lflag &= ~(ECHO | ISIG | ICANON);
  state2.c_oflag |= OLCUC;

  ioctl(STDIN_FILENO, TCSETS, &state2);

  do {
    read(STDIN_FILENO, &c, 1);
    if (c >= 'a' && c <= 'z') write(STDOUT_FILENO, &c, 1);
  } while (c != state2.c_cc[VINTR] &&
	   c != state2.c_cc[VQUIT] &&
	   c != state2.c_cc[VEOF]);

  ioctl(STDIN_FILENO, TCSETS, &state1);
  putchar('\n');

  return EXIT_SUCCESS;
}
