#include <stdio.h>
#include <stdlib.h>

struct Student{

	char name[30];
	int info[5]; //번호, 국,영,수,총점
	float avg;

};


void sum(const int *pa,int size,int *result){
	//배열p의 합, 최대값, 최소값을 result 배열에 순차로 저장
	int i,j;
	int max=0;
	int min=100;
	int temp;
	int sum_temp=0;
	
	for(i=0;i<size;i++){
		sum_temp += pa[i];
	}
	
	for(i=0;i<size;i++){
		if(pa[i]<min){	
			min = pa[i];
		}
	}

	for(i=0;i<size;i++){
		if(pa[i]>max){
			max=pa[i];
		}
	}


	result[0] = sum_temp;
	result[1] = max;
	result[2] = min;

}


void input(struct Student *p,int size){
	//학생정보 입력받아 p에 저장
	/*	
	int i;
	
	char *name_dt[] = {"a","b","c","d","e"};	
	int 	math[] = {100,90,50,70,60};
	int 	eng[]  = {50,60,70,80,80};
	int 	kor[]  = {60,90,90,90,100};
	int  	sum[]  = {0,};
	float avg[]  = {0,};

	for(i=0;i<size;i++){
	
		sum[size] = math[size] + eng[size] + kor[size];
		avg[size] = (math[size] + eng[size] + kor[size])/3;
	
	}
	
	for(i=0;i<5;i++){
		p[i].name = name_dt[i];
		for(j=0;j<5;j++){
			p[i].info[j] = math[j];
			p[i].info[j] = eng[j];

		}
	}
	*/
	int i,j;
	for(i=0;i<size;i++){
		printf("name ");
		scanf("%s",p[i].name);
		printf("num,kor,eng,math:");
		p[i].info[4]=0; // 총점 

		for(j=0;j<4;j++){
			scanf("%d",p[i].info[j]);
			if(j !=0){
				p[i].info[4] += p[i].info[j]; //총점 계산
			}
		}
		p[i].avg = (float)p[i].info[4]/3; //평균 계산
	
	}

	
}

void print(struct Student *p,int size){
	
	int i,j;
	printf("name\tnum\tkor\teng\tmath\ttotla\tavt\n");
	for(i=0;i<size;i++){
		printf("%s\t",p[i].name);
		for(j=0;j<5;j++){
			printf("%d\t",p[i].info[j]);
		}
		printf("%f\n",p[i].avg);
	}


}  //변수 p의 학생 정보 출력

void sort(struct Student *p,int size){

	int i,j;
	struct Student tmp;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(p[j].info[4]<p[j+1].info[4]){
				tmp    = p[j];
				p[j]   = p[j+1];
				p[j+1] = tmp;
			}
		}
	}

} //총점으로 정렬


void main(){
	int arr[] = {6,4,325,8,6,5};
	int result[3],i;
	struct Student data[5];

	//arr[0] = arr[1];
	sum(arr,6,result);
	printf("sum,max,min:");
	for(i=0;i<3;i++){
		printf("%d\t",result[i]);
	}
	printf("\n");
	input(data,5);
	sort(data,5);
	print(data,5);


}
