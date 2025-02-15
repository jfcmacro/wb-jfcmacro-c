#include <windows.h>
#include <stdio.h>

#define BUF_SIZE 256

int
main(int argc, char *argv[]) {
  HANDLE hIn, hOut;
  DWORD nIn, nOut;
  CHAR buffer[BUF_SIZE];

  if (argc != 3) {
    printf("Usage: cpW file1 file2\r\n");
    ExitProcess(1);
  }

  hIn = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL,
		   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  if (hIn == INVALID_HANDLE_VALUE) {
    printf("Cannot open input file. Error: %s\n",
	   GetLastError());
    ExitProcess(1);
  }

  hOut = CreateFile(argv[2], GENERIC_WRITE, 0, NULL,
		    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  
  if (hOut == INVALID_HANDLE_VALUE) {
    printf("Cannot open outfile file. Error: %s\n",
	   GetLastError());
    CloseHandle(hIn);
    ExitProcess(1);
  }

  while (ReadFile(hIn, buffer, BUF_SIZE, &nIn, NULL) && nIn > 0) {
    WriteFile(hOut, buffer, nIn, &nOut, NULL);
    if (nIn != nOut) {
      printf("Fatal write error: %d\n",
	     GetLastError());
      ExitProcess(1);
    }
  }

  CloseHandle(hIn);
  CloseHandle(hOut);

  ExitProcess(0);
}
			 
