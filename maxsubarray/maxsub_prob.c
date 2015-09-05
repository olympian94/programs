#include<stdio.h>
#include<stdlib.h>

void maxsub(int *,int , int , int *,int *, int *);
void combine(int *,int ,int ,int , int*,int*,int*);

void maxsub(int *arr, int p, int r, int *lft, int *rt, int *max)
{
	if(p==r){
		*lft=p;
		*rt=r;
		*max=arr[p];
		return;
	}
	else{

		int q = (p+r)/2;
		int lftsum, rtsum, crosssum;
		int lftlo, rtlo, crosslo;
		int lfthi, rthi, crosshi;

		maxsub(arr,p,q,&lftlo,&lfthi,&lftsum);
		maxsub(arr,q+1,r,&rtlo,&rthi,&rtsum);
		combine(arr,p,q,r,&crosslo,&crosshi,&crosssum);

		if(lftsum>=rtsum && lftsum>=crosssum)
		{
			*max=lftsum;
			*lft=lftlo;
			*rt=lfthi;
			return;
		}
		else if(rtsum>=lftsum && rtsum>=crosssum)
		{
			*max=rtsum;
			*lft=rtlo;
			*rt=rthi;
			return;
		}
		else
		{
			*max=crosssum;
			*lft=crosslo;
			*rt=crosshi;
			return;
		}
	}
}

void combine(int *arr, int p, int q, int r, int * lft, int *rt, int *maxsum)
{
	int lftsum = -999999, rtsum = -999999, temp_sum=0;
	int i;
	for(i=q; i>=p; i--)
	{
		temp_sum+=arr[i];
		if(temp_sum>lftsum)
		{
			lftsum=temp_sum;
			*lft = i;
		}
	}
	temp_sum=0;
	for(i=q+1; i<=r; i++)
	{
		temp_sum+=arr[i];
		if(temp_sum>rtsum)
		{
			rtsum=temp_sum;
			*rt = i;
		}
	}
	*maxsum = lftsum+rtsum;
}

int main()
{
	int n, j;
	scanf("%d",&n);

	int *inp = (int*)malloc(n*sizeof(int));

	for(j=0; j<n; j++)
		scanf("%d",inp+j);
	int lft=0, rt=0, maxsum=0;
	maxsub(inp,0,n-1,&lft,&rt,&maxsum);

	printf("\nlft=%d, rt=%d, maxsum=%d",lft,rt,maxsum);
	printf("\n");	
	free(inp);
	return 0;
}
