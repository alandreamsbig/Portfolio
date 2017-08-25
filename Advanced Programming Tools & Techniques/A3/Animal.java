/**
 *This Animal class program contains the animal abstract class and methods 
 *@author Alan Tsai
 *Date 5/18/16
 */

import java.io.*;
import java.util.Random;
import java.awt.Point;

public abstract class Animal
{
	protected Point location;
	protected String name;
	protected Random rng;
	public static int GRID_SIZE = 7;	

	//Constructor for the Animal class
	public Animal(String name, Random rng)
	{
		this.name = name;
		this.rng = rng;
		setStartLocation();	
	}
	
	//getName function
	public String getName()
	{
		return name;
	}
	
	//getLocation function, returns the location of the animal
	public Point getLocation()
	{
		return location;
	}
	
	//Generates random start location for the coordinates
	public void setStartLocation()
	{

		int x = rng.nextInt(GRID_SIZE);
		int y = rng.nextInt(GRID_SIZE);
		location = new Point(x,y);
	}
	
/*
	public boolean isOnSquare(Point checkequal)
	{
		if (checkequal == null)
		{
			return false;
		}
		return location.x  == p.x && location.y == p.y;
	}
*/	
	//abstract move method
	public abstract void move();
}

