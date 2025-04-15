#include <curses.h>
#include <unistd.h>

int
main(void) {
  int x, y;

  initscr();
  getmaxyx(stdscr, y,x); // getmaxyx is a macro
  printw("Number of lines = %d\n", y);
  printw("Number of rows = %d\n", x);
  refresh();
  sleep(3);
  endwin();

  return 0;
}
