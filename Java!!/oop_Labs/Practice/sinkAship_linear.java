import java.util.ArrayList;
import java.util.Scanner;
class Grid
{
	private int pos;
	private ArrayList<Integer> loc;
	public Grid()
	{	genpos();
	}
	private void genpos()
	{
		pos=(int)(Math.random()*5);
		loc = new ArrayList<Integer>(3);
		loc.add(pos);
		loc.add(pos+1);
		loc.add(pos+2);
	}
	public String fire(int num)
	{
		String result = "miss";
		if(loc.contains((Integer)num))
		{
			loc.remove((Integer)num);
			if(loc.isEmpty())
				result = "kill";
			else
				result = "hit";	
		}
		return result;
	}
	public boolean gameover()	
	{
		if(loc.isEmpty())
			return true;
		else
			return false;
	}
}
class SinkAShipGame
{
	public static void main(String[] args)
	{
		Grid game1 = new Grid();
		int guess;
		Scanner obj = new Scanner(System.in);
		while(!game1.gameover())
		{
			System.out.println("Take a guess..");
			guess= obj.nextInt();	
			System.out.println(game1.fire(guess));
		}
	}
}