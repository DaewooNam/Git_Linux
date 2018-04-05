#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"addr.h"

void add(){
   extern struct Member *head;
   extern struct Member *tail;
   char name[20];
   struct Member *m = NULL;
   while(1){
      printf("name:");
      scanf("%s", name);
      m = search(name);
      if(m == NULL){
	break;
      }else{
	puts("중복된 이름");
      }
   }
   m = (struct Member*)malloc(sizeof(struct Member));
   strcpy(m->name, name);
   printf("tel:");
   scanf("%s", m->tel);
   printf("address:");
   scanf("%s", m->address);
   if(head == NULL){
      head = m;
      head->prev = NULL;
   }else{
      tail->next = m;
      m->prev = tail;
   }
   tail = m;
   tail->next = NULL;
}
