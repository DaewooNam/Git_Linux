#include <stdio.h>
#include "memo.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int myWrite(char *dir,int cnt ){

	DIR *dp;
	struct dirent *dent;
	char buf[30], ch;
	char buf_chage[30];
	int i;

	if((dp = opendir(dir)) ==NULL){
		perror("Open Error()");
		exit(1);
	}
	
	
	if( (chdir(dir))<0){
		perror("change dir Error()");
		exit(2);
	}

	
	//while(1){

	dent = readdir(dp);
	
	printf("파일명을 입력하세요 : ");
	scanf("%s",buf);
	
	printf("%s",dent->d_name);
		
	

	/*
	if(strcmp(buf,dent->d_name)==0){
		printf("%s 파일명이 있습니다.",buf);
		printf("이름을 변경하시겠습니까(y/n): ");
		scanf("%c",ch);
		if(ch=='y'){
			printf("변경할 이름을 입력하세요 : ");
			scanf("%s",buf_change);
			strcpy(buf,buf_change);
		}
		else{
		

		}


	}
	else{
		if(	(open(buf,O_WRONLY|O_CREAT|O_TRUNC),0777)<0){
				perror("open error\n");
				exit(1);
		}

	}
	

	if(dent==NULL){
		break;
	}
	
	*/


}

