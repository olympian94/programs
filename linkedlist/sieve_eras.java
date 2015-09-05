import java.util.Scanner;
class Node
{
	private Object value;
	private node next;
	private boolean marked;
	public node()
	{
		value=null;
		next=null;
		marked=false;
	}
	public void setNext(Node nxt)
	{	next=nxt;
	}
	public void setValue(Object val)
	{	value=val;
	}
	public Object getValue()
	{	return value;
	}
	public Node getNext()
	{	return next;
	}
	public void setMarked(boolean set)
	{	marked=set;
	}
	public boolean getMarked()
	{	return marked;
	}
}
class LinkedList()
{
	private Node head;
	private int numNodes;
	public LinkedList()
	{
		head=null;
		numNodes=0;
	}
	public void add(Object val, boolean set)
	{
		Node node = new Node();
		node.setValue(val);
		node.setMarked(set);
		if(numNodes==0)
		{
			head.setNext(node);
		}
		else{
			Node temp = head.getNext();
			while(temp.getNext()!=null)
				temp=temp.getNext();
			temp.setNext(node);
		}
		numNodes++;
	}	
	public void printList()	
	{
		if(numNodes>0)
		{
			Node temp= head.getNext();
			while(temp.getNext()!=null)
			{
				System.out.println(temp.getValue+"\n"+temp.getMarked());
				System.out.println("*****************");
			}
		}
	}
}
public class sieve_eras
{
	public static void main(String[] args)
	{
		int n, k;
		Scanner inp = new Scanner(System.in);
		n=inp.nextInt();
		LinkedList list = new LinkedList();
		k=2;
		for(int j=0; j<n-1; j++)
		{
			list.add(k++,0);
		}
		list.printList();
	}
}
