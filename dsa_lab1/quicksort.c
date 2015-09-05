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
void quicksort(long int *arr, long int p, long int r);
long int partition(long int *arr, long int p, long int r);
long int main(long int argc, char*argv[])
{
	long int N,j, *arr, noOfSizes, k, i;
	scanf("%ld",&noOfSizes);
	for(k=0; k<noOfSizes; k++)
	{
		max_comps=0; min_comps=MAX_VAL; avg_comps=0;
		//for each size take 100 arrays as inp
		for(i=0; i<100; i++)
		{
			scanf("%ld",&N);
			arr=(long int*)malloc(N*sizeof(long int));
		
			for(j=0; j<N; j++)
				scanf("%ld",arr+j);
			quicksort(arr,0,N-1);
//			printf("\n");
//			for(j=0; j<N; j++)
//				printf("%ld ",*(arr+j));
//			printf("\nComparisons:\t%ld",comps);
//			printf("\nSwaps:\t%ld",swaps);
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

void quicksort(long int *arr, long int p, long int r)
{
	if(p<r)
	{
		long int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

long int partition(long int *arr, long int p, long int r)
{
	long int pivot=arr[p];
	long int i, j, temp;
	i=p;
	for(j=p+1; j<=r; j++)
	{
		if(compare(arr[j],arr[p])==-1||compare(arr[j],arr[p])==0)
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
//			swaps++;
		}
	}
	temp=arr[p];
	arr[p]=arr[i];
	arr[i]=temp;
//	swaps++;
	return i;
}
