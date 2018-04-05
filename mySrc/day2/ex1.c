#include<stdio.h>
#include<unistd.h>


extern **environ;
int main()
{
	int i;
	for(i=0;environ[i] != NULL;i++)
			printf("environ[%d] : %s\n",i,environ[i]);

}

