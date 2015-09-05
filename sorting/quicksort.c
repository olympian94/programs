#include<stdio.h>
#include<malloc.h>
int swaps=0, comps=0;
int compare(int a, int b)
{
	comps++;
	return a<b?-1:a==b?0:1;
}
void quicksort(int *arr, int p, int r);
int partition(int *arr, int p, int r);
int main(int argc, char*argv[])
{
	int T;	
	scanf("%d",&T);
	while(T--)
	{
		int N,j;
		int *arr;
		scanf("%d",&N);
		arr=(int*)malloc(N*sizeof(int));
	
		for(j=0; j<N; j++)
			scanf("%d",arr+j);
		quicksort(arr,0,N-1);
		printf("\n");
		//for(j=0; j<N; j++)
		//	printf("%d ",*(arr+j));
		printf("\nComparisons:\t%d",comps);
		printf("\nSwaps:\t%d",swaps);
		printf("\n");
	}
	return 0;
}

void quicksort(int *arr, int p, int r)
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
	int pivot=arr[p];
	int i, j, temp;
	i=p;
	for(j=p+1; j<=r; j++)
	{
		if(compare(arr[j],arr[p])==-1||compare(arr[j],arr[p])==0)
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			swaps++;
		}
	}
	temp=arr[p];
	arr[p]=arr[i];
	arr[i]=temp;
	swaps++;
	return i;
}
