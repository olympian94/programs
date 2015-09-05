enum Day
{	
	MONDAY, TUESDAY, WEDNESSDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
	public void message()
	{
		switch(this)		//ONLY AN ENUM CAN BE SWITCHED!
		{
			case MONDAY : 	System.out.println("Full of Energy");
					break;
			case WEDNESSDAY:System.out.println("Half Battle done with!!");
					break;
			case FRIDAY : 	System.out.println("Time to party");
					break;
			default :		System.out.println("Work: day in, day out");
		}
	}
}
class enumDayTester
{
	public static void main(String[] args)
	{
		Day newobj = Day.TUESDAY;	
		newobj.message();
		Day.MONDAY.message();
	}
}