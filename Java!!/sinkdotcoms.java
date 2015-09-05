// Sink-A-DotCom Game
import java.util.Scanner;

class SimpleDotCom
{
	private static final int SIZE = 3;	//DotCom size
	private static final int GSIZE = 10;	//1D grid size
	private int[] locationCells;
	private int noOfHits;
	private static int noOfGuesses;
	public boolean isSunk;

	public int[] set()
	{	
		int start;
		start=(int)(Math.random()*GSIZE);	//size of 1D grid is 5-1 + SIZE
		locationCells = new int[SIZE];
		for(int j=0; j<SIZE; j++)
		{
			locationCells[j]=start+j;
		}
		System.out.println("\n\nMy ship occupies 3 consecutive cells. \nThere are "+ GSIZE +" Cells.\n Take your Best Shot!");
		noOfHits=0;
		isSunk=false;
		noOfGuesses=0;
		return locationCells;
	}
	public String checkGuess(int guess)
	{
		if(guess < 0 || guess >= GSIZE)
			return "Invalid Cell Position. You wasted your missile :D";
		noOfGuesses++;			
		for(int j=0; j<SIZE; j++)
		{
			if(locationCells[j]==guess)
			{	
				noOfHits+=1;
				locationCells[j]=-1;		//so that it cant be hit again!
				if(noOfHits==SIZE)
				{	
					isSunk=true;
					return "KILL!! \t :'( ";
				}
				else
					return "HIT! \t :( ";
			}
			
		}	
		return "MISS \t >;) :V ";	
	}
	public void GameOver()
	{
		if(noOfGuesses==SIZE)
			System.out.println("\n\nCONGRATULATIONS!! 3 Hits in 3 Guesses!");
		else 
			System.out.println("\nYour score: "+noOfHits+" / "+noOfGuesses+" !! ");
	}
}


class SimpleDotComGame
{
	public static void main(String[] args)
	{
		SimpleDotCom game = new SimpleDotCom();
		Scanner inp_obj = new Scanner(System.in);
		int guess;
		int[] cells = new int[3];
		cells = game.set();

		System.out.println("\nWelcome to SinkADotCom...");
		while(game.isSunk==false)
		{
			System.out.println("\nTake a Guess...");
			guess=inp_obj.nextInt();
			System.out.println(game.checkGuess(guess));
		}
		game.GameOver();

	}
}