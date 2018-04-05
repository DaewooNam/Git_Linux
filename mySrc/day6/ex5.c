#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main (){

	int fd;
	char c;
	
	if((fd=open("test.txt",O_RDONLY))<0){
		perror("open");
		exit(0);
	}
	while(1){
		if(read(fd,&c,1)>0)
			putchar(c);
		else
			break;
	}
	exit(0);

}
