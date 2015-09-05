class Person
{
	private String name;
	private int age;
	public Person(String nm, int age_inp)
	{	name=nm;	age=age_inp;
	}
}
class ToStringTester
{
	public static void main(String[] args)
	{
		Person obj = new Person("Abhishek!!!",19);
		System.out.println(obj.toString());
	}
}