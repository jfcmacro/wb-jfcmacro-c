#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  char t1[] = "Shall I compare thee";
  char t2[] = " to a summer's day?";

  initscr();

  addstr(t1);
  addstr(t2);

  move(2,0);
  addstr("Though art more lovely...");
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}


  
