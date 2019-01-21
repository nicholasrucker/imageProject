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

#include "Point.h"

/*
	Default constructor is declared
*/
Point::Point()
	:x(0), y(0)
{
}

/*
	Regular constructor is declared
*/
Point::Point(double x, double y)
	:x(x), y(y)
{
}

/*
	Default destructor
*/
Point::~Point(){}

/*
	Setters and getters are declared
*/
void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y){
	this->y = y;
}

double Point::getX(){
	return this->x;
}

double Point::getY(){
	return this->y;
}









