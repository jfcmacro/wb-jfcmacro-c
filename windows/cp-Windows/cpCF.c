#include <windows.h>
#include <stdio.h>

int
main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: cpCF file1 file2\r\n");
    ExitProcess(1);
  }


  if (!CopyFile(argv[1], argv[2], FALSE)) {
    printf("CopyFile Error: %d\n",
	   GetLastError());
    ExitProcess(1);
  }


  ExitProcess(0);
}
			 
