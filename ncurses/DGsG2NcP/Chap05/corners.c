#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  initscr();
  int lines, cols;

  getmaxyx(stdscr, lines, cols);
  lines--;
  cols--;

  mvaddch(0,0,'*');
  refresh();
  napms(500);

  mvaddch(0,cols,'*');
  refresh();
  napms(500);

  mvaddch(lines,0,'*');
  refresh();
  napms(500);

  mvaddch(lines,cols,'*');
  refresh();
  napms(500);
  
  getch();
  endwin();

  return EXIT_SUCCESS;
}
