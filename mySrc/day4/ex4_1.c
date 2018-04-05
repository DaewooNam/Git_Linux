#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st{
	int my_msg_type;
	char some_text[MAX_TEXT];
};

int main(){
	int n;
	int running =1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];
	int  buffer2;
	msgid = msgget((key_t)1234,0666 | IPC_CREAT);

	if(msgid == -1){
		perror("msgid()");
		exit(1);
	}

	while(running){
		printf("Enter some text&type : ");
		scanf("%s",buffer);
		n = strlen(buffer);
		buffer[n] = '\n';
		//fgets(buffer,BUFSIZ,stdin);
		printf("type : ");
		//scanf("%d",buffer2);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text,buffer);	
		
		//printf("%s",some_data.some_text);

		if(msgsnd(msgid,(void*)&some_data,MAX_TEXT,0)==-1){
			perror("msgsnd()");
			exit(2);
		}
		if(strncmp(buffer,"end",3)==0){
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
}



