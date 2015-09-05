import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

class HugeInt
{
	protected String inp;
	protected String[] nums = new String[2];
	protected long sum;
	public void setInp(String inp)
	{	this.inp = inp;
	}
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
	public void printNums()
	{
		System.out.println(nums[0] + "\t" +nums[1]);
	}
	protected void parseInput()
	{
		long num1, num2;
		num1 = Integer.parseInt(nums[0]);
		num2 = Integer.parseInt(nums[1]);
		sum = num1 + num2;
	}
	public long getSum()
	{	return sum;
	}
	public int compare(HugeInt compareTo)
	{
		long num1 = Integer.parseInt(this.inp);
		long num2 = Integer.parseInt(compareTo.inp);
		if(num1<num2)
			return -1;
		else if(num1>num2)
			return 1;
		else return 0;
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
