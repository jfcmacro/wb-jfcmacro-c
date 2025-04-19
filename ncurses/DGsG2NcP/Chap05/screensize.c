#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();
  
  int x, y;
  getmaxyx(stdscr,y,x);
  printw("Window is %d rows by %d columns.\n", y, x);
  refresh();
  getch();
  endwin();

  return EXIT_SUCCESS;
}
