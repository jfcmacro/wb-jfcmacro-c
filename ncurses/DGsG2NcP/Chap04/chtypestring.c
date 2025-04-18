#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();

  chtype string[] = {
    'H' | A_BOLD, 'e', 'l' | A_REVERSE, 'l' | A_REVERSE, 'o', '!' | A_UNDERLINE
  };

  // for (int i = 0; string[i]; i++) {
  for (int i = 0; i < sizeof(string)/sizeof(chtype); i++) {
    addch(string[i]);
  }
  
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
