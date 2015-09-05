import java.util.regex.*;

class NumFromAlphaNum
{
	public static void main(String[] args)
	{
		String regex = "\\b\\d+\\b";
		String seq = "Hey, the contact is 9817240612 (Contact1) and (Contact2) 6555433889 Good Luck!";
		Pattern pat = Pattern.compile(regex);
		Matcher matcher = pat.matcher(seq);
		while(matcher.find())
		{
			System.out.println(matcher.group(0));
		}
	}
}