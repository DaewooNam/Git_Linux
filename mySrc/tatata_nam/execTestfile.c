#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int flag=1;
pid_t pids[2];
void a(int sig){
	printf("문제 출제 프로세스 종료\n");
	flag=0;
}


void main(){
	int cnt = 0, i,j;
	FILE *fp = NULL;
	char buf[256][256];
	char buf2[256][256];
	char ch[30];
	int fd1[2], fd2[2];

	if(pipe(fd1)<0 || pipe(fd2)<0){
			perror("pipe error");
			exit(1);
	}


	fp = fopen("a.txt", "r");
	while(fgets(buf[cnt], 256, fp)!=NULL){
		cnt++;
	}
	/*
	for(i=0;i<cnt;i++){
		buf2[i+1]=buf[i];
	}
	buf2[i+1]=(char *)0;
	*/
	for(i=0;i<2;i++){
		pids[i] = fork();
		if(pids[i]==0){
			if(i==0){ 

				close(fd1[1]);
				for(j=0;j<cnt;j++){
					read(fd1[0],buf2[j],256);
					printf("%s",buf2[j]);
					sleep(5);
				}			

			}else if(i==1){
				
				printf("aa");
				close(fd2[1]);
				close(fd1[1]);
				for(j=0;j<cnt;j++){
					read(fd1[0],buf[j],256);
				}
				read(fd2[0],ch,30);
				
				for(j=0;j<cnt;j++){

					if(!strcmp(buf[j],ch)){
						printf("sucess");
						break;
					}
					else{
						printf("fail");
						break;
					}
				}



			}
		}else if(pids[i]>0){
			
			close(fd1[0]);
			close(fd2[0]);

			//pipe2
			for(j=0;j<cnt;j++){
				write(fd1[1],buf[j],256);
			}
			
			//pipe1
			scanf("%s",ch[30]);
			write(fd2[1],ch,30);

			
		}

		


	}


	while(wait(NULL)!=pids[1]){}
	fclose(fp);
	printf("program exited\n");
}
