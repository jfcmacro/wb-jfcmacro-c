#include <ncurses.h>
#include <stdlib.h>

void curses_failure(const char*);

int
main(void) {
  initscr();

  if (!has_colors()) {
    curses_failure("Terminal cannot do colors");
  }

  /* if (start_color() != OK); { */
  /*   curses_failure("Unable to start colors."); */
  /* } */
  start_color();

  init_pair(1, COLOR_YELLOW, COLOR_RED);
  addstr("Normal text\n");
  attrset(COLOR_PAIR(1));
  addstr("Colored text. Wee!\n");
  attrset(A_NORMAL);
  addstr("Back to normal\n");
  refresh();
  getch();
  
  endwin();

  return EXIT_SUCCESS;
}

void curses_failure(const char* message) {
  endwin();
  puts(message);
  exit(EXIT_FAILURE);
}
