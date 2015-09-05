class LinkedList
{
	private Vehicle obj;
	private LinkedList next;
	public LinkedList()
	{
		obj=null;
		next=null;
	}
	public void createList(Vehicle inp)
	{
		obj=inp;
	}
	public void insertAtTail(Vehicle inp)
	{
		LinkedList node = new LinkedList();
		LinkedList temp = this;
		node.obj=inp;
		while(temp.next!=null)
			temp=temp.next;
		node.next=null;
		temp.next=node;
	}
	public void printList()
	{
		LinkedList temp = this;
		while(temp!=null)
		{
			temp.obj.printVehicle();
			temp=temp.next;			
		}
	}
	
}
class Vehicle
{
	private int ID;
	private float speed;
	public void setId(int ID_inp)
	{
		ID=ID_inp;
	}
	public void setSpeed(float speed_inp)
	{
		speed=speed_inp;
	}
	public int getID()
	{
		return ID;
	}
	public float getSpeed()
	{	
		return speed;
	}
	public void printVehicle()	
	{
		System.out.println("\nID : " + ID + "\nSpeed : " + speed);
	}
	
}
class LinkedListTester
{
	public static void main(String[] args)
	{
		LinkedList sll;
		sll = new LinkedList();
		
		Vehicle v1 = new Vehicle();
		v1.setId(101);
		v1.setSpeed(123.5f);
		Vehicle v2 = new Vehicle();
		v2.setId(102);
		v2.setSpeed(183.5f);
		Vehicle v3 = new Vehicle();
		v3.setId(103);
		v3.setSpeed(203.1f);

		sll.createList(v1);
		sll.insertAtTail(v2);
		sll.insertAtTail(v3);
		sll.printList();
	}
}