#include<stdio.h>
int main()
{
	int T;
	long long N, K, j, k, sum;
	scanf("%d",&T);
	while(T--)
	{	
		scanf("%lld %lld",&N,&K);
		long long arr[N];
		for(j=0; j<N; j++)
			arr[j]=0;
		for(j=0; j<K; j++)
		{
			scanf("%lld",&k);
			arr[k]=-1;
		}

		sum=0;
		for(j=1; j<N; j++)
		{
			if(arr[j]==-1)
				continue;
			if(j<=sum+1)
				sum+=j;
			else 
				break;
		}
		if(sum%2==0)
			printf("Chef\n");
		else
			printf("Mom\n");

	}
	return 0;
}
