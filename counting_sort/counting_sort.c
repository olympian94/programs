#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size)
{
	int j;
	for(j=0, printf("\n"); j<size; j++)
		printf("%d ",arr[j]);
}

/*
	arr: unsorted input array
	k : each ele of arr is within [0-k]
	Returns the sorted array.
*/
int* countingSort(int *arr, int size, int k)
{
	int *B = (int*)malloc(size*sizeof(int));
	//temporary storage array
	int *C = (int*)malloc((k+1)*sizeof(int));
	int j;
	//initially temp array
	for(j=0; j<=k; j++)
		C[j]=0;
	for(j=0; j<size; j++)
		C[arr[j]]++;
	//C[i] now has no of elements = i
	for(j=1; j<=k; j++)
		C[j]=C[j]+C[j-1];

	//C[i] now has no of elements <= i
	for(j=size-1; j>=0; j--)
	{
		B[C[arr[j]]-1]=arr[j];
		C[arr[j]]--;
	}
	free(C);
	return B;
}

int main()
{
	int n, j, testcases, range;
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%d",&range);
		scanf("%d",&n);
		int *arr=(int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d",arr+j);
		printf("\nInput");
		printArray(arr,n);

		int *sorted = countingSort(arr,n,range);

		printf("\nCounting Sort");
		printArray(sorted,n);

		free(arr);
		free(sorted);
		printf("\n");
	}
	printf("\n");
	return 0;
}