class Node
{
	private Object value;
	private Node next;
	public Node()
	{
		value=null;	next=null;
	}
	public Node (Object val)
	{
		value= val;		next=null;
	}
	public Node getnext()
	{	return next;
	}
	public void setnext(Node nxt)
	{	next=next;
	}
	public Object getval()
	{	return value;
	}
	public void setval(Object val)
	{	value=val;
	}
}
class LinkedList
{
	private Node head;
	private int numNodes;
	public LinkedList()
	{
		head= new Node();
		numNodes=0;
	}
	public void insertAtHead(Object val)
	{
		Node node = new Node(val);
		node.setnext(head.getnext());
		head.setnext(node);
		numNodes+=1;
	}
	public String toString()
	{
		Node temp = new Node();
		temp.setnext(head.getnext());
		String output = "";
		while(temp!=null)
		{
			output += "-" + temp.getval().toString() + "-";
			temp = temp.getnext();
		}
	}
}
class Vehicle
{
	private String name;
	private int ID;
	public void setdata(String nm, int ID_inp)
	{
		name=nm; ID=ID_inp;
	}
	public String toString()
	{
		String desc = "":
		desc+=name + " ID: "+ID;
		return desc;
	}
}
public LinkedListTester
{
	public static void main(String[] args)
	{
	}
}