#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

main(){

	pid_t pid;
	//printf("pid = %d,ppid = %d\n",getpid(),getppid());

	int i;
	char ch;
	pid = fork();

	if(pid<0){
		printf("프로세스 생성실패\n");
	}
	else if(pid==0){
		printf("자식 프로세스\n");
		for(i=0;i<10;i++){
			printf("숫자 : %d\n",i);
			sleep(1);
		}
	}
	else
		printf("부모 프로세스\n");
		for(i=0;i<10;i++){
			printf("문자 : %c\n",65+i);
			sleep(2);
		}

	//printf("pid = %d,ppid=%d\n",getpid(),getppid());
}
