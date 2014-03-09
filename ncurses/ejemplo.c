#include <ncurses.h>

int 
main() {

  initscr();
  printw("¡Hola Mundo!");
  refresh();
  getch();
  endwin();
  return 0;
}
