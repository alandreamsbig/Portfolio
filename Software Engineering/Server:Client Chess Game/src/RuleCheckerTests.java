import static org.junit.Assert.*;

import javax.swing.UnsupportedLookAndFeelException;

import org.junit.Test;

public class RuleCheckerTests {
RuleChecker rc=new RuleChecker();
	GameBoard gm=new GameBoard();
	
	@Test
	public void isValidMovetest() {
		gm.initialize("1");
		Move move=new Move(1,2,3,4);
		String result=rc.isValidMove(move, gm);
		assertEquals(result,"invalid");
	}
	
	@Test
	public void isValidMovetest1() {
		gm.initialize("2");
		Move move=new Move(7,0,6,1);
		String result=rc.isValidMove(move, gm);
		assertNotSame(result,"valid");
	}
	
	@Test
	public void islimitstest() {
		
		Move move=new Move(1,0,8,1);
		
		assertFalse(rc.withinLimits(move));
	}
	
	
	@Test
	public void isvalidJump() {
		gm.initialize("1");
		Move move=new Move(5,0,4,1);
		String result=rc.isValidMove(move, gm);
		assertEquals(result,"valid");
		
	}
	@Test
	public void testGUI() {
		try {
			GameboardGUI g=new GameboardGUI();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Menu m=new Menu();
		m.startGUI();
		m.stopGUI();
		assertTrue(true);
		
	}
}
