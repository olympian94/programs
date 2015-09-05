
public class RichTwoStatesTest{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RichTwoStates twostates = new RichTwoStates(RichStates.S1);
		twostates.event2(1);

		twostates.event2(1);
	
		//		System.out.println(twostates.status);
		twostates.event1();
//		System.out.println(twostates.status);
	}

}
