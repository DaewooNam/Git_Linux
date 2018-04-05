#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>


int main(){
	
	char buf[30]; 
	int fd;
	int cnt;

	if((fd=open("a.txt",O_RDONLY))<0){
		perror("open Error");
		exit(1);
	}

	cnt = read(fd,buf,15);
	buf[cnt] = '\0';
	printf("%s",buf);
	

}
