import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;
/**
* An Agency object defines the required fields of namem, address, phone, TIN and PAN
* @version 1.1
* @author AbhishekTiwari
* @since 1.0
*/
public class Agency
{
	protected String AgencyName;
	protected String AgencyAddr;
	protected String phonenumber;
	protected String tinnumber;
	protected String pannumber;
	public Agency()
	{
	}
	/** 
	*	Constructor with (String,String) form
		@param anm	Agency name
		@param aaddr	Agency address
		
	*/
	public Agency(String anm, String aaddr)
	{	AgencyName = anm;
		AgencyAddr = aaddr;
		phonenumber = "+91000000000000";
		tinnumber = "aa 0000000";
		pannumber = "aaaa55555aa";
	}
	public Agency(String anm,String aaddr, String pnum, String tn, String pn)
	{
		AgencyName = anm;
		AgencyAddr = aaddr;
		setphonenumber(pnum);
		settinnumber(tn);
		setpannumber(pn);
	}
	/**
	*	Performs pattern matching for phone number
	*	Eg: +91 STD Code: 4 Digits Phone Number: 8 digits
	*/
	public void setphonenumber(String pnum)
	{
		Pattern pat = Pattern.compile("^[+]91([0-9]){12}$");
		Matcher match = pat.matcher(pnum);
		if(match.matches())
		{	
			phonenumber = pnum;
			System.out.println("PhoneNumber assigned");
		}
		else
		{	phonenumber = null;
			System.out.println("Wrong phone number supplied for : "+AgencyName);
		}
	}
	/**
	*	Performs pattern matching for TIN number
	*	Format of TIN number is: <2 letters a-z A-Z><space><7 digits>
	*/

	public void settinnumber(String tinnum)
	{
		Pattern pat = Pattern.compile("^([a-zA-Z]){2}\\s([0-9]){7}$");
		Matcher match = pat.matcher(tinnum);
		if(match.matches())
		{	
			tinnumber = tinnum;
			System.out.println("TIN assigned");
		}
		else
		{	
			tinnumber = null;
			System.out.println("Wrong TIN number supplied for : "+AgencyName);
		}	
	}
	/**
	*	Performs pattern matching for PAN number
	*	<4 letters a-z A-Z><5 digits><2 letters a-z A-Z>
	*/

	public void setpannumber(String pannum)
	{
		Pattern pat = Pattern.compile("^([a-zA-Z]){4}([0-9]){5}([a-zA-z]){2}$");
		Matcher match = pat.matcher(pannum);
		if(match.matches())
		{	
			pannumber = pannum;
			System.out.println("PAN assigned");
		}
		else
		{	
			tinnumber = null;
			System.out.println("Wrong PAN number supplied for : "+AgencyName);
		}	
	}

	public void checkPAN(String five_dig_num)
	{
		Pattern pat = Pattern.compile("([0-9]){5}");
		Matcher match = pat.matcher(pannumber);
		match.find();
		System.out.println(five_dig_num + " matches the PAN of invoking object : ");
		System.out.println(five_dig_num.matches(match.group(0)));
	}
	public Agency checkAgency(String name, String addr)
	{
		Agency temp = new Agency();
		if(name.matches(AgencyName)&&name.matches(AgencyAddr))
			System.out.println("true! Agency match found");
		else
		{
			System.out.println("New Agency : "+name+ " created.");
			temp = new Agency(name,addr);
		}
		return temp;
	}
}

public class AgencyTester
{
	public static void main (String[] args)
	{
		Agency obj = new Agency("Java_Core","CC");
		obj.setphonenumber("+9144497145101");
		obj.settinnumber("at 123456047");
		obj.setpannumber("abcd12345xy");
		obj.checkPAN("11111");
		obj.checkAgency("Programming","CC");
	}
}
