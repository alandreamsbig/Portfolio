//
//  hw1.cpp
//  CS430 HW1
//  This program takes in command line arguments, reads postscript(.ps) file
//  and output to XPM file format
//
//  Created by Alan Tsai  on 9/28/16.
//  Copyright © 2016 Alan Tsai. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*Fuction declaration for drawling*/
vector <vector < char > > drawline(vector< vector<int> > &points, vector <
		vector < char > > &pixels);

int main(int argc, char* argv[]) 
{

	string input;
	
	//Take command argument
	for(int i = 0; i < argc; i++)
	{
		string temp(argv[i]);

		if(temp.compare("-f")==0)
		{
			input = argv[i+1];
		}
	}

	//Read in postscript file
	ifstream file;
	file.open(input.c_str());
	string line;
	
	//Create 500x500 pixels
	vector <vector <char> > pixels(500, vector<char>(500));
	for (int i = 0; i < 500; ++i)
	{
		for(int j = 0; j < 500; ++j)
		{
			pixels[j][i] = 'w';
		}
	}

	 //Formating the XPM file headers
    cout << "/*XPM*/" << endl;
    cout << "/*width height num_colors chars_per_pixel*/" << endl;
    cout << "/*XPM*/" << endl;
    cout << "static char *sco100[] = {" << endl;
    cout << "/*width height num_colors chars_per_pixel*/" << endl;
    cout << "\"500 500 2 1\"," << endl;
	 cout << "/*colors*/" << endl;
    cout << "\"W c #ffffff\"," << endl;
    cout << "\"B c #010101\"," << endl;
    cout <<"/*pixels*/" << endl;

 	 //Create vector of points	 
    vector< vector <int> > points;
	
	 while(!file.eof())
	 {
		getline(file, line);
		if ( line.find("BEGIN") != string::npos )
		{
			getline(file,line);
			
			while(line.find("END") == string::npos)
			{
         //Get the the data points from the postscript file       
			int s1 = line.find(" ");
			string x1 = line.substr(0,s1);
			int s2 = line.find(" ", s1+1);
			string y1 = line.substr(s1+1, s2-(s1+1));
			int s3 = line.find(" ", s2+1);
			string x2 = line.substr(s2+1, s3-(s2+1));
			int s4 = line.find(" ", s3+1);
			string y2 = line.substr(s3+1, s4-(s3+1));
			getline(file, line);
			
			/*
			cout << "x1: " << x1 << endl;
			cout << "y1: " << y1 << endl;
			cout << "x2: " << x2 << endl;
			cout << "y2: " << y2 << endl;
			cout << endl;
			*/
			
			//Adding the points to the vector
			vector<int> elements;
			elements.push_back(atoi(x1.c_str()));
			elements.push_back(atoi(y1.c_str()));
			elements.push_back(atoi(x2.c_str()));
			elements.push_back(atoi(y2.c_str()));
			
			//Adding all the point sets to the vector
			points.push_back(elements);
			}
				//Call drawline function for drawing the lines
            drawline(points,pixels);
		}
	}
	cout << "};";
}

/*Drawline function computes the increments, slopes and points to be incremented*/
vector < vector< char > > drawline(vector< vector<int> > &points, vector < vector < char > > &pixels )
{
	//Getting the data points from the vector
	for(int i = 0; i < points.size(); i++)
	{
	float x1 = points[i][0];
	float y1 = points[i][1];
	float x2 = points[i][2];
	float y2 = points[i][3];
    
	//Check if it is a negative slope, then swap point values
	if(x2 < x1)
	{
		float temp = x1;
		x1 = x2;
		x2 = temp;

		float temp2 = y1;
		y1 = y2;
		y2 = temp2;
	}
	
	//Line computation
	float dx = x2 - x1;
	float dy = y2 - y1;
	float m = dy/dx;
	
	float deltaX;
	float deltaY;
   
   //If slope is greater than 1 use DDA Algorithm	
   while (m >= 1 && y1 < y2)
   {
     if (y2 > y1)
     {
       float temp3 = y1;
       y1 = y2;
       y2 = temp3;
                
		 float temp4 = x1;
       x1 = x2;
       x2 = temp4;
      }
            
      dx = x2 - x1;
      dy = y2 - y1;
      m = dy/dx;
            
      deltaX = 1/m;
      deltaY = 1;
            
           
      float xIncrement;
      float yIncrement;
            
            
       xIncrement = x1 + deltaX;
       yIncrement = y1 + deltaY;
            
       pixels[x1][y1] = 'B';
       x1 = xIncrement;
       y1 = yIncrement;
            
            
    }
	 		/*
    		while( abs(x2-x1) < 0.001 )
        {
            float xIncrement;
            float yIncrement;
            
            deltaX = 0;
            deltaY = dy;
            
            xIncrement = x1 + deltaX;
            yIncrement = y1 + deltaY;
            
            pixels[x1][y1] = 'B';
            x1 = xIncrement;
            y1 = yIncrement;
				pixels[x2][y2] = 'B';

        }
		  */
		
   while(x1 < x2 && m < 1)
   {
            float xIncrement;
            float yIncrement;
            
            deltaX = 1;
            deltaY = m;
            
            xIncrement = x1 + deltaX;
            yIncrement = y1 + deltaY;
            
            pixels[500-y1][x1] = 'B';
            x1 = xIncrement;
            y1 = yIncrement;
   }
    pixels[500-y2][x2] = 'B';
 }	
	
	
	for (int i = 0; i < 500; ++i)
	{
		cout << "\"";
		for(int j = 0; j < 500; ++j)
		{
			cout << pixels[i][j];
		}
		cout << "\",";
	}
	
   /*
	if (abs(dx) < 0.001)
	{
		deltaX = 0;
		deltaY = dy;
	}
   */ 
	
	return pixels;
}	
