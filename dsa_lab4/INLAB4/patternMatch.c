#include<stdio.h>
#include<stdlib.h>

int comps,n,m,*T,counter;
float comps_avg=0;
int kmp(char *s, char *w);
void prefixFn(char *w);

int main()
{
	int t, runs, j,k,l,i,count,counter;
	char str[10000],word1[10000],word2[10000];
	scanf("%d",&t);
	runs=t;
	while(t--)
	{
		scanf("%s",str);
		scanf("%s",word1);
		scanf("%s",word2);

		for(n=0; str[n]!='\0'; n++);
		for(m=0; word1[m]!='\0'; m++);
		for(l=0; word2[l]!='\0'; l++);

//		printf("\n%s\n%s\n%s",str,word1,word2);
//		printf("\n%d\n%d\n%d",n,m,l);
		count=0; counter=0;
		j=0;
		int var=0;
		while(str[j]!='\0')
		{
			count=0;
			comps++;
			if(str[j]==word1[0])
			{
				k=j+1; i=1;
				while(str[k]==word1[i]&&k<n&&i<m)
				{
					comps++;
					count++; k++; i++;
				}
				if(count==(m-1))
				{
//					printf("\nKMP call j=%d",j);
					var+=kmp(str+j+m-1,word2);
				}
			}
			j++;
		}

		printf("\n%d\n%d",var,comps);
		comps_avg+=comps;
	}
	comps_avg/=runs;
	printf("\n%f",comps_avg);
	printf("\n");
	return 0;
}


int kmp(char *s, char *w)
{
	prefixFn(w);
//	printf("\nKMP\n%s\n%s",s,w);
	int q=0,i,c=0;
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
			c++;
			q=T[q-1];
		}
	}
//	printf("\nvar=%d",c);
	return c;
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
