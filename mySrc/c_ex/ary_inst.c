#include <stdio.h>
#include <stdlib.h>

void main(){

	int row,i,j;
	int (*a)[3];
	printf("몇줄?");
	scanf("%d",&row);
///	a = (int(*)[3])malloc(sizeof(int)*3*row);
	a = malloc(sizeof(int)*3*row);
	for(i=0;i<row;i++){
		for(j=0;j<3;j++){
			a[i][j] = i*3+j+1;
		
		}
	
	}

	for(i=0;i<row;i++){
		for(j=0;j<3;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	free(a);


}
