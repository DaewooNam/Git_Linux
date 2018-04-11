#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st {
	
	int type;
	char text[BUFSIZ];

};

int main(){

	int flag = 1;
	int msgid;
	int n;
	char buf[256];
	char buf2[256];
	int i=1;
	//struct my_prod my_data;
	struct my_msg_st my_data;

	msgid = msgget((key_t)1234,0666|IPC_CREAT);

	if(msgid == -1){
		perror("msgid()");
		exit(1);
	}
	
	while(flag){
		
		//sleep(1);
		printf("file produce : ");
		sprintf(buf,"%s%d","st",i);	
		strcpy(my_data.text,buf);
		i++;
		printf("%s\n",my_data.text);
		my_data.type=1;

		if(msgsnd(msgid,(void*)&my_data,BUFSIZ,0)==-1){
	
			perror("msgsnd()");
			exit(2);
		}
		
		
		if(strcmp(buf,"st50")==0){
			flag = 0;
		}
	}
		
	exit(0);


}
