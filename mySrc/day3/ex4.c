#include <stdio.h>
#include <sys/types.h>
#include <wait.h>


int main(){

	pid_t pid1, pid2,pid3;
	
	int  i;
	char ch;

	int pid_num1,pid_num2,pid_num3;


	pid1 = fork();

	if(pid1==0){
		for(i=1;i<26;i++){
			printf("%d",i);
		}
		printf("\n");
		exit(0);


	}


	pid2 = fork();

	if(pid2==0){
		for(i='a';i<='z';i++){
			printf("%c",i);
		}
		printf("\n");
		exit(0);
	}

	pid3 = fork();

	if(pid3==0){
		for(i='A';i<='Z';i++){
			printf("%c",i);
		}
		printf("\n");
		exit(0);
	}
	
	//pid = waitpid(-1,NULL,0);


	printf("%d %d %d\n",pid_num1,pid_num2,pid_num3);









}
