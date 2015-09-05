import java.io.*;
import java.util.Vector;

class ListOfNames
{
	private Vector<String> vector;
	public ListOfNames()
	{
		vector = new Vector<String>();
	}
	public ListOfNames(int size)
	{	vector = new Vector<String>(size);
	}
	public void readList(String filename)
	{
		String line = null;
		try
		{
			RandomAccessFile raf = new RandomAccessFile(filename,"r");
			while((line=raf.readLine()) != null )
			{
				vector.addElement(line);
			}
		}
		catch(FileNotFoundException fnf)
		{
			System.out.println(filename+"\tNOT FOUND");
		}
		catch(IOException io)
		{
			System.out.println(io.getMessage()+"\tIO exception!");
		}
	}

	public void writeList()
	{
		writeList("output.txt");
	}

	public void writeList(String outputFile)
	{
		PrintWriter out = null;
		try
		{
			FileWriter fob = new FileWriter(outputFile);
			out = new PrintWriter(fob);
			for(int j=0; j<vector.size(); j++)
				out.println("Value at "+ j + vector.elementAt(j));
		}
		catch(IOException io)
		{
			System.out.println(io.getMessage()+"\tIO exception!");
		}
		finally
		{	
			if(out != null)
				out.close();
		}
	}
	public void addName(String nm)
	{	vector.addElement(nm);
	}
}
class ListOfNamesTester
{
	public static void main(String[] args)
	{
		ListOfNames obj = new ListOfNames();
		obj.addName("Abhishek");
		obj.readList("names.txt");
		obj.writeList("Name_op.txt");
	}
}