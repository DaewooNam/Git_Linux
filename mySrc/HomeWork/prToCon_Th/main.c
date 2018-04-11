#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

pthread_mutex_t mutex   = PTHREAD_MUTEX_INITALIZER;
pthread_cond_t produce  = PTHREAD_COND_INITIALIZER;
pthread_cond_t consumer = PTHREAD_COND_INITIALIZER; 

int cnt, write, read, flag;
int buf[10];
int buf_size=0;

//2초마다 소비
void *consumer1(void *){
}


//엔터 소비
void *consumer2(void *){
}



int main(){
	
	int i;

	pthread_t cons1;
	pthread_t cons2;
	
	pthread_create(&cons1,NULL,consumer1,NULL);
	pthread_create(&cons2,NULL,consumer2,NULL);

	pthread_mutex_lock(&mutex);

	for(i=0;;i++){
		
		if(cnt >= 10){
			pthread_cond_wait(&produce,&mutex);
		}

		if(cnt<10){

			buf[buf_size%10]=i;
			buf_size++;
			cnt++;

		}
		if(cnt>=3){
			
			pthread_cond_signal(&consumer);	

		}

	
	}


}
