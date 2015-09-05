import junit.framework.TestCase;
import org.junit.Before;
import org.junit.Test;
public class TestJunit2 extends TestCase{
	protected double fval1;
	protected double fval2;
	@Before
	public void setUp(){
		fval1=2.0; fval2=3.0;
		System.out.println("Running setUp()");
	}
	@Test
	public void testAdd(){
		//count number of test cases
		System.out.println("No of test cases = "+this.countTestCases());
		//test getName fn 
		String name = this.getName();
		System.out.println("Test Case Name = "+name);
		//test setName
		this.setName("testNewAdd");
		String newname = this.getName();
		System.out.println("Test Case Modified Name = "+newname);
	}
	@Test
	public void testfn2(){
		String name = null;
		assertNotNull(name);
	}
	public void tearDown(){
		System.out.println("Running tearDown");
	}
}
