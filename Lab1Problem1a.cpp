// Daniel Lewis, ITSE 2431 Lab 1

#include <iostream>

using namespace std;

void calcCubeData(double sideLength, double & volume, double & sideSurfArea, double & totalSurfArea){
	sideSurfArea = sideLength * sideLength;
	volume = sideSurfArea * sideLength;
	totalSurfArea = sideSurfArea * 6;
}

int main(int argc, char const *argv[])
{
	double sideLength;
	cout << "Please enter the length of one side of your cube: ";
	cin >> sideLength;
	double volume, surfaceArea, totalSurface;
	calcCubeData(sideLength, volume, surfaceArea, totalSurface);
	cout << "Side Length: " << sideLength << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area of one side: " << surfaceArea << endl;
	cout << "Surface Area of all sides: " << totalSurface << endl;
	return 0;
}