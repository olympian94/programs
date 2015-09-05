import java.util.Scanner;
public class binary_hexa
{
	public static void main(String[] args)
	{	
		System.out.println("Enter a integer value");
		Scanner inp = new Scanner(System.in);
		int val = inp.nextInt();
		System.out.println(Integer.toBinaryString(val));
		System.out.println(Integer.toHexString(val));
	}
}