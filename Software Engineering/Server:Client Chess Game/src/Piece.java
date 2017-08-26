
public class Piece {

	boolean king;
	String color;
	int row;
	int column;
	boolean alive = false;

	public Piece() { }
	
	public Piece(String col, int row_, int column_, boolean alive_, boolean king_) {
		color = col;
		row = row_;
		column = column_;
		alive = alive_;
		king = king_;
	}
	
	void setTo(Piece p)
	{
		king = p.king;
		color = p.color;
		alive = p.alive;
	}
	
	void setColor(String color_)
	{
		color = color_;
	}
	
	String getColor()
	{
		return color;
	}
	
	boolean isKing()
	{
		return king;
	}
	
}
