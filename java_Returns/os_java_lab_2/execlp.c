#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	else if(pid==0)
	{
		// file path of command, name of command, list of arguments to give to command, NULL
		execlp("/bin/ls","ls","-l","-a","-c",NULL);
	}
	else
	{
		wait(NULL);
		printf("Child finished execution");
	}
	printf("\n");
	return 0;
}