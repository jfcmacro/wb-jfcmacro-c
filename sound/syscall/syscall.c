/*
 * syscall.c 
 * Program to illustrate common system calls.
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>

int 
main() {
  int fd;
  int arg;
  unsigned char buf[1000];
  int status;
  int fdout;

  /* open device */
  status = fd = open("/dev/dsp", O_RDWR);
  if (status == -1) {
    perror("error openning /dev/dsp");
    exit(1);
  }

  /* set a parameter using ioctl call */
  arg = 8000; /* sampling rate */
  status = ioctl(fd, SOUND_PCM_WRITE_RATE, &arg);
  if (status == -1) {
    perror("error from SOUND_PCM_WRITE_RATE ioctl");
    exit(1);
  }

  /* read some data */
  status = read(fd, buf, sizeof(buf));
  if (status == -1) {
    perror("error reading from /dev/dsp");
    exit(1);
  }
  else {
    fprintf(stdout, "Numero de elementos leidos: %d\n", status);
  }

  status = close(fd);
  if (status == -1) {
    perror("error closing /dev/dsp");
    exit(1);
  }

  status = fdout = open("/dev/audio", O_WRONLY);
  if (status == -1) {
    perror("error opening /dev/sound");
    exit(1);
  }

  /* write some data */
  status = write(fdout, buf, sizeof(buf));
  if (status == -1) {
    perror("error writing to /dev/dsp");
    exit(1);
  }

  status = close(fd);
  if (status == -1) {
    perror("error closing /dev/dsp");
    exit(1);
  }

  return 0;
}
   
