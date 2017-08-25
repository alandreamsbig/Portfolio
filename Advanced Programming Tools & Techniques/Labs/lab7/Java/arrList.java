// arrList.java - Read single words, add to arrayList
// Demonstrates:	Scanner, ArrayList
//
// Kurt Schmidt
// 10/2014
// 
// EDITOR:  tabstop=2, cols=120
//
// javac 1.6.0_65 on
// Linux 2.6.35-30-generic #61-Ubuntu SMP Tue Oct 11 17:52:57 UTC 2011 
//

// Scanner is a bit of a Swiss-army knife.  Lots of useful stuff.  See the
// documentation.

import java.io.IOException ;
import java.io.FileReader ;
import java.util.ArrayList ;
import java.util.Iterator ;
import java.util.Scanner ;

public class arrList
{
public static void main( String [] argv ) throws IOException
{
	Scanner src ;
	ArrayList<String> v = new ArrayList<String>() ;

	if( argv.length == 0 )  // read from stdin
		src = new Scanner( System.in ) ;
	else
		src = new Scanner( new FileReader( argv[0] )) ; // Can wrap a File, InputStream, or String

	while( src.hasNext() )
		v.add( src.next() ) ;

	// Various ways to iterate over ArrayList

	for( int i=0; i<v.size(); ++i )
		System.out.println( v.get( i )) ;
	System.out.println( "" ) ;

	for( String s : v )
		System.out.println( s ) ;
	System.out.println( "" ) ;
	
		// explicit iterator
	Iterator<String> it = v.iterator() ;
	while( it.hasNext() )
		System.out.println( it.next() ) ;
	System.out.println( "" ) ;

}	// main
} // class arrList

