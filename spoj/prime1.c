/*
	3.343 times faster than prime brute force in calculating primes from 1 to 1000000
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t;
	int m, n, j, l, b, size;
	int *arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&b,&n);
		size=n+1;
		arr=(int*)malloc(size*sizeof(int));
		memset(arr,0,sizeof(arr));
		for(j=2; j<size; j++)
		{
			if(arr[j]==1)
				continue;	
			m=j;
			//sieve optimisation instead of m*=2, do m*=m 
			for(m*=m, l=j+1; l<size; l++)
			{
				if(l==m)
				{
					arr[l]=1;
					m+=j;
				}
			}
		}
		for(j=b; j<size; j++)
			if(arr[j]==0)
				printf("%d\n",j);
		free(arr);
	}
	return 0;
}

	/*TLE above n=10^4
	while(t--)
	{
		scanf("%lld %lld",&m,&n);
		for(j=m; j<=n; j++)
		{
			for(k=2; k<=j; k++)
			{
				if(j%k==0)
					break;
			}
			if(j==k)
				printf("%lld\n",j);
		}
	}*/
