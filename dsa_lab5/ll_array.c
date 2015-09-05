#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int *arr;
	int eles, size;
	int head,tail;
}LIST;

LIST* createList(int size)
{
	LIST *list=(LIST*)malloc(sizeof(LIST));
	list->arr=(int*)malloc(size*sizeof(int));
	list->eles=0;
	list->size=size;
	list->head=-1;
	list->tail=-1;
	return list;
}

void insertAtHead(LIST *list,int val)
{
	if(list->head==-1)
	{
		list->head=0;
		list->tail=0;
		list->arr[list->head]=val;
		list->eles++;
	}
	else if(list->head==0)
			printf("\nList full at head-side (head=%d). Cannot add element= %d.",list->head,val);
	else
	{	
		list->head--;
		list->arr[list->head]=val;
		list->eles++;
	}
}

void insertAtTail(LIST* list, int val)
{
	if(list->tail==((list->size)-1))
		printf("\nList full at tail side (tail=%d). Cannot add element= %d.",list->tail,val);
	else
	{
		list->tail++;
		list->arr[list->tail]=val;
		list->eles++;
	}
}

int deleteFromHead(LIST *list)
{
	if(list->eles==0){
		printf("\nList empty (head=%d tail= %d). Cannot delete from head.",list->head,list->tail);
		return -1;
	}
	else
	{
		int del_ele=list->arr[list->head];
		list->head++;
		list->eles--;
		//if empty reset ptrs
		if(list->eles==0)
		{
			list->head=-1;
			list->tail=-1;
		}
		return del_ele;
	}
}

int deleteFromTail(LIST *list)
{
	int del_ele=-1;
	if(list->eles==0)
		printf("\nList is empty (head=%d tail=%d). Cannot delete from tail.",list->head,list->tail);
	else
	{
		if(list->tail>=list->head){
			del_ele=list->arr[list->tail];
			list->tail--;
			list->eles--;
			//if empty reset ptrs
			if(list->eles==0)
			{
				list->head=-1;
				list->tail=-1;
			}
		}
	}
	return del_ele;
}

void printList(LIST* list)//NOT FOR CIRCULAR LIST!
{
	int j, pos=0;
	if(list->eles==0)
		printf("\nList empty(head=%d tail=%d). Nothing to print.",list->head,list->tail);
	else{
		for(j=list->head; j<=list->tail; j++)
			printf("\n(%d)\t%d",pos++,list->arr[j]);
		printf("\n");
	}
}

int main()
{
	LIST *list1;
	list1=createList(10);
	insertAtHead(list1,1);
	insertAtHead(list1,2);
	printList(list1);

	insertAtTail(list1,2);
	insertAtTail(list1,3);
	insertAtTail(list1,4);
	insertAtTail(list1,5);
	insertAtTail(list1,6);
	insertAtTail(list1,7);
	insertAtTail(list1,8);
	insertAtTail(list1,9);
	insertAtTail(list1,10);
	insertAtTail(list1,11);
	printList(list1);

	int res, j;
	for(j=0; j<12; j++)
	{
		res=deleteFromHead(list1);
		if(res>0)
			printf("\nDeleted:\t%d",res);
	}
	printList(list1);

	for(j=0; j<12; j++)
	{
		insertAtHead(list1,j+1);
	}
	printList(list1);

	for(j=0; j<12; j++)
	{
		insertAtTail(list1,j+1);
	}
	printList(list1);

	printf("\nDeleted:\t%d",deleteFromHead(list1));
	printf("\nDeleted:\t%d",deleteFromHead(list1));
	printf("\nDeleted:\t%d",deleteFromHead(list1));
	printList(list1);
	printf("\nDeleted:\t%d",deleteFromTail(list1));
	printf("\nDeleted:\t%d",deleteFromTail(list1));
	printf("\nDeleted:\t%d",deleteFromTail(list1));
	printList(list1);

	for(j=0; j<12; j++)
	{
		res=deleteFromTail(list1);
		if(res>0)
			printf("\nDeleted:\t%d",res);
	}
	printList(list1);

	for(j=0; j<12; j++)
	{
		insertAtTail(list1,j+1);
	}
	printList(list1);

	printf("\n");
	return 0;
}
