#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

int
main(void) {
  SCREEN *screen;

  if ((screen = newterm(NULL, stdout, stdin)) == NULL) {
    perror("newterm");
    return EXIT_FAILURE;
  }

  if (set_term(screen) == NULL) {
    endwin();
    delscreen(screen);
    perror("set_term");
    return EXIT_FAILURE;
  }

  printw("This ncurses' screen has been created by newterm\n");
  refresh();
  sleep(3);
  printw("End now the screen\n");

  refresh();
  sleep(3);
  endwin();
  delscreen(screen);

  return EXIT_SUCCESS;
}
