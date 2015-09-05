#include<stdio.h>
#include<stdlib.h>
//circular linkedlist
struct node{
	struct node *next;
	int val;
};
typedef struct node NODE;
typedef struct ll{
	int numNodes;
	NODE *next;
} CHEAD;

CHEAD* createList();
void insertAtHead(CHEAD*,int);
void insertAtTail(CHEAD*,int);
void insertAtPos(CHEAD*,int,int);
int deleteFromHead(CHEAD*);
int deleteFromTail(CHEAD*);
int deleteFromPos(CHEAD*,int);
void printList(CHEAD*);
//void error(char *);


CHEAD* createList()
{
	CHEAD* chead;
	chead=(CHEAD*)malloc(sizeof(CHEAD));
	chead->next=NULL;
	chead->numNodes=0;
	return chead;
}

void printList(CHEAD* chead)
{
	if(chead->next==NULL)
		printf("\nList is empty. Cannot execute delete function.");
	else
	{
		NODE *temp=chead->next;
		int j;
		for(j=0; j<chead->numNodes; j++)
		{
			printf("\n(%d)\t%d",j,temp->val);
			temp=temp->next;
		}
		printf("\n");
	}	
}

void insertAtHead(CHEAD* chead, int val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=chead->next;
	chead->next=node;
	chead->numNodes+=1;
}

void insertAtTail(CHEAD* chead, int val_inp)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->next=chead->next;
	if(chead->next==NULL)
		chead->next=node;
	else
	{
		NODE *temp=chead->next;
		int j;
		for(j=0; j<chead->numNodes-1;j++)
			temp=temp->next;
		temp->next=node;
	}
	chead->numNodes+=1;
}

void insertAtPos(CHEAD* chead, int val_inp,int pos)
{
	if(pos<0||pos>(chead->numNodes-1))
		printf("\nInvalid position specified: %d. Cannot insert element.",pos);
	else
	{
		NODE *node=(NODE*)malloc(sizeof(NODE));
		node->next=NULL;
		node->val=val_inp;
		int j;
		if(pos==0)
		{
			node->next=chead->next;
			chead->next=node;
		}
		else
		{
			NODE *temp=chead->next;
			for(j=0; j<pos-1; j++)
				temp=temp->next;
			node->next=temp->next;
			temp->next=node;
		}
		chead->numNodes+=1;		
	}
}


int deleteFromHead(CHEAD* chead)
{
	if(chead->next==NULL){
		printf("\nList empty. Cannot delete from chead.");
		return -1;
	}
	int deleted_ele;
	NODE *temp=chead->next;
	chead->next=temp->next;
	deleted_ele=temp->val;
	free(temp);
	chead->numNodes-=1;
	return deleted_ele;	
}

int deleteFromTail(CHEAD* chead)
{
	if(chead->next==NULL){
		printf("\nList empty. Cannot delete from Tail.");
		return -1;}
	int deleted_ele;
	NODE *temp=chead->next;
	int j;
	for(j=0; j<chead->numNodes-1; j++)
		temp=temp->next;
	deleted_ele=temp->next->val;
	free(temp->next);
	temp->next=chead->next;
	chead->numNodes-=1;
	return deleted_ele;	
}

int deleteFromPos(CHEAD *chead, int pos)
{
	if(chead->next==NULL){
		printf("\nList empty. Cannot delete from pos= %d.",pos);
		return -1;}
	else if(pos<0||pos>(chead->numNodes-1)){
		printf("\nInvalid position specified: %d. Cannot Delete Element.",pos);
		return -1;
	}
	if(pos==0)
		return deleteFromHead(chead);
	else if(pos==chead->numNodes)
		return deleteFromTail(chead);
	else{
		NODE *temp=chead->next;
		NODE *temp2;
		int j, deleted_ele;
		for(j=0; j<pos-1; j++)
			temp=temp->next;
		temp2=temp->next;//to be deleted;
		deleted_ele=temp2->val;
		temp->next=temp2->next;
		free(temp2);
		chead->numNodes-=1;		
		return deleted_ele;
	}
}

int isCircular(CHEAD* chead)
{
	//LIST SHOULD HAVE ATLEAST TWO ELEMENTS
	int flag=1;
	NODE *tortouise, *hare;
	tortouise=chead->next;
	hare=chead->next;
	while(tortouise<hare)
	{
		if(tortouise==NULL||hare==NULL)
		{
			flag=0;
			break;
		}
		tortouise=tortouise->next;
		hare=hare->next->next;
	}
	return flag;
}
int main()
{
	CHEAD* list1;
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
	
	insertAtPos(list1,99,3);
	insertAtPos(list1,99,0);
	insertAtPos(list1,99,15);
	printList(list1);

	deleteFromHead(list1);
	deleteFromHead(list1);
	deleteFromHead(list1);
	printList(list1);
	
	deleteFromTail(list1);
	deleteFromTail(list1);
	deleteFromTail(list1);
	printList(list1);
	return 0;
}

