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

#include "Triangle.h"

/*
	The triangle constructor adds the points that
	make up the figure to a vector of points
*/
Triangle::Triangle(Point& p1, Point& p2, Point& p3){
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
}

/*
	Default destructor
*/
Triangle::~Triangle(){}


/*
	The triCheckPoint function is declared. This checks to see if a point
	is inside or outside the given triangle.  It fucntions with the help
	of vectors of the triangle sides.  Given the length of a vector and
	the current point, barycentric cordinaetes can be calculated to see
	if the point is indeed inside or outside the triangle.
*/

int Triangle::hit(Point& four){
/*
	The points of the triangle and the point in question are being
	stored into variables for easy mathematical manipulation
*/
  int  y1 = points[0].getX();
  int  x1 = points[0].getY();
  int  y2 = points[1].getX();
  int  x2 = points[1].getY();
  int  y3 = points[2].getX();
  int  x3 = points[2].getY();
  int  x = four.getX();
  int  y = four.getY();

/*
	Here is the math for the calculation of the vectors to determins if
	the point is inside or outside the triangle (Barycentric cordinate system)
	The vector lengths are stored as floats because otherwise the numbers would
	always be 1, 0, or greater/less than 0 and the point's location with respect
	to the triangle would not be determinable.
*/
  float aVecNum = x1 * (y3 - y1) + (y - y1) * (x3 - x1) - x * (y3 - y1);
  float aVecDem = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
  float aVec = aVecNum / aVecDem;

  float bVecNum = y - y1 - aVec * (y2 - y1);
  float bVecDem = y3 - y1;
  float bVec = bVecNum / bVecDem;

/*
	Here is just a return statement to signify is the point is within the area
	of the triangle.  1 for inside, 0 for outside.
*/

  return ((aVec >= 0) && (bVec >= 0) && ((aVec + bVec) <= 1)) ? 1 : 0;
}


