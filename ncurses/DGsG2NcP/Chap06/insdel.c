#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();

  for (int rows = 0; rows < LINES; rows++) {
    for (int cols = 0; cols < COLS; cols++) {
      addch('.');
    }
  }   
  refresh();
  getch();

  move(5,0);
  insdelln(3);
  refresh();
  getch();

  insdelln(-5);
  refresh();
  getch();
  
  endwin();
  return EXIT_SUCCESS;
}
