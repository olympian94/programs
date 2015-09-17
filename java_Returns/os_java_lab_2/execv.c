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
		char* str[5]={"ls","-l","-a","-c",NULL};
		execvp("/bin/ls",str);
	}
	else
	{
		wait(NULL);
		printf("Child finished execution");
	}
	printf("\n");
	return 0;
}