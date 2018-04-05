#include<stdio.h>
#include<string.h>
#include"addr.h"



void modifyMember(struct Member *pary,int cnt)
{
int idx = searchMember(pary,cnt); 
int i;


if(idx<0)
{
	printf("찾지못함");
	return;
}
else
{
printf("전화번호(수정)");
scanf("%s",pary[idx].tel);
printf("주소(수정)");
scanf("%s",pary[idx].address);
}


}

