#include<stdio.h>
#include<stdlib.h>

void mergesort(int *,int, int);
void merge(int *,int ,int ,int);

void merge(int *arr, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2*sizeof(int));
	int i,j, k;
	for(i=0; i<n1; i++)
		L[i] = arr[p+i];
	for(i=0; i<n2; i++)
		R[i] = arr[q+i+1];
	i=0; j=0;
	for(k=p; k<=r; k++)
	{
		if(L[i]<=R[j] || j==n2 && i!=n1)
			arr[k]=L[i++];
		else
			arr[k]=R[j++];
	}
	free(L);
	free(R);
}

void mergesort(int *arr, int p, int r)
{
	if (p<r)
	{
		int q =(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

int main()
{
	int n, j;
	scanf("%d",&n);

	int *inp = (int*)malloc(n*sizeof(int));

	for(j=0; j<n; j++)
		scanf("%d",inp+j);
	mergesort(inp,0,n-1);
	for(j=0, printf("\n"); j<n; j++)
		printf("%d ",inp[j]);
	
	printf("\n");	
	free(inp);
	return 0;
}
