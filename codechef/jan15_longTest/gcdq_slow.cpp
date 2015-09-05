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
		long LR_store[Q][2];
		for(int j=0; j<Q; j++)
		{
			for(int k=0; k<2; k++)
			{
				cin>>LR_store[j][k];
			}
		}
		/*
		//printing
		cout<<endl;
		for(int k=0; k<N; k++)
			cout<<" "<<A[k];
		cout<<endl;
		for(int j=0; j<Q; j++)
		{
			for(int k=0; k<2; k++)
				cout<<" "<<LR_store[j][k];
			cout<<endl;
		}
		*/
		//working
		for(int j=0; j<Q; j++)
		{
			L=LR_store[j][0];
			R=LR_store[j][1];
			long arr_temp[N-(R-L+1)];
			int l=0;
			for(int k=0; k<L-1; k++)
				arr_temp[l++]=A[k];
			for(int k=R; k<N; k++)
				arr_temp[l++]=A[k];
			long val=arr_temp[0];
			for(int k=0; k<l-1; k++)
			{
				long temp1, temp2;
				temp1=val;
				temp2=arr_temp[k+1];
				if(val<arr_temp[k+1])
				{
					long temp3=temp1;
					temp1=temp2;
					temp2=temp3;
				}
				val=gcd(temp1,temp2);
			}
			cout<<val<<endl;
		}
		free(A);	
	}
	return 0;
}

long gcd(long a, long b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

