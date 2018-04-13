#include <stdio.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(){
	
	struct hostent *hptr;
	struct utsname myname;
	struct sockaddr_in ip_addr;

	if(uname(&myname)<0){
			printf("uname eror\n");
			exit(1);
	}

	if((hptr=gethostbyname(myname.nodename))==NULL){
			perror("hptr()");
			exit(1);
	}
	
	printf("sysname  = %s\n",myname.sysname);
	printf("nodename = %s\n",myname.nodename);
	printf("release  = %s\n",myname.release);
	printf("version  = %s\n",myname.version);
	printf("machine  = %s\n",myname.machine);



	ip_addr.sin_addr.s_addr = *(unsigned long*)hptr->h_addr_list[0];
	printf("hostname : %s, address : %s\n",myname.nodename,inet_ntoa(ip_addr.sin_addr));

	exit(0);


}
