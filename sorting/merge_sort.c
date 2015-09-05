#include<stdio.h>
#include<malloc.h>
int swaps=0, comps=0;
int compare(int a, int b)
{
	comps++;
	return a<b?-1:a==b?0:1;
}
void mergesort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);
int main(int argc, char*argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int N,j;
		int *arr;
		scanf("%d",&N);
		arr=(int*)malloc(N*sizeof(int));
	
		for(j=0; j<N; j++)
			scanf("%d",arr+j);
		mergesort(arr,0,N-1);
		printf("\n");
		//for(j=0; j<N; j++)
		//	printf("%d ",*(arr+j));
		printf("\nComparisons:\t%d",comps);
		printf("\nSwaps:\t%d",swaps);
		printf("\n");
	}
	return 0;
}

void mergesort(int *arr, int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int *arr, int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int j,k,i;
	int *L, *R;
	L=(int*)malloc(n1*sizeof(int));
	R=(int*)malloc(n2*sizeof(int));
	for(j=0; j<n1; j++)
		L[j]=arr[p+j];
	for(j=0; j<n2; j++)
		R[j]=arr[q+1+j];
	j=0, i=0;
	for(k=p; k<=r; k++)
	{
		if( (compare(L[i],R[j])==-1||compare(L[i],R[j])==0||j==n2)&&i!=n1)
			arr[k]=L[i++];
		else
			arr[k]=R[j++];
	}
}
