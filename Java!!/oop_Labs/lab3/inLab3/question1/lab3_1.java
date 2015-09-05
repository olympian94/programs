import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;
import java.math.BigInteger;

/**
 * 
 */
class HugeInt
{
	protected String inp;
	protected String[] nums = new String[2];
	protected BigInteger sum;
	
	/**
	 * The method initializes the input variable of the class. 
	 */
	public void setInp(String inp)
	{	this.inp = inp;
	}
	
	/**
	 * Of the supplied string, the method seperates out two substrings, each of which represents a number.
	 * <p>
	 * A regular expression is used by the method. 
	 * @param inp This is the string input consisting of two numbers as one string.
	 */
	public void giveInput(String inp)
	{
		String regex = "\\d+\\b";
		Pattern pat = Pattern.compile(regex);
		Matcher match = pat.matcher(inp);
		int count = 0;
		while(count<2&&match.find())	
		{
			nums[count] = new String();
			nums[count] = match.group(0);
			count++;
		}
		parseInput();
	}
	
	/**
	 * The method prints the seperated numbers.
	 */		
	public void printNums()
	{
		System.out.println(nums[0] + "\t" +nums[1]);
	}
	
	/**
	 * This method parses the two strings seperated from the input string, into integers. Furthermore, it adds these values and 
	 * assigns the value to sum.
	 */	
	protected void parseInput()
	{
		BigInteger num1 = new BigInteger(nums[0]);
		BigInteger num2 = new BigInteger(nums[1]);
		sum = num1.add(num2);
	}
	
	/**
	 * Getter method for sum.
	 */
	public BigInteger getSum()
	{	return sum;
	}
	/**
	 * compares the supplied HugeInt number with the number in the invoking object.
	 * @param obj	Object of type HugeInt
	 */
	public int compare(HugeInt obj)
	{
		BigInteger bi1 = new BigInteger(inp);
		BigInteger bi2 = new BigInteger(obj.inp);
		return bi1.compareTo(bi2);

	}
}
class NewAdditionTester
{
	public static void main(String[] args)
	{
		Scanner inp = new Scanner(System.in);
		int N;
		String temp = "";
		System.out.println("Enter N>");
		N = Integer.parseInt(inp.nextLine());
		HugeInt[] objs = new HugeInt[N];
		for(int j=0; j<N; j++)
		{
			System.out.println("Enter inp line : "+(j+1));
			temp = inp.nextLine();
			objs[j] = new HugeInt();
			objs[j].giveInput(temp);
		}
		for(int j=0; j<N; j++)
		{
			System.out.println("Sum = " + objs[j].getSum());
		}
		HugeInt num1 = new HugeInt();
		HugeInt num2 = new HugeInt();
		num1.setInp("123");
		num2.setInp("9999999");
		System.out.println("Compare Result : "+num1.compare(num2));
	}
}
