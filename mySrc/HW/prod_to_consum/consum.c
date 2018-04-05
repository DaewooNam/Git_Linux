#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_consum{
	
	int type;
	char text[BUFSIZ];

};

int main(){

	int flag = 1;
	int msgid;
	char buf[256];
	char buf2[256];
	int i=0;
	struct my_consum my_data;

	msgid = msgget((key_t)1234,0666|IPC_CREAT);

	if(msgid == -1){
		perror("msgid()");
		exit(1);
	}
	
	while(flag){
		
		sleep(2);	
		if(msgrcv(msgid,(void*)&my_data,256,0,0)==-1){
		
			perror("msgrcv()");
			exit(1);
		}
		
		printf("You wrote : %s",my_data.text);
		
		//fets(buf2,256,stdin);
		/*
		if(!strcmp(buf,"\n")){
		
			if(msgrcv(msgid,(void*)&buf,256,0,0)==-1){
		
				perror("msgrcv()");
				exit(1);
			}
			printf("you Wrote : %s",buf);
		}
		*/

		if(strncmp(my_data.text,"end",3)==0){
			flag =0;
		}

	}
		
	if(msgctl(msgid,IPC_RMID,0)==-1){
		perror("msgctl()");
		exit(3);
	}

	exit(0);


}
