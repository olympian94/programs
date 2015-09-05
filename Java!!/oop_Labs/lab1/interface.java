interface Lookup
{
	/* return 1 if present else 0*/
	int find(String nm);
}
class stringOps implements Lookup
{
	private String[] names;
	public stringOps(String[] nms)
	{
		names = nms;
	}
	public int find (String name)
	{
		for(int j=0; j<names.length; j++)
		{
			if(names[j].equals(name))
				return 1;
		}
		return 0;
	}
}
class interfaceTester
{
	public static void main(String[] args)
	{
		String[] nms = {"Lazar_Angelov","Mark_Wahlberg","Colin_Ferrel","Hritik","Tiger_Shroff"};
		stringOps strobj = new stringOps(nms);
		String find1 = "Hritik";
		String find2 = "Abhishek";
		System.out.println("\nHritik : " + strobj.find(find1) + "\nAbhishek : " + strobj.find(find2) );
	}
}
