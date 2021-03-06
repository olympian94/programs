import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
/**
 * Program to show sorting based on natural order using comparable and on custom order using comparator
 */
class Student implements Comparable<Student>
{
	private int rn;
	private float cg;
	private String name;
	public Student(int num, float cgpa, String nm)
	{
		rn = num; cg = cgpa; name = nm;
	}
	public int getrn()
	{	return rn;
	}
	public float getcg()
	{	return cg;
	}
	public String getname()
	{	return name;
	}
	public static class orderbyrn implements Comparator<Student>
	{
		@Override
		public int compare(Student obj1, Student obj2)
		{
			return obj1.rn>obj2.rn? 1 : (obj1.rn<obj2.rn? -1 : 0 );
		}
	}
	public static class orderbycg implements Comparator<Student>
	{
		@Override
		public int compare(Student obj1, Student obj2)
		{
			return obj1.cg>obj2.cg? 1 : (obj1.cg<obj2.cg? -1 : 0 );
		}
	}
	/*	NOTE THIS FAILS!
	public static class testingcomparable implements Comparable<Student>
	{
		@Override
		public int compareTo(Student obj)
		{
			return cg>obj2.cg? 1 : (cg<obj2.cg? -1 : 0 );
		}
	}
	*/
	@Override
	public int compareTo(Student obj2)	//while overriding types have to be compatible ie either same or related by inheritance
	{
		return rn>obj2.rn? 1 : (rn<obj2.rn? -1 : 0 );
	}
	public String toString()
	{
		return rn+name+cg;
	}
}
class SortStudents
{
	public static void main(String[] args)
	{
		Student stu1 = new Student(101,9.4f,"Kunal");
		Student stu2 = new Student(810,9.9f,"Abhishek");
		Student stu3 = new Student(7,9.1f,"Gauri");
		Student stu4 = new Student(20,9.0f,"Ahmed");
		ArrayList<Student> list1 = new ArrayList<Student>();
		list1.add(stu1);
		list1.add(stu2);
		list1.add(stu3);
		list1.add(stu4);
		//print unsorted Collections
		System.out.println(list1);
		//sorting on natural order- ascending
		Collections.sort(list1);
		//print sorted Collections
		System.out.println(list1);
		//sorting in descending order
		Collections.sort(list1,Collections.reverseOrder());
		//print descending sort
		System.out.println(list1);
		//Sorting using one of the Comparators
		Collections.sort(list1, new Student.orderbycg());
		System.out.println(list1);
	}
}

