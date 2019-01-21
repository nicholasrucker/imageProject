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

#include "Header.h"

/*
	Header constructor
*/
Header::Header(string magicNumber, int width, int height, int maxVal)
	:magicNumber("P6"), width(width), height(height), maxVal(maxVal)
{
}
	
/*
	Default destructor
*/
Header::~Header(){}

/*
	Getters for header elements are implemented
*/
string Header::getMagicNumber(){
	return this->magicNumber;
}

int Header::getWidth(){
	return this->width;
}

int Header::getHeight(){
	return this->height;
}

int Header::getMaxVal(){
	return this->maxVal;
}
