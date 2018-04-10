#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a[2][3] = {{1,2,3},{4,5,6}};
	int *p = a[0] ; //1이 있는 방의 주소 할당
	int (*b)[3] = a;
	int (*c)[2][3] = &a;
	int i,j;
	for(i=0;i<6;i++){
		printf("%d\t",p[i]);
	
	}
	printf("\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}

	p = a[1];
	printf("%d\n",p[-1]); 
	p = a[0];
	printf("p=%u, b=%u, c=%u\n",p,b,c);
 	printf("p+1=%u, b+1=%u, c+1=%u\n",p+1,b+1,c+1);  //unsinged

}
