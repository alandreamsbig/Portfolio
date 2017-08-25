// csvSplit.java - Reads diskfile by records (lines), breaks lines into
//		tokens using the String.split() method
// Demonstrates:	String.split(), BufferedReader, InputStreamReader,
//		FileInputStream
//
// 3/04 
//

import java.io.*;
import java.lang.System;


public class csvSplit
{
	public static void main( String[] args ) throws Exception
	{
		int rV;
		String buff;

		if( args.length != 1 )
		{
			System.err.println( "I need ! 1 filename to read\n" );
			System.exit( 1 );
		}

		FileInputStream fileIn = new FileInputStream( args[0] );

			// "chaining" I/O classes 
		BufferedReader bIn =
			new BufferedReader( new InputStreamReader( fileIn ));

		buff = bIn.readLine();

		while( buff != null )
		{
			//System.out.println( "line: " + buff );
			String[] toks = buff.split( "," );

			int i ;
			double d ;
			String name ;

			name = toks[0] ;
			i = Integer.parseInt( toks[1] ) ;
			d = Double.parseDouble( toks[2] ) ;

			System.out.printf( "%10s has %8d ints and a float of %8.3f\n",
													name, i, d ) ;
			
			buff = bIn.readLine();
		}	// while more lines

	}	// main

}	// class fileTokInp

