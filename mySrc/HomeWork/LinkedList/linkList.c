#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
    char ch[100];
    struct _node *next;

}node;


int main()
{
	char str_read[100]="\0";
	//int cnt;	
	
	FILE *fp = fopen("link.txt","r");
	
	node *head = malloc(sizeof(node));
	node *cur;
	
	cur = head;
	while(1)
	{
		
		node *tail = malloc(sizeof(node));
		fgets(str_read,100,fp);
		strcpy(cur->ch,str_read);
		//printf("%s",cur->ch);	
		if(fgets(str_read,100,fp)==NULL)
		{
			cur->next=NULL;
			break;
			printf("break");
		}
		cur->next = tail; 	
		
		
	
	};

	
	cur = head;			
	while(cur==NULL)
	{
		printf("%s",cur->ch);
		cur = cur->next;
	}

	fclose(fp);

}
