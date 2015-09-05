#include<stdio.h>
#include<stdlib.h>

struct gnode{
	struct gnode *next;
	char name;
	char color;
	struct gnode *p;
	int d;
};
typedef struct gnode VERTEX;
typedef struct gll{
	int numNodes;
	VERTEX *next;
	char name;
} GHEAD;


struct node{
	struct node *next;
	int val;
};
typedef struct node NODE;
typedef struct ll{
	int numNodes;
	NODE *next;
} HEAD;

GHEAD* createGraphList(char);
void addv(GHEAD*,char);
char deletev(GHEAD*);
void printGraphList(GHEAD*);

HEAD* createQ();
void enq(HEAD*,int);
int deq(HEAD*);
void printQ(HEAD*);

HEAD* createQ()
{
	HEAD* head;
	head=(HEAD*)malloc(sizeof(HEAD));
	head->next=NULL;
	head->numNodes=0;
	return head;
}

void printQ(HEAD* head)
{
	if(head->next==NULL)
		printf("\nList is empty. Cannot execute print function.");
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

void enq(HEAD* head, int val_inp)
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

int deq(HEAD* head)
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


GHEAD* createGraphList(char nm)
{
	GHEAD* head;
	head=(GHEAD*)malloc(sizeof(GHEAD));
	head->next=NULL;
	head->name=nm;
	head->numNodes=0;
	return head;
}

void addv(GHEAD* head, char val_inp)
{
	VERTEX *node=(VERTEX*)malloc(sizeof(VERTEX));
	node->name=val_inp;
	node->color='W';
	node->p=NULL;
	node->d=0;
	node->next=NULL;
	if(head->next==NULL)
		head->next=node;
	else
	{
		VERTEX *temp=head->next;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	head->numNodes+=1;
}



char deletev(GHEAD* head)
{
	if(head->next==NULL){
		printf("\nList empty. Cannot delete from Tail.");
		return -1;}
	char deleted_ele;
	VERTEX *temp=head->next;
	while(temp->next->next!=NULL)
		temp=temp->next;
	deleted_ele=temp->next->name;
	free(temp->next);
	temp->next=NULL;
	head->numNodes-=1;
	return deleted_ele;	
}

void printGraphList(GHEAD* head)
{
	if(head->next==NULL)
		printf("\nList is empty. Cannot execute print function.");
	else
	{
		VERTEX *temp=head->next;
		int pos=0;
		while(temp!=NULL)
		{
			printf("%c , %c\t",temp->name,temp->color);
			temp=temp->next;
		}
	}	
}

void printGraph(GHEAD *graph[],int size)
{
	int j,k;
	for(j=0; j<size; j++)
	{
		printf("\n%c->\t",graph[j]->name);
		printGraphList(graph[j]);
	}
	printf("\n");
}

BFS(GHEAD* graph[],int size,char src)
{
	int j,k
	//for each adj list in G
	for(j=0; j<size; j++)
	{
		VERTEX *temp;
		temp=graph[j]->next;
		//traverse through the list
		for(k=0; k<graph[j]->numNodes; k++)
		{
			if(temp->name!=src)
			{
				temp->color='W';
				temp->d=999;
				temp->p=NULL;
			}
			temp=temp->next
		}
		
	}
	
}
int main()
{
	int v=8,j;
	int name='r';
	GHEAD* graph1[10];
	for(j=0; j<v; j++)
		graph1[j]=createGraphList(name++);
	addv(graph1[0],'s');
	addv(graph1[0],'v');

	addv(graph1[1],'w');

	addv(graph1[2],'u');
	addv(graph1[2],'x');
	addv(graph1[2],'w');

	addv(graph1[3],'t');
	addv(graph1[3],'x');
	addv(graph1[3],'y');

	addv(graph1[4],'r');

	addv(graph1[5],'s');
	addv(graph1[5],'t');
	addv(graph1[5],'x');

	addv(graph1[6],'w');
	addv(graph1[6],'t');
	addv(graph1[6],'u');
	addv(graph1[6],'y');

	addv(graph1[7],'x');
	addv(graph1[7],'u');


	printGraph(graph1,v);
	return 0;
}
