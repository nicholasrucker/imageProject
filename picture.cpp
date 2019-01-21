/*****************************************************************************
* Nicholas Rucker                                                            *
* nrucker                                                                    *
* CPSC 1020 Fall 2018                                                        *
* Section 2 (M.W.F 10:10 - 11:00)                                            *
* PA3                                                                        *
* This programming assignment is a culmination of everything that has been   *
* taught over the semester.  The goal is to create and image using a circle, *
* triangle, and quadrilaterial.  Various classes and files will be used, as  *
* well as polymorphism.                                                      *
******************************************************************************/

#include "Picture.h"

/*
	This will simply print the header of the image to the screen
*/
void Picture::printHeader(ofstream& outputFile, Header& fileHeader){	
	outputFile << fileHeader.getMagicNumber() << " " << fileHeader.getWidth()
						 << " " << fileHeader.getHeight() << " " << fileHeader.getMaxVal()
						 << endl;
	}

/*
	This function reads all the circles from the input file
	and stores the points into a vector of shape pointers.
	This vector of pointers is the basis for polymorphism
	in this program
*/

void Picture::readC(ifstream& input){
	string temp;
	int p1, p2, p3;

	input >> temp;

	Shape* temp1;
	
	for(int i = 0; i < 1; i++)
	{
		input >> p1;
		input >> p2;
		input >> p3;

		Point tempPoint1(p1, p2); 

		temp1 = new Circle(tempPoint1, p3);

		shapes.push_back(temp1);
	}
}

/*
	This function reads all the triangles from the input file
	and stores the points into a vector of shape pointers.
	This vector of pointers is the basis for polymorphism
	in this program
*/
void Picture::readTri(ifstream& input){
	string temp;
	int p1, p2, p3, p4, p5, p6;

	input >> temp;

	Shape* temp1;
	
	for(int i = 0; i < 1; i++)
	{
		input >> p1;
		input >> p2;
		input >> p3;
		input >> p4;
		input >> p5;
		input >> p6;

		Point tempPoint1(p1, p2);
		Point tempPoint2(p3, p4);
		Point tempPoint3(p5, p6);

		temp1 = new Triangle(tempPoint2, tempPoint1, tempPoint3);

		shapes.push_back(temp1);
	} 
}

/*
	This function reads all the quads from the input file
	and stores the points into a vector of shape pointers.
	This vector of pointers is the basis for polymorphism
	in this program
*/
void Picture::readQ(ifstream& input){
	string temp;
	int p1, p2, p3, p4, p5, p6, p7, p8;

	Shape* temp1;

	input >> temp;
	
	for(int i = 0; i < 18; i++)
	{
		input >> p1;
		input >> p2;
		input >> p3;
		input >> p4;
		input >> p5;
		input >> p6;
		input >> p7;
		input >> p8;

		Point tempPoint1(p1, p2);
		Point tempPoint2(p3, p4);
		Point tempPoint3(p5, p6);
		Point tempPoint4(p7, p8);

		temp1 = new Quad(tempPoint1, tempPoint2, tempPoint3, tempPoint4);

		shapes.push_back(temp1);
	}
} 

/*
	The storePixel function creates the vector pixel map
*/
vector< vector<Pixel> > Picture::storePixels(Header& header, ifstream& input,
																						 vector<vector<Pixel> >& imageMap){
	
/*
	The 2D vector is set to the proper size
*/
	imageMap.resize(header.getHeight(), vector<Pixel>(header.getWidth()));

	Point currP;
	
	for(int i = 0; i < header.getHeight(); i++)
	{
		for(int j = 0; j < header.getWidth(); j++)
		{
			currP.setX(i);
			currP.setY(j);

			//The background color is set with default values
			imageMap[i][j] = Pixel();

			//This is what moves the Quad objects down a row
			if(((i % 219) == 0) && (i != 0) && (j == 0))
			{
				for(int o = 2; o < 20; o++)
				{
					Quad* tempQuad = dynamic_cast<Quad*>(shapes[o]);
					tempQuad->shiftQuadY(220);
				}
			}

			//This parses through the vector of shapes calling the hit
			//function on the vector. (Polymorphsm)	
			for(int k = 2; k < 20; k++)
			{
				if(k > 1 && k < 8)
				{
					if(shapes[k]->hit(currP)  == 1)
					{
						imageMap[i][j] = Pixel(61, 92, 92);
					}
				}
				else if(k > 7 && k < 14)
				{
					if(shapes[k]->hit(currP)  == 1)
					{
						imageMap[i][j] = Pixel(255, 255, 255);
					}
				}
				else if(k > 12 && k < 20)
				{
					if(shapes[k]->hit(currP)  == 1)
					{
						imageMap[i][j] = Pixel(0, 0, 0);
					}
				}

				/*
				imageMap[i][j] = (shapes[0]->hit(currP) == 1) ? Pixel(90, 120, 168) :
												 (shapes[1]->hit(currP) == 1) ? Pixel(90, 120, 168) :
												 																			imageMap[i][j]; 
				*/
			}
		}
	} 
	return imageMap;
}

/*
	This function itterates through the 2D vector and outputs the pixel data
	to an image file
*/ 
void Picture::printPixels(ofstream& outputFile, Header& header,
												  vector< vector<Pixel> >& pixMap){

	for(int i = 0; i < header.getHeight(); i++)
	{
		for(int j = 0; j < header.getWidth(); j++)
		{
			outputFile << pixMap[i][j].getRed() 
								 << pixMap[i][j].getGreen() 
								 << pixMap[i][j].getBlue();
		}
	}
}