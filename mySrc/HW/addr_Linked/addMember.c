#include<stdio.h>
#include<string.h>
#include"addr.h"

int addMember(struct Member *arr,int cnt)
{
char name[20];
 int i;
 while(1){
   printf("name : ");
   scanf("%s", name);
   for(i=0;i<cnt;i++)
   {  
     if(!strcmp(arr[i].name,name))
     {
	printf("중복된이름\n");
	break;
     }
   }
   if(i==cnt)
   {
      break;
   } 
 }
 strcpy(arr[cnt].name,name);
 printf("tel:");
 scanf("%s",arr[cnt].tel);
 printf("address:");
 scanf("%s",arr[cnt].address);
 cnt++;
 return cnt;
}











