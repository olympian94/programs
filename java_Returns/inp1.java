import java.util.Scanner;
class Marks
{
	private float marks;
	public void get()
	{
		System.out.println("Enter Marks");
		Scanner obj = new Scanner(System.in);
		marks=obj.nextFloat();
	}
	public void print()
	{
		if(marks>=95)
			System.out.println("Very Good");
		else
			System.out.println("Work Harder");
	}
}

public class inp1
{
	public static void main(String[] args)
	{
		Marks ob1, ob2;
		ob1 = new Marks();
		ob2 = new Marks();
		ob1.get();
		ob2.get();
		ob1.print();
		ob2.print();
	}
}
