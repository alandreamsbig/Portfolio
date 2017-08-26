//
//  hw2.cpp
//  CS430 HW1
//  This program takes in command line arguments, reads postscript(.ps) file
//  and output to XPM file format
//
//  Created by Alan Tsai  on 9/28/16.
//  Copyright © 2016 Alan Tsai. All rights reserved.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*Fuction declaration for drawling*/
vector <vector < char > > drawline(vector < vector < vector <int> > > &points, vector < vector < char > > &pixels);
void LineClip(float *x1, float *y1, float *x2, float *y2);
void scanFill(vector <vector < vector <int> > > &points, vector < vector < char > > &pixels);
void affineTransform(vector < vector < vector <int> > > &points, vector <vector <char > > &pixels);
vector < vector <float> > pointPass(vector < vector <float> > T, vector < vector <float> > P);
vector < vector <float> > translation( 3, vector<float> (3));
vector < vector <float> > initial_point(3, vector<float> (3));
vector < vector <float> > scale(3, vector<float> (3));
vector < vector <float> > rotation(3, vector<float> (3));
vector < vector <float> > viewportscale(3, vector<float>(3));
vector < vector <float> > viewportorigin(3, vector<float>(3));
vector < vector <float> > viewportback(3,vector<float>(3));
vector < vector <float> > i_point(3,vector<float> (3));
float scaling_factor = 1.0;
float degree = 0;
float x_translate = 0;
float y_translate = 0;
float lowerX = 0;
float lowerY = 0;
float upperX = 499;
float upperY = 499;
float lowerX_viewport = 0;
float lowerY_viewport = 0;
float upperX_viewport = 499;
float upperY_viewport = 499;



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
		else if(temp.compare("-s") == 0)
		{
			scaling_factor = atof(argv[i+1]);
			cout << scaling_factor << endl;
		}
		else if (temp.compare("-r") == 0)
		{
			degree = atoi(argv[i+1]);
			//cout << degree << endl;
		}
		else if (temp.compare("-m") == 0)
		{
			x_translate = atoi(argv[i+1]);
		}

		else if (temp.compare("-n") == 0)
		{
			y_translate = atoi(argv[i+1]);
			//cout << y_translate << endl;
		}
		else if (temp.compare("-a") == 0)
		{
			lowerX = atoi(argv[i+1]);
			//cout << lowerX << endl;
		}
		else if (temp.compare("-b") == 0)
		{
			lowerY = atoi(argv[i+1]);
		}
		else if (temp.compare("-c") == 0)
		{
			upperX = atoi(argv[i+1]);
		}
		else if (temp.compare("-d") == 0)
		{
			upperY = atoi(argv[i+1]);
		}
		else if (temp.compare("-j") == 0)
		{
			lowerX_viewport = atoi(argv[i+1]);
		}
		else if (temp.compare("-k") == 0)
		{
			lowerY_viewport = atoi(argv[i+1]);
		}
		else if (temp.compare("-o") == 0)
		{
			upperX_viewport = atoi(argv[i+1]);
		}
		else if (temp.compare("-p") == 0)
		{
			upperY_viewport = atoi(argv[i+1]);
		}

	}

	//Read in postscript file
	ifstream file;
	file.open(input.c_str());
	string line;
	
	//Create 500x500 buffer
	vector <vector <char> > pixels(500, vector<char>(500));
	for (int i = 0; i < 500; ++i)
	{
		for(int j = 0; j < 500; ++j)
		{
			pixels[j][i] = 'W';
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
    vector< vector < vector <int> > > points;

	 while(!file.eof())
	 {
		vector < vector <int> > elements;
		getline(file, line);

		if ( line.find("BEGIN") != string::npos )
		{
			getline(file,line);
			string x1 = "null";	
			string y1 = "null";
			string x2 = "null";
			string y2 = "null";
			
			while(line.find("END") == string::npos)
			{
				if (line.find("stroke") != string::npos)
				{
					getline(file,line);
					x1 = "null";
					y1 = "null";
					
					//vector < vector < int > > elements;
					points.push_back(elements);				
				}
				else if(line.length() > 1)
				{
					if (line.find("moveto") != string::npos)
					{
							int a = line.find(" ");
							x1 = line.substr(0,a);
							int b = line.find(" ", a+1);
							y1 = line.substr(a+1, b-(a+1));
							getline(file,line);
							a = line.find(" ");
							x2 = line.substr(0,a);
							b = line.find(" ", a+1);
							y2 = line.substr(a+1, b-(a+1));
					}
					else 	if (line.find("lineto") != string::npos)
					{
					
						x1 = x2;
						y1 = y2;
					
						//Get the the data points from the postscript file       
						int s1 = line.find(" ");
						x2 = line.substr(0,s1);
						int s2 = line.find(" ", s1+1);
						y2 = line.substr(s1+1, s2-(s1+1)); 
					}
					getline(file,line);


					vector < int > polyline;
					polyline.push_back(atoi(x1.c_str()));
					polyline.push_back(atoi(y1.c_str()));
					polyline.push_back(atoi(x2.c_str()));
			     	polyline.push_back(atoi(y2.c_str()));
					elements.push_back(polyline);
				
					//cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2 " << y2 << endl;
				}
				else
				{
					getline(file,line);
				}
			
			}
			
	affineTransform(points, pixels);	
/*	
	viewportscale[0][0] = (upperX_viewport - lowerX_viewport)/(upperX-lowerX);
	viewportscale[0][1] = 0;
	viewportscale[0][2] = 0;
	viewportscale[1][0] = 0;
	viewportscale[1][1] = (upperY_viewport - lowerY_viewport)/(upperY- lowerY);
	viewportscale[1][2] = 0;
	viewportscale[2][0] = 0;
	viewportscale[2][1] = 0;
	viewportscale[2][2] = 1;

	viewportorigin[0][0] = 1;
	viewportorigin[0][1] = 0;
	viewportorigin[0][2] = -lowerX;
	viewportorigin[1][0] = 0;
	viewportorigin[1][1] = 1;
	viewportorigin[1][2] = -lowerY;
	viewportorigin[2][0] = 0;
	viewportorigin[2][1] = 0;
	viewportorigin[2][2] = 1;
	
	viewportback[0][0] = 1;
	viewportback[0][1] = 0;
	viewportback[0][2] = lowerX_viewport;
	viewportback[1][0] = 0;
	viewportback[1][1] = 1;
	viewportback[1][2] = lowerY_viewport;
	viewportback[2][0] = 0;
	viewportback[2][1] = 0;
	viewportback[2][2] = 1;


	for(int i = 0; i <points.size(); i++)
	{
		vector < vector <int> >elements = points[i];
		
		for (int j = 0; j < elements.size(); j++)
		{

			float x1 = points[i][j][0];
			float y1 = points[i][j][1];
			float x2 = points[i][j][2];
			float y2 = points[i][j][3];
			LineClip(&x1,&y1,&x2,&y2);

			i_point[0][0] = 1;
			i_point[0][1] = 0;
			i_point[0][2] = x1;
			i_point[1][0] = 0;
			i_point[1][1] = 1;
			i_point[1][2] = y1;
			i_point[2][0] = 0;
			i_point[2][1] = 0;
			i_point[2][2] = 1;
			
			vector < vector <float> > s(3,vector <float> (1));
			vector < vector <float> > s1(3,vector <float> (1));
			vector < vector <float> > s2(3,vector <float> (1));
			
			s = pointPass(viewportorigin,i_point);
			s1 = pointPass(viewportscale,s);
			s2 = pointPass(viewportback,s1);
			
			points[i][j][0]= s2[0][2];
			points[i][j][1]= s2[1][2]; 


			//float x2 = points[i][j][2];
			//float y2 = points[i][j][3];
			
			i_point[0][0] = 1;
			i_point[0][1] = 0;
			i_point[0][2] = x2;
			i_point[1][0] = 0;
			i_point[1][1] = 1;
			i_point[1][2] = y2;
			i_point[2][0] = 0;
			i_point[2][1] = 0;
			i_point[2][2] = 1;	
			
			vector < vector <float> > r(3,vector <float> (1));
			vector < vector <float> > r1(3,vector <float> (1));
			vector < vector <float> > r2(3,vector <float> (1));

			r = pointPass(viewportorigin,i_point);
			r1 = pointPass(viewportscale,r);
			r2 = pointPass(viewportback,r2);
			
			points[i][j][2] = r2[0][2];
		  	points[i][j][3] = r2[1][2];	
			
		//	LineClip(&x1,&y1,&x2,&y2);
		}

		
	}*/
			drawline(points,pixels);
			scanFill(points,pixels);
			
			for (int i = 0; i < 500; ++i)
			{
				cout << "\"";
				for(int j = 0; j < 500; ++j)
				{
					cout << pixels[i][j];
				}
				cout << "\",";
			}	
			
		}
	}
		

	cout << "};";
}

void affineTransform(vector < vector < vector <int> > > &points, vector < vector <char > > &pixels)
{
	
	translation[0][0] = 1;
	translation[0][1] = 0;
	translation[0][2] = x_translate;
	translation[1][0] = 0;
	translation[1][1] = 1;
	translation[1][2] = y_translate;
	translation[2][0] = 0;
	translation[2][1] = 0;
	translation[2][2] = 1;

	scale[0][0] = scaling_factor;
	scale[0][1] = 0;
	scale[0][2] = 0;
	scale[1][0] = 0;
	scale[1][1] = scaling_factor;
	scale[1][2] = 0;
	scale[2][0] = 0;
	scale[2][1] = 0;
	scale[2][2] = 1;

	rotation[0][0] = cos((degree*M_PI)/180);
	rotation[0][1] = -sin((degree*M_PI)/180);
	rotation[0][2] = 0;
	rotation[1][0] = sin((degree*M_PI)/180);
	rotation[1][1] = cos((degree*M_PI)/180);
	rotation[1][2] = 0;
	rotation[2][0] = 0;
	rotation[2][1] = 0;
	rotation[2][2] = 1;

	viewportscale[0][0] = (upperX_viewport - lowerX_viewport)/(upperX-lowerX);
	viewportscale[0][1] = 0;
	viewportscale[0][2] = 0;
	viewportscale[1][0] = 0;
	viewportscale[1][1] = (upperY_viewport - lowerY_viewport)/(upperY- lowerY);
	viewportscale[1][2] = 0;
	viewportscale[2][0] = 0;
	viewportscale[2][1] = 0;
	viewportscale[2][2] = 1;

	viewportorigin[0][0] = 1;
	viewportorigin[0][1] = 0;
	viewportorigin[0][2] = -lowerX;
	viewportorigin[1][0] = 0;
	viewportorigin[1][1] = 1;
	viewportorigin[1][2] = -lowerY;
	viewportorigin[2][0] = 0;
	viewportorigin[2][1] = 0;
	viewportorigin[2][2] = 1;
	
	viewportback[0][0] = 1;
	viewportback[0][1] = 0;
	viewportback[0][2] = lowerX_viewport;
	viewportback[1][0] = 0;
	viewportback[1][1] = 1;
	viewportback[1][2] = lowerY_viewport;
	viewportback[2][0] = 0;
	viewportback[2][1] = 0;
	viewportback[2][2] = 1;


	
	vector < vector <float> > origin(3,vector<float> (3));
	vector < vector <float> > back(3, vector<float> (3));

	for(int i = 0; i <points.size(); i++)
	{
		vector < vector <int> >elements = points[i];
		float xt = points[i][0][0];
		float yt = points[i][0][1];		
		
		for (int j = 0; j < elements.size(); j++)
		{
			float x1 = points[i][j][0];
			float y1 = points[i][j][1];
			
			initial_point[0][0] = 1;
			initial_point[0][1] = 0;
			initial_point[0][2] = x1;
			initial_point[1][0] = 0;
			initial_point[1][1] = 1;
			initial_point[1][2] = y1;
			initial_point[2][0] = 0;
			initial_point[2][1] = 0;
			initial_point[2][2] = 1;
		
			
			origin[0][0] = 1;
			origin[0][1] = 0;
			origin[0][2] = -xt;
			origin[1][0] = 0;
			origin[1][1] = 1;
			origin[1][2] = -yt;
			origin[2][0] = 0;
			origin[2][1] = 0;
			origin[2][2] = 1;
			
			back[0][0] = 1;
			back[0][1] = 0;
			back[0][2] = xt;
			back[1][0] = 0;
			back[1][1] = 1;
			back[1][2] = yt;
			back[2][0] = 0;
			back[2][1] = 0;
			back[2][2] = 1;

			vector < vector <float> > a(3,vector <float> (1));
			vector < vector <float> > a1(3,vector <float> (1));
			vector < vector <float> > a2(3,vector <float> (1));
			vector < vector <float> > a3(3,vector <float> (1));
			vector < vector <float> > a4(3,vector <float> (1));
			
			
			a = pointPass(origin,initial_point);
			a1 = pointPass(scale, a);
			a2 = pointPass(rotation, a1);
			a3 = pointPass(translation,a2);
			a4 = pointPass(back, a3);
			
		
			points[i][j][0] = a4[0][2];
			points[i][j][1] = a4[1][2];
			
			float x2 = points[i][j][2];
			float y2 = points[i][j][3];
		
			initial_point[0][0] = 1;
			initial_point[0][1] = 0;
			initial_point[0][2] = x2;
			initial_point[1][0] = 0;
			initial_point[1][1] = 1;
			initial_point[1][2] = y2;
			initial_point[2][0] = 0;
			initial_point[2][1] = 0;
			initial_point[2][2] = 1;

			origin[0][0] = 1;
			origin[0][1] = 0;
			origin[0][2] = -xt;
			origin[1][0] = 0;
			origin[1][1] = 1;
			origin[1][2] = -yt;
			origin[2][0] = 0;
			origin[2][1] = 0;
			origin[2][2] = 1;

			back[0][0] = 1;
			back[0][1] = 0;
			back[0][2] = xt;
			back[1][0] = 0;
			back[1][1] = 1;
			back[1][2] = yt;
			back[2][0] = 0;
			back[2][1] = 0;
			back[2][2] = 1;
			
			
			vector < vector <float> > p(3,vector <float> (1));
			vector < vector <float> > p1(3,vector <float> (1));
			vector < vector <float> > p2(3,vector <float> (1));
			vector < vector <float> > p3(3,vector <float> (1));
			vector < vector <float> > p4(3,vector <float> (1));
			
			
			p = pointPass(origin, initial_point);
			p1 = pointPass(scale, p);
			p2 = pointPass(rotation, p1);
			p3 = pointPass(translation,p2);
			p4 = pointPass(back,p3);
			
			points[i][j][2] = p4[0][2];
			points[i][j][3] = p4[1][2];
		}
	}	
}

vector < vector <float> > pointPass(vector < vector <float> > T, vector< vector <float> > P )
{
	//vector < vector <float> > Trans(3, vector <float> (3));
	//vector < vector <float> > Point(3, vector <float> (3));
	vector < vector <float> > pointPrime(3, vector <float> (3));
/*	
	for(int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
			{
				cout << T[row][col] << " ";
			}
			cout << endl;
	}

	for(int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
			{
				cout << P[row][col] << " ";
			}
			cout << endl;
	}

*/	
	for(int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			for(int inner = 0; inner < 3; inner++)
			{
			 pointPrime[row][col] += T[row][inner]*P[inner][col];
			}
			
			
		}
	}
/*
	for(int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
			{
				cout << pointPrime[row][col] << " ";
			}
			cout << endl;
	}
	cout << endl;*/
	return pointPrime;	
}


