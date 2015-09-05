package Study;
import org.junit.Test;
import static org.junit.Assert.*;
public class TestJunit
{
	@Test
	public void testfn1()
	{	
		String str2 = "works";
		assertEquals("workers",str2);
	}
	@Test
	public void testfn2()
	{	
		assertFalse(true);
	}
}
