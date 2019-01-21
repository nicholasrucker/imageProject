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

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <string>
#include "Point.h"
#include "Shape.h"

using namespace std;

class Triangle : public Shape{

	public:
		Triangle(Point&, Point&, Point&);
		~Triangle();
		int hit(Point&);
};

#endif