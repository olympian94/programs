class Student implements Comparable<Student>
{
	private int rollno;
	public void set(int rn)
	{	rollno = rn;
	}
	public int get()
	{	return rn;
	}
	public int compareTo(Student obj)
	{
		if(rollno>obj.getrn())
			return 1;
		else if(rollno<obj.getrn())
			return -1;
		else return 0;
	}	
}

