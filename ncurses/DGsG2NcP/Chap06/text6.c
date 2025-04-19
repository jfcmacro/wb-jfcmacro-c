#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  initscr();


  addstr("This is the first line.\n");
  addstr("Line two here.\n");
  addstr("The third line.\n");
  addstr("Fourth line here.\n");
  addstr("And the fifth here.\n");
  refresh();
  getch();

  move(2,0);
  deleteln();
  refresh();
  getch();

  endwin();
  return EXIT_SUCCESS;
}
