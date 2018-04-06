#include<stdio.h>
#include"addr.h"

int init(struct Member *arr, int cnt){
   FILE *fp = fopen("data.dat", "r");
   if(fp==NULL){
      printf("file open error\n");
      return 0;
   }
   while(fread(&arr[cnt], sizeof(struct Member), 1, fp)==1){
      cnt++;
   }
   fclose(fp);
   return cnt;
}
