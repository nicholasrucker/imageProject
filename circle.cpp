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

#include "Circle.h"

/*
	The circle constructor adds the center point
	to a vector of points and stores the radius.
	Both will be used in the hit function
*/
Circle::Circle(Point& p1, int radius){
		points.push_back(p1);
		this->radius = radius;
}

//Can't forget about the destructor
Circle::~Circle(){}


/* 
The hit function will determind if the pixel is inside or outside the circle
*/

int Circle::hit(Point& currentPoint){
    double testPoint;

    testPoint = sqrt((pow((currentPoint.getX() - points[0].getX()), 2)
    				        + pow((currentPoint.getY() - points[0].getY()), 2)));

    return (testPoint < radius) ? 1 : 0;

}