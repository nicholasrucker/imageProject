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

#include "Quad.h"

/*
  The Quad constructor simply adds the points that make the
  shape into a vector of points
*/
Quad::Quad(Point& p1, Point& p2, Point& p3, Point& p4){
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
}

/*
  Default destructor
*/
Quad::~Quad(){}

/*
  The shiftQuadY function is vital in this program.
  This allows for the shifiting of Quad objects after
  a full quad has been printed to the screen.  It simply
  adds the value of which you want to shift by to the current
  Y value.
*/
void Quad::shiftQuadY(int factor){
  points[0].setY(points[0].getY() + factor);
  points[1].setY(points[1].getY() + factor);
  points[2].setY(points[2].getY() + factor);
  points[3].setY(points[3].getY() + factor);
}

/*
  The hit function for the Quad works identically to the one
  from the Triangle class.  The only difference is that the math
  for the hit function is done three times.  This ensures that all
  the points inside the desired quad are covered.
*/
int Quad::hit(Point& four){
  
/*
	The points of the triangle and the point in question are being
	stored into variables for easy mathematical manipulation
*/
  int y1 = points[0].getX();
  int x1 = points[0].getY();
  int y2 = points[1].getX();
  int x2 = points[1].getY();
  int y3 = points[2].getX();
  int x3 = points[2].getY();
  int x = four.getX();
  int y = four.getY();

  bool firstTriangle;
  bool secondTriangle;
  bool thirdTriangle;


/*
	Here is the math for the calculation of the vectors to determins if
	the point is inside or outside the quad (Barycentric cordinate system)
	The vector lengths are stored as floats because otherwise the numbers would
	always be 1, 0, or greater/less than 0 and the point's location with respect
	to the quad would not be determinable.
*/
  float aVecNum = x1 * (y3 - y1) + (y - y1) * (x3 - x1) - x * (y3 - y1);
  float aVecDem = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
  float aVec = aVecNum / aVecDem;

  float bVecNum = y - y1 - aVec * (y2 - y1);
  float bVecDem = y3 - y1;
  float bVec = bVecNum / bVecDem;

  firstTriangle = ((aVec >= 0) && (bVec >= 0) && 
                                 ((aVec + bVec) <= 1)) ? 1 : 0;
  
  x2 = points[3].getY();
  y2 = points[3].getX();

  aVecNum = x1 * (y3 - y1) + (y - y1) * (x3 - x1) - x * (y3 - y1);
  aVecDem = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
  aVec = aVecNum / aVecDem;

  bVecNum = y - y1 - aVec * (y2 - y1);
  bVecDem = y3 - y1;
  bVec = bVecNum / bVecDem;

  secondTriangle = ((aVec >= 0) && (bVec >= 0) && 
                                  ((aVec + bVec) <= 1)) ? 1 : 0;

  x3 = x1;
  y3 = y1;

  aVecNum = x1 * (y3 - y1) + (y - y1) * (x3 - x1) - x * (y3 - y1);
  aVecDem = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);
  aVec = aVecNum / aVecDem;

  bVecNum = y - y1 - aVec * (y2 - y1);
  bVecDem = y3 - y1;
  bVec = bVecNum / bVecDem;

  thirdTriangle = ((aVec >= 0) && (bVec >= 0) && 
                                  ((aVec + bVec) <= 1)) ? 1 : 0;

/*
  If the current point is inside of any of
  the three triangles, it is inside the Quad
*/
  return  ((firstTriangle == 1)  || 
          (secondTriangle == 1)  || 
           (thirdTriangle == 1))   ? 1 : 0;
 
}
