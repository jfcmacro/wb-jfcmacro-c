/* Prueba 2 */

#include <Windows.h>
#include <stdio.h>

int
main() {
    int i = 0;
    HANDLE hStdIn;
    char buffer[30];
    int nBytesRead;
    
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    
    do {
        ReadFile(hStdIn, buffer, 29, &nBytesRead , NULL);
        buffer[29] = '\0';
        fprintf(stdout, "%s\n\r", buffer);
        
    } while (nBytesRead >=29);
    
    buffer[nBytesRead] = '\0';
    fprintf(stdout, "%s\n\r", buffer);
}

