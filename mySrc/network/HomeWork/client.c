#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <pthread.h>

#define PORT 50000
#define MAXSIZE 100

int main(int argc, char **argv){
	
	int sockfd, numbytes;
	char buf[MAXSIZE];
	struct hostent *he;
	struct sockaddr_in their_addr;

	if(argc !=2){
		fprintf(stderr,"usage:%s IP\n",argv[0]);
		exit(1);
	}
	if((he=gethostbyname(argv[1]))==NULL){
			perror("hethostbyname");
			exit(1);
	}

	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr = *((struct in_addr*)he->h_addr);
	bzero(&(their_addr.sin_zero),8);

	if(connect(sockfd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr))==-1){
		perror("connect()");
		exit(1); //요청
	}
	
	/*
	if((numbytes = recv(sockfd,buf,MAXDATASIZE,0))==-1){
		perror("recv");
		exit(1);
	}
	*/
	while(1){
		printf("input Message : ");
		fgets(buf,MAXSIZE,stdin);
		send(sockfd,buf,strlen(buf),0);
		
		if((numbytes =recv(sockfd,buf,MAXSIZE,0))==-1){
			perror("recv");
			exit(1);
		}	

	buf[numbytes] = '\0';
	printf("echo: %s",buf);
	if(!strncmp(buf,"exit",4)){
		break;
	}
	}
	return 0;
}
