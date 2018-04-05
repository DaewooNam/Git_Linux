#include <signal.h>
#include <stdio.h>

void sig(int sig ) {
		printf("childe die(%d)\n",getpid());	
}

void main(){
	signal(SIGINT,sig);
	pause();
}



