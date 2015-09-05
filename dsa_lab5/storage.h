#include<stdio.h>
#include<stdlib.h>

typedef struct _list
{
	int *array, head, tail;
	size_t size, count;
} list;
typedef *list plist;

plist Initialize(size_t size);
plist Resize(plist l, size_t newSize);
int ReadAtHead(plist l);/* Non-destructive read */
int RemoveAtHead(plist l); /* Destructive read */
int ReadAtTail(plist l);/* Non-destructive read */
int RemoveAtTail(plist l); /* Destructive read */
plist WriteAtHead(plist l, int i); /* Replace */
plist AppendAtHead(plist l, int i); /* Append : Resize if needed */
plist WriteAtTail(plist l, int i); /* Replace */
plist AppendAtTail(plist l, int i); /* Append : Resize if needed */


/************************************
	FOR STACK
**************************************/
plist Initialize(size_t size)
{
	plist list=(plist)malloc(size*sizeof(list));
	plist->head=0;
	plist->tail=0;
	plist->size=size;
	plist->count=0;
	return plist;
}
plist Resize(plist l, size_t newSize)
{
	l=(plist)realloc(l,newSize);
	if(l==NULL){
		error(-1,1,"Memory Inadequate");
		printf("\nMemory Inadequate");
	}
	return l;
}
int ReadAtTail(plist l)/* Non-destructive read */ //top
{
	if(l->count==0){
		printf("\nList is empty. Cannot read at head");
		return -1;
	}		
	else
		return l->arr[tail];
}
int RemoveAtTail(plist l) /* Destructive read */  //pop
{
	if(l->count==0){
		printf("\nList is empty. Cannot remove at tail");
		return -1;
	}		
	else
	{
		int del_val=l->arr[tail];
		l->tail--;
		l->count--;
		if(!l->count)
			li->tail=0;
		return del_val;
	}
}
plist WriteAtTail(plist l, int i) /* Replace */ 
{
	if(l->eles==0)
		printf("\nNo elements to overwrite.");
	else
		l->arr[l->tail]=i;
	return l;	
}
plist AppendAtTail(plist l, int i); /* Append : Resize if needed */ //push
{
	if(l->tail==l->size-1)
	{
		l=(plist)realloc(l,l->size+sizeof(int));
		if(l==NULL){
			error(-1,1,"Memory Inadequate");
			printf("\nMemory Inadequate. Coudnt reallocate and hence couldnt append at tail.");
		}

	}
	else if(l->tail==0)
		l->tail--;
	l->tail++;
	l->arr[tail]=i;
	l->count++;
	return l;
}
/************************************
	FOR QUEUE
**************************************/
plist Initialize(size_t size)
{
	plist list=(plist)malloc(size*sizeof(list));
	plist->head=0;
	plist->tail=0;
	plist->size=size;
	plist->count=0;
	return plist;
}
plist Resize(plist l, size_t newSize)
{
	l=(plist)realloc(l,newSize);
	if(l==NULL){
		error(-1,1,"Memory Inadequate");
		printf("\nMemory Inadequate");
	}
	return l;
}
int ReadAtHead(plist l)/* Non-destructive read */
{	
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot read at head.");	
		return -1;
	}
	return l->arr[head];
}

int RemoveAtHead(plist l)/* Destructive read */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot remove from head.");	
		return -1;
	}
	int del_val=l->arr[head];
	l->head++;
	l->count--;
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}
	return del_val;
}

int ReadAtTail(plist l)/* Non-destructive read */
{	
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot read at tail.");	
		return -1;
	}
	return l->arr[tail];	
}

int RemoveAtTail(plist l) /* Destructive read */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot remove from tail.");	
		return -1;
	}
	int del_val=l->arr[tail];
	l->tail--;
	l->count--;
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}
	return del_val;	
}

plist WriteAtHead(plist l, int i) /* Replace */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot write at head.");	
		return l;
	}
	l->arr[head]=i;
	return l;
}

plist AppendAtHead(plist l, int i) /* Append : Resize if needed */
{
	if(l->count!=0&&l->head==0)
	{
		printf("List full at head. Cannot append to queue.");
		return l;
	}
	if(l->count==0)
		l->head++;
	l->head--;
	l->arr[head]=i;
	l->count++;
	return l;
}

