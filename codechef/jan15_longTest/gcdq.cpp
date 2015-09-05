#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
long gcd(long,long);
int main()
{
	int T;
	scanf("%d",&T);
	long N, *A, L, R, Q, *preff, *suff;		
	while(T--)
	{
		scanf("%ld",&N);
		scanf("%ld",&Q);
		A=(long*)malloc(N*sizeof(long));
		preff=(long*)malloc(N*sizeof(long));
		suff=(long*)malloc(N*sizeof(long));
		for(int j=0; j<N; j++)
			scanf("%ld",&A[j]);
		preff[0]=A[0];
		for(int j=1; j<N; j++)
			preff[j]=gcd(preff[j-1],A[j]);
		suff[N-1]=A[N-1];
		for(int j=N-2; j>=0; j--)
			suff[j]=gcd(suff[j+1],A[j]);		
		while(Q--)
		{
			scanf("%ld",&L);
			scanf("%ld",&R);
			long val;
			if(L==1)
				val=suff[R];
			else if(R==N)
				val=preff[L-2];
			else
				val=gcd(preff[L-2],suff[R]);
			printf("%ld\n",val);
		}	
		free(A);
		free(preff);
		free(suff);	
	}
	return 0;
}

long gcd(long a, long b)
{
	long temp;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

