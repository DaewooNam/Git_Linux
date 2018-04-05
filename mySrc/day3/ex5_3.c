#include <stdio.h>
#include <unistd.h>

int main(){

	char *nargv[] = {"newpgm","parm1","parm2","parm3",(char *)0};
	char *nenv[]  = {"NAME=VAL","nextname=nextvalu","HOME=/xy",(char*)0};

	printf("this is the original program\n");

	execve("./newpgm2",nargv,nenv);

	printf("this line should never get printed\n");
}
