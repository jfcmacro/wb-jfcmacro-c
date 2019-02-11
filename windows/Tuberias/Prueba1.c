/* Prueba1 */


#include <windows.h>
#include <stdio.h>
#include <string.h>

int
main() {
    int i = 0;
    HANDLE hStdOut;
    char buffer[] = "ABCEDFGHIJKLMNOPQRSTUVWXYZ\n";
    int nBytesWritten;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for (i = 0; i < 10000; i++) {
        WriteFile(hStdOut, buffer,strlen(buffer) ,&nBytesWritten , NULL);
    }

    fprintf(stderr, "Termino Prueba1\n\r");

    ExitProcess(0);
}
