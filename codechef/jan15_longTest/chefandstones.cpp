#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;
int main()
{
	int testCases;
	scanf("%d",&testCases);
	long N, K, *A, *B, max, temp;
	while(testCases--)
	{
		scanf("%ld",&N);
		scanf("%ld",&K);
		A=(long*)malloc(N*sizeof(long));
		B=(long*)malloc(N*sizeof(long));
		//take input Ai- time
		for(int k=0; k<N; k++)
			scanf("%ld",&A[k]);
		//take input Bi- value
		//calc max profit
		max=0;
		for(int l=0; l<N; l++){
			scanf("%ld",&B[l]);
			temp=(K/A[l])*B[l]; 
			if(temp>max)
				max=temp;
		}
		printf("%ld\n",max);
		free(A);
		free(B);
	}
	return 0;
}
