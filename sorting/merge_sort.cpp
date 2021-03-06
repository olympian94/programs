#include<cstdio>
#include<iostream>
#include<stdlib.h>

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int main()
{
	int N, *A;
	scanf("%d",&N);
	A=(int*)malloc(N*sizeof(int));
	for(int j=0; j<N; j++)
		scanf("%d",&A[j]);
	mergesort(A,0,N-1);
	printf("\n");
	
	for(int j=0; j<N; j++)
		printf("%d ",A[j]);
	printf("\n");
	
	return 0;
}

void merge(int *arr,int p,int q,int r)
{
	int n1, n2;
	n1=q-p+1;
	n2=r-q;
	int *L, *R;
	L=(int*)malloc(n1*sizeof(int));
	R=(int*)malloc(n2*sizeof(int));
	//make L
	for(int j=0; j<n1; j++)
		L[j]=arr[p+j];
	//make R
	for(int k=0; k<n2; k++)
		R[k]=arr[q+k+1];

	int i=0, j=0;
	for(int k=p; k<=r; k++)
	{
		if((j==n2||L[i]<=R[j])&&i!=n1){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
	}
	free(L);
	free(R);
}
void mergesort(int *arr,int p, int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
