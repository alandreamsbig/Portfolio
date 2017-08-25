/* Shape - Abstract base class for closed, regular shapes
 * 
 * Kurt Schmidt
 * May 2015
 *
 * Java SE 7
 *
 * EDITOR:  tabstop=2, cols=80
 *
 */

public abstract class Shape
{
	private GridLoc _center ;
	private String _id ;

	public String getId() { return _id ; }

	public abstract double getArea() ;
	public abstract double getPerimeter() ;

	public Shape( GridLoc c ) { _center = c ; _id = null ; }
	public Shape( GridLoc c, String id ) { _center = c ; _id = id ; }

}	// class eg_stream

