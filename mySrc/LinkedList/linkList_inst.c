#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
   char str[255];
   struct Node *next;
};

void main(){
   struct Node *head=NULL, *tail, *cur;
   char buf[255];  
   FILE *fp = fopen("link.txt","r");
   while(fgets(buf,256,fp)!=NULL){
     cur = (struct Node*)malloc(sizeof(struct Node));
     strcpy(cur->str,buf);
    
     if(head==NULL){
	head = cur;
     }
     else
     {
      tail->next = cur;
     }
     tail = cur;
     tail->next = NULL;
    
   }
   fclose(fp);
   //링크드 리스트 전체 출력
   cur = head;
   while(cur != NULL)
   {
	printf("%s",cur->str);
        cur = cur->next;
   }
   //메모리 해제

   while(head != NULL)
   {
     cur = head;
     head = head->next;
     printf("%s 메모리해제\n",cur->str);
     free(cur);
      

   }
   
}

