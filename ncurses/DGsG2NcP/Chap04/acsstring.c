#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  
  initscr();

  attrset(A_ALTCHARSET);
  addstr("Hello, there!");
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
