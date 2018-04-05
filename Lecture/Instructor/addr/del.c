#include<stdio.h>
#include"addr.h"

int del(struct Member *arr, int cnt){
   int idx = search(arr, cnt);
   int i;
   if(idx < 0){
      return cnt;
   }else{
      for(i=idx;i<cnt-1;i++){
	arr[i] = arr[i+1];
      }
      cnt--;
      return cnt;
   }
}
