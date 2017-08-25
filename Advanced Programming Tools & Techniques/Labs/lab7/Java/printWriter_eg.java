/* printWriter_eg - Write a multiline text file.  Cf: to output from eg_stream
 *	PrintWriter writes characters (ASCII text)
 *  You'll likely need to run this on Windows (not Cygwin) to see a
 *  difference
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

public class printWriter_eg
{
	public static String filename = "writer.out.txt" ;

	public static void main( String [] argv )
		throws FileNotFoundException 
	{
		PrintWriter fout = new PrintWriter( filename ) ;

		fout.println( "Line 1" ) ;
		fout.println( "Line 2" ) ;
		fout.println( "Line 3" ) ;
		fout.println( "Line 4" ) ;

		fout.close() ;
	}	// main
}	// class eg_writer

