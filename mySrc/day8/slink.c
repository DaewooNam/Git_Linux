#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
main(int argc, char **argv){

   int fd, nbyte;
   char buf[256];

   if(argc !=3){
	printf("usage : symlink_1 actualname symname\n");
	exit(1);
   }
   if(symlink(argv[1],argv[2])<0){
	printf("symlink call error\n");
	exit(2);
   }
   else
	printf("symlink : %s -> %s\n",argv[2],argv[1]);

     fd = open(argv[2],O_RDONLY);
     if(fd<0){
	printf("file open error\n");
	return;
     }
    // nbyte = lseek(fd,0,SEEK_END);
    // read(fd,buf,nbyte);
    // buf[nbyte+1] = '\0';
    // memset(buf,256,'\0');
     
	  while(read(fd,&i,1)>=1){
		  printf("%c",(char)i);
	  }

	  close(fd);

     if((nbyte=readlink(argv[2],buf,50))<0){
	printf("readlink call error\n");
	exit(2);
     }
     else
     {
	buf[nbyte] = '\0';
	printf("buf : %s\n",buf);
     }
}

