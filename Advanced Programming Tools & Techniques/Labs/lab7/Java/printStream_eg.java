/* printStream_eg - Write a multiline text file.  Cf: to out from eg_writer
 *	PrintStream writes bytes (binary data)
 * 
 * Kurt Schmidt
 * May 2015
 *
 * Java SE 7
 *
 * EDITOR:  tabstop=2, cols=80
 *
 */

import java.io.* ;

public class printStream_eg
{
	public static String filename = "stream.out.txt" ;

	public static void main( String [] argv )
		throws FileNotFoundException 
	{
		PrintStream fout = new PrintStream( filename ) ;

		fout.println( "Line 1" ) ;
		fout.println( "Line 2" ) ;
		fout.println( "Line 3" ) ;
		fout.println( "Line 4" ) ;

		fout.close() ;
	}	// main
}	// class eg_stream

