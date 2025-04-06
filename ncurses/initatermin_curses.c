#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

int
main(void) {
  if ((initscr()) == NULL) {
    perror("initscr");
    exit(EXIT_FAILURE);
  }

  printw("This is a window get by using ncurses\n");
  refresh();
  sleep(3);

  printw("End the current terminal\n");
  refresh();
  sleep(3);

  endwin();

  return EXIT_SUCCESS;
}
