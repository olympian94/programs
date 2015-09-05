enum Suit
{
	CLUBS ("BLACK"),
	DIAMONDS("BLACK"),
	SPADES("RED"),
	HEARTS("RED");
	String color;
	Suit(String nm)	//NOTE : CANT BE ACCESSED AND HENCE HAS NO ACCESS MODIFIER
	{	color = nm; }
	public String getColor()
	{	return color; }
}
class enumSuitTester
{
	public static void main(String[] args)
	{
		for(Suit obj : Suit.values())
		{
			System.out.println(obj+" Color : "+obj.getColor());
		}
	}
}
