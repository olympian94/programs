#include<stdio.h>

int main()
{
	long int N,j,k;
	int T, c, d, arr[2001],count;
	scanf("%d",&T);
	while(T--)
	{
		count=0;
		scanf("%ld",&N);
		for(j=0; j<2001; j++)
			arr[j]=-1;
		//index = interval ending point; arr[index] = interval starting point
		//autom. storage in increasing order of interval ending
		//note: store shorter interval. So among (6,10) and (8,10), arr[10] will = 8 not 6 ie. (6,10) will be disccarded.
		for(j=0; j<N; j++)
		{
			scanf("%d %d",&c,&d);
			if(arr[d]<c)
				arr[d]=c;
		}
		//work
		for(j=0; j<2001; j++)
		{
			//j= chose smallest "valid" interval ending not yet chosen
			//now find all intervals beginning earlier than 'j', these will be deleted with the same point so no need to 
			//count these
			if(arr[j]>=0){
				for(k=0; k<2001; k++)
				{
					if(arr[k]>=0&&arr[k]<=j)
						arr[k]=-1;
				}
				count++;
			}
		}
		//print result
		printf("%d\n",count);
	}
	return 0;
}

