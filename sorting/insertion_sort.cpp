#include<stdio.h>
#include<stdlib.h>
#include<cstdio>

int main()
{
	int *arr, N;
	scanf("%d",&N);
	arr=(int*)malloc(N*sizeof(int));
	for(int j=0; j<N; j++)
		scanf("%d",&arr[j]);
	int k, key;
	for(int j=1; j<N; j++)
	{
		key=arr[j];
		k=j-1;
		while(k>=0&&arr[k]<key)
		{
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=key;
	}
	printf("\n");
	for(int j=0; j<N; j++)
		printf("%d ",arr[j]);
	printf("\n");
	free(arr);
	return 0;
}
