#include<stdio.h>
#include<stdlib.h>

typedef struct l{
	int *arr;
	int size,count;
	int head,tail;
}list;
typedef list* plist;

plist createList(int n)
{
	plist l=(plist)malloc(sizeof(list));
	l->arr=(int*)malloc(n*sizeof(int));
	l->size=n;
	l->count=0;
	l->head=-1;
	l->tail=-1;
	return l;
}

plist resize(plist l,int snew)
{
	plist nl=(plist)malloc(sizeof(list));
	//efficiently choose new size= l->count+snew
	nl->arr=(int*)malloc((l->count+snew)*sizeof(int));
	nl->count=l->count;
	nl->size=l->size+snew;
	nl->head=0;
	int j,m=0;
	for(j=l->head; j<=l->tail; j++,m++)
		nl->arr[m]=l->arr[j];
	nl->tail=m-1;
	free(l->arr);
	free(l);
	return nl;
}

plist enq(plist l,int n)		//insertAtTail
{
	if(l->tail==l->size-1){
		printf("\nQueue Overflow");
		return l;
	}
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}	
	else 
		l->tail++;
	l->arr[l->tail]=n;
	l->count++;
}

int deq(plist l)	//removeFromHead
{
	if(l->count==0){
		printf("\nQueue underflow.");
		return -1;
	}
	int delval;
	delval=l->arr[l->head];
	l->head++;
	l->count--;
	if(l->count==0)
	{
		l->head=-1;
		l->tail=-1;
	}
	return delval;
}

void printList(plist l)
{
	if(l->count==0)
		printf("\nList is empty. Cannot print.");
	else
	{
		int j;
		for(j=l->head; j<=l->tail; j++)
			printf("\n(%d)\t%d",j,l->arr[j]);
		printf("\n");
	}
}

int main()
{
	plist q1=createList(10);
	printList(q1);
	deq(q1);
	int j;
	for(j=0; j<15; j++)
		enq(q1,j+1);
	printList(q1);
	q1=resize(q1,5);

	for(j=0; j<6; j++)
		printf("\ndeq= %d",deq(q1));
	printList(q1);
	printf("\nRESIZING");
	q1=resize(q1,5);
	printList(q1);
	for(j=0; j<16; j++)
		enq(q1,j+1);
	printList(q1);
	return 0;
}
