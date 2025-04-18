#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();

  chtype box[] = {
    ACS_ULCORNER,  ACS_HLINE,  ACS_URCORNER, '\n',
    ACS_VLINE, ' ', ACS_VLINE, '\n',
    ACS_LLCORNER, ACS_HLINE, ACS_LRCORNER, '\n',
    0
  };

  addchstr(box);
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
