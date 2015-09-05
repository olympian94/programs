#include<stdlib.h>
#include<stdio.h>

int main(int argc, char*argv[])
{
	long int j, k, r=1, i;
	long int N, S, max_size;
	scanf("%ld %ld",&N,&S);
	long int *arr;
	arr=(long int*)malloc(N*sizeof(long int));

	//create N different sizes with starting size S and where the next size is one more than previous.
	arr[0]=S;
	for(j=1; j<N; j++)
		arr[j]=arr[j-1]+1;

	//number of different sizes
	printf("\n%ld",N);
	max_size=arr[N-1];
	for(i=0; i<N; i++)
	{
		//for each size, gen random 100 arrays
		for(j=0; j<100; j++)
		{	
			//100 arrays of size arr[i]
			//size of array
			printf("\n%ld\n",arr[i]);
			for(k=0; k<arr[i]; k++)
			{
				srand(r+k+i+j);
				r=rand()%1000+1; //range [0...1000]
				printf("%ld ",r);	
			}
		}
		printf("\n");
	}
	free(arr);
	return 0;
}
