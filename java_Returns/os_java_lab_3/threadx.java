class threadDemo extends Thread{
	public void run(){
		try{
			while(true){
				Thread.sleep(2000);
				System.out.println("Sup");
			}
		}
		catch(InterruptedException ex){
			ex.printStackTrace();
		}
	}
}

public class threadx{
	public static void main(String[] args) {
		threadDemo td = new threadDemo();
		td.start();
	}
}