#include<iostream>
using namespace std;
template <class type> class Node
{
	private:
	type value;
	Node* next;
	public:
	Node()
	{
		value = NULL;
		next=NULL;
	}
	void setNext(Node* nextptr)
	{
		next=nextptr;
	}
	void setValue(type value_inp)
	{
		value=value_inp;
	}
	type getValue()	
	{
		return value;
	}
	Node* getNext()
	{
		return next;
	}
}
	
template <class type> class LinkedList
{
	private:
	Node<type> head;
	int numNodes;
	public:
	LinkedList()
	{
		head.setNext(NULL);
		head.seValue(NULL);
		numNodes=0;
	}
	insertAtHead(type value_inp)
	{
		Node 
	}
}