void scanFill(vector <vector < vector <int> > > &points, vector < vector < char > > &pixels)
{
	vector <int> intersects;
	
	for(int i = 0; i <points.size(); i++)
	{
		for (int k = 0; k < 500; k++)
		{	
			vector<int> intersects;
			vector < vector <int> >elements = points[i];
			for (int j = 0; j < elements.size(); j++)
			{
				float x1 = points[i][j][0];
				float y1 = points[i][j][1];
				float x2 = points[i][j][2];
				float y2 = points[i][j][3];
             
				LineClip(&x1,&y1,&x2,&y2);
				
				float ymin, ymax, extrema;
				if(y1 > y2){
					ymax = y1;
					ymin = y2;
				}
				if(y2 > y1){
					ymax = y2;
					ymin = y1;
				}
				if(y1== y2){
					ymax = y1;
					ymin = y2;
				}
				if(ymax == k)
				{
					continue;	
				}	
				if (ymax > 499 || ymin > 499)
				{
					extrema = 499;
				}
				else if (ymax < 0 || ymin < 0)
				{
					extrema = 0;
				}

				//cout << "ymax: " << ymax << " ymin: " << ymin << endl;
				if (k >= ymin && k <= ymax){
				   	float dy = y2 - y1;
						float dx = x2 - x1;
						float m;
						float b;
						
						if(ymax == ymin){
							m = 0;
							b = k;
							//extrema = x2;
							continue;
						}
						else if ( x1 == x2){
							extrema = x1; 
						}
						else{
						
							m = dy/dx;
							b = y2 - (m*x2);	
							extrema  = (k - (b)) /(m);
						}
					//cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2 " << y2 << endl;
					intersects.push_back(extrema);
				}

				sort(intersects.begin(), intersects.end());
			}
			if (intersects.size() > 0){
			bool bit = false;
			float currentExtrema = 0;
			
			for (int s = intersects[0]; s < intersects[intersects.size()-1];s++){
					//cout << "loop here" << endl;
					while(intersects[currentExtrema] == s){
						//cout << j <<endl;
						bit = !bit;
						currentExtrema++;
					}
					if(bit){
						pixels[499-k][s] = 'B';
						//cout << s << " " << k << endl;
					}
				}
			}
		}
	
	}
}
/*Drawline function computes the increments, slopes and points to be incremented*/
vector < vector< char > > drawline(vector< vector < vector <int> > >
		&points, vector < vector < char > > &pixels )
{
	//Getting the data points from the vector
	for(int i = 0; i <points.size(); i++)
	{
		vector < vector <int> >elements = points[i];
		for (int j = 0; j < elements.size(); j++)
		{
	float x1 = points[i][j][0];
	float y1 = points[i][j][1];
	float x2 = points[i][j][2];
	float y2 = points[i][j][3];
	

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

	LineClip(&x1,&y1,&x2,&y2);

	//Line computation
	float dx = x2 - x1;
	float dy = y2 - y1;
	float m = dy/dx;
	float deltaX;
	float deltaY;



	if (x1 == x2)
	{
			if (y2 < y1)
     		{
       	float temp3 = y1;
       	y1 = y2;
       	y2 = temp3;
                
		 	float temp4 = x1;
       	x1 = x2;
       	x2 = temp4;
      	}

		while(y1 < y2)
		{

			float xIncrement;
         float yIncrement;
            
         deltaX = 0;
         deltaY = 1;
            
         xIncrement = x1 + deltaX;
         yIncrement = y1 + deltaY;
            
         pixels[499-y1][x1] = 'B';
         x1 = xIncrement;
         y1 = yIncrement;
		}
	}
	else if (abs(m) > 1)
	{
		if (y2 < y1)
     	{
       	float temp3 = y1;
       	y1 = y2;
       	y2 = temp3;
                
		 	float temp4 = x1;
       	x1 = x2;
       	x2 = temp4;
      }
      while (y1 < y2)
		{		 
      	dx = x2 - x1;
      	dy = y2 - y1;
      	m = dy/dx;
            
      	deltaX = 1/m;
      	deltaY = 1;
            
 		          
      	float xIncrement;
      	float yIncrement;
            
      	xIncrement = x1 + deltaX;
      	yIncrement = y1 + deltaY;
            
      	pixels[499-y1][x1] = 'B';
     		x1 = xIncrement;
      	y1 = yIncrement;
		}
	}
	else
	{
		while(x1 < x2)
		{
			float xIncrement;
         float yIncrement;
            
         deltaX = 1;
         deltaY = m;
            
         xIncrement = x1 + deltaX;
         yIncrement = y1 + deltaY;
            
         pixels[499-y1][x1] = 'B';
         x1 = xIncrement;
         y1 = yIncrement;
   	}
    pixels[499-y2][x2] = 'B';
	}
	}
	}


/*
	for (int i = 0; i < 500; ++i)
	{
		cout << "\"";
		for(int j = 0; j < 500; ++j)
		{
			cout << pixels[i][j];
		}
		cout << "\",";
	}
*/	
	
	return pixels;
}


