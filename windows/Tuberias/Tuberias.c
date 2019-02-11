#include <windows.h>
#include <stdio.h>

int
main() {
    HANDLE hRead;
    HANDLE hWrite;
    PROCESS_INFORMATION pc;
    SECURITY_ATTRIBUTES sa;
    STARTUPINFO si;
    DWORD creation_flags = 0;

    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        fprintf(stderr, "Error: %ld\n\r", GetLastError());
        ExitProcess((DWORD) 0);
    }

    ZeroMemory(&si, sizeof(STARTUPINFO));

    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    si.hStdOutput = hWrite;
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    if (!CreateProcess(NULL, "netstat -a -n", &sa, &sa, TRUE, creation_flags, NULL, NULL,
        &si, &pc)) {
        fprintf(stderr, "Creando prueba1 %ld\n\r", GetLastError());
        ExitProcess((DWORD) 1);
    }

    ZeroMemory(&si, sizeof(STARTUPINFO));

    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = hRead;
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    if (!CreateProcess(NULL, "prueba2", &sa, &sa, TRUE, creation_flags, NULL, NULL,
        &si, &pc)) {
        fprintf(stderr, "Creando prueba2: %ld\n\r", GetLastError());
        ExitProcess((DWORD) 1);
    }

    CloseHandle(hWrite);
    CloseHandle(hRead);

    WaitForSingleObject(pc.hProcess, INFINITE);
    ExitProcess((DWORD) 0);
}
