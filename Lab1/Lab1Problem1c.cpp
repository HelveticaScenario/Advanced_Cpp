// Daniel Lewis, ITSE 2431 Lab 1 Problem 1c

#include <iostream>

using namespace std;


void readSizeAndAllocateArray(int ** ptr, int * size){
	cout << "Enter the size of the array: ";
	cin >> *size;
	*ptr = new int[*size];
}

int main(int argc, char const *argv[])
{
	int * size = new int;
	int * ptr = NULL;
	int ** ptrptr = &ptr;
	readSizeAndAllocateArray(ptrptr, size);
	return 0;
}

// void readSizeAndAllocateArray(int *& ptr, int & size){
// 	cout << "Enter the size of the array: ";
// 	cin >> size;
// 	ptr = new int[size];
// }


