/*
struct dll
{
	int val;
	struct dll *next;
	struct dll *prev;
};

typedef struct dll NODE;

typedef struct
{
	int numNodes;
	NODE *head;
} HEAD;

HEAD* createList()
{
	HEAD *head;
	head=(HEAD*)malloc(sizeof(HEAD));
	head->numNodes=0;
	head->next=NULL;	
	head->prev=NULL;
	return head;
}

void printList(HEAD *head)
{
	if(head->numNodes==0)
		printf("\nNo nodes");
	else
	{
		NODE *temp;
		int j=0;
		temp=head->next;
		printf("\n");
		while(temp!=NULL)
		{
			printf("\n(j) val : %d\t",j++,temp->val);
			if(temp->prev!=NULL)
				printf("prev : %d",temp->prev);
			temp=temp->next;
		}
	}		
}

void insertAtHead(HEAD *head,int val_inp)
{		
	NODE *node;
	node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	node->prev=NULL;
	node->next=head->next;
	if(node->next!=NULL)
		node->next->prev=node;
	head->next=node;
	head->numNodes+=1;
				
}

void insertAtTail(HEAD* head,int val_inp)
{
	NODE *node, *temp;
	node=(NODE*)malloc(sizeof(NODE));
	node->val=val_inp;
	temp=head->next;

	//if node is empty return
	//if temp==null insertAtHead

	while(temp->next!=NULL)
		temp=temp->next;
	node->next=NULL;
	temp->next=node;
	node->prev=temp;
	head->numNodes+=1;
}

void insertAtPos(HEAD *head, int pos, int val_inp)
{
	if(pos<0 || pos>head->numnodes-1 )
		printf("\nInvalid Pos");
	else if(pos==0)
		//insertAtHead
	else
	{
		int j=0;
		NODE *node, *temp;
		node=(NODE*)mallloc(sizeof(NODE));
		node->val=val_inp;
		temp=head->next;
		for(j=0; j<pos-1; j++)
			temp=temp->next;
		node->next=temp->next;
		temp->next=node;
		if(node->next!=NULL)
			node->next->prev=node;
		node->prev=temp;
		head->numNodes+=1;
	}
		
}

void deleteFromHead(HEAD *head)
{
	//if head->numNodes==0 : EMPTY
	NODE *temp;
	temp=head->next;
	head->next=temp->next;
	if(head->next!=NULL)
		head->next->prev=NULL;
	free(temp);
	head->numNodes-=1;
}

void deleteFromTail(HEAD *head)
{
	//if numNodes==0 EMPTY
	//if numNodes==1 delete from head
	NODE *temp;
	temp=head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
}

void deleteFromPos(HEAD *head, int pos)
{
	// if numNodes==0 EMPTY
	//if pos<0 or > numNodes-1 INVALID
	//if pos==1 deleteFromHead
	NODE *temp, *temp1;
	int j;
	temp=head->next;
	for(j=0; j<pos-1; j++)
		temp=temp->next;
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	if(temp->next!=NULL)
		temp->next->prev=temp;
	head->numNodes-=1;
}*/

class DLL
{
	private int val;
	private DLL *next;
	private DLL *prev;
	private int numNodes;
	private final DLL *head;

	public void createList()
	{
		
	}
	
}

