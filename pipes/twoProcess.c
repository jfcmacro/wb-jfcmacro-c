#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{

  pid_t ptChild1, ptChild2;
  int valRetChild1, valRetChild2;
  int fd[2];

  if (pipe(fd) < 0) {

    fprintf(stderr, "Error: due %d %s\n", errno, strerror(errno));
    exit(1);
  }

  if ((ptChild1 = fork()) == 0) {

    close(0);
    dup2(fd[0], 0);
    close(fd[1]);

    execl("/usr/bin/wc", "wc", "-l", NULL);

    fprintf(stderr, "Error: this process never could reach this point\n");
    exit(2);
  }
  else if ((ptChild2 = fork()) == 0) {
    
    close(1);
    dup2(fd[1], 1);
    close(fd[0]);

    execl("/bin/cat", "cat", "twoProcess.c", NULL);

    fprintf(stderr, "Error: this process never could reach this point\n");
    exit(2);
  }

  close(fd[0]);
  close(fd[1]);

  waitpid(ptChild2, &valRetChild2, 0);
  waitpid(ptChild1, &valRetChild1, 0);

  fprintf(stdout, 
	  "%d ends with status: %d\n", ptChild2,
	  WEXITSTATUS(valRetChild2));
  fprintf(stdout, 
	  "%d ends with status: %d\n", ptChild1,
	  WEXITSTATUS(valRetChild1));

  exit(0);
}
