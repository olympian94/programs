//sieve of erathostenos
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N, j, k, m, l;
	scanf("%d",&N);	
	//to print all primes upto n
	int *arr;
	arr=(int*)malloc((N-1)*sizeof(int));

	//create list beginning with 2
	k=2;
	for(j=0; j<N-1; j++)
		arr[j]=k++;	
	//starting prime
	k=2;
	for(j=0; j<N-1; j++)
		printf("%d\n",arr[j]);

	for(l=0; l<N-1; l++)
	{
		if(arr[k]==-1)
			continue;
		m=arr[l];
		for(m*=2, j=l+1; j<N-1; j++)
		{
			if(arr[j]%m==0)
			{
				m+=arr[l];
				arr[j]=-1;
			}
		}
	printf("\n");
	for(j=0; j<N-1; j++)
		printf("%d\n",arr[j]);

	}
	printf("\n");
	for(j=0; j<N-1; j++)
		printf("%d\n",arr[j]);

	return 0;
}
