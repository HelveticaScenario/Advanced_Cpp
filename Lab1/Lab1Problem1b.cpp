// Daniel Lewis, ITSE 2431 Lab 1 Problem 1b

#include <iostream>

using namespace std;

// void calcCubeData(double sideLength, double & volume, double & sideSurfArea, double & totalSurfArea){
// 	sideSurfArea = sideLength * sideLength;
// 	volume = sideSurfArea * sideLength;
// 	totalSurfArea = sideSurfArea * 6;
// }

void calcCubeData(double sideLength, double * volume, double * sideSurfArea, double * totalSurfArea){
	*sideSurfArea = sideLength * sideLength;
	*volume = *sideSurfArea * sideLength;
	*totalSurfArea = *sideSurfArea * 6;
	// cout << sideLength << endl;
	// cout << volume << endl;
	// cout << sideSurfArea << endl;
	// cout << totalSurfArea << endl;
}

int main(int argc, char const *argv[])
{
	double sideLength;
	cout << "Please enter the length of one side of your cube: ";
	cin >> sideLength;
	double * volume = new double;
	double * surfaceArea = new double;
	double * totalSurface = new double;
	calcCubeData(sideLength, volume, surfaceArea, totalSurface);
	cout << "Side Length: " << sideLength << endl;
	cout << "Volume: " << *volume << endl;
	cout << "Surface Area of one side: " << *surfaceArea << endl;
	cout << "Surface Area of all sides: " << *totalSurface << endl;
	delete volume;
	delete surfaceArea;
	delete totalSurface;
	return 0;
}