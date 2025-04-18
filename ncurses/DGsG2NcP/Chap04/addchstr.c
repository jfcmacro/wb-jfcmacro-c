#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();

  chtype string[] = {
    'H' | A_BOLD, 'e', 'l' | A_REVERSE, 'l' | A_REVERSE, 'o', '!' | A_UNDERLINE, 0
  };

  addchstr(string);
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
