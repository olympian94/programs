interface quickaction{
	public String quickwork();
}
class Actions{
	public void print1(quickaction obj){
		System.out.println(obj.quickwork());
	}
}
class Anonytester{
	public static void main(String[] args){
		//give annonymous class obj to act1
		Actions act1 = new Actions();
		act1.print1(new	quickaction()
				{
					public String quickwork(){
						return "JustDoIt";
					}
				});
	}
}
