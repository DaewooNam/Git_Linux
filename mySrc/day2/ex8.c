#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int glob = 6;

int main(){

	int var;
	int fd;
	char buf;
	char *filename = "temp1.txt";

	pid_t pid;

	var = 88;
	printf("before fork\n");
	
	
	if((fd = open(filename,O_RDONLY))<0){
		printf("file open error");
		exit(1);
	}
	while(1){
		read(fd,&buf,1);
		printf("%c",buf);
		if(buf=='\n')
			break;
	}
	
	

	if( (pid=vfork())<0 )
			printf("fork error");
	else if (pid==0){
	
	     while(1){
	       read(fd,&buf,1);
	       printf("%c",buf);
	       if(buf=='\n')
	         break;
	    }


		glob++;
		var++;
		//_exit(0);
		return 1;
	}

	printf("pid = %d, glob= %d, var =%d\n",getpid(),glob,var);

   while(1){
       read(fd,&buf,1);
       printf("%c",buf);
       if(buf=='\n')
          break;
    }



	exit(0);
}
