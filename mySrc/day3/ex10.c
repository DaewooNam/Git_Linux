#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void show_mask(){

	sigset_t sigset;

	if(sigprocmask(0,NULL,&sigset)<0)
		printf("sigpromaks error");

	if(sigismember(&sigset, SIGINT))			printf("SIGINT");
	if(sigismember(&sigset, SIGQUIT))		printf("SIGQUIT");
	if(sigismember(&sigset, SIGUSR1))		printf("SIGUSR1");
	if(sigismember(&sigset, SIGALRM))		printf("SIGALRM");

	printf("\n");
}

int main(){

	sigset_t newmask, oldmask;

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask)<0)
		printf("sigprocmask error");

	show_mask();

	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		printf("sigprocmask error");

	exit(0);
}
