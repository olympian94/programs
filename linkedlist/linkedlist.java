class Node
{
	private Object value;
	private Node next;
	public Node()
	{
		value=null;
		next=null;
	}
	public void setNext(Node next_inp)
	{
		next=next_inp;
	}
	public void setValue(Object value_inp)
	{
		value=value_inp;
	}
	public Object getValue()
	{
		return value;
	}
	public Node getNext()
	{
		return next;
	}
}

class LinkedList
{
	private Node head;
	private int numNodes;
	public LinkedList()
	{
		head = new Node();
		numNodes=0;
	}
	public void insertAtHead(Object value_inp)
	{
		Node node = new Node();
		node.setValue(value_inp);
		node.setNext(head.getNext());
		head.setNext(node);
		numNodes+=1;
	}
	public void deleteFromHead()
	{
		if(numNodes==0)	
			System.out.println("Linked List is empty, cannot delete element.");
		else{
			Node temp= head.getNext();
			head.setNext(temp.getNext());
			numNodes-=1;
			temp=null;
		}
	}
	public void printList()
	{
		Node temp = head.getNext();
		System.out.println("Nodes:\t"+numNodes);
		while(temp!=null)
		{
			System.out.println(temp.getValue().toString());
			temp=temp.getNext();
		}
	}
}

class lltester
{
	public static void main(String[] args)
	{
		LinkedList list = new LinkedList();
		list.printList();
		list.insertAtHead("A1");
		list.insertAtHead("A2");
		list.insertAtHead("A3");
		list.insertAtHead("A4");
		list.insertAtHead("A5");
		list.printList();
		list.deleteFromHead();
		list.deleteFromHead();
		list.deleteFromHead();
		list.deleteFromHead();
		list.deleteFromHead();
		list.deleteFromHead();
		list.deleteFromHead();
		list.printList();
	}
}
