import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class RegEx
{
	public static void main(String[] args)
	{
		Scanner inp = new Scanner(System.in);
		String str;
		str = inp.nextLine();
		System.out.println("str.replaceFirst(\"[a-z]\",\"0\")  : "+ str.replaceFirst("[a-z]","0"));
		System.out.println("str.replaceAll(\"[A-Z]\",\"-\")  :\t"+ str.replaceAll("[A-Z]","-"));

		String regex = "([0-9]){,3}";
		String seq = "Your salary is 999.";
		Pattern pat = Pattern.compile(regex);
		Matcher matcher = pat.matcher(seq);
		boolean found = matcher.find();
}
