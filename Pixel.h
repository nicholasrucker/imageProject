/*****************************************************************************
* Nicholas Rucker                                                            *
* nrucker                                                                    *
* CPSC 1020 Fall 2018                                                        *
* Section 2 (M.W.F 10:10 - 11:00)                                            *
* PA3                                                                				 *
* This programming assignment is a culmination of everything that has been	 *
* taught over the semester.  The goal is to create and image using a circle, *
* triangle, and quadrilaterial.  Various classes and files will be used, as  *
* well as polymorphism.																					             *
******************************************************************************/

#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

class Pixel{
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;

	public:
		Pixel();
		Pixel(unsigned char red, unsigned char green, unsigned char blue);
		~Pixel();
		unsigned char getRed();
		unsigned char getGreen();
		unsigned char getBlue();

};

#endif