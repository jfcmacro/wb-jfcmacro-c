#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  
  initscr();

  addch(A_ALTCHARSET | ACS_PI);
  addstr(" = 3.14159");
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
