#include<stido.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

main()
{
	char *fname = "test2.txt";
	int fd, num=0;
	char buf[255];

	fd = open(fname, O_WRONLY);
	if(fd<0){
		printf("file open error");
		exit(1);
	}
	while(1){
		fgets(buf,255,stdin);
		num = strlen(buf);
		if(!strncmp(buf,"end",3)){
			break;
		}
		write(fd,buf,num);
	}
	close(fd);

}

