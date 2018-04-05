#include<stdio.h>
#include"addr.h"
void printA(){
extern struct Member *head;
   struct Member *cur = head;
   while(cur != NULL){
      printf("%s / %s / %s\n", cur->name, cur->tel, cur->address);
      cur = cur->next;
   }
}
