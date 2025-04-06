#include <ncurses.h>

int 
main() {
  WINDOW *cw;
  int lns = LINES, cols = COLS;
  int x, y;

  x = lns << 1;
  y = cols << 1;

  cw = initscr();
  
  wrefresh(cw);
  wgetch(cw);
  endwin();
  
  return 0;
}
