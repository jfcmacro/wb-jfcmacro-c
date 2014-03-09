#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int
main() {
  int mailBox;
  int newMailBox;
  char buffer[BUFFER_SIZE];
  long int nCarLeidos;
  long int nTotalCarLeidos;
  struct flock f_lock;

  mailBox = open("/var/mail/fcardona", O_RDWR);

  nTotalCarLeidos = 0;

  if (mailBox < 0) {
    return 1;
  }

  f_lock.l_start = (off_t) 0;
  f_lock.l_len = (off_t) 0;
  f_lock.l_type = F_WRLCK;
  f_lock.l_whence = SEEK_SET;

  if (fcntl(mailBox, F_SETLKW, &f_lock) < 0) {
    close(mailBox);
    return 2;
  }

  do {

    nCarLeidos = read(mailBox, buffer, BUFFER_SIZE);
    
    if (nCarLeidos > 0) {
      write(1, buffer, nCarLeidos);
      nTotalCarLeidos += nCarLeidos;
    }
    
  } while (nCarLeidos == BUFFER_SIZE);

  f_lock.l_start = (off_t) 0;
  f_lock.l_len = (off_t) 0;
  f_lock.l_type = F_UNLCK;
  f_lock.l_whence = SEEK_SET;
  
  if (fcntl(mailBox, F_SETLKW, &f_lock) < 0) {
    close(mailBox);
    return 3;
  }

  close(mailBox);

/*   if (nTotalCarLeidos > 0) { */
    
/*     mailBox = open("/var/mail/fcardona", O_CREAT | O_TRUNC); */
/*   } */

  return 0;
}
