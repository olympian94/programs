class Greeter
{
	private String name;
	public Greeter(String nm)
	{
		name=nm;
	}
	public void sayhello()
	{
		System.out.println("Hello " +name+" !");
	}
}
class GreeterTester
{
	public static void main(String[] args)
	{
		Greeter obj = new Greeter("Abhishek");
		obj.sayhello();
	}
}