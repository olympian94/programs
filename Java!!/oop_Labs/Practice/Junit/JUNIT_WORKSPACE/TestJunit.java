import org.junit.Test;
import static org.junit.Assert.*;
public class TestJunit{
	@Test
	public void testAdd(){
		String str = "JUnit working";
		assertEquals("JUnit working",str);
	}
}
