//
//  hw6.cpp
//  CS430 HW6
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
vector <vector < char > > drawline(vector < vector < vector <int> > > &triSets, vector < vector < char > > &pixels);
void LineClip(float *x1, float *y1, float *x2, float *y2);
void scanFill(vector <vector < vector <int> > > &triSets, vector < vector < char > > &pixels);
vector < vector <float> > pointPass(vector < vector <float> > T, vector <vector <float> > P);
vector < vector <float> > translation( 3, vector<float> (3));
vector < vector <float> > initial_point(3, vector<float> (3));
vector < vector <float> > scale(3, vector<float> (3));
vector < vector <float> > v_trans(3, vector<float> (3));
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
float xPRP = 0;
float yPRP = 0;
float zPRP = 1;
float xVRP = 0;
float yVRP = 0;
float zVRP = 0;
float xVPN = 0;
float yVPN = 0;
float zVPN = -1;
float xVUP = 0;
float yVUP = 1;
float zVUP = 0;
float uMin = -0.7;
float vMin = -0.7;
float uMax = 0.7;
float vMax = 0.7;
float front = 0.6;
float back = -0.6;
vector <float> VPN;
vector <float> VUP;
void projection(vector < vector <float> > &vertex, vector< vector <float> >
		&f, vector < vector < char > > &pixels);
vector< vector < vector <int> > > triSets;
bool green = true;
bool blue = true;


