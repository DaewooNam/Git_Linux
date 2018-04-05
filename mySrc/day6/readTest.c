#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void main(int argc,char *argv[]){
	int fd1, fd2, ofs, i;
	char ch;
	
	if(argc<2){
	   printf("파일명 두 개를 입력하시오");
	   return;
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY |O_CREAT);
	if(fd1<0 || fd2<0){
	   printf("file open error");
	   return;
	}
	ofs = lseek(fd1,0L,SEEK_END);//long type
	for(i=2;i<=ofs;i++){
	   lseek(fd1,-i,SEEK_END);
	   read(fd1,&ch,1);
	   printf("%c",(char)ch);
	   write(fd2,&ch,1);
	}
	close(fd1);
	close(fd2);

}


