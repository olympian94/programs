#include<stdio.h>

int n;
int memoarray[1000000];

int min(int a, int b)
{
	if(a<b)
		return a;
	else return b;
}
//with memoization
int getMinSteps(int n)
{
	if(n==1) return 0;
	if(memoarray[n]!=-1) return memoarray[n];
	int r = 1 + getMinSteps(n-1);
	if(n%2==0) r = min(r,1+getMinSteps(n/2));
	if(n%3==0) r = min(r,1+getMinSteps(n/3));
	memoarray[n]=r;
	return r;
}

int main()
{
	int tstcases, n, i;
	for(i=0; i<1000000; i++)
		memoarray[i]=-1;
	scanf("%d",&tstcases);
	while(tstcases--)
	{
		scanf("%d",&n);
		printf("\nanswer %d",getMinSteps(n));
	}
	printf("\n");
	return 0;
}