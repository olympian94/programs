class LinkedList
{
	private int val;
	private static int numNodes=0;
	private LinkedList next;
	public void createList(int val_inp)
	{
		val=val_inp;
		next=null;
	}
	public void insertAtHead(int val_inp)	//assume head is always the calling obj
	{
		LinkedList node = new LinkedList();
		node.next=next;
		next=node;
		node.val=val;
		val=val_inp;
		LinkedList.numNodes+=1;
	}
	public int deleteFromHead()		//assume head always calls
	{
		int delval;
		if(next==null)
		{	
			System.out.println("\nList has only one element. Its reference cant be earthed. Val set to 0 :V :v :| ");
			val=0;
			return 0;
		}
		LinkedList temp =this.next;	
		this.next=temp.next;
		delval=temp.val;
		temp=null;	//reference CUTT OFF
		LinkedList.numNodes-=1;
		return delval;
	}
	public void printList()
	{
		LinkedList temp = this;
		int j=0;
		while(temp!=null)
		{
			System.out.println(j++ + " VAL = " + temp.val);
			temp=temp.next;
		}
		System.out.printf("\n");
	}
}
class LinkedListTester
{
	public static void main(String[] args)
	{
		LinkedList list1 = new LinkedList();
		list1.createList(10);
		list1.printList();

		list1.insertAtHead(20);
		list1.printList();

		list1.insertAtHead(30);
		list1.printList();

		list1.insertAtHead(40);
		list1.printList();

		list1.insertAtHead(50);
		list1.printList();

		list1.insertAtHead(60);
		list1.printList();

		list1.insertAtHead(70);
		list1.printList();

		list1.deleteFromHead();
		list1.printList();
	}
}