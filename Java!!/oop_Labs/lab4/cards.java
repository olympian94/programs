import java.util.Arrays;

enum Suit
{
	SPADES, HEARTS, CLUBS, DIAMONDS;
}
enum Value
{
	two (1), three (2), four (3), five (4), six (5), seven (6), eight (7), nine (8), ten (9), ACE (10), JACK (11), KING(12), QUEEN(13);
	private int pos;
	Value(int val_inp)
	{	pos = val_inp;
	}
	public int getPos()
	{	return pos;
	}
}
class Card 
{
	protected Suit cardType;
	protected Value val;
	/**
	* deck size is declared constant at 52
	*/
	public static final int SIZE = 52;
	public void setSuit(Suit inp)
	{
		cardType = inp;
	}
	public void setVal(Value valinp)
	{
		val = valinp;
	}
	public Suit getSuit()
	{	return cardType;
	}
	public Value getVal()
	{	return val;
	}
	public void printCard()
	{
		System.out.println("Card Suit :\t"+cardType+"\tValue :\t"+val);
	}
	public static void main(String args[])
	{
		Card[] deck1 = new Card[SIZE];
		int pos=0;
		for(Suit var1 : Suit.values())
		{
			for(Value var2 : Value.values())
			{
				deck1[pos] = new Card();
				deck1[pos].setVal(var2);
				deck1[pos].setSuit(var1);
				pos++;
			}
		}
		for(int j=0 ; j< SIZE; j++)
			deck1[j].printCard();	
		CardShuffler.shuffleDeck(deck1);
		System.out.println("\n\n\nSHUFFLED!!!\n\n");
		for(int j=0 ; j< SIZE; j++)
			deck1[j].printCard();	
	
	}
}
class CardShuffler
{
	public static final int NUMTIMES = 100;
	/**
	 * Choose a number b/w 0-51 (both inclusive), swap attributes for the cards at those indices
	 * @param deck Input card deck
	 */
	public static void shuffleDeck(Card[] deck)
	{
		Card temp = new Card();
		for(int j = 0; j<NUMTIMES; j++)
		{
			int rand1 = (int)(Math.random()*52);	
			int rand2 = (int)(Math.random()*52);
		
			temp.setSuit(deck[rand1].getSuit());
			temp.setVal(deck[rand1].getVal());
		
			deck[rand1].setSuit(deck[rand2].getSuit());
			deck[rand1].setVal(deck[rand2].getVal());
				
			deck[rand2].setSuit(temp.getSuit());
			deck[rand2].setVal(temp.getVal());
		}
	}
}