import java.io.*;
import java.util.Vector;
class ListOfNumbers
{
	private Vector<Integer> victor;
	private static final int SIZE = 20;
	public ListOfNumbers()
	{
		victor = new Vector<Integer>();
		readList("infile.txt");
		writeList();
	}
	public void readList(String filename)
	{
		String line = null;
		try
		{
			RandomAccessFile raf = new RandomAccessFile(filename,"r");
			while((line=raf.readLine()) != null)
			{
				Integer i = new Integer(Integer.parseInt(line));
				System.out.println(i);
				victor.addElement(i);
			}
		} 
		catch(FileNotFoundException fnf)
		{	
			System.err.println("file : " +filename+"not found");
		} 
		catch (IOException io)
		{	
			System.err.println(io.toString());
		}
	}
	public void writeList()	
	{
		PrintWriter out = null;
		try
		{
			out = new PrintWriter(new FileWriter("outputfile.txt"));
			for(int j =0; j<victor.size(); j++)
				out.println("value at " + j+ " = "+victor.elementAt(j));
		} 
		catch(ArrayIndexOutOfBoundsException e)
		{	
			System.err.println(e.getMessage());
		}
		catch(IOException e)
		{
			System.err.println(e.getMessage());
		}
		finally
		{
			if(out!=null)
				out.close();
			else
				System.out.println("PrintWriter not open");
		}
	}
}
class ListOfNumbersTester
{
	public static void main(String[] args)
	{
		new ListOfNumbers();
	}
}