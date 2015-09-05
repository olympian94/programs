enum Planet
{
	MERCURY (3.303e+23, 2.4397e6),	//These constants are created by the ctor defined below!
	VENUS   (4.869e+24, 6.0518e6),	//these constants basically call the ctor with these parameters
	EARTH   (5.976e+24, 6.37814e6),
	MARS    (6.421e+23, 3.3972e6),
	JUPITER (1.9e+27,   7.1492e7),
	SATURN  (5.688e+26, 6.0268e7),
	URANUS  (8.686e+25, 2.5559e7),
	NEPTUNE (1.024e+26, 2.4746e7);

	private final double mass;
	private final double radius;
	public static final double G = 6.673E-11;
	
	Planet(double mass_inp, double radius_inp)
	{
		mass=mass_inp;
		radius=radius_inp;
	}
	private double mass(){return mass;}
	private double radius(){return radius; }

	double surfaceGravity()	
	{	return (G*mass)/(radius*radius);
	}

	double surfaceWeight(double otherMass)
	{	return otherMass*surfaceGravity();
	}
	public static void main(String[] args)
	{
		if(args.length!=1)
		{
			System.out.println("Enter your weight as CLA to know your weight on all the planets of the Solar System");
			System.exit(-1);
		}
		double earthWeight = Double.parseDouble(args[0]);
		double mass = earthWeight/EARTH.surfaceGravity();
		for(Planet p : Planet.values() )		//for-each loop
		{
			System.out.printf("Your weight on %s is %f\n",p,p.surfaceWeight(mass));
		}
		Planet p = MERCURY;
		System.out.println(p.surfaceGravity());
	}
}