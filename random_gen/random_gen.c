#include<stdlib.h>
#include<stdio.h>

int main(int argc, char*argv[])
{

	if(argc!=4)
	{
		printf("\nEnter 'no_of_arrays', 'size_of_each_array' and 'max' (will be used to draw random nos from [-int(max)...int(max)]) \nas command line arguments...Program Terminated.\n");
		return 1;
	}
	int no_of_arrays = atoi(argv[1]);
	int size_of_each_array = atoi(argv[2]);
	int max= atoi(argv[3]);

	int j, k , r, count=0;

	printf("\n%d",no_of_arrays);
	for(k=0; k<=no_of_arrays; k++)
	{
		printf("\n%d\n",size_of_each_array);
		for(j=0; j<size_of_each_array; j++)
		{
			/*use: rand()% (max-min+1) + min;*/
			srand(k+2*j);
			r=rand()% (2*max+1)+(-1*max);
			printf("%d ",r);	
		}
	}
	return 0;
}
