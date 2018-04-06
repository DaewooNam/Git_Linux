#include<stdio.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
int f=0, w_fd;
void child1(int fd){
	char buf[256];
	while(read(fd, buf, 256)>0){
		if(!strncmp(buf, "end", 3)){
			break;
		}
		printf("문제:%s\n", buf);
	}
	printf("문제 종료\n");
}
void a(int sig){
	if(!f){
		printf("시간초과\n");
		write(w_fd, "\0", 1);
	}
}
void child2(int fd){
	char buf[256];
	w_fd=fd;
	signal(SIGUSR1, a);
	while(1){
		f=0;
		scanf("%s", buf);
		f=1;
		write(fd, buf, 256);
		pause();
	}
}
void main(){
	pid_t pid;
	FILE *fp;
	int p1[2],p2[2], score=0;
	char buf[256], buf2[256];
	pipe(p1);
	if(fork()==0){
		close(p1[1]);
		child1(p1[0]);
		exit(0);
	}
	pipe(p2);
	if((pid=fork())==0){
		close(p2[0]);
		child2(p2[1]);
		exit(0);
	}
	close(p1[0]);
	close(p2[1]);
	fp = fopen("a.txt", "r");
	while(fgets(buf, 256, fp)!=NULL){
		write(p1[1], buf, 256);
		sleep(5);
		kill(pid, SIGUSR1);
		sleep(1);
		read(p2[0], buf2, 256);
		printf("p:%sa:%s\n",buf, buf2);
		if(!strncmp(buf, buf2, 4)){
			printf("success\n");
			score+=10;
		}else{
			puts("fail");
		}
		sleep(3);
	}	
	write(p1[1], "end", 3);
	kill(pid, SIGINT);
	printf("score:%d\n", score);
	close(p1[1]);
	close(p2[0]);
	fclose(fp);
}
