#include<stdlib.h>
#include<stdio.h>

int main(int argc, char*argv[])
{
	int n,m,i,j,r;
	n=atoi(argv[1]);
	m=atoi(argv[2]);
	char *arr;
	arr=(char *)malloc(10000*sizeof(char));

	for(i=0; i<n; i++)
	{
		//for each size, gen random 100 arrays
		for(j=0; j<m; j++)
		{	
			srand(r+i+j/2);
			r = rand()%(2)+97;
			printf("%c ",r);	
		}
		printf("\n");
	}
	free(arr);
	return 0;
}

/*
up vote 3 down vote
	

For those who understand the bias problem but can't stand the unpredictable run-time of rejection-based methods, this series produces a progressively less biased random integer in the [0, n-1] interval:

r = n / 2;
r = (rand() * n + r) / (RAND_MAX + 1);
r = (rand() * n + r) / (RAND_MAX + 1);
r = (rand() * n + r) / (RAND_MAX + 1);
...

It does so by synthesising a high-precision fixed-point random number of i * log_2(RAND_MAX + 1) bits (where i is the number of iterations) and performing a long multiplication by n.

When the number of bits is sufficiently large compared to n, the bias becomes immeasurably small.

It does not matter if RAND_MAX + 1 is less than n (as in this question), or if it is not a power of two, but care must be taken to avoid integer overflow if RAND_MAX * n is large.

*/
