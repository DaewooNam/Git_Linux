#include <stdio.h>
#include <string.h>
#include "addr.h"


int searchMember(struct Member *arr,int cnt)
{
int idx;
char name[20];
printf("검색 : ");
int i;
scanf("%s",name);	
	for(i=0;i<cnt;i++)
	{
		if(strcmp(name,arr[i].name)==0)
		{


		
		
		return i;
		
		break;

		}
		

	}

		
	return -1;

	

}





