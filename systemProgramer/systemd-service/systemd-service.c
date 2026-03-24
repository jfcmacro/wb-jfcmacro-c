#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

  char syslog_buffer[BUFFER_SIZE];
  int running = 0;
  
  openlog("systemd-service", LOG_CONS | LOG_ERR | LOG_PID, LOG_USER);
  for(;;) {
    bzero(syslog_buffer, BUFFER_SIZE);
    sprintf(syslog_buffer, "running step: %d", running++);
    syslog(LOG_INFO | LOG_USER, syslog_buffer);
    sleep(10);
  }

  return EXIT_SUCCESS;
}
