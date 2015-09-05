#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int *var = (int*)malloc(sizeof(int));
	*var=3;
	printf("%p %d\n",var,*var);
	free(var);
	printf("%p %d\n",var,*var);	

	return 0;
}