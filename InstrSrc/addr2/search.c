#include<stdio.h>
#include<string.h>
#include"addr.h"
struct Member* search(char *name){
   extern struct Member *head;
   struct Member *cur = head;
   while(cur != NULL){
      if(!strcmp(cur->name,name)){
	return cur;
      } 
      cur = cur->next;
   }
   return NULL;
}
