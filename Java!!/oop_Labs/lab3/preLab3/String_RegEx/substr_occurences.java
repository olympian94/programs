import java.util.Scanner;
class Substr
{
	static int noOfSubstr(String str, String substr)
	{
		if(str.contains(substr)==false)
			return 0;
		int counter=0;
		int lenstr = str.length();
		int lensubstr=substr.length();
		for(int j=0; j < lenstr; j++)
		{
			if(str.charAt(j)==substr.charAt(0))
			{
				int k = j, l =0, count=0;
				while(str.charAt(k)==substr.charAt(l))
				{
					count++;
					k++; l++;
					if(l>lensubstr-1)
						break;
				}
				if(count==lensubstr)
				{
					j+=substr.length();
					counter++;
				}
			}
		}	
		return counter;
	}
	public static void main(String[] args)
	{
		Scanner obj = new Scanner(System.in);
		String str, substr;
		System.out.println("Enter String>");
		str = obj.nextLine();
		System.out.println("Enter Sub String>");
		substr = obj.nextLine();
		System.out.println("Number of occurences of Substr in Str is : "+ noOfSubstr(str,substr));
	}
}