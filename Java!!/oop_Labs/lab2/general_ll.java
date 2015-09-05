class Head
{
	private Node next;
	public Head()
	{
		next=null;
	}
}
class NODE
{
	private Object obj;
	private NODE next;
	public Head insertAtHead(Head head_node, Object obj_inp)
	{
		obj=obj_inp;
		next=head_node.next;
		head_node.next=node;
		return head_node;
	}
	public void printList(Head head_node)
	{
		while(head_node.next!=null)
		{
			head_node.next.obj.print();
		}
	}	
}
class Car
{
	private int ID;
	private String name;
	public Car (int ID_inp, String name_inp)
	{
		ID=ID_inp; name=name_inp;
	}
	public void print()
	{
		System.out.ln("\nName : " + name +"\tID : " + ID);
	}
}
class llTester
{
	public static void main(String[] args)
	{
		Car ob1 = new Car("Honda",101);
		Car ob2 = new Car("Toyota",102);
		car ob3 = new Car("Audi",999);
		NODE list1 = new NODE();
		
		
	}
}