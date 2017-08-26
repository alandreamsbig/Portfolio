/*********************
 * Main class
 * 
 * Handles the main menu selection for survey and test
 * 
 * @author Alan Tsai
 * @Since 2016-10-30
 */


import java.io.*;
import java.util.Scanner;

public class Main
{
	MenuLoop menu = new MenuLoop();

	public static void main(String[] args)
	{
		Main m = new Main();
		int choice = -1;
		
		
		do
		{
			m.menu1();
			try
			{
				choice = Integer.parseInt(Survey.scanner.nextLine());
				
				if (choice != 1 && choice != 2)
				{
					throw new NumberFormatException();
				}
			}
			catch(NumberFormatException e)
			{
				System.out.println("Wrong inuput entered. Please select 1 or 2");
				choice = -1;
			}
		
		
			switch (choice)
			{
			case 1:
				m.menu2S();
				choice = -1;
				break;
			case 2:
				m.menu2T();
				choice = -1;
				break;
			default:
				System.out.println("Invalid Input");
			}
		} while (choice != 1 && choice != 2);
	}
	
		public void menu1()
		{
			System.out.println("-------- Main Menu --------");
			System.out.println("1) Survey");
			System.out.println("2) Test"); 
			
		}
		
		public void menu2S()
		{
			int choice = -1;
			do 
			{
				System.out.println("1) Create a new Survey");
				System.out.println("2) Display a Survey");
				System.out.println("3) Load a Survey");
				System.out.println("4) Save a Survey");
				System.out.println("5) Modify an Existing Survey");
				System.out.println("6) Take a Survey");
				System.out.println("7) Tabulate a Survey");
				System.out.println("8) Return to main menu");
				choice = menu.MenuSelect("Survey");
			}while(choice != 8);
			
		}
		
		public void menu2T()
		{
			int choice = -1;
			do
			{
				System.out.println("1) Create a new Test");
				System.out.println("2) Display a Test");
				System.out.println("3) Load a Test");
				System.out.println("4) Save a Test");
				System.out.println("5) Modify an Existing Test");
				System.out.println("6) Take a Test");
				System.out.println("7) Tabulate a Test");
				System.out.println("8) Grade a Test");
				System.out.println("9) Return to main menu");
				choice = menu.MenuSelect("Test");
			}while(choice != 9);
		}
	
}