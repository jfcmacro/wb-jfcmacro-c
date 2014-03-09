#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int
main() {


	pid_t pid;

	pid = fork();

	if (pid == -1) {

		fprintf(stdout, "Error: %d\n", errno);
		exit(1);
	}

	if (pid == 0) {
	
		sleep(30);
		exit(1);

	}
	else {

		fprintf(stdout, "Hijo: %d\n", pid);

		int status;

		wait(&status);


		if (WIFEXITED(status)) { //
			
			fprintf(stdout, "Hijo termino con codigo: %d\n", 
				WEXITSTATUS(status));

		}
		else {

			if (WIFSIGNALED(status)) {

				fprintf(stdout, "Señal del hijo: %d\n",
					WTERMSIG(status));
			}
			else {

				if (WIFSTOPPED(status)) {

					fprintf(stdout, "Señal de parada: %d\n",
						WSTOPSIG(status));
				}
		
			}

		}

	}

	return 0;
}	

