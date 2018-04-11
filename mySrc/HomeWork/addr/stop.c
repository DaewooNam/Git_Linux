#include<stdio.h>
#include"addr.h"

void stop(struct Member *arr,int cnt){
   FILE *fp = fopen("data.dat","w");
   if(fp==NULL){
      printf("file open error\n");  
      return;
   }
   
   if(fwrite(arr,sizeof(struct Member),cnt,fp) !=cnt){
	printf("write error\n");
   }
   fclose(fp);
   

}
