#include <stdio.h>
#include <unistd.h>

main(){
	printf("this is the origianl program\n");

	execl("./newpgm","newpgm","parm1","parm2","parm3",(char*)0);

	printf("this line should never get printed\n");
}

