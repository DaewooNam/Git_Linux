#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void mySystem(char *dir){
	

	DIR *dp;
	struct dirent *dent;

		if((dp=opendir(dir))==NULL){
			perror("error OpenDir");
			exit(1);
		}
		
		while(1){

		dent = readdir(dp);
		printf("%s",dent->d_name);
			if(dent==NULL){
				break;
			}
		}
}


int main()
{
	mySystem(".");

}








	


