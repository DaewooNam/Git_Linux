#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

main(void){

	struct stat  statbuf;

	if(stat("before.test",&statbuf)<0){
		perror("stat error for before.test");
		exit(-1);
	}
	if(chmod("before.test",(statbuf.st_mode & ~S_IXGRP | S_ISGID))<0){
		perror("chmod error for before.test");
		exit(-1);
	}

	if(chmod("after.test",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0){
		perror("chmod error for after.test");
		exit(-1);
	}
}
