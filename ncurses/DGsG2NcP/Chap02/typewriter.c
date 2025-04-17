#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  int ch;
  initscr();

  addstr("Type a few lines of text\n");
  addstr("Press ~ to quit\n");

  while ((ch = getch()) != '~');

  endwin();

  return EXIT_SUCCESS;
}


  
