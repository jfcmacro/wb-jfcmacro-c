#include <windows.h>
#include <stdio.h>

int
main() {

  HANDLE hProcess = GetCurrentProcess();

  DWORD dwPID = GetProcessId(hProcess);

  printf("PID: %ld\n", dwPID);

  HANDLE hTimer = NULL;
  LARGE_INTEGER liDueTime;
  liDueTime.QuadPart = -5000000000LL;

  if ((hTimer = CreateWaitableTimer(NULL, TRUE, NULL)) == NULL) {
    fprintf(stderr, "CreateWaitableTimer failed (%d)\n", GetLastError());
    ExitProcess(1);
  }

  if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0)) {
    fprintf(stderr, "SetWaitable failed (%d)\n", GetLastError());
    ExitProcess(1);
  }

  if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0) {
    fprintf(stderr, "WaitForSingleObject failed (%d)\n", GetLastError());
    ExitProcess(1);
  }

  ExitProcess(0);
}
