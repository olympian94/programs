#include<stdio.h>
#include<stdlib.h>
int key[10],next[10],prev[10];
int freee,l1,l2,j;

void clearall()
{
	int j,k;
	freee=0;
	for(j=0; j<10; j++)
		key[j]=0;
	for(j=0; j<9; j++)
		next[j]=j+1;
	next[9]=-1;
	for(j=9; j>=1; j--)
		prev[j]=j-1;
	prev[0]=-1;

}
void printAll()
{
	int j;
	printf("\nALL ARRAYS:\n");	
	printf("\nNEXT\t");
	//print
	for(j=0; j<10; j++)
		printf("\t%d",next[j]);
	printf("\nKEY\t");
	//print
	for(j=0; j<10; j++)
		printf("\t%d",key[j]);

	printf("\nPREV\t");
	//print
	for(j=0; j<10; j++)
		printf("\t%d",prev[j]);
	printf("\nFREE\t%d",freee);
}
int allocateObj()
{
	if(freee==-1)
		return -1;
	int x=freee;
	freee=next[x];
	return x;
}
void freeeObj(int x)
{
	next[x]=freee;
	key[x]=0;//DOES IT ADD TO COST?
	freee=x;
}
void insertAtTail(int *l,int val)
{
	int x=allocateObj();
	if(x!=-1)
	{
		if(*l==-1)
		{
			*l=x;
			prev[x]=-1;
		}	
		else{
			int temp=*l;
			while(next[temp]!=-1)
				temp=next[temp];		
			next[temp]=x;
			prev[x]=temp;
		}
		next[x]=-1;
		key[x]=val;
	}
	else 
		printf("\nOverflow");
}

int deleteFromHead(int *l)
{
	int temp=*l;
	if(temp!=-1){
		int delval=key[temp];
		*l=next[temp];
		prev[*l]=-1;
		freeeObj(temp);
		return delval;
	}
	else
		printf("\nUnderflow");
}
void printList(const int *l)
{
	int j,k;
	printf("\n");
	for(j=*l; j!=-1; j=next[j])
	{
		printf("\t%d",key[j]);
	}
	printf("\n");
}

int main()
{
	clearall();
	l1=-1; l2=-1;
	printAll();

	insertAtTail(&l1,11);
	printAll();
	insertAtTail(&l1,22);
	printAll();

	insertAtTail(&l2,55);
	printAll();
	insertAtTail(&l2,66);
	printAll();
	insertAtTail(&l1,33);
	printAll();
	insertAtTail(&l1,44);
	printAll();
	insertAtTail(&l2,77);
	printAll();

	printList(&l1);
	printList(&l2);

	printf("\nDeleted= %d",deleteFromHead(&l2));
	printAll();
	printf("\nDeleted= %d",deleteFromHead(&l2));
	printAll();
	printf("\nDeleted= %d",deleteFromHead(&l2));
	printAll();
	printf("\nDeleted= %d",deleteFromHead(&l2));
	printAll();
	printf("\nDeleted= %d",deleteFromHead(&l2));
	printAll();

	printList(&l1);
 	printList(&l2);

	printf("\n\n");
	return 0;
}

