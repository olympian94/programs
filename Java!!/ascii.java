class ascii
{
	public static void main(String[] args)
	{
		//System.out.println("Hello "+String);
		for(int j=1; j<256; j++)
		{
			if(j%8==0)
				System.out.println("\n");
			else
				System.out.print((char)j+" ");
		}
		/* THIS IS A TEST BLOCK
		int x=5;
		while(x)
		{
			System.out.println("WTF");
			x--;
		} */		
	}
}