import static org.junit.Assert.*;

import org.junit.Test;

public class GameBoardTests {
GameBoard gb=new GameBoard();
Move mv;
	@Test
	public void initilizetest() {
		gb.initialize("1");
		assertEquals(gb.playerNo,"1");
	}
	
	@Test
	public void initilizetest1() {
		
		gb.initialize("1");
		Piece[][] pieces=gb.getPieces();
		assertEquals(pieces[0][1].color,"white");
	}
	@Test
	public void initilizetest2() {
		
		gb.initialize("1");
		Piece[][] pieces=gb.getPieces();
		assertEquals(pieces[7][0].color,"red");
	}
	@Test
	public void initilizetest3() {
		
		gb.initialize("1");
		gb.printGameBoard();
	}
	@Test
	public void getPlayerTestt() {
		
		gb.initialize("1");
		assertEquals(gb.getPlayerNo(),"1");
		gb.initialize("2");
		assertEquals(gb.getPlayerNo(),"2");
		
	}
	@Test
	public void getPlayerTesttofail() {
		
		gb.initialize("1");
		assertNotSame(gb.getPlayerNo(),"2");
		gb.initialize("2");
		assertNotSame(gb.getPlayerNo(),"4");
		
	}
	//Move tests
	@Test
	public void moveConstTest(){
		mv=new Move(0,0, 1,2);
		assertEquals(mv.getStartRow(),0);
		assertEquals(mv.getStartCol(),0);
		assertEquals(mv.getDestRow(),1);
		assertEquals(mv.getDestCol(),2);
	}
	@Test
	public void moveConstTest1(){
		mv=new Move(0,0, 1,2);
		mv.setStartCol(2);
		mv.setStartRow(4);
		mv.setDestRow(6);
		mv.setDestCol(8);
		assertEquals(mv.getStartRow(),4);
		assertEquals(mv.getStartCol(),2);
		assertEquals(mv.getDestRow(),6);
		assertEquals(mv.getDestCol(),8);
	}
}
