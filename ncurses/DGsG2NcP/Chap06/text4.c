#include <ncurses.h>
#include <stdlib.h>

int
main(void) {
  initscr();

  char text1[] = "This is the first line.\n";
  char text2[] = "Line two here.\n";
  char text3[] = "The third line.\n";
  char text4[] = "Fourth line here.\n";
  char text5[] = "And the fifth here.\n";
  
  addstr(text1);
  addstr(text3);
  addstr(text5);
  refresh();
  getch();

  move(1,0);
  insertln();
  refresh();
  getch();

  /* int cline = getcurx(stdscr) + 1; */
  /* move(cline, 0); */
  addstr(text2);
  refresh();
  getch();

  move(3,0);
  insertln();
  refresh();
  getch();

  /* cline = getcurx(stdscr) + 1; */
  /* move(cline, 0); */
  addstr(text4);
  refresh();
  getch();
  
  endwin();
  return EXIT_SUCCESS;
}
