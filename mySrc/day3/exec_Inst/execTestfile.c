#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(){
	pid_t pids[2];
	int cnt = 0,i;
	FILE *fp =NULL;
	char buf[256][256];
	char *buf2[256];
	fp = fopen("a.txt","r");
	while(fgets(buf[cnt],256,fp)!=NULL){
		cnt++;
	}
	for(i=0;i<cnt;i++){
		buf2[i+1] = buf[i];
	}

	buf2[i+1] = (char*)0;
	for(i=0;i<2;i++){
		pids[i] =fork();
		if(pids[i]==0){
			if(i==0){
				buf2[0] ="proc1";
				execv("./proc1",buf2);
			}else if(i==1){
				buf2[0] = "proc2";
				execv("./proc2",buf2);
			}
		}
	}
	for(i=0;i<2;i++){
		wait(NULL);
	}
	fclose(fp);
	printf("program exited\n");
}