int main(int argc, char* argv[]) 
{

	string input;
	string file2;
	string file3;
	//Take command argument
	for(int i = 0; i < argc; i++)
	{
		string temp(argv[i]);

		if(temp.compare("-f")==0)
		{
			input = argv[i+1];
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
		else if(temp.compare("-x") == 0)
		{
			xPRP = atof(argv[i+1]);
		}
		else if (temp.compare("-y") == 0)
		{
			yPRP = atoi(argv[i+1]);
			//cout << degree << endl;
		}
		else if (temp.compare("-z") == 0)
		{
			zPRP = atoi(argv[i+1]);
		}

		else if (temp.compare("-X") == 0)
		{
			xVRP = atoi(argv[i+1]);
			//cout << y_translate << endl;
		}
		else if (temp.compare("-Y") == 0)
		{
			yVRP = lowerX = atoi(argv[i+1]);
			//cout << lowerX << endl;
		}
		else if (temp.compare("-Z") == 0)
		{
			zVRP = atoi(argv[i+1]);
		}
		else if (temp.compare("-q") == 0)
		{
			xVPN = atoi(argv[i+1]);
		}
		else if (temp.compare("-r") == 0)
		{
			yVPN = atoi(argv[i+1]);
		}
		else if (temp.compare("-w") == 0)
		{
			zVPN = atoi(argv[i+1]);
		}
		else if (temp.compare("-Q") == 0)
		{
			xVUP = atoi(argv[i+1]);
		}
		else if (temp.compare("-R") == 0)
		{
			yVUP = atoi(argv[i+1]);
		}
		else if (temp.compare("-W") == 0)
		{
			zVUP = atoi(argv[i+1]);
		}
		else if (temp.compare("-u") == 0)
		{
			uMin = atoi(argv[i+1]);
		}
		else if (temp.compare("-v") == 0)
		{
			vMin = atoi(argv[i+1]);
		}
		else if (temp.compare("-U") == 0)
		{
			uMax = atoi(argv[i+1]);
		}
		else if (temp.compare("-V") == 0)
		{
			vMax = atoi(argv[i+1]);
		}
		else if (temp.compare("-g") == 0)
		{
			green = true;
			file2 = argv[i+1];
		}
		else if (temp.compare("-b") == 0)
		{
			blue = true;
			file3 = argv[i+1];
		}


	}

	//Read in postscript file
	ifstream file;
	file.open(input.c_str());

	string line;
	
	//Create 500x500 buffer
	vector <vector <char> > pixels(500, vector<char>(500));
	vector < vector <int> > zBuffer(500,vector<int> (500));
	for (int i = 0; i < 500; ++i)
	{
		for(int j = 0; j < 500; ++j)
		{
			pixels[j][i] = 'W';
			zBuffer[j][i] = -1;
		}
	}

    cout << "/*XPM*/" << endl;
    cout << "/*width height num_colors chars_per_pixel*/" << endl;
    cout << "/*XPM*/" << endl;
    cout << "static char *sco100[] = {" << endl;
    cout << "/*width height num_colors chars_per_pixel*/" << endl;
    cout << "\"500 500 2 1\"," << endl;
	 cout << "/*colors*/" << endl;
    cout << "\"W c #010101\"," << endl;
    cout << "\"B c #ff0000\"," << endl;
    cout <<"/*pixels*/" << endl;

 	 //Create vector of points	 
    vector< vector < vector <int> > > points;
	 
	 vector < vector <float> > vertex;
	 vector < vector <float> > f;

	 while(!file.eof())
	 {
		//vector < vector <int> > vertex;
		getline(file, line);

		string x1 = "null";
		string y1 = "null";
		string z1 = "null";
		string f1 = "null";
		string f2 = "null";
		string f3 = "null";
	
		vector <float> vertexPoint;	
		vector<float> fIndex;

		if (line.find("v") != string::npos)
		{
			int a = line.find(" ");
			int b = line.find(" ", a+1);
			x1 = line.substr(a+1, b-(a+1));
			int c = line.find(" ", b+1);
			y1 = line.substr(b+1, c-(b+1));
			int d = line.find(" ", c+1);
			z1 = line.substr(c+1, line.length()-(c+1));
			
			vertexPoint.push_back(atof(x1.c_str()));
			vertexPoint.push_back(atof(y1.c_str()));
			vertexPoint.push_back(atof(z1.c_str()));
			
			vertex.push_back(vertexPoint);
		}
		else 	if (line.find("f") != string::npos)
		{
					
			int s1 = line.find(" ");
			int s2 = line.find(" ", s1+1);
			f1 = line.substr(s1+1,s2-(s1+1));
			int s3 = line.find(" ", s2+1);
			f2 = line.substr(s2+1, s3-(s2+1));
			int s4 = line.find(" ", s3+1);
			f3 = line.substr(s3+1,line.length()-(s3+1));
			
			fIndex.push_back(atof(f1.c_str()));
			fIndex.push_back(atof(f2.c_str()));
			fIndex.push_back(atof(f3.c_str()));

			f.push_back(fIndex);
		}
			

	}
	
		projection(vertex,f,pixels);		
		drawline(triSets,pixels);
		scanFill(triSets,pixels);
		
			
			for (int i = 0; i < 500; ++i)
			{
				cout << "\"";
				for(int j = 0; j < 500; ++j)
				{
					cout << pixels[i][j];
				}
				cout << "\",";
			}	
		
	
	cout << "};";
}

void projection(vector < vector <float> > &vertex, vector < vector <float> >
		&f, vector < vector < char > > &pixels)
{
	
	VPN.push_back(xVPN);
	VPN.push_back(yVPN);
	VPN.push_back(zVPN);

	VUP.push_back(xVUP);
	VUP.push_back(yVUP);
	VUP.push_back(zVUP);

	float u1[3] = {(VUP[1]*VPN[2])-(VUP[2]*VPN[1]),
		(VUP[2]*VPN[0])-(VUP[0]*VPN[2]), (VUP[0]*VPN[1])-(VUP[1]*VPN[0])};
	float h = sqrt((u1[0]*u1[0]) + (u1[1]*u1[1]) + (u1[2]*u1[2]));
	
	float u[3] = {(u1[0]/h),(u1[1]/h),(u1[2]/h)};
	
	float v[3] = {(VPN[1]*u[2])-(VPN[2]*u[1]), (VPN[2]*u[0])-(VPN[0]*u[2]),
		(VPN[0]*u[1])-(VPN[1]*u[0])};
	
	
	//Create 3d vector for sets of polygons	
	vector < vector < vector <float> > > polygon;
	
	for (int s = 0; s < f.size(); s++)
	{
		vector < vector <float> > polysets;
		
		float f1 = f[s][0];
		float f2 = f[s][1];
		float f3 = f[s][2];
		
		vector <float> p;
		p.push_back(vertex[f1-1][0]);
		p.push_back(vertex[f1-1][1]);
		p.push_back(vertex[f1-1][2]);
		
		
		vector <float> p1;
		p1.push_back(vertex[f2-1][0]);
		p1.push_back(vertex[f2-1][1]);
		p1.push_back(vertex[f2-1][2]);
		
		vector <float> p2;
		p2.push_back(vertex[f3-1][0]);
		p2.push_back(vertex[f3-1][1]);
		p2.push_back(vertex[f3-1][2]);

		polysets.push_back(p);
		polysets.push_back(p1);
		polysets.push_back(p2);

		polygon.push_back(polysets);
	}

	vector <int> triPoints;
			
	//Get the x,y,z values from polygon vector	
	for (int i = 0; i < polygon.size(); i++)
	{
		vector < vector <float> > poly = polygon[i];
		for (int j = 0; j < poly.size(); j++)
		{
			float x = polygon[i][j][0];
			float y = polygon[i][j][1];
			float z = polygon[i][j][2];
			
			//cout << x << y << z << endl;	

			//Detect if polygon is within view volume
			typedef int Out;
		
			const int Inside = 0;
			const int Above = 1;
			const int Below = 2;
			const int Right = 4;
			const int Left = 8;
			const int Behind = 16;
			const int Front = 32;

		
			float zmin = (zPRP - front)/(back-zPRP);
			Out code = Inside;
			if ( y > -z)
			code |= Above;
			else if(y < z)
			code |= Below;
			if (x > -z )
			code |= Right;
			else if ( x < z)
			code |= Left;
			if (z < -1)
			code |= Behind;
			else if (z > zmin)
			code |= Front;

			float r = sqrt((VPN[0]*VPN[0]) + (VPN[1]*VPN[1]) + (VPN[2]*VPN[2]));
			//Rotation matrix
			float Rotation[4][4] = {{u[0],u[1], u[2], 0}, {v[0],v[1],v[2],0},
			{VPN[0]/r,VPN[1]/r,VPN[2]/r,0}, {0, 0, 0 ,1}};
		
			float Translation[4][4] = {{1, 0, 0, -xVRP},{0, 1, 0, -yVRP}, {0, 0,
			1, -zVRP}, {0, 0 , 0, 1}};


			float MView[4][4];
		
			for(int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					MView[row][col] = 0;
					for(int inner = 0; inner < 4; inner++)
					{
			 			MView[row][col] += Rotation[row][inner]*Translation[inner][col];
					}
			
				}
			}
		
			float a = (2*zPRP)/((uMax-uMin)*(zPRP - back));
			float b = ((uMax + uMin) - 2*xPRP)/((uMax-uMin)*(zPRP-back));
			float c = -((uMax+uMin)*zPRP)/((uMax-uMin)*(zPRP-back));
			float d = (2*zPRP)/ ((vMax-vMin)*(zPRP-back));
			float e = ((vMax + vMin)-2*yPRP)/((vMax-vMin)*(zPRP-back));
			float f = -((vMax + vMin)*zPRP)/((vMax-vMin)*(zPRP-back));
			float g = 1/(zPRP-back);
			float h = -((zPRP)/(zPRP-back));
			float MPerspective[4][4] = {{a, 0 , b, c}, {0, d, e, f}, {0, 0, g, h},
			{0, 0, 0, 1}};

			float v[4][4];
			for(int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					v[row][col] = 0;
					for(int inner = 0; inner < 4; inner++)
					{
			 			v[row][col] += MPerspective[row][inner]*MView[inner][col];
					}
			
				}
			}
	
		
			float vPoints[4][1]= {{0},{0}, {0}, {0}};
			float P[4][1] ={{x}, {y},{z},{1}};
			//cout << P[0][0] << " " << P[1][0] << " " << P[2][0] << " " << P[3][0] << endl;
			for(int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					vPoints[row][0] += v[row][col]*P[col][0];
				}
			}

			x  = vPoints[0][0];
			y = vPoints[1][0];
			z = vPoints[2][0];
		
		//cout << x << " " << y << " " << z << endl;			
				
			float polyX = x/-z;
			float polyY = y/-z;

			//cout << polyX << " " << polyY << endl;	
			
			translation[0][0] = 1;
			translation[0][1] = 0;
			translation[0][2] = 1;
			translation[1][0] = 0;
			translation[1][1] = 1;
			translation[1][2] = 1;
			translation[2][0] = 0;
			translation[2][1] = 0;
			translation[2][2] = 1;

			scale[0][0] = (upperX_viewport - lowerX_viewport)/2;
			scale[0][1] = 0;
			scale[0][2] = 0;
			scale[1][0] = 0;
			scale[1][1] = (upperY_viewport - lowerY_viewport)/2;
			scale[1][2] = 0;
			scale[2][0] = 0;
			scale[2][1] = 0;
			scale[2][2] = 1;	
			
			v_trans[0][0] = 1;
			v_trans[0][1] = 0;
			v_trans[0][2] = uMin;
			v_trans[1][0] = 0;
			v_trans[1][1] = 1;
			v_trans[1][2] = vMin;
			v_trans[2][0] = 0;
			v_trans[2][1] = 0;
			v_trans[2][2] = 1;

		   vector < vector <float> > n(3,vector <float> (1));
			vector < vector <float> > n1(3,vector <float> (1));	

			n = pointPass(scale,translation);
			n1 = pointPass(v_trans, n);
			
			float polyP[3][1] = {{polyX},{polyY},{1}};
			float DPoints[3][3] = {{n1[0][0], n1[0][1], n1[0][2]},
				{n1[1][0],n1[1][1],n1[1][2]},{n1[2][0],n1[2][1],n1[2][2]}};
			 
			float polyPoints[3][1] = {{0},{0},{0}}; 
			 
			for(int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
				{
					polyPoints[row][0] += DPoints[row][col]*polyP[col][0];
				}
			}

			int xPrime = polyPoints[0][0];
			int  yPrime = polyPoints[1][0];

			//cout << xPrime << " " << yPrime << endl;
			
		//	vector<int>triPoints;
			
			triPoints.push_back(xPrime);
			triPoints.push_back(yPrime);
		/*	
			for (int i = 0; i < triPoints.size(); i++)
			{
				//cout << triPoints[i] << endl;
			}*/
			/*
			vector< vector <int> >triPoly;
			vector< vector < vector <int> > > triSets;
			
			for(i = 0; i < triPoints.size()-2; i+=3)
			{
				triPoly.push_back(triPoints[i]);
				triPoly.push_back(triPoints[i+1]);
				triPoly.push_back(triPoints[i+2]);
				triPoly.push_back(triPoints[i]);
				
				triSets.push_back(triPoly);
			
			}		
			
			drawline(triSets, pixels);	

			
			*/
			
				
/*
		for(int row = 0; row < 3; row++)
		{
		for (int col = 0; col < 3; col++)
			{
				cout << translation[row][col] << " ";
			}
			cout << endl;
		}
		cout << endl;
*/		
/*	
	
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 4; j++)	
			{
				cout << MPerspective[k][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
*/		
	
		}
	}
			vector< vector <int> >triPoly;
			//vector< vector < vector <int> > > triSets;
			/*for(int s = 0; s < triPonts.size(); s++)
			{
				cout << triPonts[s] << endl;
			}*/
			for(int i = 0; i < triPoints.size(); i+=6)
			{
				vector<int> temp;
				temp.push_back(triPoints[i]);
				temp.push_back(triPoints[i+1]);
				temp.push_back(triPoints[i+2]);
				temp.push_back(triPoints[i+3]);
				
				for (int k = 0; k < temp.size(); k++)
				{
					//cout << temp[k] << endl;
				}
				vector<int> temp1;
				temp1.push_back(triPoints[i+2]);
				temp1.push_back(triPoints[i+3]);
				temp1.push_back(triPoints[i+4]);
				temp1.push_back(triPoints[i+5]);

				vector<int>temp2;
				temp2.push_back(triPoints[i+4]);
				temp2.push_back(triPoints[i+5]);
				temp2.push_back(triPoints[i]);
				temp2.push_back(triPoints[i+1]);

				triPoly.push_back(temp);
				triPoly.push_back(temp1);
				triPoly.push_back(temp2);
				
				triSets.push_back(triPoly);
				//cout<< triSets[i][0][1] <<endl;	
			}		
			
			drawline(triSets, pixels);	

	
}

