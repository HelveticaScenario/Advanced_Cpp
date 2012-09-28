//Daniel Lewis Lab3


#include "IntegerSet.h"

using namespace std;

int main(){
	IntegerSet set, set2;

	// std::vector<bool> v(101,true);
	// cout <<   v.capacity() << endl;
	// cout << v.at(1) << endl;


	// set.printSet();
	// set2.insertElement(40);
	// set2.insertElement(20);
	// set.insertElement(40);
	// set.insertElement(30);
	  
	// set.insertElement(0);

	// IntegerSet set2(set);
	// IntegerSet uni, sect;
	// uni = set.unionOfSets(set2);
	// sect = set.intersectionOfSets(set2);

	// uni.printSet();
	// sect.printSet();

	// cout << set.isEqualTo(set2) << endl;

	// set2.insertElement(30);
	// set.insertElement(20);

	// cout << set.isEqualTo(set2) << endl;
	// int array[5] = {3, 7, 36, 24, 99};
	// array[0] = 3;
	// IntegerSet set(array, 5);
	set += 5;
	set += 10;
	

	set2 += 10;
	set2 += 20;

	IntegerSet uni = set | set2;
	IntegerSet sect = set & set2;

	cout << set;
	cout << set2;
	cout << (set == set2) << endl;
	set -= 5;
	set2 -= 20;
	cout << (set == set2) << endl;


	cout << uni;
	cout << sect;


	return 0;
}
