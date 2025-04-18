#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>

int
main(void) {

  cchar_t heart = {
    A_NORMAL,
    L"\u2665"
  };

  setlocale(LC_CTYPE, "en_US.UTF-8");
  initscr();

  addstr("I ");
  add_wch(&heart);
  addstr(" Ncurses");
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
