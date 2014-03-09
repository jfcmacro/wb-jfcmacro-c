#include <windows.h>
#include <stdio.h>

#define MAX_PIPE_NAME 256

int
LeerEscribir(HANDLE hInput, HANDLE hOutput) {

	static char buffer[MAX_PIPE_NAME * 4];
	DWORD nByteRW;
	OVERLAPPED overlapped;

	overlapped.hEvent = NULL;
	overlapped.InternalHigh = 0;
	overlapped.Offset = 0;

	do {

		if (!ReadFile(hInput, buffer, sizeof(buffer), &nByteRW, &overlapped))
			return -1;
		
		if (!WriteFile(hOutput, buffer, nByteRW, &nByteRW, NULL))
			return -1;

	} while (nByteRW == sizeof(buffer));

	return 0;
}

int
main(int argc, char *argv[]) {

	HANDLE hTuberiaNombrada;
	SECURITY_ATTRIBUTES SecurityAttributes;
	SECURITY_DESCRIPTOR SecurityDescriptor;
	char nombreTuberia[MAX_PIPE_NAME];
	HANDLE hOutput;
	HANDLE hInput;

	if (argc != 2) {
		fprintf(stderr, "Uso: %s <nombretuberia>\r\n", argv[0]);
		ExitProcess(1);
	}

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	hInput  = GetStdHandle(STD_INPUT_HANDLE);
	
	InitializeSecurityDescriptor(&SecurityDescriptor,
		SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&SecurityDescriptor, TRUE,
		NULL, FALSE);
	SecurityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
	SecurityAttributes.bInheritHandle = FALSE;
	SecurityAttributes.lpSecurityDescriptor = &SecurityDescriptor;

	sprintf(nombreTuberia, "\\\\.\\PIPE\\%s", argv[1]);

	hTuberiaNombrada = CreateNamedPipe(nombreTuberia,
		PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, PIPE_WAIT, 1, 0, 0, 0, &SecurityAttributes);

	if (hTuberiaNombrada == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "Error al crear handle %ld\r\n",
			GetLastError());
		ExitProcess(1);
	}

	if (!ConnectNamedPipe(hTuberiaNombrada, NULL))  {
		fprintf(stderr, "Error al connectar cliente %ld\r\n",
			GetLastError());
		ExitProcess(1);
	}

	while (1) {

		if (LeerEscribir(hTuberiaNombrada, hOutput) < 0) {
			fprintf(stderr, "No se pudo leer o escribir %ld\r\n",
				GetLastError());
			ExitProcess(1);
		}

		if (LeerEscribir(hInput, hTuberiaNombrada) < 0) {
			fprintf(stderr, "No se pudo leer o escribir %ld\r\n",
				GetLastError());
			ExitProcess(1);
		}
	}

	return 0;
}
