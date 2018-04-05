#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int i=1, flag=0, score;
void a(int sig){
	fflush(stdin);	
	i++;
	if(!flag)
		printf("시간초과\n");
}
void b(int sig){
	printf("당신의 점수는 %d입니다.\n", score);
	exit(0);
}
void main(int argc, char *argv[]){
	char buf[256];
	signal(SIGUSR1, a);
	signal(SIGINT, b);

	for(;;){
		flag=0;
		scanf("%s", buf);
		//printf("test:%d:%s\n", i, argv[i]);
		if(!strncmp(argv[i], buf, 4)){
			printf("success\n");
			score+=10;
		}else{
			printf("fail\n");
		}
		flag=1;
		pause();
	}
}
