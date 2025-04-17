#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  char text[] = "Greetings from Ncurses!";
  char *t;

  initscr();

  t = text;

  while (*t) {
    addch(*t);
    t++;
    refresh();

    napms(100);
  }

  getch();

  endwin();

  return EXIT_SUCCESS;
}


  
