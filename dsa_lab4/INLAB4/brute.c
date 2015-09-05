#include<stdio.h>
int comps,n,m;
float comps_avg=0;
int main()
{
	int t, runs, j,k,l,i,count,counter;
	char str[10000],word[10000];
	scanf("%d",&t);
	runs=t;
	while(t--)
	{
		scanf("%s",str);
		scanf("%s",word);
		for(n=0; str[n]!='\0'; n++);
		for(m=0; word[m]!='\0'; m++);
		count=0; counter=0;
		j=0;
		while(str[j]!='\0')
		{
			count=0;
			comps++;
			if(str[j]==word[0])
			{
				k=j+1; i=1;
				while(str[k]==word[i]&&k<n&&i<m)
				{
					comps++;
					count++; k++; i++;
				}
				if(count==(m-1))
					counter++;
			}
			j++;
		}
		printf("\n%d\n%d",counter,comps);
		comps_avg+=comps;
	}
	comps_avg/=runs;
	printf("\n%f",comps_avg);
	printf("\n");
	return 0;
}
