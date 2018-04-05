#include<fcntl.h>
#include<stdio.h>

main()
{
	char *fname = "test.txt";
	int fd;
	
	fd = creat(fname,0777);
	if(fd<0)
		perror("creat()");
	else{
		printf("Sucess!\n Filename : %s, fd :%d\n",fname,fd);
		close(fd);
	}

}
