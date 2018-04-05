#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	pid_t pid;

	sleep(5);
	printf("\nProcess ID 		= %d\n",pid=getpid());
	printf("Parent Process ID  = %d\n",getppid());
	printf("Real User ID		   = %d\n",getuid());
	printf("Effective User ID  = %d\n",geteuid());
	printf("Real group ID 	   = %d\n",getgid());
	printf("Effective group ID = %d\n",getegid());
}
