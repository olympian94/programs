#include<stdio.h>
#include<stdlib.h>
void randomqs(int *arr,int,int);
int randompt(int*arr,int,int);
int n;
int main()
{
	int t, *arr, j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d",&arr[j]);
		randomqs(arr,0,n-1);
		for(j=0,printf("\n"); j<n; j++)
			printf("%d ",arr[j]); 
		free(arr);
	}
	return 0;
}

void randomqs(int *arr, int p, int r)
{
	if(p<r)
	{
		srand(p+r);
		int q=randompt(arr,p,r);
		randomqs(arr,p,q-1);
		randomqs(arr,q+1,r);
	}
}

int randompt(int *arr, int p, int r)
{
	int l=rand()%(r-p+1)+p;
	int i,j, temp;
	printf("\n%d %d %d",p,r,l);
	temp=arr[p];
	arr[p]=arr[l];
	arr[l]=temp;
	i=p;
	for(j=p+1; j<=r; j++)
	{
		if(arr[j]<arr[p])
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[i];
	arr[i]=arr[p];
	arr[p]=temp;
	return i;
}