vector < vector <float> > pointPass(vector < vector <float> > T, vector< vector <float> > P )
{
	vector < vector <float> > pointPrime(3, vector <float> (3));	
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

/*Drawline function computes the increments, slopes and points to be incremented*/
vector < vector< char > > drawline(vector< vector < vector <int> > >
		&triSets, vector < vector < char > > &pixels )
{
	//Getting the data points from the vector
	for(int i = 0; i <triSets.size(); i++)
	{
		vector < vector <int> >triPoly = triSets[i];
		for (int j = 0; j < triPoly.size(); j++)
		{
	float x1 = triSets[i][j][0];
	float y1 = triSets[i][j][1];
	float x2 = triSets[i][j][2];
	float y2 = triSets[i][j][3];
	
	//cout << x1 << " " << y1 << " " << x2 << " " << y2<< endl;

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




void scanFill(vector <vector < vector <int> > > &triSets, vector < vector < char > > &pixels)
{
	vector <int> intersects;
	
	for(int i = 0; i <triSets.size(); i++)
	{
		for (int k = 0; k < upperY; k++)
		{	
			vector<int> intersects;
			vector < vector <int> >triPoly = triSets[i];
			for (int j = 0; j < triPoly.size(); j++)
			{
				float x1 = triSets[i][j][0];
				float y1 = triSets[i][j][1];
				float x2 = triSets[i][j][2];
				float y2 = triSets[i][j][3];
             
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
				if (ymax > upperY || ymin > upperY)
				{
					extrema = upperY;
				}
				else if (ymax < lowerY || ymin < lowerY)
				{
					extrema = lowerY;
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
						pixels[upperY-k][s] = 'B';
						//cout << s << " " << k << endl;
					}
				}
			}
		}
	
	}
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
	
