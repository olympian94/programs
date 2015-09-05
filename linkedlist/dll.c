#include<stdio.h>
#include<stdlib.h>

struct n
{
	int val;
	struct n* next;
	struct n* prev;
};
typedef struct n NODE;
typedef struct 
{
	NODE* next;
	int numNodes;
}HEAD;

HEAD* createList()
{
	HEAD* head=(HEAD*)malloc(sizeof(HEAD));
	head->next=NULL;
	head->numNodes=0;
	return head;	
}

void insertAtHead(HEAD *head,int n)
{
	NODE * node=(NODE*)malloc(sizeof(NODE));
	node->val=n;
	if(head->next!=NULL)
		head->next->prev=node;
	node->next=head->next;
	node->prev=NULL;
	head->next=node;
	head->numNodes+=1;
}

void insertAtTail(HEAD *head,int n)
{
	NODE * node=(NODE*)malloc(sizeof(NODE));	
	node->val=n;
	NODE *temp=head->next;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=node;
	node->next=NULL;
	node->prev=temp;
	head->numNodes+=1;
}

void insertAtPos(HEAD *head,int n,int pos)
{
	if(pos<0||pos>head->numNodes)
		printf("\nInvalid position specified: %d",pos);
	else if(pos==0)
		insertAtHead(head,n);
	else if(pos==head->numNodes)
		insertAtTail(head,n);
	else
	{
		int j;
		NODE *temp=head->next;
		for(j=0; j<pos-1; j++)
			temp=temp->next;	
		NODE * node=(NODE*)malloc(sizeof(NODE));
		node->val=n;
		if(temp->next!=NULL)	
//although it will never be null because in that case the pos will=numNodes and control will not come here
			temp->next->prev=node;
		node->next=temp->next;
		node->prev=temp;
		temp->next=node;
		head->numNodes+=1;
	}
}

int deleteFromHead(HEAD* head)
{
	if(head->numNodes==0){
		printf("\nUnderflow.");
		return -1;
	}
	int delval=head->next->val;
	NODE *temp=head->next;
	if(temp->next!=NULL)
		temp->next->prev=NULL;
	head->next=temp->next;
	free(temp);
	head->numNodes-=1;
	return delval;
}

int deleteFromTail(HEAD * head)
{
	if(head->numNodes==0){
		printf("\nUnderflow.");
		return -1;
	}
	int delval;
	NODE *temp=head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	delval=temp->next->val;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
	return delval;
}

int deleteFromPos(HEAD *head, int pos)
{
	if(head->numNodes==0){
		printf("\nUnderflow.");
		return -1;
	}
	else if(pos<0||pos>head->numNodes-1){
		printf("\nInvalid position specified: %d",pos);
		return -2;
	}
	else if(pos==0)
		return deleteFromHead(head);
	else if(pos==head->numNodes-1)
		return deleteFromTail(head);
	else{
		int delval,j;
		NODE *temp=temp->next;
		for(j=0; j<pos-1; j++)
			temp=temp->next;
		NODE *temp2=temp->next;
		if(temp2->next!=NULL)
			temp2->next->prev=temp;
		temp->next=temp2->next;
		delval=temp2->val;
		free(temp2);
		return delval;		
	}
}

void printList(HEAD *head)
{
	if(head->numNodes==0)
		printf("\nList empty. Nothing to print.");
	else{
		NODE *temp=head->next;
		int j=0;
		while(temp!=NULL)
		{
			printf("\n(%d) NODE=\t%d",j++,temp->val);
			if(temp->prev!=NULL)
				printf("\nPREV=\t%d",temp->prev->val);
			printf("\n");
		}
	}
}

int main()
{
	return 0;
}
