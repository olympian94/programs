

/**
 * @author ASHU SHARMA
 */
	

public class windchill {
    
public static void main (String[] args) {
        
    String V= args[0];
	String T= args[1];
    double velocity = Double.			(V);
	double time = Double.			(T);
	System.out.println("velocity == " +velocity);
	System.out.println("time == " + time);
        double windchill = 35.74 + (0.6215)*time - 35.75*(Math.		(velocity, 0.16)) + (0.4275) *time *(Math.		(velocity, 0.16));
        
	System.out.println("windchill index ==" + Math.		(windchill));
        }
    }

