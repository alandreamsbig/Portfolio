/* Circle - Child of Shape
 * 
 * Kurt Schmidt
 * May 2015
 *
 * Java SE 7
 *
 * EDITOR:  tabstop=2, cols=80
 *
 */

public class Circle extends Shape
{
	private double _radius ;

	public Circle( double rad, GridLoc l )
	{
		super( l ) ;
		_radius = rad ;
	}

	public Circle( double rad, GridLoc l, String id )
	{
		super( l, id ) ;
		_radius = rad ;
	}

	@Override
	public double getArea() { return Math.PI*_radius*_radius ; }

	@Override
	public double getPerimeter() { return 2*Math.PI*_radius ; }

}	// class eg_stream

