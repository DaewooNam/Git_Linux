#include <stdio.h>
main(){

	char first,last,ch;
	int pid,i;

	if((pid==fork())>0){
		first = 'A';
		last  = 'Z';
	}
	else if(pid==0){

		first = 'a';
		last  = 'z';
	}

	for(ch=first;ch<=last;ch++){

		write(1,&ch,1);
		sleep(1);
	}
}
