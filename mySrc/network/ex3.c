#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc,char **argv){
	
	struct sockaddr_in ip_addr;
	char *ip;

	ip_addr.sin_addr.s_addr = inet_addr(argv[1]);
	printf("inet_addr() : dotten decimal(%s)->hexa(%x)\n",argv[1],ip_addr.sin_addr.s_addr);
	
	ip = inet_ntoa(ip_addr.sin_addr);
	printf("inet_addr() : dotten decimal(%s)->hexa(%x)\n",ip_addr.sin_addr.s_addr,ip);
	
	exit(0);
}
