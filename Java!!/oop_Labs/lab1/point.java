//import java.util.Scanner

class Point
{
	private double x;
	private double y;
	public static Point origin = new Point(0.0,0.0);
	
	public Point(double x1, double y1)
	{
		x=x1; 
		y=y1;
	}

	public void print()
	{
		System.out.println("Point is " + x + " , " + y);	
	}
	
	public void clear()
	{
		x=0.0; y=0.0;
	}
	public double distance(Point p1)
	{
		double xdiff, ydiff;
		xdiff=x-p1.x;
		ydiff=y-p1.y;		
		return Math.sqrt(xdiff*xdiff+ydiff*ydiff);
	}
	public void move(Point p1)
	{
		x=p1.x;
		y=p1.y;
	}
}
class PointTester
{
	public static void main(String[] args)
	{
		Point p1, p2, p3;
		p1 = new Point(10.0,10.0);
		p2 = new Point(5.0,5.0);
		p3 = new Point(2.5,2.5);
		
		p1.print();		p2.print();		p3.print();
		System.out.println(p1.distance(p2));
		
		p2.move(p3);
		p1.print();		p2.print();		p3.print();
		
		p1.clear();		p2.clear();		p3.clear();
		p1.print();		p2.print();		p3.print();

	}
}