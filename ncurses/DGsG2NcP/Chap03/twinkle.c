#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  initscr();

  attron(A_BOLD);
  addstr("Twinkle, twinkle, little start\n");
  attron(A_BLINK);
  addstr("How I Wonder what you are.\n");
  attroff(A_BOLD);
  addstr("Up above the world so high,\n");
  addstr("Like a diamond in the sky.\n");
  attrset(A_NORMAL);
  addstr("Twinkle, twinkle, little start\n");
  addstr("How I Wonder what you are.\n");
  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}
