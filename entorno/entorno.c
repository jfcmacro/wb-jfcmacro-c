#include <stdio.h>
#include <unistd.h>

int
main(int argc, char* argv[], char* envp[])
{
  int i;

  printf("\nArguments\n");
  for (i = 0; i < argc; i++) {
    printf("Address: %x Value: %s\n", argv[i], argv[i]);
  }

  printf("\nEnviroment\n");
  for (i = 0; envp[i]; i++) {
    printf("Address: %x Value: %s\n", envp[i], envp[i]);
  }

  exit(0);
}
