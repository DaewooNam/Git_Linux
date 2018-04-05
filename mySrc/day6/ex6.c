#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


main()
{
	char *fname = "test.txt";
	int fd1,fd2,cnt;
	char buf[30];
	
	fd1 = open(fname, O_RDONLY);
	if(fd1<0){
		perror("open()");
		exit(-1);
	}
	fd2 = dup(fd1);
	cnt = read(fd1,buf,12);
	buf[12]='\0';
	printf("fd1's printf : %s\n",buf);
	
	lseek(fd1,1,SEEK_CUR);
	cnt = read(fd2,buf,12);
	buf[cnt] = '\0';
	printf("fd2's printf : %s\n",buf);
		
	


}
