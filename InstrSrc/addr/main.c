#include<stdio.h>
#include"addr.h"

void main(){
   struct Member data[30];
   int i, cnt = 0, flag = 1, menu = 0;
   cnt = init(data, cnt);
   while(flag){
      printf("1.add 2.search 3.edit 4.del 5.printall 6.stop\n");
      scanf("%d", &menu);
      switch(menu){
	case 1:
	   cnt = addMember(data, cnt);
	   break;
	case 2:
	   i = search(data, cnt);
	   if(i<0)
	      puts("not found");
	   else
	      printf("%s/%s/%s\n", data[i].name, data[i].tel, data[i].address);
	   break;
   	case 3:
	   edit(data, cnt);
	   break;
	case 4:
	   cnt = del(data, cnt);
	   break;
	case 5:
	   printAll(data, cnt);
	   break;
	case 6:
	   flag = 0;
	   stop(data, cnt);
	   break;
      }
   }
}
