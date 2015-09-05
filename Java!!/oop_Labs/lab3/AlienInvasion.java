import java.io.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.MessageDigest;
import java.util.zip.InflaterInputStream;


public class AlienInvasion {
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
			{
				System.out.println(pwd);
				defuse(pwd);
			}
		}
		return 0;
	}

	

	public static void main(String args[])
	{
		Password obj = new Password();
		obj.readFile("passwords.txt");
	}


	
	public void defuse(String password)
	{
		try {
			MessageDigest md5 = MessageDigest.getInstance("MD5");
			byte[] passwordDigest = md5.digest(password.getBytes("UTF-8"));
			byte[] correctPassword = {25,30,-91,-102,38,120,86,-99,13,19,-72,-48,-47,-9,111,98};
			byte[] text1={120, -100, -115, -110, 79, 75, -60, 48, 16, -59, -17, -5, 41, -122, -84, 116, 32, 52, 115, 20, 12, 66, -23, 97, 117, -60, -99, 110, 89, 87, 65, -40, 67, 9, -67, -25, -5, -33, 76, -45, 102, 91, 21, 19, 7, 10, -99, -57, -5, -27, 77, -2, 0, -4, -93, -22, 88, -69, -94, -49, -17, -15, 65, -124, 29, 90, 52, -75, 47, 1, -28, 89, 89, -26, 59, 4, -123, -128, 96, -12, -71, 42, 49, -93, -120, 104, -91, 112, -64, -76, -124, 40, -106, -122, 34, 117, -31, -74, 123, -123, -49, -45, -5, -113, -31, 3, -125, 107, -85, -8, -24, -58, 71, 104, 42, -66, 102, -78, -56, 10, 3, -87, -21, -86, 12, 32, 2, -31, -85, 92, -64, -98, 78, 103, 120, 107, 63, 94, -70, -25, -112, 122, 88, 41, 80, -102, -89, 31, -109, -108, 74, 82, -79, -3, 59, -114, -30, -34, -100, -9, 73, -112, 77, -47, -62, -11, -57, -74, 59, 92, 126, 113, -29, -20, 114, -77, -94, 111, 88, 79, -123, -68, -28, 75, -94, 94, -38, 12, 55, 31, -60, 62, 26, 55, -118, -56, 125, 15, -71, -101, -117, -57, 63, 76, -85, -85, -115, -54, -94, -121, -20, 125, 71, -52, 126, -117, 10, -77, -101, 108, 84, -96, 40, 14, -39, 16, 45, 27, -99, 32, -62, -46, -21, 53, -109, -105, 110, 45, -103, -14, 115, 71, 52, -28, 125, -19, 61, 25, -60, -35, 23, 59, 42, -120, -11};
			byte[] text2={120, -100, 125, 79, -69, 14, -62, 48, 12, -36, -13, 21, -89, 44, 109, -122, -38, 123, -104, -112, 96, 64, 13, -22, 0, 29, 16, 38, -4, 72, -108, 111, -57, 9, 15, 9, -108, 112, -78, -30, 115, 116, -10, -39, -64, 23, 76, -109, 54, 32, 31, 70, 26, -84, -30, -53, -78, 98, 62, -124, -80, -33, 97, 61, 97, 27, -62, -113, -108, -68, -35, 12, -28, -119, -84, 22, -4, 127, 58, 48, 30, 99, -92, -104, -77, -89, -63, 58, -22, -85, -89, -94, -27, -70, 69, 121, 72, -35, -60, -23, -73, 118, 44, -3, -31, 99, -126, 39, 100, 68, -108, 76, -55, 57, -125, 36, -46, 20, 87, 7, -103, -112, -54, 37, -22, -92, -103, -97, 14, -54, -50, -3, -59, -28, 125, -71, -10, -16, 100, 24, 114, -67, -33, -88, -117, -105, -100, 107, 40, -52, 3, -20, -97, 65, -102};
			
			InputStream in;
			
			if(MessageDigest.isEqual(passwordDigest, correctPassword))
				in = new InflaterInputStream(new ByteArrayInputStream(text1));
			else
				in = new InflaterInputStream(new ByteArrayInputStream(text2));
			
	        ByteArrayOutputStream baos = new ByteArrayOutputStream();
	        try {
	            byte[] buffer = new byte[8192];
	            int len;
	            while((len = in.read(buffer))>0)
	                baos.write(buffer, 0, len);
	            System.out.println(new String(baos.toByteArray(), "UTF-8") );
	        } catch (IOException e) {
	            throw new AssertionError(e);
	        }
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

