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

#include "Pixel.h"

/*
	Default constructor is declared.
	An initialzation list is used to get
	the initial pixel values if theyre not given.
*/
Pixel::Pixel()
	:red(179), green(179), blue(179)
{
}

/*
	Overloaded constructor is declared so
	the user can set the pixel color values
*/
Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue)
	:red(red), green(green), blue(blue)
{
}
	
/*
	Default destructor
*/
Pixel::~Pixel(){}

/*
	Getters are declared
*/
unsigned char Pixel::getRed(){
	return this->red;
}

unsigned char Pixel::getGreen(){
	return this->green;
}

unsigned char Pixel::getBlue(){
	return this->blue;
}