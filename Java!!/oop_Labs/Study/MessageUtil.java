public class MessageUtil
{
	private String message;
	public MessageUtil(String mssg)
	{
		message=mssg;
	}
	public String printMessage()
	{
		System.out.println("Message received...\n"+message);
		return message;
	}	
}
