/**
  *This is a Chase class that compares the coordinates of cat and mouse,
  *checks if the mouse in in the water or on the bridge, generates 30 random
  *plays of the game
  *@author Alan Tsai
  *Date 5/18/16
  */
import java.io.*;
import java.util.Random;
import java.awt.Point;

public class Chase
{
	//declare variables for counting the total time the event happened
	private static double totalEscaped = 0;
	private static double totalDrowned = 0;
	private static double totalCatEat = 0;

	//The playGame function which plays the game
	public static void playGame()
	{
	Random rnd = new Random();
	Cat cat = new Cat("cat", rnd);
	Mouse  mouse = new Mouse("mouse", rnd);
	
	int countEscaped = 0;
	int countDrowned = 0;
	int countCatEat = 0;

	//While the cat location and the mouse location are not on the same coordinates
	while(!cat.getLocation().equals(mouse.getLocation())) 
		{
		mouse.move(); //mouse moves first
		Point location = mouse.getLocation(); //get the location of the mouse

		//Checks if the mouse is on the bridge
		if ((location.x == 2 && location.y == 0)||(location.x == 4  && location.y == 0) || (location.x == 2 && location.y == 6) ||
				(location.x == 4 && location.y == 6) || (location.x == 0 && location.y == 2) || (location.x == 0 && location.y == 4) || 
				(location.x == 6 && location.y == 2) && (location.x == 6 && location.y == 4))
			   {  
					System.out.println("mouse escaped");
					countEscaped++;
					break;
				}
		//Checks if the mouse is on the island
		else if ( location.x <= 5 && location.y <=5 && location.x >= 1 && location.y >= 1)
					{
				      //do nothing
				   }
		//If it is not on the island and not on the bridge, then it is in the water
		else
				{
					System.out.println("mouse drowned");
					countDrowned++;
					break;
				}
		
		//cat moves next
		cat.move();

		//checks if the cat and the mouse have the same coordinates
		if (cat.getLocation().equals(mouse.getLocation()))
			{
				System.out.println("cat had a snack");
				countCatEat++;
			}
		}
	
	//count the total percentage of the event occured
	totalEscaped += (((double)countEscaped/30.0)*100.0);
	totalDrowned += (((double)countDrowned/30.0)*100.0);
	totalCatEat += (((double)countCatEat/30.0)*100.0);
	}

	//Generates 30 times of different playgame
	public static void main( String [] argv )
	{
		for (int i = 0; i < 31; i++)
		{
		playGame();
		}

		System.out.println(" ");
		System.out.println("Mouse escaped: " + totalEscaped + "%");
		System.out.println("Mouse drowned: " + totalDrowned + "%");
		System.out.println("Cat had a snack: " + totalCatEat + "%");
		System.out.println(" ");
	}
}
