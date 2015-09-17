#include<pthread.h>
#include<stdio.h>

/*
	note : global variable 'sum' is shared by the main thread and the new thread which does the summation!
	In java since the lang is OO there are no global vars, hence vars are shared via refrences to class objects.

	note: to compile a program like this which uses 'pthread.h' do:
	gcc filename.c -o outputfilename -pthread
*/
 double sum;
 void *runner(void *param);

 int main(int argc, char const *argv[])
 {
 	//thread identifier
 	pthread_t tid;
 	//set of thread attributes
 	pthread_attr_t attr;

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
 	//get deafult attributes
 	pthread_attr_init(&attr);
 	//create thread
 	pthread_create(&tid,&attr,runner,argv[1]);
 	//wait for thread to exit
 	pthread_join(tid,NULL);
 	printf("sum = %lf\n",sum);
 	return 0;
 }

 void *runner(void *param)
 {
 	double i, upper = atoi(param);
 	sum=0;
 	for(i=1; i<=upper; i++)
 		sum+=i;
 	pthread_exit(0);
 }