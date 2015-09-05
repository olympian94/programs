class Point
{
	public double x;
	public double y;
}

class ObjTester
{
	public static void main(String[] args)
	{
		Object oref = new Point();
		oref = 37.789f;
		System.out.printf("\n\n Heeeeeeres Lassie!! \t %-10.2f ",oref);
	}
}