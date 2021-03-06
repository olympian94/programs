enum States
{
	APPROVED, PENDING, FINALIZING, REJECTED, FINAL
}
enum Phases
{
	ENTRY, ACTIVE, EXIT
}
class AccountApproval
{
	boolean sendLetter;
	boolean letterSent;
	protected States state;
	protected Phases phase;
	public AccountApproval()
	{
		sendLetter=false;
		letterSent=false;
		state=States.PENDING;
		phase=Phases.ENTRY;
	}/*
	public AccountApproval(States st)
	{	
		AccountApproval();
		state=st;
	}
	public AccountApproval(States st,Phases ph)
	{	
		AccountApproval();
		state=st;
		phase=ph;
	}*/
	public void approve()
	{
		switch(state)//state wise response; also note no outputs assc. with this event
		{
			case PENDING:
				phase=Phases.EXIT;	//exit w/o guard conditions
				stateMachine();
				phase=Phases.ENTRY;
				state=States.APPROVED;
				stateMachine();
				break;
			case FINAL:
				System.out.println("Already in Final");
				break;
			default: break;
		}
	}
	public void reject()
	{
		switch(state)//state wise response; also note no outputs assc. with this event
		{
			case PENDING:
				phase=Phases.EXIT;
				stateMachine();
				phase=Phases.ENTRY;
				state=States.REJECTED;
				stateMachine();
				break;
			case FINAL:
				System.out.println("Already in Final");
				break;
			default: break;
		}
	}
	public void complete()
	{
		switch(state)//state wise response; 
		{
			case REJECTED:
			case APPROVED:
				sendLetter=true;	//output of event
				phase=Phases.EXIT;	//exit w/o guards
				stateMachine();
				phase=Phases.ENTRY;
				state=States.FINALIZING;
				stateMachine();
				break;
			case FINAL:
				System.out.println("Already in Final");
				break;
			default: break;
		}
	}
	public void check()
	{
		switch(state)//state wise response
		{
			case FINALIZING:
				if(letterSent)
				{
					phase=Phases.EXIT;
					stateMachine();
					phase=Phases.ENTRY;
					state=States.FINAL;
					stateMachine();
				}
				else
					System.out.println("Letter not sent by User, Cannot Finalize.");
				break;
			case FINAL:
				System.out.println("Already in Final");
				break;
			default: break;
		}
	}
	public void doapproved()
	{
		switch(phase)
		{
			case ENTRY:
				System.out.println("approvalQueue()");
				phase=Phases.ACTIVE;	//allow fall through to active
			case ACTIVE:
				System.out.println("enterDetails()");
				break;
			case EXIT:
				System.out.println("composeApprovalLetter()");
				break;
			default:
				System.out.println("INCORRECT PHASE");
		}
	}
	public void stateMachine()
	{
		switch(state)
		{
			case PENDING:
				System.out.println("state: " + state.toString() + "; phase: " + phase.toString());
				break;
			case APPROVED:
				doapproved();
				break;
			case REJECTED:
				System.out.println("state: " + state.toString() + "; phase: " + phase.toString());
				break;
			case FINALIZING:
				System.out.println("state: " + state.toString() + "; phase: " + phase.toString());
				break;
			case FINAL:
				System.out.println("In final");
				//in final reset fields
				sendLetter=false;
				letterSent=false;
				break;
			default:
				System.out.println("INCORRECT STATE");
				
		}
	}
}

class AccountApprovalTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AccountApproval acApproval;

		System.out.println("\nFirst test case");
		System.out.println("----------------");
		acApproval = new AccountApproval();
		acApproval.complete();
		acApproval.approve();
		acApproval.reject();
		acApproval.complete();
		acApproval.check();
		acApproval.letterSent = true;
		acApproval.check();
		
		System.out.println("\nSecond test case");
		System.out.println("----------------");
		acApproval = new AccountApproval();
		acApproval.complete();
		acApproval.reject();
		acApproval.approve();
		acApproval.complete();
		acApproval.check();
		acApproval.letterSent = true;
		acApproval.check();
	}

}
