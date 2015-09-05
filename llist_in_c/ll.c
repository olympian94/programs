#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *next;
	int val;
};
typedef struct node NODE;
typedef struct ll{
	int numNodes;
	NODE *next;
} HEAD;

HEAD* createList();
void insertAtHead(HEAD*,int);
void insertAtTail(HEAD*,int);
void insertAtPos(HEAD*,int,int);
int deleteFromHead(HEAD*);
int deleteFromTail(HEAD*);
int deleteFromPos(HEAD*,int);
void printList(HEAD*);
//void error(char *);


HEAD* createList()
{
	HEAD* head;
	head=(HEAD*)malloc(sizeof(HEAD));
	head->next=NULL;
	head->numNodes=0;
	return head;
}

void printList(HEAD* head)
{
	if(head->next==NULL)
		printf("\nList is empty. Cannot execute delete function.");
	else
	{
		NODE *temp=head->next;
		int pos=0;
		while(temp!=NULL)
		{
			printf("\n(%d)\t%d",pos++,temp->val);
			temp=temp->next;
		}
		printf("\n");
	}	
}

void insertAtHead(HEAD* head, int val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=head->next;
	head->next=node;
	head->numNodes+=1;
}

void insertAtTail(HEAD* head, int val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=NULL;
	if(head->next==NULL)
		head->next=node;
	else
	{
		NODE *temp=head->next;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	head->numNodes+=1;
}

void insertAtPos(HEAD* head, int val_inp,int pos)
{
	if(pos<0||pos>(head->numNodes-1))
		printf("\nInvalid position specified: %d. Cannot insert element.",pos);
	else
	{
		NODE *node=(NODE*)malloc(sizeof(NODE));
		node->next=NULL;
		node->val=val_inp;
		int j;
		if(pos==0)
		{
			node->next=head->next;
			head->next=node;
		}
		else
		{
			NODE *temp=head->next;
			for(j=0; j<pos-1; j++)
				temp=temp->next;
			node->next=temp->next;
			temp->next=node;
		}
		head->numNodes+=1;		
	}
}


int deleteFromHead(HEAD* head)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from head.");
		return -1;
	}
	int deleted_ele;
	NODE *temp=head->next;
	head->next=temp->next;
	deleted_ele=temp->val;
	free(temp);
	head->numNodes-=1;
	return deleted_ele;	
}

int deleteFromTail(HEAD* head)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from Tail.");
		return -1;}
	int deleted_ele;
	NODE *temp=head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	deleted_ele=temp->next->val;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
	return deleted_ele;	
}

int deleteFromPos(HEAD *head, int pos)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from pos= %d.",pos);
		return -1;}
	else if(pos<0||pos>(head->numNodes-1)){
		printf("\nInvalid position specified: %d. Cannot Delete Element.",pos);
		return -1;
	}
	if(pos==0)
		return deleteFromHead(head);
	else if(pos==head->numNodes)
		return deleteFromTail(head);
	else{
		NODE *temp=head->next;
		NODE *temp2;
		int j, deleted_ele;
		for(j=0; j<pos-1; j++)
			temp=temp->next;
		temp2=temp->next;//to be deleted;
		deleted_ele=temp2->val;
		temp->next=temp2->next;
		free(temp2);
		head->numNodes-=1;		
		return deleted_ele;
	}
}
int main()
{
	HEAD* list1;
	list1=createList();

	insertAtHead(list1,1);
	insertAtHead(list1,2);
	insertAtHead(list1,3);
	insertAtHead(list1,4);
	printList(list1);

	insertAtTail(list1,5);
	insertAtTail(list1,6);
	insertAtTail(list1,7);
	insertAtTail(list1,8);
	printList(list1);

	insertAtPos(list1,99,0);
	insertAtPos(list1,99,4);
	insertAtPos(list1,99,10);
	printList(list1);

	printf("\nDeleted:\t%d",deleteFromHead(list1));
	printf("\nDeleted:\t%d",deleteFromHead(list1));
	printList(list1);

	printf("\nDeleted:\t%d",deleteFromTail(list1));
	printf("\nDeleted:\t%d",deleteFromTail(list1));
	printList(list1);

	printf("\nDeleted:\t%d",deleteFromPos(list1,0));
	printf("\nDeleted:\t%d",deleteFromPos(list1,4));
	printf("\nDeleted:\t%d",deleteFromPos(list1,9));
	printf("\nDeleted:\t%d",deleteFromPos(list1,2));
	printList(list1);
	return 0;
}

