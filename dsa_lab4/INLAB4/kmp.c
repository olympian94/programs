#include<stdio.h>
#include<stdlib.h>

int comps,n,m,*T,counter;
float comps_avg=0;
void kmp(char *s, char *w);
void prefixFn(char *w);

int main()
{
	int t, runs, j,k,l,i;
	char str[10000],word[10000];
	scanf("%d",&t);
	runs=t;
	while(t--)
	{
		scanf("%s",str);
		scanf("%s",word);
		for(n=0; str[n]!='\0'; n++);
		for(m=0; word[m]!='\0'; m++);
		counter=0; comps=0;
		kmp(str,word);
		free(T);
		printf("\n%d\n%d",counter,comps);
		comps_avg+=comps;
	}
	comps_avg/=runs;
	printf("\n%f",comps_avg);
	printf("\n");
	return 0;
}

void kmp(char *s, char *w)
{
	prefixFn(w);
	int q=0,i;
	for(i=0; i<n; i++)
	{
		while(q>0&&w[q]!=s[i])
		{
			comps++;
			q=T[q-1];
		}
		if(w[q]==s[i])
		{
			comps++;
			q++;
		}
		if(q==m)
		{
			counter++;
			q=T[q-1];
		}
	}
}

void prefixFn(char *w)
{
	T=(int*)malloc(m*sizeof(int));
	T[0]=0;
	int k=0,q;
	for(q=1; q<m; q++)
	{
		while(k>0&&w[k]!=w[q])
			k=T[k-1];
		if(w[k]==w[q])
			k++;
		T[q]=k;
	}	
}
