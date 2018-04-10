#include <stdio.h>



void error1(char * msg){
	printf("error1이 발생하였음\n");
	printf("%s\n",msg);
}

void error2(char * msg){
	printf("error2이 발생하였음\n");
	printf("%s\n",msg);
}

void error3(char * msg){
	printf("error3이 발생하였음\n");
	printf("%s\n",msg);
}

void error4(char * msg){
	printf("error4이 발생하였음\n");
	printf("%s\n",msg);
}

void main(){
	int code = 0;
	void (*arr[4])(char *)={error1,error2,error3,error4};
	printf("error(0~3):");
	scanf("%d",&code);
	if(code<0 || code>3){
		code =1;
	}
	arr[code]("error");

	/*
	switch(code)
	{
		case 0:
			{
				error1("aa");
				break;
			}
		case 1:
			{
				error2("bb");
				break;
			}
		case 2:
			{
				error3("cc");
				break;
			}
		case 3:
			{
				error4("dd");
				break;
			}
	}
	
	*/

}
