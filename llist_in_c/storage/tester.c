#include "dq.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	plist dequeue1=createList(10);
	enqH(dequeue1,1);
	enqH(dequeue1,2);
	enqH(dequeue1,3);
	enqT(dequeue1,4);
	enqT(dequeue1,5);
	enqT(dequeue1,6);
	enqT(dequeue1,7);
	printList(dequeue1);

	deqH(dequeue1);
	deqH(dequeue1);
	deqT(dequeue1);
	deqT(dequeue1);
	printList(dequeue1);

	return 0;
}
