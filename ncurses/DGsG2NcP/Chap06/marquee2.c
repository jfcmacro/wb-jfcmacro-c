#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int
main(void) {
  initscr();

  char text[] = "Amstrong walks on moon!";
  int len = strlen(text);
  char *t = text;
  int middleLine = LINES / 2;
  int center = (COLS - len + 1) / 2;
  move(middleLine, 0);
  for (char a = 'a'; a < 'Z' + 1; a++) {
    addch(a);
    addstr("  ");
  }

  
  while (len) {
    move(middleLine, center);
    insch(*(t + len - 1));
    refresh();
    napms(100);
    len--;
  }
  getch();

  
  endwin();
  return EXIT_SUCCESS;
}
