//import java.io.*;
import java.util.Scanner;
class Marks
{
	private float marks;
	public void get()
	{
		System.out.println("Enter marks\n");
		Scanner ob = new Scanner(System.in);
		marks=ob.nextFloat();
	}
	public void print()
	{
		if(marks>95)
			System.out.println("Grade is A");
		else if(marks>80)
			System.out.println("Grade is B");		
		else
			System.out.println("Grade is C");	
	}
}
class MarksTester
{
	public static void main(String[] args)
	{
//                                BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		Marks ob1, ob2;
		ob1=new Marks();
		ob2=new Marks();
		ob1.get();
		ob2.get();
		ob1.print();
		ob2.print();
	}
}