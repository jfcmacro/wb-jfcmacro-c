#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int
main(void) {
  initscr();

  const char *catMessage = "Where did the silly cat go?";
  const char *FAT = "fat";
  int middleLine = LINES / 2;
  int middleMsgLen = (COLS - strlen(catMessage)) / 2;
 
  move(middleLine,middleMsgLen);
  addstr(catMessage);

  move(middleLine, middleMsgLen + 14);
  for (int i = 0; i < 5; i++) {
    delch();
    refresh();
    napms(250);
  }

  getch();
  
  int fatLen = strlen(FAT);
  for (int i = 0; i < fatLen; i++) {
      move(middleLine, middleMsgLen + 14 + i);
      insch(FAT[i]);
      refresh();
      napms(500);
  }
  
  getch();

  endwin();
  return EXIT_SUCCESS;
}
