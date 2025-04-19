#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int
main(void) {

  initscr();
  int ch = '\0';

  addstr("Type some text; '~' to end:\n");
  refresh();

  while ((ch = getch()) != '~');

  int row,col;
  getyx(stdscr, row, col);
  printw("\n\nThe cursor was at position %d %d ", row, col);
  printw("when you stopped typing.\n");

  refresh();
  getch();
  endwin();

  return EXIT_SUCCESS;
}
