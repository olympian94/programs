import java.util.Arrays;
/**
 *@author Abhishek Tiwari
 */
enum Suit
{	/**card types*/
	SPADES, CLUBS, DIAMONDS, HEARTS;
}
enum Value
{	/**Values a card of any type can take*/
	two(1), three(2), four(3), five(4), six(5), seven(6), eight(7), nine(8), ten(9), ACE(10), JACK(11), KING(12), QUEEN(13);
	/**card position*/
	private int pos;
	/**constructor to initialize card position */
	Value(int p)
	{	pos = p;
	}
	/**@return card position*/
	public int getpos()
	{	return pos;
	}
}
class Card
{
	protected Suit cardType;
	protected Value cardValue;
	public static final int SIZE =52;
	public void setSuit(Suit s)
	{	cardType = s;
	}
	public void setValue(Value v)
	{	cardValue = v;
	}
	public Suit getSuit()
	{	return cardType;
	}
	public Value getValue()
	{	return cardValue;
	}
	@Override
	public String toString()
	{	
		String s =cardType+"\t"+cardValue;
		return s;
	}
	public static void main(String[] args)
	{
		Card[] deck1 = new Card[SIZE];
		int j = 0;
		for( Suit s : Suit.values())
		{
			for(Value v : Value.values())
			{
				deck1[j] = new Card();
				deck1[j].setSuit(s);
				deck1[j].setValue(v);
				j++;
			}				
		}
		for(j=0; j<SIZE; j++)
			System.out.println(deck1[j].toString());
		System.out.println("After Shuffle");
		CardShuffler.shuffleDeck(deck1);	

		for(j=0; j<SIZE; j++)
			System.out.println(deck1[j].toString());
	}
}
class CardShuffler
{
	public static final int TIMES = 500;
	public static void shuffleDeck(Card[] deck)
	{
		Card temp = new Card();
		for(int j=0; j<TIMES; j++)
		{
			int rand1 = (int)(Math.random()*52);	
			int rand2 = (int)(Math.random()*52);	
			temp.setSuit(deck[rand1].getSuit());
			temp.setValue(deck[rand1].getValue());

			deck[rand1].setSuit(deck[rand2].getSuit());
			deck[rand1].setValue(deck[rand2].getValue());

			deck[rand2].setSuit(temp.getSuit());
			deck[rand2].setValue(temp.getValue());
		}
	}
}