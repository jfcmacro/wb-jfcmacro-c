#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  initscr();
  start_color();

  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  attrset(COLOR_PAIR(1));

  addstr("I'm Mr. Black!\n");
  attrset(COLOR_PAIR(2));

  addstr("I am Mr. Yellow!\n");
  attrset(COLOR_PAIR(1) | A_BOLD);

  addstr("I am feeling bold!\n");
  attrset(COLOR_PAIR(2) | A_BOLD);

  addstr("Me too!");
  refresh();
  getch();
  
  endwin();
  return EXIT_SUCCESS;
}
