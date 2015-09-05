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
void mergesort(long int *arr, long int p, long int r);
void merge(long int *arr, long int p, long int q, long int r);
long int main(long int argc, char*argv[])
{
	long int noOfSizes, j,k;
	long int N,i,*arr;

	scanf("%ld",&noOfSizes);
	for(i=0; i<noOfSizes; i++)
	{
		max_comps=0; min_comps=MAX_VAL; avg_comps=0;
		//for each array size take 100 arrays as inp
		for(k=0; k<100; k++)
		{
			scanf("%ld",&N);
			arr=(long int*)malloc(N*sizeof(long int));
			for(j=0; j<N; j++)
				scanf("%ld",arr+j);
			mergesort(arr,0,N-1);
//			printf("\n");
//			for(j=0; j<N; j++)
//				printf("%ld ",*(arr+j));
//			printf("\nComparisons:\t%ld",comps);
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

void mergesort(long int *arr, long int p, long int r)
{
	if(p<r)
	{
		long int q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(long int *arr, long int p, long int q, long int r)
{
	long int n1=q-p+1;
	long int n2=r-q;
	long int j,k,i;
	long int *L, *R;
	L=(long int*)malloc(n1*sizeof(long int));
	R=(long int*)malloc(n2*sizeof(long int));
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
	free(L);
	free(R);
}
