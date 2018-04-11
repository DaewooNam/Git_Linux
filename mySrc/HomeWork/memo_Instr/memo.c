#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <dirent.h>
#include <stdlib.h>

void openDir(char (*names)[256]){

	DIR *dp;
	int i=0;

	struct dirent *dent;
	if( (dp = opendir("./memo"))==NULL){
		puts("dir open error");
		exit(-1);
	}

	while((dent = readdir(dp))!=NULL){
		strcpy(names[i],dent->d_name);
		if(!strcmp(names[i],".")||!strcmp(names[i],"..")){
			continue;
		}
		i++;
	}
	strcpy(names[i],"");
	closedir(dp);

}
void printDir(char (*names)[256]){

	int i=0;
	while(1){
		if(!strcmp(names[i],"")){
			break;
		}
		printf("%d.%s\n",i,names[i]);
		i++;
	}
}

void myRead(char (*names)[256]){
	
	int fd;
	int idx;
	char buf[256];
	printDir(names);
	printf("읽을 파일의 번호 :");
	scanf("%d",&idx);
	sprintf(buf,"%s%s","memo/",names[idx]);
	fd = open(buf,O_RDONLY);
	
	if(fd<0){
		puts("file open error");
		exit(1);
	}
	memset(buf,'\0',256);
	while(read(fd,buf,256)>0){
		printf("%s",buf);
		memset(buf,'\0',256);
	}

	close(fd);
	
}

int checkName(char *p, char(*x)[256]){
	int i=0;

	while(!strcmp(x[i],"")){
	
		if(!strcmp(p,x[i])){
			return 1;
		}
		i++;
	}
	printf("중복되지 않음\n");
	return 0;
}
void myWrite(char (*names)[256] ){
	
	char name[256];
	char path[256];
	int flag=1, menu,openFlag =0, fd;


	while(flag){
		printf("파일명을 입력하세요 : ");
		scanf("%s",name);
		flag = checkName(name, names);
			
		if(flag){
			printf("있는 파일명\n 1.새로입력 2.덮어쓰기 3.이어쓰기");
			scanf("%d",&menu);
			switch(menu){
				case 2:
					flag=1;
					openFlag = O_TRUNC;
					break;
				case 3:
					flag =1;
					openFlag = O_APPEND;
					break;
			}	
		}
		sprintf(path,"memo/%s",name );
		fd = open(path,O_WRONLY|O_CREAT|openFlag,0777);
		openDir(names);
		if(fd<0){
			puts("file open error");
			return;
		}
		printf("내용을 입력하시오. 끝내려면 end를 입력하시오\n");

		while(1){
			scanf("%s",name);
			menu = strlen(name);
			name[menu+1] = '\n';
			if(!strncmp(name,"end",3)){
				break;
			}
			write(fd,name,256);
		}
		close(fd);
}
void main(){
	
	char files[256][256];
	int menu,flag =1;

	if(access("memo",F_OK)!=0){
		mkdir("memo",0777);	
	}	
	
	openDir(files);
	printDir(files);

	while(flag){
		puts("1.read 2.write 3.delete 4.stop");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				{	
					myRead(files);
					break;
			   }
			case 2:
				{ myWrite(files);
					break;
				}
			case 3:
				{	//delete();
					break;
				}
			case 4:
				{flag = 0;
					break;
				}
					
		}
	}


}
