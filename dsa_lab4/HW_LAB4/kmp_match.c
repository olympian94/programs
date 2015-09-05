#include<stdio.h>
#include<stdlib.h>
int n, m;
int *T;
void prefixFn(char *wptr);
void KMP(char *s, char *w);
int main()
{
	char S[100], W[100];
	int j,t;
	while(t--){
		scanf("%s",S);
		scanf("%s",W);
		for(n=0; S[n]!='\0'; n++);
		for(m=0; W[m]!='\0'; m++);
		KMP(S,W);
	}
	return 0;	
}

//preproccessing part of KMP algo
void prefixFn(char *wptr)
{
	T=(int*)malloc(m*sizeof(int));
	T[0]=0;
	int k=0,q;
	for(q=1; q<m; q++)
	{
		while(k>0&&wptr[k]!=wptr[q])
			k=T[k-1];
		if(wptr[k]==wptr[q])
			k++;
		T[q]=k;
	}
}

void KMP(char *s, char *w)
{	
	prefixFn(w);
	int q=0, i;
	for(i=0; i<n; i++)
	{
		while(q>0&&w[q]!=s[i])
			q=T[q-1];
		if(w[q]==s[i])
			q++;
		if(q==m){
			printf("\nFound at %d",i-m+1);
			q=T[q-1];}
	}
	free(T);
}
