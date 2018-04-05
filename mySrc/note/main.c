#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){

	int memoAcces;
	struct stat 	statbuf;
	char ch[100];
	int cnt;
	
	while(1){
			
		memoAcces = access("memo",F_OK);
		if(memoAcces == 0){
		
			//printf("폴더가 존재합니다\n");
			/*	
			if (chdir("memo")<0){
				perror("chdir()");
				exit(-1);
			}
			*/
			//getcwd(ch,100);
			//printf("current directory : %s\n",ch);
			//my_write();
			cnt = myWrite("memo",0);

			if(cnt==3)
				break;
		}
		else{
			printf("메모 경로가 없습니다\n");
			
			if(mkdir("memo",0777)<0){
				perror("mkdir error");
				exit(-1);
			}
			printf("memo 경로를 만들었습니다\n");


		}	
	}
	

}
