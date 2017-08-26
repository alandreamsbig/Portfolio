
public class GameBoard {

	Piece[][] pieces = new Piece[8][8];
	String playerNo = null;
	
	void initialize(String playerNo_)
	{
		playerNo = playerNo_;
		String myColor = null;
		String otherColor = null;
		
		myColor = playerNo.equals("1") ? "red" : "white";
		otherColor = myColor.equals("red") ? "white" : "red";
		
		helpInit(0, 3, otherColor);
		helpInit(5, 8, myColor);
		setToNull(3, 5);
	}
	
	Piece[][] getPieces()
	{
		return pieces;
	}
	
	String getPlayerNo()
	{
		return playerNo;
	}
	
	void addChecker(String color, int row_, int column_, boolean king)
	{
		Piece temp = pieces[row_][column_];
		temp.alive = true;
		temp.setColor(color);
		temp.king = king;
		temp.row = row_;
		temp.column = column_;
	}
	
	void helpInit(int startRow, int finishRow, String myColor)
	{
		for(int i = startRow; i < finishRow; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				pieces[i][j] = new Piece();
				
				if ((i + j) % 2 == 1)
				{
					pieces[i][j] = new Piece(myColor, i, j, true, false);
				}
				else
					pieces[i][j] = new Piece("", i, j, false, false);
			}
		}
	}
	
	void setToNull(int startRow, int finishRow)
	{
		for(int i = startRow; i < finishRow; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				pieces[i][j] = new Piece("", i, j, false, false);
			}
		}
	}
	
	void printGameBoard()
	{
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				Piece temp = pieces[i][j];
				if (temp.alive == true)
					System.out.println("Piece at row " + temp.row + " and column " + temp.column + " is alive and has "
				+ temp.getColor() + " color.\n");
				else
					System.out.println("Piece at row " + i + " and column " + j + " is empty.\n");
			}
		}
	}
	
	void makeMove(Move move)
	{
		int startR = move.getStartRow();
		int startC = move.getStartCol();
		int destR = move.getDestRow();
		int destC = move.getDestCol();
		
		if (move.isJump())
		{
			if (startR - destR == 2)
			{
				if (destC - startC == 2)
				{
					pieces[startR - 1][startC + 1].alive = false;
				}
				else if (startC - destC == 2)
				{
					pieces[startR - 1][startC - 1].alive = false;
				}
			}
			
			else if (destR - startR == 2)
			{
				if (destC - startC == 2)
				{
					pieces[startR + 1][startC + 1].alive = false;
				}
				else if (startC - destC == 2)
				{
					pieces[startR + 1][startC - 1].alive = false;
				}
			}
		}

		pieces[destR][destC].setTo(pieces[startR][startC]);
		pieces[startR][startC].alive = false;
		if (destR == 0 && !pieces[destR][destC].isKing())
			pieces[destR][destC].king = true;
	}
	
}
