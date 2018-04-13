#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define MYPORT 50000    /* the port users will be connecting to */
#define BACKLOG 10     /* how many pending connections queue will hold */
#define MAXSIZE 100
main()
{
    int sockfd, new_fd, numbytes;  
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
    if((new_fd=accept(sockfd,(struct sockaddr *)&their_addr,&sin_size))== -1){
            perror("accept");
            exit(0);
    }
    printf("server:connection from %s\n",inet_ntoa(their_addr.sin_addr));
	while(1){
    	numbytes=recv(new_fd, buf, MAXSIZE, 0);
		buf[numbytes] = '\0';
    	printf("Received: %s",buf);
    	send(new_fd,buf,strlen(buf),0);
		if(!strncmp(buf, "exit", 4)){
			break;
		}
	}
    close(new_fd);
    close(sockfd);
}
