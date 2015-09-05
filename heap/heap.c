#include<stdio.h>
#include<stdlib.h>
#define MIN_VAL -9999999

typedef struct bin_heap
{
	int *arr;
	int heapsize;
	int len;
} heap;

heap *createHeap(int size)
{
	heap *_heap=(heap*)malloc(sizeof(heap));
	_heap->arr = (int*)malloc(size*sizeof(int));
	_heap->len=size;
	_heap->heapsize=0;
	return _heap;
}

void maxheapify(heap *A, int i)
{
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if(l<=A->heapsize && A->arr[l] > A->arr[i])
		largest = l;
	else
		largest = i;
	if(r<=A->heapsize && A->arr[r]>A->arr[largest])
		largest = r;
	if( largest!=i )
	{
		int temp=A->arr[i];	
		A->arr[i]=A->arr[largest];
		A->arr[largest]=temp;
		maxheapify(A,largest);		
	}
}

void buildmaxheap(heap *A)
{
	//builds max heap of the array and sets heapsize to len-1
	A->heapsize = A->len-1;
	int j;
	for(j=(A->len)/2; j>=0; j--)
		maxheapify(A,j);
}

void heapsort(heap *A)
{
	buildmaxheap(A);
	int i, temp;
	for(i=A->len-1; i>=1; i--)
	{
		temp=A->arr[i];
		A->arr[i]=A->arr[0];
		A->arr[0]=temp;
		A->heapsize--;
		maxheapify(A,0);
	}
}

int heapMaximum(heap *A)
{
	return A->arr[0];
}

int HeapExtractMax(heap *A)
{
	if(A->heapsize<1)
		printf("\nHeap Underflow");
	int max=A->arr[0];
	//heapsize initially set to len-1 in buildmaxheap procedure
	A->arr[0]=A->arr[A->heapsize]; 
	A->heapsize--;
	maxheapify(A,0);
	return max;
}

void HeapIncreaseKey(heap* A, int i, int key)
{
	if(key<A->arr[i])
			printf("\nKey supplied is smaller than existing.");
	A->arr[i]=key;
	int temp;
	//parent_index=(i+1)/2 - 1
	//while index >0 and max heap property is not satisfied
	while(i>0 && A->arr[(i+1)/2 - 1]<A->arr[i])
	{
		temp=A->arr[i];
		A->arr[i]=A->arr[(i+1)/2 - 1];
		A->arr[(i+1)/2 - 1]=temp;
		i= (i+1)/2 - 1;
	}
}

void MaxHeapInsert(heap *A, int key)
{
	if(A->heapsize+1==A->len)
	{
		int newlen = A->len+1, j;
		int * newarr = (int*)malloc(newlen*sizeof(int));
		for(j=0; j<=A->heapsize; j++)
			newarr[j]=A->arr[j];
		A->len++;
		A->heapsize++;
		free(A->arr);
		A->arr=newarr;
	}
	else
		A->heapsize++;
	A->arr[A->heapsize]=MIN_VAL;
	HeapIncreaseKey(A,A->heapsize,key);

}

void printHeap(heap *A)
{
	int j;
	for(j=0, printf("\n"); j<=A->heapsize; j++)
		printf("%d ",A->arr[j]);
}

int main()
{
	int n, j;
	scanf("%d",&n);
	heap *test_heap=createHeap(n);
	for(j=0; j<n; j++)
		scanf("%d",(test_heap->arr)+j);

	//builds max heap of the array and sets heapsize to len-1
	buildmaxheap(test_heap);
//	heapsort(test_heap);
	/*printf("\n%d",HeapExtractMax(test_heap));
	printf("\n%d",HeapExtractMax(test_heap));
	printf("\n%d",HeapExtractMax(test_heap));
	printf("\n%d",HeapExtractMax(test_heap));*/

	printHeap(test_heap);
	printf("\nIncrease key");
	HeapIncreaseKey(test_heap,4,18);
	printHeap(test_heap);

	printf("\nInsert key");
	MaxHeapInsert(test_heap,20);
	printHeap(test_heap);
	MaxHeapInsert(test_heap,-5);
	printHeap(test_heap);
	MaxHeapInsert(test_heap,10);
	printHeap(test_heap);
	
	printf("\n");
	free(test_heap->arr);	
	free(test_heap);
	return 0;
}