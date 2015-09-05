#include<stdio.h>

int min(int a, int b)
{
	if(a<b)
		return a;
	else return b;
}

int dp[100000000];
void getMinSteps()
{
	int i;
	dp[1]=0;
	for(i=2; i<100000000; i++)
	{
		dp[i]=1+dp[i-1];
		if(i%2==0)
			dp[i]=min(dp[i], 1+dp[i/2]);
		if(i%3==0)
			dp[i]=min(dp[i], 1+dp[i/3]);
	}
}

int main()
{
	int tstcases, n, i;
	scanf("%d",&tstcases);
	getMinSteps();
	while(tstcases--)
	{
		scanf("%d",&n);
		printf("\nanswer %d",dp[n]);
	}
	printf("\n");
	return 0;
}