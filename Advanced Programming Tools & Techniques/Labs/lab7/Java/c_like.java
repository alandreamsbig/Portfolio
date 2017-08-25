// c_like.java - An example of a simple, c-like program, a single class that
//		contains only static methods
//	No objects are instantiated
//  
// Kurt Schmidt
// 5/15
//
// javac 1.7.0_80 on
// Linux 3.13.0-48-generic #80-Ubuntu x86_64 x86_64 x86_64 GNU/Linux
//
// EDITOR:  tabstop=2, cols=80
//

import java.io.* ;

public class c_like
{
	public static int kurt = 12 ;

	public static int gcd( int a, int b )
	{
		if( b>a )
			return gcd( b, a ) ;
		if( b==0 )
			return a ;
		return gcd( b, a%b ) ;
	}

	public static void main( String [] argv )
	{
		System.out.println( "The gcd( 15, 6 ) is: " + gcd( 15, 6 ) ) ;
	}
} 	// class first


