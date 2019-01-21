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

#ifndef PICTURE_H
#define PICTURE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <string>
#include "Header.h"
#include "Pixel.h"
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Quad.h"

using namespace std;

class Picture
{
	private:
		vector<Shape*> shapes;
	public:
		void printHeader(ofstream&, Header&);
		vector< vector<Pixel> > storePixels(Header&, ifstream&,
																				vector< vector<Pixel> >&);
		void printPixels(ofstream&, Header&, vector< vector<Pixel> >&);
		void readTri(ifstream&);
		void readC(ifstream&);
		void readQ(ifstream&);
};

#endif