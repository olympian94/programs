#include<stdio.h>
int main()
{
	int T;
	long a, b, num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld %ld",&a,&b);
		num=0;
		while(a!=0)
		{
			num= (num*10)+a%10;
			a/=10;
		}
		a=num;
		num=0;
		while(b!=0)
		{
			num= (num*10)+b%10;
			b/=10;
		}
		b=num;
		a+=b;
		num=0;
		while(a!=0)
		{
			num= (num*10)+a%10;
			a/=10;
		}
		printf("%ld\n",num);
	}
	return 0;
}
