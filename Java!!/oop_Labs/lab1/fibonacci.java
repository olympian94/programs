import java.util.Scanner;

class FibApp
{
	static final float PI = 3.14f;
	public static void main(String[] args)
	{
		int t1, t2, temp, N;
		System.out.println("\nEnter N> ");
		Scanner obj = new Scanner(System.in);
		N=obj.nextInt();
		
		int[] fibarr = new int[N];
		t1=0;
		t2=1;
		System.out.println("\nThis is fibonacci " +PI);
		System.out.println(t1);
		System.out.println(t2);
		for(int j=0; j<N; j++)
		{
			temp=t1+t2;
			fibarr[j]=temp;			
			t1=t2;
			t2=temp;
		}
		for(int j=0; j<N; j++)
		{
			if(j%5==0)
				System.out.print("\n");
			System.out.print(fibarr[j]+ "\t");
		}
	}		
}