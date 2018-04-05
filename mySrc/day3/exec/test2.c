#include <stdio.h>
#include <string.h>

int main(){

	char buf[255];
	int num;

	while(1){
		fgets(buf,255,stdin);
		if(!strncmp(buf,"\n",1)){
			break;
		}

	}


}
