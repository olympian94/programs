#include<pthread.h>
#include<stdio.h>

//to compile do:
//gcc filename.c -o outputfilename -pthread

int value =0;
void* runner(void *param);

int main(int argc, char const *argv[])
{
	int pid;
	pthread_t tid;
	pthread_attr_t attr;
	int i=0;

	for(i=0; i<3; i++)
		pid=fork();
	/*pid = fork();*/
	if(pid==0)
	{
		pthread_attr_init(&attr);
		pthread_create(&tid,&attr,runner,NULL);
		pthread_join(tid,NULL);
		printf("\nCHILD: value = %d ##### parent is %d ###### my id is %d",value,getppid(),getpid());
	}
	else if(pid>0){
		wait(NULL);
		printf("\nPARENT: value = %d ##### child is %d #### my id is %d",value,pid,getpid());
	}
	printf("\n");
	return 0;
}

void* runner(void *param)
{
	value=5;
	pthread_exit(0);
}