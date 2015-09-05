#include<stdio.h>
#include<stdlib.h>

int main()
{
	int j;
	for(j=1; j<=2; j++)
		fork();
	printf("From %d\n", getpid());
	return 0;
}