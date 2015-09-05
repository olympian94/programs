#include<stdio.h>
#include<stdlib.h>

void printArray(long int *arr, long int size)
{
	long int j;
	for(j=0, printf("\n"); j<size; j++)
		printf("%ld ",arr[j]);
}


long int hand_multiplication(long int num1, long int num2)
{
	long int total_digits_in_num1, total_digits_in_num2, j, k, i;
	long int temp;

	temp=num1;
	total_digits_in_num1=0;
	total_digits_in_num2=0;

	while(temp!=0)
	{
		temp/=10;
		total_digits_in_num1++;
	}

	temp=num2;
	while(temp!=0)
	{
		temp/=10;
		total_digits_in_num2++;
	}

	long int *digit_array_num1=(long int*)malloc(total_digits_in_num1*sizeof(long int));
	long int *digit_array_num2=(long int*)malloc(total_digits_in_num1*sizeof(long int));

	temp=num1;
	j=0;
	while(temp!=0)
	{
		digit_array_num1[j++]=temp%10;
		temp/=10;
	}
	temp=num2;
	j=0;
	while(temp!=0)
	{
		digit_array_num2[j++]=temp%10;
		temp/=10;
	}


	long int size_of_res_arr= total_digits_in_num1*2+1;
	long int* res_arr=(long int *)malloc(size_of_res_arr*sizeof(long int));
	for(j=0; j<size_of_res_arr; j++)
		res_arr[j]=0;

	long int carry=0, res, place, l=0, carry2=0;
	//before start
	printf("\nnum1, num2, total_digits_in_num1, total_digits_in_num2 = %ld %ld %ld %ld",num1,num2,total_digits_in_num1,total_digits_in_num2);
	printf("\nDig array num1");
	printArray(digit_array_num1,total_digits_in_num1);
	printf("\nDig array num2");
	printArray(digit_array_num2,total_digits_in_num2);

	for(i=0; i<total_digits_in_num1; i++)
	{
		carry=0; l=0;
		l+=i; carry2=0;
		for(j=0; j<total_digits_in_num2; j++)
		{
			res=digit_array_num1[i]*digit_array_num2[j]+carry;
			place=res%10;
			carry=res/10;
			if(j==total_digits_in_num2-1)
			{
				temp=place+res_arr[l]+carry2;
				res_arr[l++]=temp%10;
				carry2=temp/10;
				if(carry2||carry)
				{
					res_arr[l]=res_arr[l]+carry+carry2;
					l++;
				}
			}
			else
			{
				temp=res_arr[l]+place+carry2;
				res_arr[l++]=temp%10;
				carry2=temp/10;
			}
		}
		printf("\nIntermediate Result:");
		printArray(res_arr,l);
	}
	
	printf("\nl size_of_res_arr %ld %ld",l,size_of_res_arr);
	free(digit_array_num2);
	free(digit_array_num1);
	printf("\nResult:");

	printArray(res_arr,l);

	long double power_of_10=1;
	long double temp1=0;
	for(j=0; j<l; j++)
	{
		temp1+=res_arr[j]*power_of_10;
		power_of_10*=10;
	}
	printf("\nProduct= %Lf",temp1);
	free(res_arr);
}

long int main()
{
	long int n1, n2, j, testcases;
	scanf("%ld",&testcases);
	while(testcases--)
	{
		scanf("%ld",&n1);
		printf("\nInput1 %ld",n1);

		scanf("%ld",&n2);
		printf("\nInput1 %ld",n2);

		hand_multiplication(n1,n2);
		printf("\n");
	}
	printf("\n");
	return 0;
}

/*long int counter=0;
	for(i=0; i<total_digits_in_num1; i++)
	{
		counter++;
		carry=0; l=size_of_res_arr-1;
		l-=counter; carry2=0;
		for(j=0; j<total_digits_in_num2; j++)
		{
			res=digit_array_num1[i]*digit_array_num2[j]+carry;
			place=res%10;
			carry=res/10;
			if(j==total_digits_in_num2-1)
			{
				temp=place+res_arr[l]+carry2;
				res_arr[l--]=temp%10;
				carry2=temp/10;
				res_arr[l]=res_arr[l]+carry+carry2;
				l--;
			}
			else
			{
				temp=res_arr[l]+place+carry2;
				res_arr[l--]=temp%10;
				carry2=temp/10;
			}
		}
		printArray(res_arr,size_of_res_arr);
	}
	free(digit_array_num2);
	free(digit_array_num1);

	printArray(res_arr,size_of_res_arr);

	free(res_arr);
}*/