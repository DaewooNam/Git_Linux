#include <stdio.h>
#include <sys/types.h>
#include <wait.h>

int main(){

	pid_t pid;
	printf("i'm the original process : pid = %d, ppid = %d\n",getpid(),getppid());
	pid = fork();

	if( pid != 0){
		printf("i'm parent process : pid = %d, ppid = %d\n",getpid(),getppid());
		printf("my child process : pid = %d\n",pid);
		wait(NULL);
	}
	else{
		sleep(5);
		printf("i'm childe process : pid = %d, ppid=%d\n",getpid(),getppid());
	}

	printf("pid %d terminates \n",getpid());
}

