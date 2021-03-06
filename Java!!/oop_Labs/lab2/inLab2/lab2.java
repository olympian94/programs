class Vehicle implements Cloneable
{
	private int VehicleID;
	private static int nextVehicleID = 0;
	private float currentSpeed;
	private float currentDir;	//in degrees
	private String owner;
	public Vehicle()
	{
		VehicleID=nextVehicleID;
		nextVehicleID++;
		currentSpeed=0;
		currentDir=0;
		owner=null;
	}
	public Vehicle(String owner_inp)
	{
		VehicleID=nextVehicleID;
		nextVehicleID++;
		currentSpeed=0;
		currentDir=0;
		owner=owner_inp;
	}
	public void setVehicleID(int ID)
	{	VehicleID=ID;
	}
	public void setcurrentSpeed(float speed)
	{	currentSpeed=speed;
	}
	public void setcurrentDir(float degrees)
	{	currentDir=degrees;
	}
	public void setowner(String owner_inp)
	{	owner=owner_inp;
	}
	public int getVehicleID()
	{	return VehicleID;
	}
	public float getcurrentSpeed()
	{	return currentSpeed;
	}
	public float getcurrentDir()
	{	return currentDir;
	}
	public String getowner()
	{	return owner;
	}
	public static int highestID()
	{	return (nextVehicleID-1);
	}
	public void changeSpeed(float newSpeed)
	{	currentSpeed=newSpeed;
	}
	public void stop()
	{	currentSpeed=0;
	}
	public void copyVehicle(Vehicle obj)
	{
		VehicleID=obj.VehicleID;
		currentSpeed=obj.currentSpeed;
		currentDir=obj.currentDir;
		owner=obj.owner;
	}
	public Vehicle HighestSpeed(Vehicle[] obj_arr)
	{
		Vehicle temp =new Vehicle();
		int max_index = 0;
		for(int j=1; j<obj_arr.length; j++)
		{
			if(obj_arr[j].currentSpeed>obj_arr[max_index].currentSpeed)
				max_index=j;
		}
		temp.copyVehicle(obj_arr[max_index]);
		return temp;
	}
	public void print()
	{
		System.out.println("Owner "+owner);
		System.out.println("VID :"+VehicleID);
		System.out.println("Current speed: "+currentSpeed);
		System.out.println("Current Direction"+currentDir);
		System.out.println("\n");
	}
	public Object clone() throws CloneNotSupportedException
	{
		return super.clone();
	}
}
class VehicleApp
{
	public static void main(String[] args) 
	{
		Vehicle[] cars = new Vehicle[5];
		cars[0]= new Vehicle();
		cars[0].setcurrentSpeed(123.5f);
		cars[0].setcurrentDir(45f);
		cars[0].setowner("Toyota");

		cars[1]= new Vehicle();
		cars[1].setcurrentSpeed(183.5f);
		cars[1].setcurrentDir(55f);
		cars[1].setowner("Audi");

		cars[2]= new Vehicle();
		cars[2].setcurrentSpeed(158.5f);
		cars[2].setcurrentDir(30f);
		cars[2].setowner("Honda");

		cars[3]= new Vehicle();
		cars[3].setcurrentSpeed(323.5f);
		cars[3].setcurrentDir(100f);
		cars[3].setowner("Ferrari");

		cars[4]= new Vehicle("Mercedes");
		cars[4].setcurrentSpeed(223.1f);
		cars[4].setcurrentDir(56f);
		
		for(int j=0; j<cars.length; j++)
			cars[j].print();
	
		Vehicle copycar = new Vehicle();
		copycar.copyVehicle(cars[4]);
		
		Vehicle max_speedVehicle = new Vehicle();
		max_speedVehicle = max_speedVehicle.HighestSpeed(cars);
		max_speedVehicle.print();

		System.out.println("Highest ID assigned : "+Vehicle.highestID());

		cars[0].changeSpeed(999f);
		System.out.println("New speed : "+cars[0].getcurrentSpeed());
		cars[0].stop();	
		System.out.println("New speed : "+cars[0].getcurrentSpeed());
		}
}

class Garage implements Cloneable
{
	private static final int SIZE = 10;
	private Vehicle[] varr = new Vehicle[SIZE];	
	private static int VIG = 0;	//vehicles in garage
	public Garage()
	{
		for(int j = 0; j<SIZE; j++)
			varr[j] = new Vehicle();		//CREATE NEW MEMORY SPACE FOR THESE VEHICLES
	}
	public Object clone() throws CloneNotSupportedException
	{
		Garage cloned;
		cloned = (Garage) super.clone();
		cloned.varr = (Vehicle[]) varr.clone();		//GENERATE CLONE OF MUTABLE FIELD
		return cloned;		
	}
	public int fillGarage(Vehicle[] cars)
	{
		if(cars.length > SIZE)
		{
			System.out.println("Supplied Cars will not fit in the Garage.");
			return 0;
		}
		for(int j=0; j< cars.length; j++)
		{
			varr[j].copyVehicle(cars[j]);		//COPY SUPPLIED VEHICLE ATTRIBUTES TO SPACE CREATED
			VIG++;
		}
		
		return 1;
	}
	public void printGarage()
	{
		for(int j=0; j<VIG; j++)
		{
			varr[j].print();
		}
	}
	public void changeSpeed(float inp, int pos)	//to illustrate deep copying
	{
		varr[pos].setcurrentSpeed(inp);	
	}
}

class GarageTester
{
	public static void main(String[] args) throws CloneNotSupportedException
	{
		Vehicle[] cars = new Vehicle[4];
		cars[0]= new Vehicle();
		cars[0].setcurrentSpeed(123.5f);
		cars[0].setcurrentDir(45f);
		cars[0].setowner("Toyota");

		cars[1]= new Vehicle();
		cars[1].setcurrentSpeed(183.5f);
		cars[1].setcurrentDir(55f);
		cars[1].setowner("Audi");

		cars[2]= new Vehicle();
		cars[2].setcurrentSpeed(158.5f);
		cars[2].setcurrentDir(30f);
		cars[2].setowner("Honda");

		cars[3]= new Vehicle();
		cars[3].setcurrentSpeed(323.5f);
		cars[3].setcurrentDir(100f);
		cars[3].setowner("Ferrari");

		Garage g1 = new Garage();
		g1.fillGarage(cars);
		Garage g2 = (Garage) g1.clone();
		g2.changeSpeed(101,2);
		g1.printGarage();
		g2.printGarage();
	}
}
