#include <windows.h>
#include <stdio.h>

#define MAX_PIPE_NAME 256

int
LeerEscribir(HANDLE hInput, HANDLE hOutput) {

	static char buffer[MAX_PIPE_NAME * 4];
	DWORD nByteRW;
	
	do {

		if (!ReadFile(hInput, buffer, sizeof(buffer), &nByteRW, NULL))
			return -1;
		
		if (!WriteFile(hOutput, buffer, nByteRW, &nByteRW, NULL))
			return -1;

	} while (nByteRW == sizeof(buffer));

	return 0;
}

int
main(int argc, char *argv[]) {

	HANDLE hTuberiaNombrada;
	HANDLE hOutput;
	HANDLE hInput;
	char nombreTuberia[MAX_PIPE_NAME];

	if (argc != 2) {
		fprintf(stderr, "Uso: %s <nombretuberia>\r\n", argv[0]);
		ExitProcess(1);
	}

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	hInput  = GetStdHandle(STD_INPUT_HANDLE);

	sprintf(nombreTuberia, "\\\\.\\PIPE\\%s", argv[1]);

	hTuberiaNombrada = CreateFile(nombreTuberia, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
		SECURITY_IMPERSONATION, NULL);

	if (hTuberiaNombrada == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "Error al abrir tuberia %ld\r\n",
			GetLastError());
		ExitProcess(1);
	}

	while (1) {

		if (LeerEscribir(hInput, hTuberiaNombrada) < 0) {
			fprintf(stderr, "No se pudo leer o escribir %ld\r\n",
				GetLastError());
			ExitProcess(1);
		}

		if (LeerEscribir(hTuberiaNombrada, hOutput) < 0) {
			fprintf(stderr, "No se pudo leer o escribir %ld\r\n",
				GetLastError());
			ExitProcess(1);
		}

	}

	return 0;
}