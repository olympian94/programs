class threadM extends Thread{
	public void run(){
		try{
			for(int i=0; i<10; i++){
				Thread.sleep(1000);
				System.out.println("Thread M");
			}
		}
		catch(InterruptedException ex){
			ex.printStackTrace();
		}
	}
}

class threadN extends Thread{
	public void run(){
		try{
			for(int i=0; i<20; i++){
				Thread.sleep(2000);
				System.out.println("Thread N");
			}
		}
		catch(InterruptedException ex){
			ex.printStackTrace();
		}
	}
}

public class threadDemo2{
	public static void main(String[] args) {
		threadM tm = new threadM();
		
		threadN tn = new threadN();
		
		try
		{
			tm.start();
			tn.start();
			tm.join();
			tn.join();
			System.out.println("Both threads have finished.");
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}
}