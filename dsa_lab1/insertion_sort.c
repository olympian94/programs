#include<stdio.h>
#include<malloc.h>
#define MAX_VAL 2147483647
long int swaps=0, comps=0, max_comps=0, min_comps=0;
double avg_comps=0;
long int compare(long int a, long int b)
{
	comps++;
	return a<b?-1:a==b?0:1;
}

void insertion_sort(long int *arr, long int size);
long int main()
{
	long int *arr, N, T, j, k, i;
	long int noOfSizes;
	scanf("%ld",&noOfSizes);
	for(i=0; i<noOfSizes; i++)
	{
		max_comps=0; min_comps=MAX_VAL; avg_comps=0;
		//take 100 array inputs for each size
		for(k=0; k<100; k++)
		{
			scanf("%ld",&N);
			arr=(long int*)malloc(N*sizeof(long int));
			for(j=0; j<N; j++)
				scanf("%ld",&arr[j]);
			insertion_sort(arr,N);
//			printf("\n");
//			for(j=0; j<N; j++)
//				printf("%ld ",arr[j]);
//			printf("\nComparisons:\t%ld\n",comps);
			if(comps>max_comps)
				max_comps=comps;
			if(comps<min_comps)
				min_comps=comps;
			avg_comps+=comps;
			free(arr);
		}
		avg_comps/=100;
		printf("\n%ld\n%ld\n%ld\n%f\n",N,max_comps,min_comps,avg_comps);
		/*
		printf("\n***************************************");
		printf("\nMax:\t%ld\nMin:\t%ld\nAvg:\t%f",max_comps,min_comps,avg_comps);
		printf("\n***************************************");
		*/
	}
	return 0;
}

void insertion_sort(long int *arr, long int N)
{
	long int k, key, j;
	for(j=1; j<N; j++)
	{
		key=arr[j];
		k=j-1;
		while(k>=0&&compare(arr[k],key)==1)
		{
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=key;
	}

}
