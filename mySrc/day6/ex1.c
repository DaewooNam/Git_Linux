#include<fcntl.h>
#include<stdio.h>
main()
{
	char *fname = "test.txt";
	int fd;

	fd = open(fname,O_RDONLY);
	if(fd>0)
	{
		printf("Success\n FileName : %s, fd : %d\n",fname,fd);
		close(fd);
	}
	else
		perror("open failed\n");

}
