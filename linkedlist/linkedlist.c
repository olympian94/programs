//linkedlist.h
struct ll
{
	int value;
	struct ll *next;
}
typedef struct ll NODE;
typedef struct
{
	int numNodes;
	NODE *next;
} HEAD;

//linkedlistops.h
extern HEAD *createList();
extern void printList(HEAD);
extern void insertAtHead(HEAD*,int);
extern void insertAtTail(HEAD*,int);
extern void insertAtPos(HEAD*,int,int);
extern int deleteFromHead(HEAD*);
extern int deleteFromTail(HEAD*);
extern int deleteFromPos(HEAD*,int);
extern int deleteValue(HEAD*,int);

//linkedlistops.c
/*
#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
*/
HEAD* createList()
{
	HEAD *head;
	head= (HEAD*)malloc(sizeof(HEAD));
	head->numNodes=0;
	head->next=NULL;
	return head;
}

void printList(HEAD head)
{
	NODE *temp = head->next;
	if(temp==NULL)
		printf("\nList is Empty.\n");
	else
	{
		int pos=1;
		while(temp!=NULL)
		{
			printf("\n<%d>\t%d",pos++,temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
}

void insertAtHead(HEAD *head, int num)
{
	NODE *node= (NODE*)malloc(sizeof(NODE));
	node->value=num;
	node->next=head->next;
	head->next=node;
	head->numNodes+=1;
}

void insertAtTail(HEAD* head,int num)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->value=num;
	node->next=NULL;
	NODE *temp=head->next;
	while(temp->next!=NULL)		
		temp=temp->next;
	temp->next=node;
	head->numNodes+=1;
}

void insertAtPos(HEAD* head,int num,int pos)
{
	NODE *temp = head->next;
	NODE *node= (NODE*)malloc(sizeof(NODE));
	if(pos==0)
		insertAtHead(head,num);
	else if(pos<0||pos>head->(numNodes-1))
		printf("\nInvalid pos:\t%d\n",pos);
	else{
	int j=0;
	for(;j<pos-1;j++)
		temp=temp->next;
	node->value=num;
	node->next=temp->next;
	temp->next=node;		
	head->numNodes+=1;
	}
}

int deleteFromHead(HEAD *head)
{
	if(head->next==NULL)
	{
		printf("\nList is Empty, cannot delete.\n");
		return -1;
	}
	else{
	int val=head->next->value;
	NODE *temp=head->next;
	head->next=temp->next;
	free(temp);
	head->numNodes-=1;
	return val;
	}
}

int deleteFromTail(HEAD *head)
{
	if(head->next==NULL)
	{
		printf("\nList is Empty, cannot delete.\n");
		return -1;
	}
	else{
	int num;
	NODE *temp = head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	num=temp->next->value;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
	return num;
	}
}

int deleteFromPos(HEAD* head, int pos)
{
	if(head->next==NULL)
	{
		printf("\nList is Empty, cannot delete.\n");
		return -1;
	}
	else if(pos<0||pos>head->(numNodes-1)){
		printf("\nInvalid pos:\t%d\n",pos);
		return -1;
	}
	else if(pos==0)
	{
		return deleteFromHead(head);
	}
	else{
	
	}
}
