#include<stdio.h>
int main()
{
	long m,n,j,k,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&m,&n);
		for(j=m; j<=n; j++)
		{
			for(k=2; k<=j; k++)
			{
				if(j%k==0)
					break;
			}
			if(j==k)
				printf("%ld\n",j);
		}
	}
	return 0;
}
