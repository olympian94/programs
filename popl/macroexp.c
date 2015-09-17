#include<stdio.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}
int main()
{
	int t=5, x=10;
	printf("\nz,x = %d %d",t,x);
	//will not work because macro expansion also creates a temp var named t
	SWAP(t,x)
	printf("\nz,x = %d %d",t,x);
	return 0;
}
