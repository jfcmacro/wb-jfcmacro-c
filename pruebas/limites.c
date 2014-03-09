#include <sys/time.h> 
#include <sys/resource.h> 
#include <unistd.h> 

int
main() {

	int limites[] = { RLIMIT_CPU, RLIMIT_FSIZE, RLIMIT_DATA,
			RLIMIT_STACK, RLIMIT_CORE, RLIMIT_RSS,
			RLIMIT_NPROC, RLIMIT_NOFILE, RLIMIT_MEMLOCK,
 			RLIMIT_AS };
	char *char_limites[] = { "RLIMIT_CPU", "RLIMIT_FSIZE", "RLIMIT_DATA",
			"RLIMIT_STACK", "RLIMIT_CORE", "RLIMIT_RSS",
			"RLIMIT_NPROC", "RLIMIT_NOFILE", "RLIMIT_MEMLOCK",
 			"RLIMIT_AS" };
	struct rusage uso;

	int i;

	for (i = 0; i < sizeof(limites) /sizeof(int); i++) {
		struct rlimit datos;
		getrlimit(limites[i], &datos);
		printf("%s %d %d\n", char_limites[i], datos.rlim_cur,
			datos.rlim_max);
	}

	getrusage(getpid(), &uso);

	printf("ru_maxrss: %ld\n", uso.ru_maxrss);
	printf("ru_ixrss: %ld\n", uso.ru_ixrss);
	printf("ru_idrss: %ld\n", uso.ru_idrss);
	printf("ru_isrss: %ld\n", uso.ru_isrss);
	printf("ru_minflt: %ld\n", uso.ru_minflt);
	printf("ru_majflt: %ld\n", uso.ru_majflt);
	printf("ru_nswap: %ld\n", uso.ru_nswap);
	printf("ru_inblock: %ld\n", uso.ru_inblock);
	printf("ru_outblock: %ld\n", uso.ru_oublock);
	printf("ru_msgrcv: %ld\n", uso.ru_msgrcv);
	printf("ru_nsignals: %ld\n", uso.ru_nsignals);
	printf("ru_nvcsw: %ld\n", uso.ru_nvcsw);
	printf("ru_nivcsw: %ld\n", uso.ru_nivcsw);
	
	return 0;
} 
