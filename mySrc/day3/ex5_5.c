#include <stdio.h>
#include <unistd.h>

int main(){

	if(fork()==0){
		execl("/bin/echo","echo","this is","message one",(char*)0);
		printf("exec one failed");
		exit(1);
	}

	printf("Parent program ending\n");
}
