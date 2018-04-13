#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
int flag=1;
pid_t pids[2];
void a(int sig){
	printf("문제 출제 프로세스 종료\n");
	kill(pids[1], SIGINT);
	flag=0;
}
void main(){
	int cnt = 0, i;
	FILE *fp = NULL;
	char buf[256][256];
	char *buf2[256];
	fp = fopen("a.txt", "r");
	signal(SIGUSR2, a);
	while(fgets(buf[cnt], 256, fp)!=NULL){
		cnt++;
	}
	for(i=0;i<cnt;i++){
		buf2[i+1]=buf[i];
	}
	buf2[i+1]=(char *)0;
	for(i=0;i<2;i++){
		pids[i] = fork();
		if(pids[i]==0){
			if(i==0){
				buf2[0]="proc1";
				execv("./proc1", buf2);
			}else if(i==1){
				buf2[0]="proc2";
				execv("./proc2", buf2);
			}
		}
	}

	while(flag){
		kill(pids[0], SIGUSR1);
		sleep(5);
		kill(pids[1], SIGUSR1);
	}

	while(wait(NULL)!=pids[1]){}
	fclose(fp);
	printf("program exited\n");
}
