#include<stdio.h>
#include<stdlib.h>

void quicksort(int *arr, int p , int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

int partition(int *arr, int p, int r)
{
	/*
		Randomised Quicksort: before running partition algo, swap arr[r] and arr[i], because arr[r] is chosen as pivot by algo
		and here we swap arr[r] with arr[i] and i is randomly chosen from [p-r], thus randomising the algo.
		use: rand()% (max-min+1) + min;
	*/
	int temp,j, i, x;
	srand(p+r);
	i=rand()% (r-p+1) + p;
	temp= arr[i];
	arr[i]=arr[r];
	arr[r]=temp;

	x = arr[r];
	i = p-1;
	for(j=p; j<r; j++)
	{
		if(arr[j]<=x)
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}

void printArray(int *arr, int size)
{
	int j;
	for(j=0, printf("\n"); j<size; j++)
		printf("%d ",arr[j]);
}

int main()
{
	int n, j, testcases;
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%d",&n);
		int *arr=(int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d",arr+j);
		printf("\nInput");
		printArray(arr,n);

		quicksort(arr,0,n-1);

		printf("\nAfter Quicksort");
		printArray(arr,n);
		free(arr);
		printf("\n");
	}
	printf("\n");
	return 0;
}