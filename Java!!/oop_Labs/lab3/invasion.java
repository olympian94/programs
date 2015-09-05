import java.io.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class Password
{
	public void readFile(String fileName)
	{
		try
		{
			RandomAccessFile raf = new RandomAccessFile(fileName,"r");
			String line = null;
			while((line=raf.readLine()) != null)
				checkPassword(line);
		}
		catch(FileNotFoundException fnf)
		{	System.out.println(fnf.getMessage());
		}
		catch(IOException io)
		{	System.out.println(io.getMessage());
		}
	}
	public int checkPassword(String pwd)	//return val = 0 if true, else error code
	{
		if(pwd.length() < 20 )
			return 1;		
		else
		{
			Pattern pat = Pattern.compile("^[^$\\d]*\\D\\d(.)*(\\d{2}/\\d{2}/\\d{4}\\s\\d\\d:\\d\\d)$");
			Matcher match = pat.matcher(pwd);
			if(match.find())
				System.out.println(pwd);
		}
		return 0;
	}
}
class PwdTester
{
	public static void main(String[] args)
	{
		Password obj = new Password();
		obj.readFile("passwords.txt");
	}
}