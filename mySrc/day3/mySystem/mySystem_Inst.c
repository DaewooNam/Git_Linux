#include <stdio.h>
#include <unistd.h>
#include <string.h>

void mySystem(char *cmd){
	
	pid_t pid = fork(); //ls 자체도 프로세스 이므로 자식 프로세스가 필요함 
	if(pid==0){
		execlp(cmd,cmd,(char*)0);
	}else if(pid>0){
		wait(NULL);//자식이 죽을때까지 기다림
	}

}

void main(int argc,char *argv[]){
	puts("mySystem() 전");
	mySystem(argv[1]);
	puts("mySystem() 후");

}
