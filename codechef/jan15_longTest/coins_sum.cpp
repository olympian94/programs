/*
Given a list of N coins, their values (V1, V2, ... , VN), and the total sum S. Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), or report that it's not possible to select coins in such a way that they sum up to S. 
*/
#include<cstdio>
#include<stdlib.h>
#include<iostream>
int main()
{
	int T, N, *V, S;
	//input no of testcases
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);	
		scanf("%d",&S);
		V=(int*)malloc(N*sizeof(int));
		int max=0, min=0;
		//input array
		for(int j=0; j<N; j++)
			scanf("%d",&V[j]);

		for(int j=0; j<N-1; j++)
		{
			min=j;	
			for(int k=j+1; k<N; k++)
			{
				if(V[min]>V[k])
					min=k;					
			}
			if(min!=j)
			{
				int temp=V[min];
				V[min]=V[j];
				V[j]=temp;
			}
		}
		for(int j=0; j<N; j++)
			printf("%d\t",V[j]);
		printf("\n");
		int temp, rem, count=0, id, ans=0;
		id=N-1;
		max=V[id];
		min=V[0];
		temp=S;
		while(temp>min)
		{
			while(max>temp&&id>0)
			{
				max=V[id--];
			}
			printf("\n temp count max = %d %d %d",temp,count,max);
			count=temp/max;
			ans+=count;
			temp-=count*max;
		}	
		if(temp==0)
			printf("%d\n",ans);
		else
			printf("Not Possible.\n");
		free(V);
	}
	return 0;
}
