/* GridLoc - Simple class, holds a pair of integers
 * 
 * Kurt Schmidt
 * May 2015
 *
 * Java SE 7
 *
 * EDITOR:  tabstop=2, cols=80
 *
 */


public abstract class GridLoc
{
	public int x ;
	public int y ;

	public GridLoc( int x, int y )
	{
		this.x = x ;
		this.y = y ;
	}

	double distFrom( GridLoc op )
	{
		int dx = op.x - x ;
		int dy = op.y - y ;

		return Math.sqrt( dy*dy + dx*dx ) ;
	}
}

