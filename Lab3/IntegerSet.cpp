//Daniel Lewis Lab3

#include "IntegerSet.h"

using namespace std;

IntegerSet::IntegerSet() : _set(101,false) {
	;
}

IntegerSet::IntegerSet(const IntegerSet & otherSet){
	this->_set = otherSet._set;
}

IntegerSet::IntegerSet(const int array[], const int length) : _set(101,false) {
	for (int i = 0; i < length; i++)
	{
		this->insertElement(array[i]);
	}
}


void IntegerSet::insertElement(int element){

	if (!_set[element])
	{
		_set[element] = true;
	}
}

void IntegerSet::deleteElement(int element){

	if (_set[element])
	{
		_set[element] = false;
	}
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& otherSet) const {
	IntegerSet uni;
	for (int i = 0; i < 101; ++i)
	{
		if (this->_set[i] || otherSet._set[i])
		{
			uni.insertElement(i);
		}
	}
	return uni;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& otherSet) const {
	IntegerSet sect;
	for (int i = 0; i < 101; ++i)
	{
		if (this->_set[i] && otherSet._set[i])
		{
			sect.insertElement(i);
		}
	}
	return sect;
}

bool IntegerSet::isEqualTo(const IntegerSet& otherSet) const {
	for (int i = 0; i < 101; ++i)
	{
		if (this->_set[i] != otherSet._set[i])
		{
			return false;
		}
	}
	return true;
}


void IntegerSet::printSet(ostream & out)const{
	bool isEmpty = true;
  	for(int i = 0; i < 101; i++){
    	if (_set[i]){
    		out << i << " ";
    		if (isEmpty)
    		{
    			isEmpty = false;
    		}
    	}
  	}
  	if (isEmpty)
  	{
  		out << "---";
  	}
  	out << endl;
}

IntegerSet& IntegerSet::operator=(const IntegerSet& rhs){
	this->_set = rhs._set;
	return *this;
}

void IntegerSet::operator+=(const int rhs){
	this->insertElement(rhs);

}
void IntegerSet::operator-=(const int rhs){
	this->deleteElement(rhs);
}
bool IntegerSet::operator==(const IntegerSet &rhs) const {
	return this->isEqualTo(rhs);
}
IntegerSet IntegerSet::operator|(const IntegerSet &rhs) const {
	
	return this->unionOfSets(rhs);
}
IntegerSet IntegerSet::operator&(const IntegerSet &rhs) const {
	return this->intersectionOfSets(rhs);
}

ostream & operator<<(ostream & out, const IntegerSet & intObj){
	intObj.printSet(out);
	return out;
}

