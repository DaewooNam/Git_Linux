#include <stdio.h>
#include <string.h>
#include "addr.h"


int delMember(struct Member *arr,int cnt)
{
int idx = searchMember(arr,cnt);
int i;	

if(idx<0)
{
printf("찾지못함");
}
else
{
arr[idx]=arr[idx+1];
cnt--;


}
return cnt;	
	
}
