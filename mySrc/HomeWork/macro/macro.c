#include <stdio.h>

//1.set
#define set(scr,pos) (scr |= (1<<pos));
//2.setArea
#define setAr(scr,pos,size) ();
//3.SetZero
#define setZero(scr,pos) (scr &= 1<<pos);
//4.SetZeroArea
#define setZeroAr(scr,pos,size) ();
//5.SetConversion
#define setConv(scr,pos) (scr ^= 1<<pos);
//6.SetCheck
#define check(scr,pos)   ((scr)&(1<<(pos)));
//7.SetExtraction
#define setEx(scr,pos)


int main(){

	int scr = 10;
	int temp;
	//set(scr,5);

	temp = check(scr,5);
	printf("bit = %d\n",temp);

}
