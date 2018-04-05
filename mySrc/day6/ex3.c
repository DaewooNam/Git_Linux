#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

main(){
	char *fname = "test.txt";
	int fd;
	off_t fsize;
	
	if((fd=open(fname,O_RDONLY))<0)
	{
		perror("open()");
		exit(-1);
	}
	fsize = lseek(fd,0,SEEK_END);
	printf("the size of <%s> is %u bytes.\n", fname,fsize);
	exit(0);


}
