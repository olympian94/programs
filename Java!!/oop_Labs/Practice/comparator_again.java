import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student
{
	private int rollnum;
	private double cgpa;
	public Student(int rn, double cg){
		rollnum = rn;
		cgpa=cg;
	}
	public int getrn(){
		return rollnum;
	}
	public double getcg(){
		return cgpa;
	}
	public static class OrderByRollnum implements Comparator<Student>{
		public int compare(Student ob1, Student ob2){
			return ob1.getrn()>ob2.getrn()?1:(ob1.getrn()<ob2.getrn()?-1:0);
		}
	}
	public static class OrderByCgpa implements Comparator<Student>{
		public int compare(Student ob1, Student ob2){
			return ob1.getcg()>ob2.getcg()?1:(ob1.getcg()<ob2.getcg()?-1:0);
		}
	}
	public String toString(){
		return rollnum+"\t"+cgpa;		
	}
}
class Tester
{
	public static void main(String[] args){
		Student ob1 = new Student(810,9.81);
		Student ob2 = new Student(002,9.75);
		Student ob3 = new Student(442,8.75);
		ArrayList<Student> list1 = new ArrayList<Student>();
		list1.add(ob1);
		list1.add(ob2);
		list1.add(ob3);	
		System.out.println(list1);	
		Collections.sort(list1, new Student.OrderByRollnum());
		System.out.println(list1);	
		Collections.sort(list1, new Student.OrderByCgpa());
		System.out.println(list1);	
	}
}
