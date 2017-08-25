// hashMap.java - One of the several dictionaries in Java
// Demonstrates:	HashMap
//
// Kurt Schmidt
// 5/2015
// 
// EDITOR:  tabstop=2, cols=120
//
// Java SE 7
//

import java.util.Set ;
import java.util.ArrayList ;
import java.util.HashMap ;
import java.util.Collections ;
import java.io.* ;

public class hashMap
{
	public static void main( String [] argv ) throws IOException
	{
		HashMap<String, Integer> d = new HashMap<String, Integer>() ;

		d.put( "DE", 1 ) ;
		d.put( "NJ", 3 ) ;
		d.put( "PA", 2 ) ;
		d.put( "GA", 4 ) ;
		d.put( "CT", 2 ) ;
		d.put( "Confused", 52 ) ;

		if( d.containsKey( "CT" ) )
			System.out.println( "CT is in spot #" + d.get( "CT" ) + "\n" ) ;

		// Look at entire dictionary
			// A Set, like an ArrayList, is a Collection
		Set<String> keys = d.keySet() ;

		if( ! d.isEmpty() )
		{
			for( String s : keys )
				System.out.printf( "%-10s: %2d\n", s, d.get( s )) ;
		}

			// Hey, Confused isn't a state
		d.remove( "Confused" ) ;
			// And CT wasn't 2nd, it was 5th
		d.put( "CT", 5 ) ;

		System.out.println( "\nOkay, in order this time:\n" ) ;

		ArrayList<String> v = new ArrayList<String>( d.keySet() ) ;
		Collections.sort( v ) ;

		for( String s : v )
				System.out.printf( "%-10s: %2d\n", s, d.get( s )) ;

	}	// main
} // class arrList

