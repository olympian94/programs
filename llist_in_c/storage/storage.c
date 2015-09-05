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
	if(l->head<=l->tail)
	{	
		for(j=l->head; j<=l->tail; j++,m++)
			nl->arr[m]=l->arr[j];
	}
	else
	{
		for(j=l->head; j<=l->size-1; j++,m++)
			nl->arr[m]=l->arr[j];
		for(j=0; j<=l->tail; j++,m++)
			nl->arr[m]=l->arr[j];
	}
	nl->tail=m-1;
	free(l->arr);
	free(l);
	return nl;
}

plist insertAtTail(plist l,int n)	//insertAtTail
{
	if((l->head==0&&l->tail==l->size-1)||(l->tail+1==l->head)){
		printf("\nOverflow");
		return l;}
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}	
	else if(l->tail==l->size-1)
		l->tail=0;
	else 
		l->tail++;
	l->arr[l->tail]=n;
	l->count++;
	return l;
}
	
plist insertAtHead(plist l, int n)	//insert At Head
{
	if((l->head==0&&l->tail==l->size-1)||(l->tail+1==l->head)){
		printf("\nOverflow");
		return l;}
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}	
	else if(l->head==0)
		l->head=l->size-1;
	else
		l->head--;
	l->arr[l->head]=n;
	l->count++;
	return l;
}

int deleteFromTail(plist l)
{
	if(l->count==0){
		printf("\nUnderflow.");
		return -1;}
	int delval=l->arr[l->tail];
	if(l->tail==0)
		l->tail=l->size-1;
	else
		l->tail--;
	l->count--;
	if(l->count==0)
	{
		l->head=-1;
		l->tail=-1;
	}
	return delval;	
}

int deleteFromHead(plist l)
{
	if(l->count==0){
		printf("\nUnderflow.");
		return -1;}
	int delval=l->arr[l->head];
	if(l->head==l->size-1)
		l->head=0;
	else
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
		printf("\nCQueue Empty.");
	else{
		int j;
		if(l->head<=l->tail)
		{	
			for(j=l->head; j<=l->tail; j++)
				printf("\n(%d)\t%d",j,l->arr[j]);
		}
		else
		{
			for(j=l->head; j<=l->size-1; j++)
				printf("\n(%d)\t%d",j,l->arr[j]);
			for(j=0; j<=l->tail; j++)
				printf("\n(%d)\t%d",j,l->arr[j]);
		}
		printf("\n");
	}
}

