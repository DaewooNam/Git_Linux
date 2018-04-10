#include <stdio.h>
#include <stdlib.h>


int main(){

	int i,j;
	int (*ary)[3];

	//for(i=0;i<3;i++){
		ary = malloc(sizeof(int)*9);
	//}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		
			ary[i][j]= i+j;
			printf("%td",ary[i][j]);
			
		}
		printf("\n");

	}
		
	

}
