#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void a(){
	char i;
	for(i='A';i<='Z';i++){
		printf("%c",i);
	}
	printf("\n");
	exit(0);
}

void b(){
	char i;
	for(i='a';i<='z';i++){
		printf("%c",i);
	}
	printf("\n")
		exit(0);
}

void c(){
	char i
		for(i=1;i<26;i++){
			printf("%d",i);
		}
	printf("\n")
		exit(0);
}

void main(){
	pid_t pids[3], pid;
	char *str[3] = {"ABC stop", "abc stop", "123 stop"};
	void (*f[3])() = {a,b,c};
	int i,j;

	for(i=0;i<3;i++){
		pids[i] = fork();
		if(pids[i] == 0){
			f[i]();
		}
	}

	for(i=0;i<3;i++){
		pid = waitpid(-1,NULL,0);
		for(j=0;j<3;j++){
			if(pid==pids[j]){
				printf("%s\n",str[j]);
				break;
			}
		}
	}
}

