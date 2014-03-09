
struct resultado {
	short codRet;
	short codFalla;
	long valor;
};

program CALPROG {
	version CALVERS {
		resultado SUMAR(long val1, long val2) = 1;
	} = 1;
} = 0x31110001;		
