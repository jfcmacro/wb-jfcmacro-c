#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>

int
main(void) {

  wchar_t hello[] = {
    0x041f, 0x0440, 0x0438,
    0x0432, 0x0435, 0x0442,
    0x0021, 0x0
  };

  setlocale(LC_CTYPE, "en_US.UTF-8");
  initscr();

  addwstr(hello);
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}
