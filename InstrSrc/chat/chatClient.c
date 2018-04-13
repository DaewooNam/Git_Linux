#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <pthread.h>

#define PORT 50000    /* the port client will be connecting to */
#define MAXDATASIZE 100 /* max number of bytes we can get at once */
void* Thread( void *arg )
{
   char buf[MAXDATASIZE];
	int numbytes, fd = *(int*)arg;
	while(1){
    	numbytes=recv(fd, buf, MAXDATASIZE, 0);
		buf[numbytes] = '\0';
    	printf("%s",buf);	
	}
    pthread_exit(0);  /* 쓰레드 종료 함수 */
}
int main(int argc, char *argv[])
{
	pthread_t th;
    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr; /* connector's address information */

    if (argc != 2) {
        fprintf(stderr,"usage: %s IP\n",argv[0]);
            exit(1);
    }    
    if ((he=gethostbyname(argv[1])) == NULL) {  /* get the host info */
        herror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;      /* host byte order */
    their_addr.sin_port = htons(PORT);    /* short, network byte order */
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);     /* zero the rest of the struct */

    if(connect(sockfd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr))==-1){
        perror("connect");
        exit(1);
    }
	pthread_create( &th,NULL,Thread,&sockfd);  
	while(1){
     	printf("msg:\n");
		fgets(buf,MAXDATASIZE,stdin);
		send(sockfd,buf,strlen(buf),0);
		if(!strncmp(buf, "exit", 4)){
			pthread_cancel(th);
			break;
		}
	}
    //close(sockfd);

    return 0;
}
