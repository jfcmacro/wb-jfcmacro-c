#include <ncurses.h>

int 
main() {
  WINDOW *cw;
  int nLnsTerm;
  int nColsTerm;
  int x, y;


  cw = initscr();
  nLnsTerm = LINES;
  nColsTerm = COLS;
  y = nLnsTerm >> 1;
  x = 20; // nColsTerm >> 1;
  mvwprintw(cw, y, x, "Lines: %d Cols: %d at x: %d y: %d",
            nLnsTerm, nColsTerm, x, y);

  // wprintw(cw,"Lines: %d Cols: %d at x: %d y: %d",
  //           nLnsTerm, nColsTerm, x, y);
  
  wrefresh(cw);
  wgetch(cw);
  endwin();
  
  return 0;
}
