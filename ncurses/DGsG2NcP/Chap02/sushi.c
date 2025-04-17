#include <ncurses.h>
#include <stdlib.h>

int
main(void) {

  int pieces;
  const float uni = 4.5;

  initscr();

  addstr("SUSHI BAR");
  move(2,0);
  printw("We have UNI today for %.2f.\n", uni);
  addstr("How many pieces would you like?");

  refresh();

  scanw("%d", &pieces);
  printw("You want %d pieces?\n", pieces);
  printw("That will be $%.2f!", uni*(float)pieces);

  refresh();
  getch();

  endwin();

  return EXIT_SUCCESS;
}


  
