/* Square - Child of Shape
 * 
 * Kurt Schmidt
 * May 2015
 *
 * Java SE 7
 *
 * EDITOR:  tabstop=2, cols=80
 *
 */

public class Square extends Shape
{
	private double _side ;

	public Square( double side, GridLoc l )
	{
		super( l ) ;
		_side = side ;
	}

	public Square( double side, GridLoc l, String id )
	{
		super( l, id ) ;
		_side = side ;
	}

	@Override
	public double getArea() { return _side*_side ; }

	@Override
	public double getPerimeter() { return 4*_side ; }

}	// class eg_stream

