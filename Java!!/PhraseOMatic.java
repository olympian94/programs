class PhraseOMatic
{
	public static void main(String[] args)
	{
		String[] wordListOne={"amazing","new","24/7","delivering","discreet","amazing","startling","tremendous","game-changing"};
		String[] wordListTwo={"solution","program","plan","company","office","room","place","car","phone"};
		int len1 = wordListOne.length;
		int len2 = wordListTwo.length;
		int rand1 = (int)(Math.random()*len1);
		int rand2 = (int)(Math.random()*len2);
		String phrase = wordListOne[rand1] + " " + wordListTwo[rand2];
		System.out.println("What is comming is a " +phrase);
		
	}
}