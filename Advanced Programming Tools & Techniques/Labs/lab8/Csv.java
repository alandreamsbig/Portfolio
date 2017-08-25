/**
  *This Csv program parses a csv file called test.csv
  *@author Alan Tsai
  *Date: 5/19/16
  */

import java.util.Scanner;
import java.io.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;

//Creates a Csv class
public class Csv
{
	public static void main(String[] args)
	{
		try{
			//read the csv file called test.csv
	BufferedReader Reader = new BufferedReader(new FileReader (new
				File("test.csv")));
	String currentline = Reader.readLine(); //read the lines in the file
		while (currentline != null)//get nextline until eof
		{
			String[] splitted =
				currentline.split(","); //split the strings with ","
			for (int i=0; i < splitted.length; i++)
         {
			System.out.println("field[" + i +  "]= " + splitted[i].trim());
			//print the field and exclude the white leading spaces
		
			}
			currentline = Reader.readLine();//read next line
		}
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}

