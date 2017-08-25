/**
  *This is a cat class generates random moves for the cat and checks for 
  *valid moves
  *@author Alan Tsai
  *Date:5/18/16
  */

import java.io.*;
import java.awt.Point;
import java.util.Random;

public class Cat extends Animal {
	
	//set the random move for directions of North, South, East, West
	protected int RANDOM_MOVE = 4;
	
	//Constructor for the Cat class
	public Cat(String name, Random rng)
	{
		super(name, rng);
	}

	public void move(){

		Point original = location; //save original location

		//Checks if the random generated moves are valid or not, the cat
		//should not be off the island
		int move = rng.nextInt(RANDOM_MOVE);
		  while (move == 0 && location.getY() == 0 || move == 1 && location.getY() == 6 || 
				  move == 2 && location.getX() == 6 || move == 3 && location.getX() == 0)
	      {
	          move = rng.nextInt(RANDOM_MOVE); //generate new random moves if it's not a valid move
	      }

      //The moving of the cat with x, y coordinates 
		if (move == 0)
		{
			location.translate(0, -1);
		}
		else if (move == 1){
			location.translate(0, 1);
		}
		else if (move == 2){
			location.translate(1, 0);
		}
		else if (move == 3){
			location.translate(-1,0);
		} 

		if (location.x == 0 || location.x == 6 || location.y == 0 || location.y == 6){
			location = original;

		}
	}
	/*
	private boolean isLegal(Point p)
	{
		if (p 
		{		
			return false;
		}
	}

	prvtivate List<Point> getValidMoves()
	{
		List<Point> moves = new ArrayList<Point>();

		Point p = new Point(location.x, location.y - 1);
		Point p1 = new Point(location.x, location.y + 1);
		Point p2 = new Point(location.x -1, location.y);
		Point p3 = new Point(location.x + 1, location.y);

		if(!isLegal(p))
		{
			moves.add(p);
		}
		if(!isLegal(p1))
		{
			moves.add(p1);
		}
		if(!isLegal(p2))
		{
			moves.add(p2);
		}
		if(!isLegal(p3))
		{
			moves.add(p3);
		}
	}
*/
}

