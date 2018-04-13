#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <pthread.h>

#define MYPORT 50000    /* the port users will be connecting to */
#define BACKLOG 10     /* how many pending connections queue will hold */
#define MAXSIZE 100
int clients[MAXSIZE], cnt;
pthread_t th[MAXSIZE];
pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
void* Thread( void *arg )
{
	char buf[MAXSIZE];
	char msg[MAXSIZE];
	int numbytes, i, j, fd=*(int*)arg;
	while(1){
    	numbytes=recv(fd, buf, MAXSIZE, 0);
		buf[numbytes] = '\0';
    	printf("client%d: %s",fd, buf);
		sprintf(msg, "client%d: %s", fd, buf);
		pthread_mutex_lock ( &mutex ); 
		for(i=0;i<cnt;i++){
    		send(clients[i],msg,strlen(msg),0);
		}
		if(!strncmp(buf, "exit", 4)){
			pthread_mutex_unlock ( &mutex );
			break;
		}
		pthread_mutex_unlock ( &mutex );
	}
    close(fd);
	for(i=0;i<cnt;i++){
		if(clients[i]==fd){
			for(j=i;j<cnt-1;j++){
				clients[j]=clients[j+1];
				th[j]=th[j+1];
			}
			cnt--;
		}
	}
    pthread_exit(0);  /* 쓰레드 종료 함수 */
}
main()
{
	
    int sockfd, new_fd;  
    struct sockaddr_in my_addr;    /* my address information */
    struct sockaddr_in their_addr; /* connector's address information */
    int sin_size;
    char buf[MAXSIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET;         /* host byte order */
    my_addr.sin_port = htons(MYPORT);     /* short, network byte order */
    my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
    bzero(&(my_addr.sin_zero), 8);        /* zero the rest of the struct */

    if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))== -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    sin_size = sizeof(struct sockaddr_in);
    
	while(1){
		
    	if((new_fd=accept(sockfd,(struct sockaddr *)					&their_addr,&sin_size))== -1){
            perror("accept");
            exit(0);
    		}
		printf("server:connection from %s\n",inet_ntoa(their_addr.sin_addr));
		pthread_mutex_lock ( &mutex );
		clients[cnt]=new_fd;
		pthread_create( &th[cnt],NULL,Thread,&clients[cnt]);  
		cnt++;
		pthread_mutex_unlock ( &mutex );
	}
    
    close(sockfd);
}
