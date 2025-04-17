#include <ncurses.h>
#include <unistd.h>

int main(void) {
  initscr();

  box(stdscr, '|', '-');
  refresh();
  getch();
  // sleep(5);
  endwin();

  return 0;
}
