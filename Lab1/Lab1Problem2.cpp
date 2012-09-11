// Daniel Lewis, ITSE 2431 Lab 1 Problem 2

#include <iostream>

using namespace std;

double * createAndFillArray(int & length){
	cout << "How long would you like your array to be: ";
	cin >> length;
	double * a = new double[length];
	for(int i=0; i<length; i++){
		cout << "Enter value at index " << i << ": ";
		cin >> a[i];
	}
	cout << endl;
	for(int i=0; i<length; i++){
		cout << "The value at index " << i << " is: " << a[i] << endl;
	}
	cout << endl;
	return a;
}

void calcArrayExtremes(double * a, int length, int * minIdx, int * maxIdx){
	*minIdx = *maxIdx = 0;
	for( int i=0; i<length; i++){
		cout << "a at index " << i <<  " is " << *(a+i) << endl;
		if (*(a+(*minIdx)) > *(a+i))
		{
			cout << "minIdx changed from " << *minIdx;
			*minIdx = i;
			cout << " to " << *minIdx << endl; 
		}
		if (*(a+(*maxIdx)) < *(a+i))
		{
			cout << "maxIdx changed from " << *maxIdx;
			*maxIdx = i;
			cout << " to " << *maxIdx << endl; 
		}
	}
	;
}

int main(int argc, char const *argv[])
{
	int length;
	double * a = createAndFillArray(length);
	int * minIdx = new int;
	int * maxIdx = new int;
	//cout << "POINTER MATH: " << *(a+1) << endl;
	calcArrayExtremes(a, length, minIdx, maxIdx);
	cout << endl;
	cout << "The minIdx is " << *minIdx << endl;
	cout << "The maxIdx is " << *maxIdx << endl;
	delete a;
	delete minIdx;
	delete maxIdx;
	return 0;
}