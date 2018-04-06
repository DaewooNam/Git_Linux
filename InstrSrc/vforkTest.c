#include <unistd.h>
#include<stdio.h>
#include<sys/fcntl.h>
#include<stdlib.h>
static int glob = 6;        /* external variable in initialized data */

int main(void)
{
        int     var, fd;        /* automatic variable on the stack */
        pid_t   pid;
        char buf;			
        var = 88;
       printf("before fork\n");  
			fd = open("a.txt", O_RDONLY);
 		while(1){
			read(fd, &buf, 1);
			printf("%c", buf);
                 if(buf=='\n')break;
                   }
		printf("\n");
        if ( (pid = vfork()) < 0)
                printf("fork error");
        else if (pid == 0) 
        { 
                glob++;                 
                var++;
while(1){
			read(fd, &buf, 1);
			printf("%c", buf);
                 if(buf=='\n')break;
                   }
		printf("\n");
                exit(0);
        } 
        printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
while(1){
			read(fd, &buf, 1);
			printf("%c", buf);
                 if(buf=='\n')break;
                   }
		printf("\n");
        return 1;
}
