#include<stdio.h>
//전체비트1로셋
#define SETALL(src) ((src)|=0xff)
//전체비트 0으로 클리어
#define CLEARALL(src) ((src)&=0x0)
//특정비트셋
#define SETBIT(src,idx) ((src)|=(1<<(idx)))
//특정비트 클리어
#define CLEARBIT(src,idx) ((src)&=~(1<<(idx)))
//여러비트 셋
#define SETAREA(src,bit,idx) ((src)|=((bit)<<(idx)))
//여러비트 클리어
#define CLEARAREA(src,bit,idx) ((src)&=~((bit)<<(idx)))
//특정비트 반전
#define REVBIT(src,idx) ((src)^=(1<<(idx)))
//여러비트 반전
#define REVAREA(src,bit,idx) ((src)^=((bit)<<(idx)))
//특정비트 추출(확인)
#define CHECK_BIT(src,idx) (((src)>>(idx))&1)
//여러비트 추출
#define EXTRACT_BITS(src, bit, idx) (((src)>>(idx))&(bit))
void print_binary(char x){
	int i;
	for(i=7;i>=0;i--){
		printf("%d", CHECK_BIT(x, i));
	}
	printf("\n");
}
void main(){
	unsigned char a = 0x3a;
	char b;
	print_binary(a);
	SETBIT(a,6);
	print_binary(a);
	CLEARBIT(a,3);
	print_binary(a);
	SETAREA(a,0xf,4);
	print_binary(a);
	CLEARAREA(a,0xf,4);
	print_binary(a);
	REVBIT(a,7);
	print_binary(a);
	REVAREA(a,0xf,2);
	print_binary(a);
	b = EXTRACT_BITS(a,0x7,4);
	printf("a:");
	print_binary(a);
	printf("b:");
	print_binary(b);
	SETALL(a);
	print_binary(a);
	CLEARALL(a);
	print_binary(a);
}

