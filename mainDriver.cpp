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

#include "Picture.h"

int main(int argc, char* argv[]){

	if (argc != 3)
	{
		cout << "Follow the format <executable><inputFile><outputFile>" << endl;
		exit(1);
	}

	ifstream inputFile;
	inputFile.open(argv[1]);

	ofstream outputFile;
	outputFile.open(argv[2]);

	if(argv[1] == NULL)
	{
		cout << "The output file could not be opened" << endl;
		exit(1);
	}

	if(argv[2] == NULL)
	{
		cout << "The input file could not be opened" << endl;
		exit(1);
	}

/*
	Header and Picture objects are cerated for use of class functions.
	The 2D vector of pixels is also created so the image can be stored
	and printed to the output ppm file.
*/

	Header fileHeader("P6", 960, 1000, 255);
	Picture imagePicture;
	vector< vector<Pixel> > pixelMap; 

/*
	The shape data is read in for each respective shape.  The function
	adds each shape's point data to a vector of shape pointers. The hit
	function will be called on the pointers (polymorphism) to determine
	which color pixel will be stored in the 2D pixel vector.
*/
	imagePicture.readC(inputFile);
	imagePicture.readTri(inputFile);
	imagePicture.readQ(inputFile);

	imagePicture.printHeader(outputFile, fileHeader);
	pixelMap = imagePicture.storePixels(fileHeader, inputFile, pixelMap);
	imagePicture.printPixels(outputFile, fileHeader, pixelMap);

	inputFile.close();
	outputFile.close();

	return 0;
}