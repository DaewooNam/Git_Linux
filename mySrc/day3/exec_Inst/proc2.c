#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]){
	int i;
	char buf[256];
	for(i=1;i<argc;i++){
		scanf("%s",buf);
		if(!strncmp(argv[i],buf,4)){
			printf("success\n");
		}else{
			printf("fail\n");
		}
	}
}
