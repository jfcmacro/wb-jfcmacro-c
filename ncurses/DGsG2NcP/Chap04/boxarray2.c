#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();

  char box[] = "lqk\nx x\nmqj\n";

  attrset(A_ALTCHARSET);
  addstr(box);
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
