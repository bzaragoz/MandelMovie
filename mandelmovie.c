#include <errno.h>	// errno()
#include <stdio.h>	// atoi(), printf()
#include <stdlib.h>	// exit(), sprintf()
#include <string.h>	// strerror()
#include <sys/types.h>	// wait()
#include <sys/wait.h>	// wait()
#include <unistd.h>	// exit()

int main (int argc, char** argv){
	float x = 0.38941;
	float y = -0.265;
	float s = 0.000001;

	if (argc < 2){
		printf("Not enough arguments\n");
		printf("Usage: ./mandelmovie <number_of_processes>\n");
	} else if (argc > 2){
		printf("Too many arguments\n");
		printf("Usage: ./mandelmovie <number_of_processes>\n");
	} else {
		int num_processes = atoi(argv[1]);
		float iterations = (2-s)/49;
		pid_t pids[num_processes];

		int i, j;
		for (i = 0; i < 50; i=i+num_processes){
			for (j = 0; j < num_processes; ++j){
				if (i+j < 50){
					if ((pids[j] = fork()) < 0){
						printf("Error: %s\n", strerror(errno));
						exit(EXIT_FAILURE);
					} else if (pids[j] == 0){
						char mandelCommand[100];
						sprintf(mandelCommand, "./mandel -x %F -y %F -s %F -m 2000 -W 1680 -H 1050 -o mandel%i.bmp", x, y, 2-((i+j)*iterations), (i+j)+1);

						system(mandelCommand);
						exit(EXIT_SUCCESS);
					}
				}
			}

			int status, currentProcess = num_processes;
			pid_t pid;
			while (currentProcess > 0){
				pid = wait(&status);
				currentProcess--;

			}
		}
	}

	return 0;
}
