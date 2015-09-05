class enumeration{

	enum Currency{
		//internally calls constructors
		TEN(10), TWENTY(20), FIFTY(50);
		private int val;
		private Currency(int v){
			val=v;
		}
		public int value(){
			return val;
		}
		public void setValue(int valnew){
			val = valnew;
		}
	}
	public static void main(String[] args){
		Currency c1 = Currency.TEN;
		Currency c2 = Currency.TWENTY;
		Currency c3 = Currency.FIFTY;
		Currency.FIFTY.setValue(100);
		System.out.println(Currency.FIFTY.value());

	}

}