#include<stdio.h>

int main(int argc, char const *argv[])
{
	int size;
	int arr[size];
	scanf("%d",&size);
	int j;
	for(j=0; j<size; j++)
		scanf("%d",arr+j);

	for(j=0; j<size*10; j++)
		printf("\n%d\n",arr[j]);
	return 0;
}