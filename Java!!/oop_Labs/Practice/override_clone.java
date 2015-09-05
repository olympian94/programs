class Student implements Cloneable
{
	protected String name;
	protected int rollno;
	public void setStudent(String nm, int rn)
	{	name = nm; rollno=rn;
	}
	@Override
	public Object clone() throws CloneNotSupportedException
	{	return super.clone();
	}
	public void print()
	{
		System.out.println(name+"\t"+rollno);
	}
}
class Batch implements Cloneable
{
	protected Student[] stu;
	protected String teacher;
	public void setStudent(Student[] s)
	{	stu = s;
	}
	public void setTeacher(String nm)
	{	teacher = nm;
	}
	public Student[] getStudent()
	{	return stu;
	}
	public String getTeacher()
	{	return teacher;
	}
	@Override
	public Object clone() throws CloneNotSupportedException
	{
		Batch cloned = (Batch)super.clone();
		cloned.setStudent((Student[])cloned.getStudent().clone());
		return cloned;
	}
	public void printBatch()
	{
		for(int j=0; j<stu.length; j++)
		{
			stu[j].print();
		}
		System.out.println("Teacher "+teacher);
	}
}
class CloneTester
{
	public static void main(String[] args) throws CloneNotSupportedException
	{
		Student[] s1 = new Student[2];
		Student[] s2 = new Student[2];
		
		for(int j=0; j<2; j++)
		{
			s1[j] = new Student();
			s2[j] = new Student();
		}
		s1[0].setStudent("Abhishek",810);
		s1[1].setStudent("Ab2",810);
		s2[0].setStudent("Rahul",81);
		s2[1].setStudent("Rh2",81);

		//create batch
		Batch b1 = new Batch();
		b1.setStudent(s1);
		b1.setTeacher("ESKannan");

		//create clone
		Batch b1_clone = (Batch) b1.clone();

		//print
		System.out.println("Batch :");	
		b1.printBatch();	
		System.out.println("Batch Clone:");		
		b1_clone.printBatch();

		//modify clone
		b1_clone.setStudent(s2);			
		b1_clone.setTeacher("Rathi");

		//print again
		System.out.println("Batch :");	
		b1.printBatch();	
		System.out.println("Batch Clone:");		
		b1_clone.printBatch();
	}
}