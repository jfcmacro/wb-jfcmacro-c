#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);

int
main(void) {

  HANDLE hThrd;
  DWORD threadId;

  for (int i = 0; i < 5; ++i) {
    hThrd = CreateThread(NULL, 0,
			 ThreadFunc,
			 (LPVOID) 100,
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
  int nn = (int) n;

  for (int i = 0; i < nn; ++i) {
    printf("%d%d%d%d%d%d%d%\n",
	   nn,nn,nn,nn,nn,nn,nn);
  }

  return 0;
}
