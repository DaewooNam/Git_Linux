#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t        sem; 
char buf[256];
char buf2[256];
int mode;
void* a( void *arg )
{
   int i;
 	while(1){
		sem_wait( &sem );
		if(mode==-1){
			sem_post(&sem);
			break;
		}
		if(mode==1){
			printf("문제:%s\n", buf);
			mode=2;
		}
	    sem_post(&sem);
		 usleep(1);
           }
	printf("문제출제종료\n");
    pthread_exit(0);  
}
void* b( void *arg )
{
   int i, m, flag=1;
 	while(flag){
		sem_wait( &sem );  //
			m = mode;	   // 이부분이 무엇이지 
		sem_post(&sem);	   //
		switch(m){
			case -1:
				flag=0;
				break;
			case 2:
				scanf("%s", buf2);
				mode=3; //시간 초과를 해주기 위해 
			break;
		}
		 usleep(1);
    }
	printf("답안입력종료\n");
    pthread_exit(0);  
}
void main( void ) // -1 종료
{
    int i;
    FILE *fp;
    sem_init( &sem, 0, 1);
    void*(*f[])(void*) = {a, b};
    pthread_t threads[2]; 
    
    for ( i=0; i<2; i++ )  // 이순간 부터 task 줄 서기 시작함
      pthread_create( &threads[i],NULL,f[i],NULL);          
    	   
	fp = fopen("a.txt", "r");
	while(1){
		sem_wait( &sem );
		if(fgets(buf, 256, fp)==NULL){
			mode=-1;	
			sem_post(&sem);				
			break;
		}
		mode=1;
		sem_post(&sem);	
		sleep(5);
		sem_wait( &sem );
		switch(mode){
			case 2:
				printf("시간초과\n");
				break;
			case 3:
				if(!strncmp(buf, buf2,4)){
					printf("성공\n");
				}else{
					printf("실패\n");
				}
				break;
		}
		sem_post(&sem);
		usleep(1);
	}
	pthread_cancel(threads[1]);
	fclose(fp);
	puts("프로그램 종료\n");
    pthread_exit(0); 
}
