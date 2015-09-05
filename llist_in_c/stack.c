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

plist resize(plist l)
{
	plist nl=(plist)malloc(sizeof(list));
	nl->arr=(int*)malloc((l->size+5)*sizeof(int));
	nl->count=l->count;
	nl->size=l->size+5;
	nl->head=l->head;
	nl->tail=l->tail;
	int j,m=0;
	for(j=l->head; j<=l->tail; j++,m++)
		nl->arr[m]=l->arr[j];
	free(l->arr);
	free(l);
	return nl;
}
plist push(plist l, int n)	//insertAtTail
{
	if(l->tail==l->size-1){
		printf("\nStack overflow.");
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
	return l;
}

int pop(plist l)		//removeFromTail
{
	if(l->count==0){
		printf("\nStack underflow.");
		return -1;
	}
	int delval;
	delval=l->arr[l->tail];
	l->tail--;
	l->count--;
	if(l->count==0)
	{
		l->tail=-1;
		l->head=-1;
	}
	return delval;
}

void printList(plist l)		//print
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
	plist stack1;	
	stack1=createList(10);
	printList(stack1);
	pop(stack1);
	int j;
	for(j=0; j<15; j++)
		push(stack1,j+1);
	printList(stack1);
	stack1=resize(stack1);
	for(j=0; j<7; j++)
		push(stack1,j+1);
	printList(stack1);
	return 0;
}
