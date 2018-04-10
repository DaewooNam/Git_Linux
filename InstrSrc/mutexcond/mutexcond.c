#include <stdio.h>
#include <pthread.h>

int buffer[10];
int count =0, read_idx=0, write_idx=0, num= 1, flag =0; 
			//읽을 위치, 쓸 위치 인덱스  (읽을위치 쓸 위치가 다름요)


pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;  //길 막아주는 친구 뮤텍스는 한개만 만들어주면 되용
pthread_cond_t cond_produce = PTHREAD_COND_INITIALIZER;  //생산자
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER; //소비자

void *consumer1(void*arg) // 첫번재 소비자 (2초에 한번씩)
{	
	while(1){
		pthread_mutex_lock(&mutex);
		if(count <=0 ||flag){
			if(!flag){
				flag=1;
			}
			printf("data empty \n consumer1 wait \n");
			pthread_cond_wait(&cond_consumer, &mutex);
			flag=0;
			printf("consumer1 wake\n");
		}

		if(count<=8){
			//printf("producer wake\n");
			pthread_cond_signal(&cond_produce);
		}
		printf("consumer1:%d\n", buffer[read_idx%10]);
		read_idx++;
		count--;
		pthread_mutex_unlock(&mutex);
		sleep(2);

	}
}




void *consumer2(void *arg)// 두번재 소비자 (엔터값 
{	
	while(1){
	getchar();
	pthread_mutex_lock(&mutex);
		if(count <=0 ||flag){
			if(!flag){
				flag=1;
			}
		printf("data empty \n consumer2 wait \n");
			pthread_cond_wait(&cond_consumer, &mutex);
			flag=0;
			printf("consumer2 wake\n");
		}

	if(count<=8){
			//printf("producer wake\n");
			pthread_cond_signal(&cond_produce);
		}
		printf("consumer2:%d\n", buffer[read_idx%10]);
		read_idx++;
		count--;
		pthread_mutex_unlock(&mutex);
		

	}
}


void main(void){  //생산자 
	int i;	
	int addnum=0;	
	
	pthread_t thread;
	pthread_t thread2;

	pthread_create(&thread, NULL, (void*(*)(void*))consumer1,NULL);
	pthread_create(&thread2, NULL, (void*(*)(void*))consumer2,NULL);
	
	
	for(i=1; ; i++){   //넣어줄 숫자
		pthread_mutex_lock(&mutex);
		
		if(count==10){
			printf("data full \n produce wait\n");			
			pthread_cond_wait(&cond_produce, &mutex);
			
		}
		else if(count < 10)
		{
			buffer[write_idx%10] =i;
				count++;
				write_idx++;

			if(count >=3){
				pthread_cond_signal(&cond_consumer);				
			}

		}

		pthread_mutex_unlock(&mutex);
		sleep(1);
		

	}



	


	pthread_exit(0);
}
