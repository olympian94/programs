class Book implements Cloneable
{
	protected String name;
	public void setBook(String nm)
	{	name = nm;
	}
	public String getBook()
	{	return name;
	}
	public Object clone() throws CloneNotSupportedException
	{	return super.clone();
	}
}
class Student implements Cloneable
{
	protected String studentName;
	protected Book[] books = new Book[2];
	public Student()
	{
		studentName = "newStudent";
		books[0] = new Book();
		books[1] = new Book();
	}
	public void setName(String nm)
	{	studentName= nm;
	}
	public void setBooks(String book1,String book2)
	{
		books[0].setBook(book1);
		books[1].setBook(book2);
	}
	@Override
	public Object clone() throws CloneNotSupportedException
	{
		Student copy;
		copy = (Student) super.clone();
		copy.books = (Book[]) books.clone();
		return copy;
	}
	public void print()
	{
		System.out.println(studentName + "\t" + books[0].getBook() + "\t" + books[1].getBook());
	}
}
class CloneTester
{
	public static void main(String[] args)	throws CloneNotSupportedException
	{
		Student obj1 = new Student();
		obj1.setName("Abhishek");
		obj1.setBooks("abc1","abc1");
		obj1.print();
		Student obj2;
		obj2 = (Student) obj1.clone();
		obj2.setBooks("abc2","abc2");
		obj2.print();
	}
}
