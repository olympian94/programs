#include<iostream>
#include<stdlib.h>
using namespace std;
long gcd(long,long);
int main()
{
	int T;
	cin>>T;
	long N, *A, L, R, Q;		
	while(T--)
	{
		cin>>N;
		cin>>Q;
		A=(long*)malloc(N*sizeof(long));
		for(int j=0; j<N; j++)
			cin>>A[j];
		while(Q--)
		{
			cin>>L;
			cin>>R;
			long arr_temp[N-(R-L+1)];
			int l=0;
			for(int k=0; k<L-1; k++)
				arr_temp[l++]=A[k];
			for(int k=R; k<N; k++)
				arr_temp[l++]=A[k];
			long val=arr_temp[0];
			for(int k=0; k<l-1; k++)
				val=gcd(val,arr_temp[k+1]);
			cout<<val<<endl;

		}	
		free(A);	
	}
	return 0;
}

long gcd(long a, long b)
{
	long t;
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

