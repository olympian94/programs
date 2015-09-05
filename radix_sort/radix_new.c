#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
		//printf("\nList is Empty, cannot delete.");
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

void printArray(int *arr, int size)
{
	int j;
	for(j=0, printf("\n"); j<size; j++)
		printf("%d ",arr[j]);
}


/*
	i/p:
	-------------------------------------------------------------------------------------------------------
	arr : unsorted input array
	size : size of array
	total_digits : The no of digits in the biggest number
	-------------------------------------------------------------------------------------------------------
	o/p:
	-------------------------------------------------------------------------------------------------------
	arr : array is sorted 
	-------------------------------------------------------------------------------------------------------
	Description:
	-------------------------------------------------------------------------------------------------------
	This is a proper implementation of radix sort using lists as 'buckets'. There are 10 buckest corressp. to 0,1,2...9. There will as
	many passes as the no of digits in the input element with maximum no of digits. Each pass corressp. to 1's place, then 10's place
	on the next iteration, then 100's place on the next and so on. On each pass according to the digit, the number is placed in the 
	corressp. list. For example 356 will be placed in '6'th list on first pass, '5'th list on second pass and '3'rd list on the third
	pass. After each pass elements will be taken from lists begining from list 0, list 1 ... list 9 and elements will be popped from
	head placed in the array itself. And then the process will be repeated from the next iteration in the same way untill all passes
	are done. The array will finally have the sorted output.
	-------------------------------------------------------------------------------------------------------
*/
void radixSort(int *arr, int size, int total_digits)
{
	int j, i, l, pass, power, dig, val;
	HEAD *list_arr[10]={NULL};
	for(j=0; j<10; j++)
		list_arr[j]=createList();

	for(pass=1; pass<=total_digits; pass++)
	{
		//do a pass on the array based on the digit in 'pass' place (one's place, 10's place, 100's place and so on)
		for(j=0; j<size; j++)
		{
			power=pow(10,pass);
			dig=arr[j]%power;
			if(pass-2>=0)
				dig/=pow(10,pass-1);
			insertAtTail(list_arr[dig],arr[j]);
		}
		//after this loop, the lists of list has elements according to the pass

		//based on the pass, collect the elements from the 10 lists and put them back in the array in the order created
		//after the above pass
		for(j=0, l=0; j<10; j++)
		{
			val=deleteFromHead(list_arr[j]);
			//val=-1 implies no more elements are in the lists
			if(val!=-1)
			{
				//do j-- so that the loop stays on list_arr[j] and doesnt move onto the next list in the list of lists (list_arr)
				j--;
				arr[l++]=val;
			}
		}
		//after this loop the list of lists: list_arr is now empty and array arr will have the array elements in order created
		//by the pass
	}

	//free every list in list of lists : list_arr
	for(j=0; j<10; j++)
		free(list_arr[j]);
}

int main()
{
	int n, j, testcases, digits;
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%d",&digits);
		scanf("%d",&n);
		int *arr=(int*)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			scanf("%d",arr+j);
		printf("\nInput");
		printArray(arr,n);

		radixSort(arr,n,digits);

		printf("\nCounting Sort");
		printArray(arr,n);

		free(arr);
		printf("\n");
	}
	printf("\n");
	return 0;
}