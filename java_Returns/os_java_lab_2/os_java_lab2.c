#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *myName = argv[0];
	int cpid = fork();
	

	if(cpid==0)
	{
		//parent process
		printf("\nin parent pid =%d", getpid());
		printf("\n");
		exit(0);
	}
	else
	{	//child process
		printf("\nin child pid =%d", getpid());
		printf("\n");
		exit(0);
	}

	return 0;
}