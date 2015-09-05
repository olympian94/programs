public class DepartmentTest 
{
	public static void main(String []args)
	{
		Department d = new Department("CS","Computer Science","Bharat M Deshpande");
		d.addNewCourse(1, "OOP", "TSRK Prasad");
		d.addNewCourse(2, "DSA", "Rajendra Roul");
		d.addNewCourse(3, "Compiler Design", "Ramprasad Joshi");
		d.addNewCourse(4, "Computer Architecture", "Biju K Raveendran");
		d.addNewCourse(5, "Computer Networks", "Sreejith V");
		
		d.Search("S");	//search and print
		d.removeCourse(3);
		d.removeCourse(3);
		d.Search("S");	//search and print
	}
}
