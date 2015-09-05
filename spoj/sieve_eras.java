//sieve of eras; very slow after 1500
import java.util.Scanner;

class Node
{
	private Object value;
	private Node next;
	private boolean marked;
	public Node()
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

class LinkedList
{
	private Node head;
	private int numNodes;
	public LinkedList()
	{
		head=new Node();
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
	public Node get(int pos)
	{
		if(numNodes>0)
		{
			if(pos==0)
				return head.getNext();
			else
			{
				Node temp=head.getNext();
				for(int j=0; j<pos; j++)
					temp=temp.getNext();
				return temp;
			}
		}
		return null;
	}
	public void mark(int pos)
	{
		if(numNodes>0)
		{
			Node temp=head.getNext();
			for(int j=0; j<pos; j++)
				temp=temp.getNext();		
			temp.setMarked(true);
				
		}
	}
	public void printList()	
	{
		if(numNodes>0)
		{
			Node temp= head.getNext();
			while(temp!=null)
			{
				System.out.println(temp.getValue()+"\n"+temp.getMarked());
				System.out.println("*****************");
				temp=temp.getNext();
			}
		}
	}
	public void printPrime()
	{
		if(numNodes>0)
		{
			Node temp= head.getNext();
			while(temp!=null)
			{
				if(!temp.getMarked())
					System.out.println(temp.getValue()+"\n");
				temp=temp.getNext();
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
			list.add(k,false);
			k++;
		}
//		list.printList();

		Node get;
		int m, j, l, val, num;			
		for(j=0; j<n-1; j++)
		{
			get=list.get(j);
			if(get.getMarked())
				continue;
			num=(Integer) get.getValue();			
			m=num;
			for(m*=2, l=1; l<n-1; l++)
			{
				get=list.get(l);
				val= (Integer) get.getValue();
				if(val==m)
				{
					list.mark(l);
					m+=num;
				}
			}
		}
//		list.printList();
		System.out.println();
		list.printPrime();
	}
}
