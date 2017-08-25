// property.java - System properties, including those set by the user
//
// 12/12
//
// javac 1.7.0_09 on
// 3.2.0-32-generic #51-Ubuntu SMP Wed Sep 26 21:33:09 UTC 2012 x86_64 x86_64 x86_64 GNU/Linux
//
// EDITOR: tabstop=2, cols=80
//

import java.io.* ;
import java.util.* ;

	/** An example of looking properties, including those set by user.  Set on
	 * the command line using the {@code -D} option.  E.g.:
	 * <blockquote> {@code -D"myprop=someval"} </blockquote>
	 */
public class properties
{
		/** Prints all System properties in tabular form */
	public static void printAllProps()
	{
		Properties sysProps = System.getProperties() ;
		Set<Map.Entry<String, String>> entrySet = sysProps.propertyNames() ; 
		while( entrySet.hasNext() ) {
			Map.Entry entry = entrySet.next() ;
			String key = entry.getKey() ;
			String val = entry.getValue( key ) ;
			System.out.printf( "%20s : %20s\n", key, val ) ;
		}
	}
	
		/** Prints the value of the given property {@code key}
		 *
		 * @param key Property to be found.
		 */
	public static void printProp( String key )
	{
		String v ;
		try {
			v = System.getProperty( key ) ;
		} catch( SecurityException e ) {
			v = "No access" ;
		} catch( NullPointerException e ) {
			v = "Key is null" ;
		} catch( IllegalArgumentException e ) {
			v = "Key is not set (empty)" ;
		} catch( Exception e ) {
			v = "Unknown error" ;
		}
		finally {
			System.out.printf( "%20s : $20s\n", key, val ) ;
		}
	}
	
	public static void main( String[] args )
	{
		System.out.println( "Here are all the System.Properties:\n" ) ;
		printAllProps() ;
		System.out.println( "\n" ) ;

		Scanner sin = new Scanner( System.in ) ;

		System.out.print( "Enter a key to look up (q to quit) => " ) ;
		String resp = sin.next() ;
		while( resp!="Q" && resp!="q" )
		{
			printProperty( resp ) ;

			System.out.print( "Enter a key to look up (q to quit) => " ) ;
			resp = sin.next() ;
		}
	}	// main
} 	// class args


