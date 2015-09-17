class Outer
{
	int i, j;
	static int l=3;
	public Outer()
	{
		i=1; j=2;
	}
	public Outer(int i, int j)
	{
		this.i=i;
		this.j=j;
	}
	int getI()
	{
		return i;
	}
	class Inner{
		char a;
		void set(char a)
		{
			this.a=a;
		}
		char get()
		{
			return a;
		}
		int fn()
		{
			Outer obj = new Outer(12,13);
			return obj.getI();
		}
	}

	static class StaticInner{
		int a;
		void showDiff()
		{
			//System.out.println(i);
			System.out.println(l);
		}
	}
}

class NestedTest
{
	public static void main(String[] args) {
		Outer obj = new Outer();
		Outer.Inner innerobj = obj.new Inner();
		innerobj.set('b');
		System.out.println(innerobj.fn());

     	Outer.StaticInner staticInner = new Outer.StaticInner();
     	staticInner.showDiff();
	}
}