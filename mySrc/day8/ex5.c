#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <stdlib.h>

main(){

	struct stat	statbuf;
	
	if(lchown("aaa",0,0)<0){
		perror("chmod error for aaa");
		exit(-1);
	}
}
