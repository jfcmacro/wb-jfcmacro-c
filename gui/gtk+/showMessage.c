/*
 *
 */

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
SurferPrint(const gchar *buf) {
  printf("Dude, ");
  printf(buf);
}

void
SurferMessage(const gchar *buf) {
  printf("Dude, ya got a message - ");
  printf(buf);
}

void 
SurferWarning(const gchar *buf) {
  printf("Bad news Dude. - ");
  printf(buf);
}

void 
SurferError(const gchar *buf) {
  printf("Major wipe out, dude. - ");
  printf(buf);
}

void
ShowParams() {
  printf("Must pass in parameter. Valid parameter are:\n");
  printf(" 'suffer' - use surfer message handling.\n");
  printf(" 'normal' - use normal message handling.\n");
  exit(0);
}

int
main(int argc, char *argv[]) {

  if (argc <= 1) {
    ShowParams();
  }

  if (strcmp(argv[1], "normal") == 0) {
  } else if (strcmp(argv[1], "surfer") == 0) {
    g_set_error_handler(SurferError);
    g_set_warning_handler(SurferWarning);
    g_set_message_handler(SurferMessage);
    g_set_print_handler(SurferPrint);
  } else {
    ShowParams();
  }

  g_print("Here's a print\n");
  g_message("Here's a message\n");
  g_warning("Here's a warning\n");

  g_error("Here's an error\n");
}
