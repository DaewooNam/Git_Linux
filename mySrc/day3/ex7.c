#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig){
	printf("signal no(%d) Receieve\n",sig);
}

void main(){

	if(signal(SIGUSR1,handler)==SIG_ERR){
		fprintf(stderr,"cannot set USR!\n");
		exit(1);
	}
	if(signal(SIGUSR2,handler)==SIG_ERR){
		fprintf(stderr,"cannot set USR2\n");
		exit(1);
	}
	for(;;)
		pause();
}


