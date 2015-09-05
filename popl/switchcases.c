#include<stdio.h>
int main(int argc, char const *argv[])
{
	int counter = 3;
	switch(counter)
	{
		case 1 :
		printf("\number 1");
		break;

		case 2 :
		printf("\number 2");
		break;

		case 3 :
		printf("\number 3");
		break;

		case 4 :
		printf("\number 4");
		break;

		default : printf("\ndefault case");
	}
	return 0;
}