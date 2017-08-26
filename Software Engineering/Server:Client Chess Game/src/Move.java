import java.io.Serializable;

public class Move implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	boolean myturn;
	int startRow, startCol, destRow, destCol;
	
	public Move(int startR, int startC, int destR, int destC)
	{
		startRow = startR;
		startCol = startC;
		destRow = destR;
		destCol = destC;
	}
	
	public Move() {
		// TODO Auto-generated constructor stub
	}
	
	void setTo(Move m)
	{
		myturn = m.myturn;
		startRow = m.getStartRow();
		startCol = m.getStartCol();
		destRow = m.getDestRow();
		destCol = m.getDestCol();
	}
	
	void reverse()
	{
		startRow = 7 - startRow;
		startCol = 7 - startCol;
		destRow = 7 - destRow;
		destCol = 7 - destCol;
	}
	
	void printMove()
	{
		System.out.println("Startrow: " + startRow + "; startCol: " + startCol + "; destRow: " + 
				destRow + "; destCol: " + destCol + ".\n");
	}

	boolean isJump()
	{
		// we only check if it's a jump, not if it's a valid move
		return ((destRow - startRow == 2) || (startRow - destRow == 2));
	}
	
	int getStartRow()
	{
		return startRow;
	}
	
	int getStartCol()
	{
		return startCol;
	}
	
	int getDestRow()
	{
		return destRow;
	}
	
	int getDestCol()
	{
		return destCol;
	}
	
	void setStartRow(int startR)
	{
		startRow = startR;
	}
	
	void setStartCol(int startC)
	{
		startCol = startC;
	}
	
	void setDestRow(int destR)
	{
		destRow = destR;
	}
	
	void setDestCol(int destC)
	{
		destCol = destC;
	}
}
