//Daniel Lewis Lab3


#include <iostream>
#include <vector>

using namespace std;

class IntegerSet{
		friend ostream & operator<<(ostream & out, const IntegerSet & intObj);
	public:
		IntegerSet();
		IntegerSet(const IntegerSet& otherSet);
		IntegerSet(const int array[], const int length);
		//~IntegerSet();
		void printSet(ostream & out=cout) const;
		void insertElement(int element);
		void deleteElement(int element);
		IntegerSet unionOfSets(const IntegerSet& otherSet) const;
		IntegerSet intersectionOfSets(const IntegerSet& otherSet) const;
		bool isEqualTo(const IntegerSet& otherSet) const;
		IntegerSet & operator=(const IntegerSet &rhs);
		void operator+=(const int rhs);
		void operator-=(const int rhs);
		bool operator==(const IntegerSet &rhs) const;
		IntegerSet operator|(const IntegerSet &rhs) const;
		IntegerSet operator&(const IntegerSet &rhs) const;


	private:
 		vector<bool> _set;
};

ostream & operator<<(ostream & out, const IntegerSet & intObj);
