#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int i=1, cnt;
char **p;
void a(int sig){
	printf("%s", p[i++]);
	if(i==cnt){
		sleep(5);
		printf("문제가 종료되었음\n");
		kill(getppid(), SIGUSR2);
		exit(0);
	}
}
void main(int argc, char *argv[]){
	p = argv;
	cnt = argc;
	signal(SIGUSR1, a);
	for(;;)
		pause();
}
