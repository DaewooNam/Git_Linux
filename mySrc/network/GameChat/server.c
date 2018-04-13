#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <semaphore.h>

#define MYPORT 50000
#define BACKLOG 10
#define MAXSIZE 100
	
pthread_t threads[MAXSIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int cnt;
int fd_arr[MAXSIZE];

void* Thread(void *arg){
	
	int numbyte, new_fd;
	int i,j;
	char buf[MAXSIZE];
	char msg[MAXSIZE];
	new_fd = *((int*)arg);

	numbyte = recv(new_fd,buf,MAXSIZE,0);//읽은 데어티 수
	buf[numbyte]= '\0';
	printf("recived : %s",buf);


}/*
	while(1){

		numbyte = recv(new_fd,buf,MAXSIZE,0);//읽은 데어티 수
		buf[numbyte]= '\0';
		printf("recived : %s",buf);
		sprintf(msg,"client%d:%s",new_fd,buf);
	}
	
		//send(new_fd,buf,strlen(buf),0);
		//

		pthread_mutex_lock(&mutex);
		for(i=0;i<cnt;i++){
			send(fd_arr[i],msg,strlen(msg),0);
		}	
		
		if(!strncmp(buf,"exit",4)){
			
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);

	}

	close(new_fd);
	//
	for(i=0;i<cnt;i++){
		if(fd_arr[i]==new_fd){
			for(j=i;j<cnt-1;j++){
				fd_arr[j] = fd_arr[j+1];
				threads = threads[j+1];
			}
			cnt--;
		}
	}
	pthread_exit(0);

	
}
*/




main(){

	int  sockfd,new_fd;
//	int  new_fd,numbyte;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	struct thread_arg *th_arg;
	int sin_size;
	int i=0;
	//char buf[MAXSIZE];
	
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);

	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1){
		perror("bind");
		exit(1);
	}

	if(listen(sockfd,BACKLOG)==-1){
		perror("listen");
		exit(1);
	}

	sin_size = sizeof(struct sockaddr_in);

	while(1){
		if((new_fd= accept(sockfd,(struct sockaddr * )&their_addr,&sin_size))==-1){
			perror("accept");
			exit(1); //허용
		}
		
		printf("new_fd = %d\n",new_fd);	
		
		//pthread_create(&threads[i],NULL,(void*(*)(void*))Thread,&new_fd)		

		pthread_mutex_lock(&mutex);
		fd_arr[cnt] = new_fd;
		pthread_create(&threads[cnt],NULL,(void*(*)(void*))Thread,&new_fd);	
		cnt++;
		pthread_mutex_unlock(&mutex);
	}
	

	close(new_fd);
	close(sockfd);
}



