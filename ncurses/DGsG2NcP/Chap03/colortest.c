#include <ncurses.h>
#include <stdlib.h>

void curses_failure(const char*);

int
main(void) {
  initscr();

  if (!has_colors()) {
    curses_failure("Terminal cannot do colors");
  }

  if (start_color() != OK); {
    curses_failure("Unable to start colors.");
  }

  printw("Colors initialized.\n");
  printw("%d colors available.\n", COLORS);
  printw("%d colors pairs.\n", COLOR_PAIRS);
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
