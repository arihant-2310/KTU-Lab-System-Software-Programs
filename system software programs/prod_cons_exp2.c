#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define buffer_size 5
void *producer();
void *consumer();
int wait(int );
int signal(int );
int mutex=1,full=0,empty=5,buffer_index=0;
int main()
{
	pthread_t c_thread,p_thread;
	pthread_create(&p_thread, NULL,producer, NULL); 
	pthread_create(&c_thread, NULL,consumer, NULL); 
	pthread_join(p_thread,NULL);
	pthread_join(c_thread,NULL);
	return 0;
		
}
void *producer()
{
	while(1)
	{ if(empty!=0)
	   {
		empty=wait(empty);
		mutex=wait(mutex);
		++buffer_index;
		printf("\nProduced: %d \n",buffer_index);
		mutex=signal(mutex);		
		full=signal(full);
		//printf("In Producer, Mutex: %d \n full: %d \n empty: %d \n",mutex,full,empty); 
		
		sleep(1);
		
	  }
	else	
		{
			printf("\nBuffer is Full!!");
			sleep(2);
		}
	}
}
void *consumer()
{
	while(1)
	{ if(full!=0)
	   {
		full=wait(full);
		mutex=wait(mutex);
		printf("\nComsumed:%d\n",buffer_index--);
		mutex=signal(mutex);
		empty=signal(empty);
		
		sleep(2);
		//printf("In consumer,Mutex: %d \n full: %d \n empty: %d \n",mutex,full,empty); 
	   }
	  else
		{
			printf("\nBuffer is empty!!");
			sleep(0.5);
		}
	}
}
int wait(int s)
{

	while(s<0);
	s=s-1;
	return s;	
	
}
int signal(int s)
{
	
	s=s+1;
	return s;
	
}
