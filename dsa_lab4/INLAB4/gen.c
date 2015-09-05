#include<stdio.h>
int main()
{
	int j,k,r;
	for(j=0; j<50; j++)
	{
		for(k=0; k<10000; k++)
		{
			srand(k+j);
			r=rand()%2+97;
			printf("%c",r);
		}
		printf("\n");
		for(k=0; k<1000; k++)
		{
			srand(k+j);
			r=rand()%2+97;
			printf("%c",r);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
