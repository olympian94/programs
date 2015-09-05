import java.util.regex.Pattern;
import java.util.regex.Matcher;

class StartEndMethods
{
	public static void main(String[] args)
	{
		String regex = "\\bname\\b";
		String seq = "The name name is name.";
		Pattern pat = Pattern.compile(regex);
		Matcher match = pat.matcher(seq);
		while(match.find())
		{
			System.out.println("Start : "+match.start() + "\t End : "+match.end());
		}
	}
}