import java.util.Vector;

public class RuleChecker {
	
	String isValidMove(Move move, GameBoard gameBoard)
	{
		Piece[][] pieces = gameBoard.getPieces();
		Piece currentP = pieces[move.startRow][move.startCol];
		String myColor = gameBoard.getPlayerNo().equals("1") ? "red" : "white";
		
		if (!currentP.alive)
			return "invalid";	// can't move a nonchecker piece lol
		
		if (!currentP.getColor().equals(myColor))
			return "invalid";	// can't move opponent's checker
		
		if (!withinLimits(move))
			return "invalid";
		
		if (pieces[move.destRow][move.destCol].alive)
			return "invalid";	// trying to jump on another checker
		
		if (move.startRow == move.destRow || move.startCol == move.destCol)
			return "invalid";	// can't move to same row or col
		
		if (move.startRow - move.destRow < 0 && !currentP.isKing())
			return "invalid";	// can't move backwards if not king
		
		if (move.isJump())
			return isValidJump(move, gameBoard) ? "valid" : "invalid";
		
		if (jumpsAvailable(gameBoard) && !move.isJump())
			return "mustJump";
		
		return "valid";
	}
	
	boolean withinLimits(Move move)
	{
		return (move.getDestRow() >= 0 && move.getDestRow() <= 7) && (move.getDestCol() >= 0 && move.getDestCol() <= 7);
	}
	
	boolean withinBoard(int number)
	{
		return (number >= 0 && number <= 7);
	}
	
	boolean jumpsAvailable(GameBoard gameBoard)
	{
		Piece[][] pieces = gameBoard.getPieces();
		String myColor = gameBoard.getPlayerNo().equals("1") ? "red" : "white";
		Piece temp = new Piece();
		
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				temp = pieces[i][j];
				if (temp.alive == true && temp.getColor().equals(myColor))
				{
					if (!findValidJumps(temp, gameBoard).isEmpty())
						return true;
				}
			}
		}
		
		return false;
	}
	
	Vector<Move> findValidJumps(Piece piece, GameBoard gameBoard)
	{
		Vector<Move> validJumps = new Vector<Move>();
		int startRow = piece.row;
		int startCol = piece.column;
		
		Move move = new Move(startRow, startCol, startRow - 2, startCol + 2);
		if (isValidJump(move, gameBoard))
			validJumps.addElement(move);
		
		move = new Move(startRow, startCol, startRow - 2, startCol - 2);
		if (isValidJump(move, gameBoard))
			validJumps.addElement(move);
		
		if (piece.isKing())
		{
			move = new Move(startRow, startCol, startRow + 2, startCol + 2);
			if (isValidJump(move, gameBoard))
				validJumps.addElement(move);
			
			move = new Move(startRow, startCol, startRow + 2, startCol - 2);
			if (isValidJump(move, gameBoard))
				validJumps.addElement(move);
		}
		
		return validJumps;
	}
	
	boolean isValidJump(Move move, GameBoard gameBoard)
	{
		Piece[][] pieces = gameBoard.getPieces();
		String myColor = gameBoard.getPlayerNo().equals("1") ? "red" : "white";
		int startR = move.startRow;
		int startC = move.startCol;
		int destR = move.destRow;
		int destC = move.destCol;
		Piece currentP = pieces[startR][startC];
		Piece temp;
		
		if (!withinLimits(move))
			return false;
		
		if (!((destR - startR == 2 || startR - destR == 2) && (destC - startC == 2 || startC - destC == 2)))
			return false; // the parameters are not correct
		
		if (pieces[destR][destC].alive)
			return false;	// trying to jump on another checker
		
		if (!currentP.getColor().equals(myColor))
			return false;	// can't move opponent's checker
		
		if (move.startRow == move.destRow || move.startCol == move.destCol)
			return false;	// can't move to same row or col
		
		if (startR - destR == 2)
		{
			if (destC - startC == 2)
			{
				temp = pieces[startR - 1][startC + 1];
				if ((!temp.alive) || (temp.getColor() == myColor))
					return false;	// there's no checker to eat or I'm trying to eat one of my checkers
			}
			else if (startC - destC == 2)
			{
				temp = pieces[startR - 1][startC - 1];
				if ((!temp.alive) || (temp.getColor() == myColor))
					return false;
			}
		}
		
		else if (destR - startR == 2)
		{
			if (!pieces[startR][startC].king)
				return false;	// has to be king to move backwards
			
			if (destC - startC == 2)
			{
				temp = pieces[startR + 1][startC + 1];
				if ((!temp.alive) || (temp.getColor() == myColor))
					return false;
			}
			else if (startC - destC == 2)
			{
				temp = pieces[startR + 1][startC - 1];
				if ((!temp.alive) || (temp.getColor() == myColor))
					return false;
			}
		}
		
		return true;
	}
	
	/* check if all my checkers are captured and if I have no available moves */
	boolean gameOver(GameBoard gameBoard)
	{
		Piece[][] pieces = gameBoard.getPieces();
		String myColor = gameBoard.getPlayerNo().equals("1") ? "red" : "white";
		Piece temp = new Piece();
		
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				temp = pieces[i][j];
				if (temp.alive == true && temp.getColor().equals(myColor) && !findValidMoves(temp, gameBoard).isEmpty())
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
	Vector<Move> findValidMoves(Piece piece, GameBoard gameBoard)
	{
		Vector<Move> validMoves = new Vector<Move>();
		int startRow = piece.row;
		int startCol = piece.column;
		
		Move move = new Move(startRow, startCol, startRow - 1, startCol + 1);
		if (isValidMove(move, gameBoard).equals("valid"))
			validMoves.addElement(move);
		
		move = new Move(startRow, startCol, startRow - 1, startCol - 1);
		if (isValidMove(move, gameBoard).equals("valid"))
			validMoves.addElement(move);
		
		move = new Move(startRow, startCol, startRow - 2, startCol + 2);
		if (isValidMove(move, gameBoard).equals("valid"))
			validMoves.addElement(move);
		
		move = new Move(startRow, startCol, startRow - 2, startCol - 2);
		if (isValidMove(move, gameBoard).equals("valid"))
			validMoves.addElement(move);
		
		if (piece.isKing())
		{
			move = new Move(startRow, startCol, startRow + 1, startCol + 1);
			if (isValidMove(move, gameBoard).equals("valid"))
				validMoves.addElement(move);
			
			move = new Move(startRow, startCol, startRow + 1, startCol - 1);
			if (isValidMove(move, gameBoard).equals("valid"))
				validMoves.addElement(move);
			
			move = new Move(startRow, startCol, startRow + 2, startCol + 2);
			if (isValidMove(move, gameBoard).equals("valid"))
				validMoves.addElement(move);
			
			move = new Move(startRow, startCol, startRow + 2, startCol - 2);
			if (isValidMove(move, gameBoard).equals("valid"))
				validMoves.addElement(move);
		}
		
		return validMoves;
	}
}
