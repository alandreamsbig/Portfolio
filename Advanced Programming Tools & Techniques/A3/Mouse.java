/**
  *This is a Mouse class containing the mouse moves and checks if it is a
  *valid move or not
  *@author Alan Tsai
  *Date: 5/18/16
  */

import java.io.*;
import java.util.Random;
import java.awt.Point;

public class Mouse extends Animal {

	protected int RANDOM_MOVE = 4;
	
	//Constructor for the Mouse class
	public Mouse(String name, Random rng)
	{
		super(name, rng);
	}
	
	//Checks if the random generated moves are valid
	public void move(){

		int move = rng.nextInt(RANDOM_MOVE);
		while (move == 0 && location.getY() == 0 || move == 1 && location.getY()
				== 6 || move == 2 && location.getX() == 6 || move == 3 &&
				location.getX() == 0)
		{
			move = rng.nextInt(RANDOM_MOVE);//Generated new moves if it's not valid
		}

		//The move of Mouse, change in x, y coordinates
		if (move == 0)
		{
			location.translate(0,-1);
			
		}
		else if (move == 1) {
			location.translate(0,1);
		}
		else if (move == 2) {

			location.translate(1,0);
		}
		else if (move == 3) {

			location.translate(-1,0);
		}
	}
}
