#include <stdio.h>
#include <windows.h>

void dormir(int tiempo)
{
	#ifdef WIN
		Sleep(tiempo);
	#endif

	#ifdef LINUX
		sleep(tiempo);
	#endif
}