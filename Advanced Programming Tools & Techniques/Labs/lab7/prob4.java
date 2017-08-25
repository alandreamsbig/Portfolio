//GeekWatch(Prob4)
//Alan Tsai

import java.io.*;
import java.time.Instant;

public class prob4
{
	public static void main( String[] argv)
	{
		String s = argv[0];
		int input = Integer.parseInt(s);

		switch(input)
		{
			case 1 :
				long seconds = Instant.now().getEpochSecond();
				long milliseconds = seconds*1000;
				System.out.println("milliseconds since January 1, 1970: " + milliseconds);
				break;
			case 2:
				long second = Instant.now().getEpochSecond();
				System.out.println("seconds since January 1, 1970: " + second);
				break;
			case 3:
				long sec = Instant.now().getEpochSecond();
				long days = sec/86400;
				System.out.println("days since January 1, 1970: " + days);
			   break;
			case 4:
				Instant timestamp = Instant.now();
				System.out.println("Current date and time: " + timestamp);
				break;	
			default:
				System.out.println("Error: Choose correct number");
		}
	}
}

				
