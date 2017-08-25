//A gInt class with different behaviors and methods for Gaussian Inteter
//Author: Alan Tsai
//5/29/16

import java.io.*;
import java.util.*;
import java.lang.Math;

public class gInt{
	
	public int realNum = 0;
	public int imaginaryNum = 0;
	public double i = Math.sqrt(-1);

	//constructor
	public gInt( int r)
	{
		realNum = r;
	}

	//c'tor
	public gInt( int r, int i)
	{
		realNum = r;
		imaginaryNum = i;
	}

	//The real part of the number
	public int real()
	{
		return realNum;
	}

	//The imaginary part of the number
	public int imag()
	{
		return imaginaryNum;
	}

	//Return a new gInt, the sum of this and rhs
	public gInt add( gInt rhs)
	{
		gInt result = new gInt(0,0);
		result.realNum = (rhs.realNum + realNum);
		result.imaginaryNum = (rhs.imaginaryNum + imaginaryNum);
		return result;
	}

	//Return a new gInt, the product of this and rhs
	public gInt multiply( gInt rhs )
	{
		gInt result = new gInt(0,0);
		result.realNum = (realNum*rhs.realNum) - (imaginaryNum*rhs.imaginaryNum);
		result.imaginaryNum = (realNum*rhs.imaginaryNum) + (imaginaryNum*rhs.realNum);
		return result;
	}

	//Return the L2-norm of the integer(the distance from the origin)
	public float norm()
	{
		return (float)Math.sqrt((realNum * realNum) + (imaginaryNum * imaginaryNum));
	}

	public boolean equals( Object isObject )
	{
		if( isObject instanceof gInt)
		{
			gInt agInt = (gInt)isObject;
			return (agInt.real() == real() && agInt.imag() == imag());
		}
		return false;
	}
}