plist WriteAtTail(plist l, int i) /* Replace */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot write at tail.");	
		return l;
	}
	l->arr[tail]=i;
	return l;
}

plist AppendAtTail(plist l, int i) /* Append : Resize if needed */
{
	if(l->tail==l->size-1)
	{
		l=(plist)realloc(l,l->size+sizeof(int));
		if(l==NULL){
			error(-1,1,"Memory Inadequate");
			printf("\nMemory Inadequate. Coudnt reallocate and hence couldnt append at tail.");
		}

	}
	else if(l->tail==0)
		l->tail--;
	l->tail++;
	l->arr[tail]=i;
	l->count++;
	return l;
}

/****************************************************
	FOR CIRCULAR QUEUE
****************************************************/
plist Initialize(size_t size)
{
	plist list=(plist)malloc(size*sizeof(list));
	plist->head=0;
	plist->tail=0;
	plist->size=size;
	plist->count=0;
	return plist;
}
plist Resize(plist l, size_t newSize)
{
	l=(plist)realloc(l,newSize);
	if(l==NULL){
		error(-1,1,"Memory Inadequate");
		printf("\nMemory Inadequate");
	}
	return l;
}
int ReadAtHead(plist l)/* Non-destructive read */
{	
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot read at head.");	
		return -1;
	}
	return l->arr[head];
}

int RemoveAtHead(plist l)/* Destructive read */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot remove from head.");	
		return -1;
	}
	int del_val=l->arr[head];
	if(l->head==l->size-1)
		l->head=0;
	else
		l->head++;
	l->count--;
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}
	return del_val;
}

int ReadAtTail(plist l)/* Non-destructive read */
{	
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot read at tail.");	
		return -1;
	}
	return l->arr[tail];	
}

int RemoveAtTail(plist l) /* Destructive read */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot remove from tail.");	
		return -1;
	}
	int del_val=l->arr[tail];	
	if(l->tail==0)
		l->tail=l->size-1;
	else
		l->tail--;
	l->count--;
	if(l->count==0)
	{
		l->head=0;
		l->tail=0;
	}
	return del_val;	
}

plist WriteAtHead(plist l, int i) /* Replace */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot write at head.");	
		return l;
	}
	l->arr[head]=i;
	return l;
}

plist AppendAtHead(plist l, int i) /* Append : Resize if needed */
{
	if((l->head==0&&l->tail==l->size-1)||(l->tail+1==l->head))
	{
		printf("List full at head. Cannot append to queue.");
		return l;
	}
	if(l->count==0){
		l-arr[head]=i;
		l->count++;
		return l;
	}
	else if(l->head==0)
		l->head=l->size-1;
	else
		l->head--;
	l->arr[head]=i;
	l->count++;
	return l;
}

plist WriteAtTail(plist l, int i) /* Replace */
{
	if(l->count==0)
	{
		printf("\nNo element to read. Hence cannot write at tail.");	
		return l;
	}
	l->arr[tail]=i;
	return l;
}

plist AppendAtTail(plist l, int i) /* Append : Resize if needed */
{
	plist newList=(plist)malloc(sizeof(list));
	newList->arr=(int*)malloc((l->size+1)*sizeof(int));
	newList->size=l->size+1;
	newList->count=l->count;
	if(l->tail+1==l->head)//list full, ptrs in between
	{
		newList->head=0;
		int j,l=0;
		for(j=l->head; j<l->size; j++,l++)
			newList->arr[l]=l->arr[j];
		for(j=0; j<=l->tail; j++,l++)
			newList->arr[l]=l->arr[j];
		newList->tail=l;
		newList->arr[tail]=i;
		newList->count++;
		return newList;
	}
	else if((l->head==0&&l->tail==l->size-1))//list full but ptrs at beginning and at end
	{
		l=(plist)realloc(l,l->size+sizeof(int));
		if(l==NULL){
			error(-1,1,"Memory Inadequate");
			printf("\nMemory Inadequate. Coudnt reallocate and hence couldnt append at tail.");
		}
		l->tail++;
		l->arr[tail]=i;
		l->count++;
		return l;
	}
	else if(l->tail

	else if(l->tail==0)
		l->tail--;
	l->tail++;
	l->arr[tail]=i;
	l->count++;
	return l;
}

int main()
{
	plist list1;
	list1=Initialize(10);
	return 0;
}
