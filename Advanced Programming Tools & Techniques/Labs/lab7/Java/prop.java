
import java.lang.System.* ;
import java.util.Properties ;

public class prop
{
	public static void main( String [] argv )
	{
		Properties p = System.getProperties() ;

		p.list( System.out ) ;
	}
} ;
