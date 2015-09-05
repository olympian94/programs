//Implement a queue using two stacks
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

int top(plist l)
{
	if(l->count==0)
		return -1;
	else
		return l->arr[l->tail];
}

int isEmpty(plist l)
{
	if(l->count==0)
		return 1;
	else 
		return 0;
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

void enq(plist s1,plist s2,int n)
{
	push(s1,n);
}

int deq(plist s1,plist s2)
{
	if(s2->count!=0){
		return pop(s2);	
	}
	while(s1->count!=0)
		push(s2,pop(s1));
	return pop(s2);
}

void printq(plist s1,plist s2)
{
	int topval;
	if(s1->count==0&&s2->count==0)
		printf("\nQ empty");
	else{
		if(!isEmpty(s2))
		{
			int j=0;
			for(j=s2->tail; j>=0; j--)
				printf("\n(%d)\t%d",j,s2->arr[j]);
		}
		if(!isEmpty(s1))
			printList(s1);
		else
			printf("\n");
	}	
}

int main()
{
	plist s1=createList(10);
	plist s2=createList(10);
	enq(s1,s2,1);
	enq(s1,s2,2);
	enq(s1,s2,3);
	enq(s1,s2,4);
	printq(s1,s2);

	deq(s1,s2);
	deq(s1,s2);
	printq(s1,s2);

	enq(s1,s2,1);
	enq(s1,s2,2);
	printq(s1,s2);
		
	enq(s1,s2,5);
	enq(s1,s2,6);
	enq(s1,s2,7);
	enq(s1,s2,8);
	printq(s1,s2);

	deq(s1,s2);
	deq(s1,s2);
	printq(s1,s2);

	return 0;
}

