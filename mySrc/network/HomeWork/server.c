#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#define MYPORT 50000
#define BACKLOG 10
#define MAXSIZE 100
	
struct thread_arg{
	
	int numbyte,new_fd;
	char buf[MAXSIZE];


};



void* thread(void *arg){
	
	struct thread_arg *p = (struct thread_arg*)arg;
	
	
	while(1){
		p->numbyte = recv(p->new_fd,p->buf,MAXSIZE,0);//읽은 데어티 수
		p->buf[p->numbyte]= '\0';
		printf("recived : %s",p->buf);
		send(p->new_fd, p->buf,strlen(p->buf),0);
		if(!strncmp(p->buf,"exit",4)){
			break;
		}
	}
	
}





main(){

	int  sockfd;
//	int  new_fd,numbyte;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	struct thread_arg *th_arg;
	int sin_size;
	int i=0;
	//char buf[MAXSIZE];
	
	pthread_t threads[2];

	pthread_create(&threads[0],NULL,(void*(*)(void*))thread,th_arg);

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
		if((th_arg->new_fd= accept(sockfd,(struct sockaddr * )&their_addr,&sin_size))==-1){
			perror("accept");
			exit(1); //허용
		}

		printf("new_fd = %d\n",th_arg->new_fd);
		pthread_t threads[2];
		threads[i] = th_arg->new_fd;
		
		/*
		if(new_fd == 5){
			break;
		}
		
		
		pthread_create(&threads[i],NULL,(void*(*)(void*))thread,th_arg);
		i++;
		*/
	}

	/*
	printf("server:connection from%s\n",inet_ntoa(their_addr.sin_addr));
	printf("input Message : ");
	fflush(stdin);

	fgets(buf,MAXSIZE,stdin);
	
	
	if((numbyte = recv(sockfd,buf,MAXSIZE,0))==-1){
		perror("recv");
		exit(1);
	}
	

	while(1){
		numbyte = recv(new_fd,buf,MAXSIZE,0);//읽은 데어티 수
		buf[numbyte]= '\0';
		printf("recived : %s",buf);
		send(new_fd,buf,strlen(buf),0);
		if(!strncmp(buf,"exit",4)){
			break;
		}
	}
	
	
	if(send(new_fd,buf,strlen(buf),0)==-1){
		perror("send");
		exit(0);
	}
*/	
	

	close(th_arg->new_fd);
	close(sockfd);
}



