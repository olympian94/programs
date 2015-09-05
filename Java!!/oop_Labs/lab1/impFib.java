import java.util.Scanner;
class Fib
{
	private long num;
	private boolean isEven;
	public void set(long n,boolean val)
	{
		num=n;
		isEven=val;
	}
	public void print()
	{
		if(isEven==true)
			System.out.print(num+"* \t");
		else
			System.out.print(num+"\t");
	}
}
class ImpFibTester
{
	public static void main(String[] args)
	{
		Scanner obj = new Scanner(System.in);
		int N;
		long t1=0, t2=1, temp;
		boolean flag;

		System.out.print("\nEnter Nuber of Fib terms required> ");
		N=obj.nextInt();

		Fib[] fibarr = new Fib[N];
		//throws NullPointerException as all references in the array are initialized to NULL 
		for(int j=0; j<N; j++)
		{
			fibarr[j]= new Fib();
		}
		fibarr[0].set(t1,true);
		fibarr[1].set(t2,false);

		for(int j=2; j<N; j++)
		{
			temp=t1+t2;
			t1=t2;
			t2=temp;
			
			if(temp%2==0)
				flag=true;
			else
				flag=false;
			fibarr[j].set(temp,flag);
		}
		
		for(int j=0; j<N; j++)
		{
			if(j%5==0)
				System.out.print("\n");
			fibarr[j].print();
		}
	}
}