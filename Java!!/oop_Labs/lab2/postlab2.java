abstract class OutDoorGames
{
	protected String sportName;
	protected String playerName;
	abstract void game();	//no access modifier?	implmntn to be given by subclasses correct?
	protected int minutesOfPlay;
	public void set(String snm, String pnm, int mop)
	{
		sportName=snm;
		playerName=pnm;
		minutesOfPlay=mop;
	}
	public String getsportName()
	{	return sportName;
	}
	public String getplayerName()
	{	return playerName;
	}
	public getmop()
	{	return minutesOfPlay;
	}
}
class OutDoorGamesTest extends OutDoorGames
{
	public static void main(String[] args)
	{
		OutDoorGamesTest obj1, obj2, obj3;
		obj1.set("Football","Abhishek",90);
		obj2.set("Cricket","Vijay",240);
		obj3.set("Boxing","Abhishek",15);
	}
}
