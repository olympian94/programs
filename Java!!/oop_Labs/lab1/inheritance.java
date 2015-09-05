class Person
{
	protected String name;
	protected int age;
	public void get_Person (String nm, int age_inp)
	{	
		name = nm;
		age=age_inp;
	}
	public void print()
	{
		System.out.println("\nName is " + name + "\nAge is " + age );
	}
}
class SportsPerson extends Person
{
	protected float weight;
	protected float height;	
	protected String sport;
	public void get_SportsPerson(float wt, float ht, String sport_inp)
	{
		weight=wt;	height=ht;		sport= sport_inp;		
	}
	public void print_sport()	//note name chosen so as to avoid overriding
	{
		System.out.println("\nSport is " + sport);
	}
}
class Student extends SportsPerson
{
	private float CGPA;
	private String major;
	public Student (String major_inp, float cgpa_inp, String nm, int age, float wt, float ht, String sport)
	{
		super.get_Person(nm,age);
		super.get_SportsPerson(wt,ht,sport);		
		major = major_inp;
		CGPA=cgpa_inp;
	}
	public void print()	//overriding print() of Person
	{
		System.out.println("\nName is " + name + "\nAge is " + age );		
		System.out.println("\nCGPA : " + CGPA + "\nMajor is " + major);		
		super.print_sport();
	}
}
class inheritanceTester
{
	public static void main(String[] args)
	{
		Student obj = new Student ("CompSci",9.811f,"AbhiTiwari",19,75f,1.8f,"Boxing");
		obj.print();
	}
}