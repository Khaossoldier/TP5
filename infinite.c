#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void
infinite
(int n){
	int i, j;
	pid_t pid;
	for (i = 0; i < n; i++){
		pid = fork();
		switch(pid){
			case -1: exit(EXIT_FAILURE);
			case 0: 
				while (1==1){
					printf("%d", pid);
					sleep(5);
				}
				exit(i);
		}
	}
	for (j=0; j<n; j++){
		wait(&i);
		if(WIFEXITED(i)){
			system("ps");
			printf("%d\n",WEXITSTATUS(i));
		}
	}
}

int
main
(int argc, char *argv[]){
	infinite(atoi(argv[1]));
	return 0;
}
