//Even Or Odd(Prob2)
//Alan Tsai

import java.io.*;


public class prob2
{
	public static void main( String[] argv)
	{
		String s = argv[0];
		int l = Integer.parseInt(s);
		if ((l % 2) == 0 )
		{
			System.out.println("even");
		}
		else
		{
			System.out.println("odd");
		}
	}
}	
