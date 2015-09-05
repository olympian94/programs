class Account{
	private int balance;
	synchronized public void deposit(int amount)
	{
		balance += amount;
	}
	int getBalance(){
		return balance;
	}
}

class Customer extends Thread{
	Account account;
	//variable for showing the thread which is running this objects methods
	int threadNumber;
	Customer(Account account, int threadNumber){
		this.account=account;
		this.threadNumber = threadNumber;
	}

	public void run(){
		try{
			for(int i=0; i<1000; i++)
			{
				System.out.println("In thread number " + Integer.toString(threadNumber));
				account.deposit(10);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}

class synchDemo{
	private final static int NUMCUSTOMERS = 10;
	public static void main(String[] args) {
		Account account = new Account();

		//each customer object will run in a separate thread
		//each will try to modify the variable 'balance' of the 
		//same object 'account'. The synchronized setter method
		//will ensure that all the threads will modify it 
		//sequentially.
		Customer customers[] = new Customer[NUMCUSTOMERS];
		for(int i=0; i<NUMCUSTOMERS; i++)
		{
			customers[i]=new Customer(account,i);
			customers[i].start();
		}

		//wait for each customers thread to terminate
		for(int i=0; i<NUMCUSTOMERS; i++)
		{
			try{
				customers[i].join();
			}
			catch(InterruptedException e)
			{	e.printStackTrace(); }
		}

		//display the variable : balance
		System.out.println(account.getBalance());
	}
}