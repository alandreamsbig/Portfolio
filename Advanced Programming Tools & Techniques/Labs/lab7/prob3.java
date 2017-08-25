//LeapYear(Prob3)
//Alan Tsai

import java.io.*;

public class prob3
{
	public static void main( String[] argv)
	{
		String s = argv[0];
		int year = Integer.parseInt(s);
		boolean LeapYear;

			LeapYear = ((year % 4 ==0) && (year % 100 !=0) || (year % 400==0));

			if (LeapYear)
			{
				System.out.println("leap year!");
			}
			else
			{
				System.out.println("not a leap year!");
			}
	}
}

