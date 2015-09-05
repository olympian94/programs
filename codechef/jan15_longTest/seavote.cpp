#include<cstdio>
#include<iostream>
#include<stdlib.h>
int main()
{
	int T, N, *B;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		B=(int*)malloc(N*sizeof(int));
		for(int j=0; j<N; j++)
			scanf("%d",&B[j]);
		
	}
	return 0;
}
