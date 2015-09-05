class Student
{
	private String name;
	private String cg;
	Student(String nm, String cgpa)
	{
		name = nm; cg = cgpa;
	}
	@Override
	public int hashCode()
	{
		System.out.println("The hash code is "+super.hashCode());
		return 1;
	}
}
class TestObjectClass
{
	public static void main(String[] args)
	{
		Student stud1 = new Student("abhi","9");	
		Student stud2 = new Student("abhay","9");	
		stud1.hashCode();		
		stud2.hashCode();
	}
}