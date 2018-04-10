#include <stdio.h>
#include <pthread.h>

pthread_t thread;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond =PTHREAD_COND_INITIALIZER;



int count =0;
int flag =0;
void* Thread (void* arg){
	
		while(1){
		
			pthread_mutex_lock(&mutex);
			if((count/10%2)==0){
			 pthread_cond_wait(&cond, &mutex);
			}

			if(flag){
			
				printf("count = %d\n", count);
				flag=0;

			}

			pthread_mutex_unlock(&mutex);
			if(count ==99)
				break;
			usleep(1);
		}

		printf("print stop\n");

}

void main(void){

	int i;
	pthread_create(&thread, NULL, (void*(*)(void*))Thread,NULL);

	for(i=0;i<100;i++){
	pthread_mutex_lock(&mutex);
	count++;

	flag=1;
	if(count ==10||count ==30||count ==50||count ==70||count ==90){

	printf("condition signal %d\n", i);
	}
	
	pthread_mutex_unlock(&mutex);
usleep(1):
	
	
	}
	pthread_exit(0);
}
