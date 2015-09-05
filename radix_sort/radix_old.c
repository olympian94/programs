#include<stdio.h>
#include<stdlib.h>

struct ll
{
	int value;
	struct ll *next;
};
typedef struct ll NODE;
typedef struct
{
	int numNodes;
	NODE *next;
} HEAD;

HEAD *createList();
void printList(HEAD*);
void insertAtTail(HEAD*,int);
int deleteFromTail(HEAD*);
int deleteFromHead(HEAD *head);

HEAD* createList()
{
	HEAD *head;
	head= (HEAD*)malloc(sizeof(HEAD));
	head->numNodes=0;
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
			printf("\n<%d>\t%d",pos++,temp->value);
			temp=temp->next;
		}
		printf("\n");
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

void insertAtTail(HEAD* head,int num)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));
	node->value=num;
	node->next=NULL;
	if(head->next==NULL)
		head->next=node;
	else{
		NODE *temp=head->next;
		while(temp->next!=NULL)		
			temp=temp->next;
		temp->next=node;
	}
	head->numNodes+=1;
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

int max_dig(int *arr,int size)
{
	int j, count=0,max;
	max=arr[0];
	for(j=1; j<size; j++)
		if(arr[j]>max)
			max=arr[j];
	while(max!=0)
	{
		max/=10;
		count++;
	}

}
int main()
{
	int inp[]={322,123,456,789,2,54};
	int size=6;
	int j,dig;
	HEAD *arr[10]={NULL};

	for(j=0; j<10; j++)
		arr[j]=createList();
	//pass1
	printf("\n--------------------------------PASS1");
	for(j=0; j<6; j++)
	{
		dig=inp[j]%10;
		insertAtTail(arr[dig],inp[j]);
	}


	for(j=0; j<10; j++){
		printf("-----------------%d",j);
		printList(arr[j]);
		printf("\n");
	}

	//pass2
	printf("\n--------------------------------PASS2");
	HEAD *arr2[10]={NULL};
	int temp;
	for(j=0; j<10; j++)
		arr2[j]=createList();
	for(j=0; j<10; j++)
	{
		int val=deleteFromHead(arr[j]);
		temp=val;
		if(val!=-1)
		{
			j--;//to ensure that all nos. int the list against a digit are taken
			temp/=10;
			dig=temp%10;
			insertAtTail(arr2[dig],val);
		}		
	}
	for(j=0; j<10; j++){
		printf("-----------------%d",j);
		printList(arr2[j]);
		printf("\n");
	}	
	for(j=0; j<10; j++)
		free(arr[j]);

	//pass3
	printf("\n--------------------------------PASS3");
	HEAD *arr3[10]={NULL};
	for(j=0; j<10; j++)
		arr3[j]=createList();
	for(j=0; j<10; j++)
	{
		int val=deleteFromHead(arr2[j]);
		temp=val;
		if(val!=-1)
		{
			j--;//to ensure that all nos. int the list against a digit are taken
			temp/=100;
			dig=temp%10;
			insertAtTail(arr3[dig],val);
		}		
	}
	for(j=0; j<10; j++){
		printf("-----------------%d",j);
		printList(arr3[j]);
		printf("\n");
	}
	for(j=0; j<10; j++)
		free(arr2[j]);

	//generate output array;	
	int l=0;
	for(j=0; j<10; j++)
	{
		int val=deleteFromHead(arr3[j]);
		if(val!=-1)
		{
			j--;//to ensure that all nos. int the list against a digit are taken
			inp[l++]=val;
		}		
	}

	if(l!=size)
		printf("\nAfter algo run mismatch in number of elements!!!");
	for(j=0; j<size; j++){
		printf("\n%d",inp[j]);
	}
	for(j=0; j<10; j++)
		free(arr3[j]);
	return 0;
}