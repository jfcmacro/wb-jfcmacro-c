/* Prueba 1 */
#include <Windows.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[]) {
 
    if (argc == 2)
        fprintf(stdout , "%s\n\r", argv[1]);
    else
        fprintf(stdout, "Salio\n\r");
        
    fprintf(stderr, "%s hStdIn: %ld hStdOut: %ld \n\r", argv[1],
            GetStdHandle(STD_INPUT_HANDLE),
            GetStdHandle(STD_OUTPUT_HANDLE));
            
    ExitProcess(0);
}

