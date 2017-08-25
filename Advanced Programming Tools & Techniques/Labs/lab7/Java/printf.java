// buffWrite.java - Writing to file, appending, using write()
// Demonstrates:	BufferedWriter, FileWriter
//
// Kurt Schmidt
// 1/15
// 
// EDITOR:  tabstop=2, cols=80
//
// javac 1.7.0_72 on
// Linux 3.2.0-74-generic #109-Ubuntu x86_64 x86_64 x86_64 GNU/Linux
//

import java.io.BufferedWriter ;
import java.io.FileWriter ;
import java.io.IOException ;

public class buffWrite
{
	public static void main( String [] args ) throws IOException
	{
		if( args.length == 0 )  // read from stdin
		{
			System.out.println( "\nProvide a filename as a command-line argument.\n" ) ;
			System.exit( 1 ) ;
		}

		//BufferedWriter out = new BufferedWriter( new FileWriter( args[0] )) ;
		BufferedWriter out = new BufferedWriter( new FileWriter( args[0], true )) ;
			// provide true as a 2nd arg to append

		out.write( "Line 1\n" ) ;
		out.write( "Line 2" ) ;
		out.write( "Line 3?\n" ) ;
		out.write( "Okay.  Line 3\n" ) ;

		out.close() ;  // I needed this, oddly
	} // main
} // class buffWrite


