#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void center(int, const char*);

int
main(void) {

  initscr();
  int lines, cols;

  center(1, "Penguin Soccer Finals");
  center(5, "Cattle Dung Samples from Temecula");
  center(7, "Catatonic Theater");
  center(9, "Why do ions hate each other?");
  
  getch();
  endwin();

  return EXIT_SUCCESS;
}

void
center(int row, const char* title) {
  int width = getmaxx(stdscr);

  int len = strlen(title);

  int indent = (width - len) / 2;

  mvaddstr(row, indent, title);
  refresh();
}

/* void */
/* center(int row, const char* title) { */
/*   int len, indent, y, width; */
/*   getmaxyx(stdscr, y, width); */

/*   len = strlen(title); */
/*   indent = (width - len) / 2; */

/*   mvaddstr(row, ident, title); */
/*   refresh(); */
/* } */
