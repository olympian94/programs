#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 10

typedef struct{
	int value;
} item;
item buffer[BUFFER_SIZE];
//logical pointers, since they are global they will available to both threads of execution of this process.
int in=0;
int out=0;
int totalItems;

void *producer();
void *consumer();

 int main(int argc, char const *argv[])
 {
 	//thread identifier
 	pthread_t tid1;
 	//set of thread attributes
 	pthread_attr_t attr1;

	if(argc!=2)
 	{
 		fprintf(stderr,"usage: a.out <integer value>\n");
 		return -1;
 	}
 	if(atoi(argv[1])<0)
 	{
 		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
 		return -1;
 	}
 
 	totalItems=atoi(argv[1]);
 	//get deafult attributes
 	pthread_attr_init(&attr1);

 	//create thread
 	pthread_create(&tid1,&attr1,producer);

 	consumer();
 	/*//wait for thread to exit
 	pthread_join(tid,NULL);*/
 	printf("\nAT THE END!");
 	return 0;
 }

void *producer()
 {
 	item nextProduced;
 	int j=1;
 	while(j<=totalItems)
 	{
 		nextProduced.value=j;
 		while( (in+1)%BUFFER_SIZE == out )
 			;
 		buffer[in]=nextProduced;
 		printf("\nProduced = %d, in = %d, out = %d ",j,in,out);
 		in = (in+1)%BUFFER_SIZE;
 		j++;
 	}
 	pthread_exit(0);
 }

void* consumer()
 {
 	item nextConsumed;
 	int track=-1;
 	while(track!=totalItems)
 	{
 		while(in==out)
 			;
 		nextConsumed=buffer[out];
 		track=nextConsumed.value;
		printf("\nConsumed = %d, in = %d, out = %d ",track,in,out);
		out=(out+1)%BUFFER_SIZE;
 	}
 	//this fn is called in the main thread of execution so if .exit() is called here, the main thread will end here only,
 	//and not return to main function. Hence do not do thread.exit here like we did in producer fn 	
 }
