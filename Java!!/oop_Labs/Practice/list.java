import java.util.ArrayList;
class Student implements Cloneable
{
	protected String name;
	protected float cgpa;
	public void setStudent(String nm, float cg)
	{	name = nm; cgpa=cg;
	}
	@Override
	public Object clone() throws CloneNotSupportedException
	{	return super.clone();
	}
	public void print()
	{
		System.out.println(name+"\t"+cgpa);
	}
}
class ListTester
{
	public static void main(String[] args)
	{
		ArrayList<Student> StudentList = new ArrayList<Student>();
		Student s1 = new Student();
		Student s2 = new Student();
		s1.setStudent("Abhishek",9.81f);
		s2.setStudent("Ronak",7.81f);
		StudentList.add(s1);
		StudentList.add(s2);
		System.out.println(StudentList.size());
		System.out.println(StudentList.toString());
	}
}