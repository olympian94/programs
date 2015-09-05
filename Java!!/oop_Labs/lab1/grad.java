import java.util.Scanner;
class Person
{
	private String name;
	private int age;
	public Person()
	{
		Scanner inp = new Scanner (System.in);
		System.out.println("\nPerson :	Enter name and age >");
		name=inp.nextLine();
		age=inp.nextInt();		
	}
}
class Student extends Person
{
	private float cgpa;
	private int rollno;
	public Student()
	{
		Scanner inp = new Scanner (System.in);
		System.out.println("\nStudent :	Enter Roll No and CGPA >");
		rollno=inp.nextInt();		
		cgpa=inp.nextInt();
	}	
}
class InhApp
{
	public static void main(String[] args)
	{
	}
}