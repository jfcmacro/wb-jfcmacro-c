#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);

int
main(void) {

  HANDLE hThrd;
  DWORD threadId;
  int i;

  for (i = 0; i < 5; ++i) {
    hThrd = CreateThread(NULL, 0,
			 ThreadFunc,
			 (LPVOID) i,
			 0,
			 &threadId);
    if (hThrd) {
      printf("Thread launced\n");
    }
  }

  // Sleep(2000);
  return EXIT_SUCCESS;
}

DWORD WINAPI ThreadFunc(LPVOID n) {
  int i;

  for (i = 0; i < 10; ++i) {
    printf("%d%d%d%d%d%d%d%\n",
	   n,n,n,n,n,n,n);
  }
}
