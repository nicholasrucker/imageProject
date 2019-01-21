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

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <fstream>
using namespace std;

class Point{
	private:
		int x;
		int y;

	public:
		Point();
		Point(double, double);
		~Point();
		double getX();
		double getY();
		void setX(double);
		void setY(double);
};

#endif