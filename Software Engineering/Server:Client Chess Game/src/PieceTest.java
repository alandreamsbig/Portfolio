import static org.junit.Assert.*;

import org.junit.Test;

public class PieceTest {
	Piece p=new Piece("black", 1, 2,true,true);
	@Test
	public void testConstructor() {
		
		
		
		assertEquals(p.getColor(),"black");
		assertEquals(p.row,1);
		assertEquals(p.column,2);
	}

	
	@Test
	public void testSetTo() {
		
		Piece p1=new Piece();
		p1.setTo(p);
		
		assertEquals(p.getColor(),"black");
		assertEquals(p.row,1);
		assertEquals(p.column,2);
	}
	
	@Test
	public void testSetcolor() {
		
		Piece p1=new Piece();
	p1.setColor("blue");
		
		assertEquals(p1.getColor(),"blue");
		
	}
	@Test
	public void testgetcolor() {
		
	
		
		assertEquals(p.getColor(),"black");
		
	}
	
	
}
