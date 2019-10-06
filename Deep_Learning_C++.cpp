
#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include "MoveConstructorExample.h"
using std::cout;
using std::vector;
using std::iterator;


void print(vector<int> v) {

	cout << "Printing " << v.size() << endl;
	vector<int>::iterator myPtr;
	for (myPtr = v.begin(); myPtr < v.end(); myPtr++) {
		cout << *myPtr << " ";
	}
	cout << endl;

}

int main()
{
	MoveConstructorExample mC;

	// iterators (random access for vectors // generalization over pointers)
	vector<int> v= { 1, 2, 3 };
	vector<int>::iterator myPtr;
	print(v);

	vector<int> one = { 1 ,2, 3, 4, 5 };
	print(one);

	vector<int> two(one);
	print(two);


	// Scott Meyers item 5 - 

	// range based assign
	vector<int> three;
	three.assign((two.begin() + two.size() / 2), two.end()); 
	print(three);

	// range based construction
	vector<int> four(three.begin(), three.end());
	print(four);

	// range based erase
	/* 
		vector.end() = Returns an iterator referring to the past-the-end
		element in the vector container.The past-the-end element is the theoretical
		element that would follow the last element in the vector. It does not point to
		any element, and thus shall not be dereferenced.
	*/

	// single erase
	vector<int> five(one.begin(), one.end());
	myPtr = five.end() - 1;
	cout << *myPtr << endl;
	five.erase(myPtr);
	print(five);

	// range erase
	vector<int> six(one.begin(), one.end());
	vector<int>::iterator iter1, iter2;
	iter1 = six.begin();
	iter2 = six.end();
	iter1++;
	iter2--;
	six.erase(iter1, iter2);
	print(six);

	// range base insert
	vector<int> seven(one.begin(), one.end());
	vector<int>::iterator iter = six.begin();
	seven.insert(seven.end(), iter, six.end());
	print(seven);

	return 0;
}
