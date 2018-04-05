#include <stdio.h>
#include <unistd.h>

int main(){

	char *nargv[] = {"newpg","parm1","parm2","pamr3",(char*)0};

	printf("this is the original program\n");

	execv("./newpgm",nargv);

	printf("This line should never goet pinrted\n");
}
