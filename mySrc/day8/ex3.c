#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main()
{
   if(open("before.test",O_WRONLY|O_CREAT|O_TRUNC,0777)<0){
	printf("1st open call error\n");
   }

   umask(077);

   if(open("after.test",O_WRONLY | O_CREAT | O_TRUNC, 0777)<0){
	printf("1st open call error\n");
	exit(2);
   }
}
