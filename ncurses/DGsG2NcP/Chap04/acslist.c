#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  
  initscr();
 
  for (int a = 0; a < 127; a++) {
    printw("\t%2X:", a);
    addch(A_ALTCHARSET | a);
  }
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
