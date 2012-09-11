// Daniel Lewis, ITSE 2431 Lab 1 Problem 2

#include <iostream>

using namespace std;

int * createAndFillArray(int & length){
	cout << "How long would you like your array to be: ";
	cin >> length;
	int * a = new int[length];
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

void arrayMap(int * a, int length, int(*func)(int)){
	for(int i = 0; i < length; i++){
		a[i] = func(a[i]);
	}
}

int timesTwo(int x){
	return 2 * x;
}

int main(int argc, char const *argv[]){
	int length;
	int * a = createAndFillArray(length);
	arrayMap(a, length, timesTwo);
	for(int i=0; i<length; i++){
		cout << "The new value at index " << i << " is: " << a[i] << endl;
	}
	cout << endl;
}