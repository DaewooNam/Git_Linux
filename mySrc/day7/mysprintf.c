#include<stdio.h>

void main(){
   char buf[256];
   char str[10];
   int a;
   float b;

  // sprintf(buf,"%s %d %f\n","aaa",10,3.14f);
  // printf("%s",buf);
   sscanf(buf,"%s%d%f",str,&a,&b);
   printf("str=%s, a=%d, b=%f\n", str,a,b);

}
