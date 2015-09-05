#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	
	if(argc!=2)
	{
		printf("Please enter integer 'n' as CLA. fork() will be called 'n' times.\n");
		return 0;
	}
	int j, cpid;
	for(j=1; j<=atoi(argv[1]); j++)
		cpid = fork();

	if(cpid == 0)
		printf("parent %d\n",cpid);
	else 
		printf("child %d ppid %d \n",cpid, getppid());
	return 0;
}