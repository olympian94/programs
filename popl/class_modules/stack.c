#include<stdio.h>
static int fn2()
{
	int n =2;
	printf("\nThis is fn2\n");
	return 2;
}

void fn1()
{
	printf("\nThis is fn1\n");
	fn2();
}
