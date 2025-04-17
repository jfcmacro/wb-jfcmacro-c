#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  initscr();

  addstr("Attention!\n");
  beep();
  refresh();
  getch();

  addstr("I said, ATTENTION!\n");
  flash();
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
