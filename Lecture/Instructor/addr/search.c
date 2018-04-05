#include<stdio.h>
#include<string.h>
#include"addr.h"

int search(struct Member *arr, int cnt){
   char name[20];
   int  i;
   printf("search name:");
   scanf("%s", name);
   for(i=0;i<cnt;i++){
      if(!strcmp(name, arr[i].name)){
  	return i;
      }
   }
   return -1;
}
