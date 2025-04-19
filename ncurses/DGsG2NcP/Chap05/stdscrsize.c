#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();
  
  printw("Window is %d rows by %d columns.\n", LINES, COLS);
  refresh();
  getch();
  endwin();

  return EXIT_SUCCESS;
}
