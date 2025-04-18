#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  
  initscr();

  addch('c');
  addch(A_BOLD | 'a');
  addch(A_REVERSE | 't');
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
