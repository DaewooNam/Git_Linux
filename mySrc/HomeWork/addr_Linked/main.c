#include<stdio.h>
#include"addr.h"

void main()
{   
	struct Member *head=(struct Member)malloc(sizeof(struct Member));
	struct Member *tail=(struct Member)malloc(sizeof(struct Member));
	struct Member *cur    

	int cnt=0;
   int i;
   int choice=0;
	
	cur = head;

 
while(1)
{
      printf("1.추가/2.검색/3.수정/4.삭제/5.전체출력/6.나가기");
      scanf("%d",&choice);

  switch (choice)
    {
           
      case 1:
      {
        cnt = addMember(data,cnt);
       	break;
      }
      case 2:
      {
        searchMember(data,cnt);
	break;
      }
      case 3:
      {
        modifyMember(data,cnt);
	break;
      }
      case 4:
      {
        cnt = delMember(data,cnt);
	break;
      }
      case 5:
      {
        

        for(i =0;i<cnt;i++){
        printf("%s / %s / %s \n",data[i].name, data[i].tel, data[i].address);
        }

        break;

      }
      case 6:
      {
	choice = 6;
	break;
      }
    }

   if(choice ==6)
   {
     
	break;
   };
 
};
 

  
    
    
}  


