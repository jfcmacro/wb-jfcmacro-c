#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();
  addstr("Goodbye, cruel C programming!");
  refresh();
  getch();
  endwin();

  return EXIT_SUCCESS;
}
