#include <stdio.h>
#include <unistd.h>

int main(){

	puts("system()전");
	system("ls");
	puts("system() 후");
}
