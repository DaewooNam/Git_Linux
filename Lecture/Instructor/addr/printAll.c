#include<stdio.h>
#include"addr.h"

void printAll(struct Member *arr, int cnt){
   int i;
   for(i=0;i<cnt;i++){
      printf("name:%s\n", arr[i].name);
      printf("tel:%s\n", arr[i].tel);
      printf("address:%s\n", arr[i].address);
      printf("=============\n");
   }
}