/*code reference: https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm*/
typedef int Out;

const int Inside = 0;
const int Left = 1;
const int Right = 2;
const int Bottom = 4;
const int Top = 8;

Out ComputeOut(double x, double y)
{
	Out code = Inside;
	if ( x < 0)
		code |= Left;
	else if(x > 500)
		code |= Right;
	if (y < 0)
		code |= Bottom;
	else if ( y > 500)
		code |= Top;
	
	return code;
}

void LineClip(float *x1, float *y1, float *x2, float *y2)
{
	Out out0 = ComputeOut(*x1, *y1);
	Out out1 = ComputeOut(*x2, *y2);
	bool check = false;
	
	
	while(true)
	{
		if (!(out0 | out1))
		{
			check = true;
			break;
		}
		else if (out0 & out1)
		{
			
			*x1 = 0;
			*y1 = 0;
			*x2 = 30;
			*y2 = 0;
			break;
		}
		else
		{
			float x, y;

			Out outside = out0 ? out0 : out1;

			if (outside & Top)
			{
				x = *x1 + (*x2 - *x1) * ((500-1) - *y1) / (*y2 - *y1);
				y = 500-1;
			}
			else if (outside & Bottom)
			{
				x = *x1 + (*x2 - *x1) * (0 - *y1) / (*y2 - *y1);
			  	y = 0;
			}
			else if (outside & Right)
			{
				y = *y1 + (*y2 - *y1) * ((500-1) - *x1) / (*x2 - *x1);
				x = 500-1;
			}
			else if (outside & Left)
			{
			 	y = *y1 + (*y2 - *y1) * (0 - *x1) / (*x2 - *x1);
				x = 0;
			}
			else if ((outside & Top) && (outside & Bottom) && (outside & Left)
					&& outside & Right)
			{
				y = 0;
				x = 0;
			}

			if (outside == out0)
			{
				*x1 = x;
			 	*y1 = y;
				out0 = ComputeOut(*x1, *y1);
			}
			else
			{
				*x2 = x;
				*y2 = y;
				out1 = ComputeOut(*x2, *y2);
			}

		}
	}
}
	
