#include<stdio.h>

int comps;
float comp_avg=0;
int main()
{
	int t,i,j,k,count,n,m,counter,runs;
	char str[10000],word[10000];
	scanf("%d",&t);
	runs=t;
	while(t--)
	{
		scanf("%s",str);
		scanf("%s",word);
		j=0; i=0; count=0; counter=0;
		for(n=0; str[n]!='\0'; n++);
		for(m=0; word[m]!='\0'; m++);
		comps=0;
		while(str[j]!='\0')
		{
			count=0;
			if(str[j]==word[0])
			{
				comps++;
				k=j+1; i=1;
				while((str[k]==word[i])&&k<n&&i<m)
				{
					comps++;
					count++;
					k++;
					i++;
				}
				if(count==(m-1))
					counter++;
			}
			j++;
		}
		comp_avg+=comps;
		printf("\n%d\n%d",counter,comps);
	}
	comp_avg/=runs;
	printf("\n%f",comp_avg);
	printf("\n");
	return 0;
}
