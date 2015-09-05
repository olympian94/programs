/*WORTHLESS IMPLEMENTATION. TOO SLOW*/
#include<stdio.h>
#include<stdlib.h>
struct ll
{
	int value;
	int m;
	struct ll *next;
};
typedef struct ll NODE;

typedef struct
{
	int numNODEs;
	NODE *next;
} HEAD;

HEAD* createList()
{
	HEAD *head;
	head= (HEAD*)malloc(sizeof(HEAD));
	head->numNODEs=0;
	head->next=NULL;
	return head;
}

void printList(HEAD *head)
{
	NODE *temp = head->next;	
	if(temp==NULL)
		printf("\nList is Empty.\n");
	else
	{
		int pos=1;
		while(temp!=NULL)
		{
			printf("\n<%d>\t%d\t%d",pos++,temp->value,temp->m);
			temp=temp->next;
		}
		printf("\n");
	}
}


void add(HEAD *head,int num, int set)
{
	NODE *node= (NODE*)malloc(sizeof(NODE));
	node->value=num;
	node->m=set;
	if(head->numNODEs==0)
	{
		head->next=node;
	}
	else
	{
		NODE *temp=head->next;
		while(temp->next!=NULL)		
			temp=temp->next;
		temp->next=node;
	}
	head->numNODEs+=1;
}

NODE* get(HEAD* head,int pos)
{
	NODE *temp = head->next;
	int j;
	if(pos==0)
		return head->next;
	for(j=0; j<pos; j++)
		temp=temp->next;
	return temp;
}

void mark(HEAD* head,int pos)
{
	NODE *temp = head->next;
	int j;
	for(j=0; j<pos; j++)
		temp=temp->next;
	temp->m=1;
}

void printUnmarked(HEAD* head)
{
	NODE *temp=head->next;
	int j;
	while(temp!=NULL)
	{
		if(!temp->m)
			printf("\n%d",temp->value);
		temp=temp->next;
	}
}

int main()
{
	HEAD* list;
	list=createList();
	int n, val, j, k;
	scanf("%d",&n);
	k=2;
	for(j=0; j<n-1; j++)
	{
		add(list,k++,0);
	}
//	printUnmarked(list);
//	printList(list);
	NODE *getnode;
	int m,l,num;
	for(j=0; j<n-1; j++)
	{
		getnode=get(list,j);
		if(getnode->m)
			continue;
		num=getnode->value;
		m=num;
		for(m*=2, l=1; l<n-1; l++)
		{
			getnode=get(list,l);
			val=getnode->value;
			if(val==m)
			{
				mark(list,l);
				m+=num;
			}
		}
	}
	printUnmarked(list);
//	printList(list);

	return 0;
}
