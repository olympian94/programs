#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a=5, b=1, c=2, d=0;
	if (a && b || c && d)
		printf("\nHello");
	else
		printf("\nHi");
	return 0;
}