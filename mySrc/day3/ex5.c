#include <stdio.h>
extern **environ;
void main(int argc, char *argv[]){
		int i;
		for(i=0;i<argc;i++){
			printf("arg1=%s\n",argv[i]);
		}
		
		for(i=0;environ[i] != NULL;i++){
			printf("environ[%d]=%s\n",i,environ[i]);

		}
}
