#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

main (int argc,char *argv[]){
	int fd_r,fd_w;
	char buf[255];
	char c_r,c_w;
	char *fname_r = "a.txt";
	char *fname_w = "b.txt";
	
	if((fd_r=open(fname_r,O_RDONLY))<0){
		perror("open()");
		exit(-1);
	}
	if((fd_w=open(fname_w,O_WRONLY))<0){
		perror("open()");
		exit(-1);
	}
		

	while(1){
	   if(read(fd_r,&c_r,1))>0){
		fgets(buf,255,fname_r);
	   }
	   else
	   {
		break;
	   }
	}

	printf("%s",buf);
}
