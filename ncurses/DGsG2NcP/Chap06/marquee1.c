#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int
main(void) {
  initscr();

  char text[] = "Amstrong walks on moon!";
  char *t = text;
  int len = strlen(text);

  int middleLine = LINES / 2;
  int center = (COLS - len + 1) / 2;
  while (len) {
    move(middleLine,center);
    insch(*(t + len - 1));
    refresh();
    napms(100);
    len--;
  }
 
  refresh();
  getch();
  
  endwin();
  return EXIT_SUCCESS;
}
