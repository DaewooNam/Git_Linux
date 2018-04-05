#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void catchint(int signo){

	printf("SIGINT RECEIVE %d\n",signo);
	// signal(SIGINT,SIG_DFL);
}

int main(){
	signal(SIGINT,(void *)catchint);

	printf("sleep call #1\n"); sleep(3);
	printf("sleep call #2\n"); sleep(3);
	printf("sleep call #3\n"); sleep(3);
	printf("sleep call #4\n"); sleep(3);
	printf("Exiting");
	exit(0);
}

