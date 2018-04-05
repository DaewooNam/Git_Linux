#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

main()
{
	struct stat	statbuf;
	
	if(truncate("trun.txt",10)<0){
		perror("truncate error");
		exit(-1);
	}

}
