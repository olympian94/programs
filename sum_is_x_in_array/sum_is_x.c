/*
	given array of n, and inp x. Check if there exists two elements in array such that their sum is x.
*/
#include<stdio.h>
#include<stdlib.h>

void sum_is_x(int *, int, int, int);
void check_boundary(int *,int,int,int,int);

void sum_is_x(int *arr, int p , int r, int sum)
{
	if(p<r)
	{
		int q = (p+r)/2;
		sum_is_x(arr,p,q,sum);
		sum_is_x(arr,q+1,r,sum);
		check_boundary(arr,p,q,r,sum);		
	}
}

void check_boundary(int *arr, int p, int q, int r, int sum)
{
	if(arr[q]+arr[q+1]==sum)
		printf("\nat %d %d",arr[q],arr[q+1]);
}

int main()
{
	int n, j,sum;
	scanf("%d",&sum);
	scanf("%d",&n);

	int *inp = (int*)malloc(n*sizeof(int));

	for(j=0; j<n; j++)
		scanf("%d",inp+j);
	sum_is_x(inp,0,n-1,sum);
	printf("\n");	
	free(inp);
	return 0;
}
/*
	soln by divide and conquer. As in merge sort div n into n/2 n/2 and while combining check if middle two elements sum matches the req condition. Since we divide recursively in half, all adj elements will be checked.
*/
