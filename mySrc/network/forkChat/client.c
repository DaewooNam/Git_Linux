#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 1024



char *escapechar = "exit\n";

int main(int argc, char *argv[]){

	char line[MAXLINE];
	char sendline[MAXLINE];
	char recvline[MAXLINE+1];
	char *haddr;
	int n,size,comp,port;
	pid_t pid;
	static int s;
	static struct sockaddr_in server_addr;
	int len;
	static struct sockaddr_in fd_ser;

	if(argc<3){
		perror("argc[]");
		exit(1);
	}else{
		haddr = argv[1];
		port = atoi(argv[2]);
	}

	if((s = socket(PF_INET,SOCK_STREAM,0))<0){
		perror("socket()");
		exit(1);
	}
	bzero((char*)&server_addr,sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(haddr);
	server_addr.sin_port = htons(port);


	if(connect(s,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
		printf("client:can't connect to server.\n");
		exit(1);
	}
	len = sizeof(fd_ser);
	if(getpeername(s,(struct sockaddr*)&fd_ser,&len)==0){
		printf("fd_ser IP :%s,Port = %u",inet_ntoa(fd_ser.sin_addr),(unsigned)ntohs(fd_ser.sin_port));
	}
	if((pid = fork())>0){
		while((size = read(0,sendline,MAXLINE))>0){
			sendline[size] = '\0';
			if(write(s,sendline,strlen(sendline)) !=size){
				printf("client : can't write to server.\n");
				exit(1);
			}
			if(strncmp(sendline,escapechar,4)==0){
				kill(pid,SIGQUIT);
				break;
			}
		}
	}
	else if(pid ==0){
		while(1){
			if((size=read(s,recvline,MAXLINE))>0){
				recvline[size] = '\0';
				if(strncmp(recvline,escapechar,4)==0){
						kill(getppid(),SIGQUIT);
						break;
				}
			}
		}
	}

	close(s);
}




