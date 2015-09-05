#include<stdio.h>
#include<stdlib.h>

/*
	All function in this file are modified to work on float values.
*/
void printArray(float *arr, int size)
{
	int j;
	for(j=0, printf("\n"); j<size; j++)
		printf("%f ",arr[j]);
}

struct ll
{
	float value;
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
void insertAtTail(HEAD*,float);
float deleteFromTail(HEAD*);
float deleteFromHead(HEAD *head);

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
	{
		printf("\nList is Empty.");
	}
	else
	{
		int pos=1;
		while(temp!=NULL)
		{
			printf("\n<%d>\t%f",pos++,temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
}

float deleteFromHead(HEAD *head)
{
	if(head->next==NULL)
	{
		//printf("\nList is Empty, cannot delete.");
		return -1;
	}
	else{
		float value=head->next->value;
		NODE *temp=head->next;
		head->next=temp->next;
		free(temp);
		head->numNodes-=1;
		return value;
	}
}

void insertAtTail(HEAD* head,float num)
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

void insertionSort(float *arr, int size)
{
	int j, k;
	float key;
	for(j=1; j<size; j++)
	{
		key=arr[j];
		k=j-1;
		while(k>=0&&arr[k]>key)
		{
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=key;
	}
}

void insertion_sort_on_list(HEAD *head)
{
	//read the list into an array
	int size= head->numNodes, j=0;
	float *arr=(float*)malloc(size*sizeof(float));
	NODE* temp = head->next;
	while(temp!=NULL)
	{
		arr[j++]=temp->value;
		temp=temp->next;
	}
	//sort by insertion sort
	insertionSort(arr,size);
	//put back into list
	temp=head->next;
	j=0;
	while(temp!=NULL)
	{
		temp->value=arr[j++];
		temp=temp->next;
	}
	//done
	//printArray(arr,size);
	//printList(head);
}

/*
	Bucket Sort assumes the input values are uniformly distributed in the range [0..1). It creates size-1 buckets. Each bucket
	holds values in the half open interval [j/10 , (j+1)/10 ] for j=0...size-1. Insertion sort is run on the values in a bucket.
	Finally all the values are collected into input array in the order bucket 0 to bucket 'size-1'.
*/

void bucketSort(float *arr, int size)
{
	//let B[0..n-1] be a new array of lists
	int j;
	HEAD* B[size];
	for(j=0; j<size; j++)
		B[j]=createList();

	//bucket B[j] holds values in the half open interval [j/10 , (j+1)/10 ]
	for(j=0; j<size; j++)
	{
		int pos=size*arr[j];
		insertAtTail(B[pos],arr[j]);
	}

	//sort the values in the lists
	for(j=0; j<size; j++)
	{
		//printf("\nRunning insertionSort on list%d",j);
		insertion_sort_on_list(B[j]);
	}		
		
	//read the sorted values in the lists into the array again
	int l;
	NODE* temp;
	for(l=0, j=0; l<size; l++)
	{
		temp=B[l]->next;
		while(temp!=NULL)
		{
			arr[j++]=temp->value;
			temp=temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, j, testcases;
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%d",&n);
		float *arr=(float*)malloc(n*sizeof(float));
		for(j=0; j<n; j++)
			scanf("%f",arr+j);
		printf("\nInput");
		printArray(arr,n);

		bucketSort(arr,n);

		printf("\nBucket Sort");
		printArray(arr,n);

		free(arr);
		printf("\n");
	}
	printf("\n");
	return 0;
}