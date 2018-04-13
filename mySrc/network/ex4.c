#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	
	char **pptr;
	struct hostent			*hptr;
	struct sockaddr_in 	ip_addr;
	struct sockaddr_in 	ip_val;

	inet_aton(argv[1],&ip_addr.sin_addr);
	hptr = gethostbyaddr((char*)&ip_addr.sin_addr,4,AF_INET);
	printf("official hostname : %s\n",hptr->h_name);

	for(pptr= hptr->h_aliases;*pptr !=NULL;pptr++)
		printf("\talias : %s\n",*pptr);

	ip_val.sin_addr.s_addr = *(unsigned long*)hptr->h_addr_list[0];
	printf("address : %s\n",inet_ntoa(ip_val.sin_addr));
	exit(0);


}
