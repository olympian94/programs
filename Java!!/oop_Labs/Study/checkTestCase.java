package Study;
import junit.framework.TestCase;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;
import org.junit.Assert.*;
public class checkTestCase extends TestCase
{
	protected int v1, v2;
	@Before
	public void setUp()
	{
		System.out.println("setUp...");
		v1=5; v2=10;
	}
	@Test
	public void testfn()
	{
		System.out.println("Test Case name...\n"+this.getName());
		assertEquals(5,v1+v2);
	}
	@After
	public void tearDown()
	{
		System.out.println("tearDown...");
	}
}
