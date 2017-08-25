// rv.java - Reads command-line arg, converts to int, calls System.exit
//
// 11/14
//
//


import java.io.*;

public class rc
{
	public static void main( String[] argv ) 
	{
		int rv = 0 ;

		if( argv.length > 0 )
			rv = Integer.parseInt( argv[0] );

		System.exit( rv ) ;

	} // main

} 	// class intArgs


