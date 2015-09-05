import java.util.regex.Pattern;
import java.util.regex.Matcher;
class StringMatcher
{
	public static void main(String[] args)
	{
		String regex = "\\b[Ss]mall[tT]alk\\b";
		String[] sentences = {"Hi its smalltalk bro!","Hi its SmallTalk bro!","Hi its Smalltalk bro!","Hi its smallTalk bro!"};
		Pattern pat = Pattern.compile(regex);
		for(int j=0; j<sentences.length; j++)
		{	
			Matcher mat = pat.matcher(sentences[j]);
			if(mat.find())
				System.out.println(mat.group(0));
		}
	}
}