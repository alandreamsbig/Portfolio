import static org.junit.Assert.*;

import org.junit.Test;

public class TestClass {
	ConnectionHelper ch=new ConnectionHelper();
	@Test
	public void testConnect() {
		
		ch.connect();
		assertNotNull(ConnectionHelper.socket_);
	ch.closeConnection();
	
	}
	@Test
	public void testConnectP1() {
		
		ch.connect();
		String abc=ch.ReadPlayer();
		assertEquals(abc,"1");
		
		ch.closeConnection();
	
	}
	@Test
	public void testConnectWrite() {
		ch.connect();
		String abc=ch.ReadPlayer();
		//ch.Write("hello");
	//	String ab=ch.Read();
		//assertEquals(ab,"hello");
		ch.closeConnection();
		
	
	
	}
}
