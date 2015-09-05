abstract class benchmark
{
	abstract void benchmark(int arg);
	public final long repeatMethod(int count, int arg)
	{
		long startTime = System.nanoTime();	//calling a static fn
		for(int j=0; j<count; j++)
			benchmark(arg);
		return (System.nanoTime()-startTime);
	}
}
class GenerateFibonacciNos extends benchmark
{
	void benchmark(int terms)
	{
		int t1=0, t2=1, temp;
		for(int j=0; j<terms; j++)
		{
			temp=t1+t2;
			t1=t2;
			t2=temp;
			System.out.printf("- %d -",temp);
		}
	}	
	public static void main(String[] args)	//take input of no of terms from CLA
	{
		int terms=	Integer.parseInt(args[0]);
		GenerateFibonacciNos obj = new GenerateFibonacciNos();
		long time= obj.repeatMethod(1,terms);
		/*	CAN DO THE ABOVE WITH THE FOLLOWING STMT USING TEMP INSTANCE
		 	long time = new GenerateFibonacciNos().repeatMethos(1,terms);
		System.out.println("\n\nTIME STAMP: "+time+ " * 10^(-9) seconds");
	}
}