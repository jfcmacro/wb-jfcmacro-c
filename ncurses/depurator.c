#include <curses.h>

int
main(void) {
  initscr();

  curses_trace(TRACE_CALLS);
  printw("Set debug level for TRACE_CALLs");
  refresh();
  endwin();

  return 0;
}
