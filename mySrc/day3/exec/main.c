#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX 2

int main(){

	int i;
	
	pid_t pid[MAX];

	pid[MAX-2] = fork();
	pid[MAX-1] = fork();
	if(pid[MAX-2]==0){
	execl("./test1","test1");
	execl("./test2","test2",(char*)0);
	}
	if(pid[MAX-1==0]){
	execl("./test1","test1");
	execl("./test2","test2",(char*)0);
	}
	printf("this line should never get printed\n");
}
