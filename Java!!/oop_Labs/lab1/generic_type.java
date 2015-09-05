interface isPresent <Type>
{
	int find(Type ele);
}
class arrOps implements isPresent<Integer>
{
	private int[] arr;
	public arrOps(int[] arr_inp)
	{
		arr= arr_inp;
	}
	public int find(Integer val)
	{
		for(int j=0; j<arr.length; j++)
		{
			if(arr[j]==val)
				return 1;
		}
		return 0;
	}
}
class stringOps implements isPresent<String>
{
	private String[] names;
	public stringOps(String[] nms)
	{
		names=nms;
	}
	public int find(String name)
	{
		for(int j=0; j<names.length; j++)
		{
			if(names[j].equals(name))
				return 1;
		}
		return 0;
	}
}
class genericTypeTester
{
	public static void main(String[] args)
	{
		int[] arr_inp = {5,6,4,2,8,9};
		String[] str_inp = {"Hritik_Roshan","Tiger_Shroff","Abhishek","Ranveer","Ryan_Reynolds","Chris_Hemsworth","Chris_Evans","Matt_Damon"};

		arrOps arr_obj = new arrOps(arr_inp);
		stringOps str_obj = new stringOps(str_inp);
		
		System.out.println("1 in arr : " + arr_obj.find(1) + "\nAbhishek in Str : " +str_obj.find("Abhishek"));
	}
}