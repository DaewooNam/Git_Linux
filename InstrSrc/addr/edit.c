#include<stdio.h>
#include"addr.h"

void edit(struct Member *arr, int cnt){
   int idx = search(arr, cnt);
   if(idx<0){
      printf("not found\n");
      return;
   }else{
      printf("new tel:");
      scanf("%s", arr[idx].tel);
      printf("new address:");
      scanf("%s", arr[idx].address);
   }
}
