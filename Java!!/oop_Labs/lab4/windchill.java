import java.util.Scanner;
public class windchill
{
	public static void main(String[] args)
	{
		Scanner inp = new Scanner(System.in);
		double T, V;
		System.out.println("Enter T and V.");
		T = inp.nextDouble();
		V = inp.nextDouble();
		System.out.println(Math.round((35.74 + (0.6215)*T - 35.75*(Math.pow(V, 0.16)) + (0.4275)*T*(Math.pow(V,0.16)))));
	}
}