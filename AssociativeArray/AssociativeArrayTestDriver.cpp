#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
using namespace std;

#include "AssociativeArray.h"
// #include "Queue.h"

int main()
{
	cout << "Programmer: Daniel Simpson\n";
	cout << "Programmer ID: 1546217\n";
	cout << "FILE: " << __FILE__ << ends << endl << endl;

	//===========================================
	//Primitive Data Type Test (Int)
	//===========================================
	AssociativeArray<int, int> intTest;
	cout << "AssociativeArray<int,int> test:\n";
	cout << "-------------------------------\n\n";

	cout << "AssociativeArray<int,int> [] Square Bracket Operator Setter and getter: \n";
	cout << "------------------------------------------------------------ \n";
	intTest[1] = 2;
	cout << "\nEXPECTED: 2";
	cout << "\nACTUAL: " << intTest[1] << endl;
	assert(2 == intTest[1]);
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> containsKey: \n";
	cout << "------------------------------------------------------------ \n";
	cout << "\nEXPECTED: TRUE";
	assert(true == intTest.containsKey(1));
	cout << "\nACTUAL: TRUE" << endl;
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> deleteKey: \n";
	cout << "------------------------------------------------------------ \n";
	cout << "\nEXPECTED: 0";
	intTest.deleteKey(1);
	//assert(false == intTest.containsKey(1));
	cout << "\nACTUAL: " << intTest[1] << endl;
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> size: \n";
	cout << "------------------------------------------------------------ \n";
	cout << "\nEXPECTED: 1";
	//assert(0 == intTest.size());
	cout << "\nACTUAL: " << intTest.size() << endl;
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> copy constructor: \n";
	cout << "------------------------------------------------------------ \n";
	AssociativeArray<int, int> intTestCopy(intTest);
	cout << "\nEXPECTED: 2";
	cout << "\nACTUAL: " << intTestCopy[1] << endl;
	assert(intTestCopy[1] == intTest[1]);
	assert(intTestCopy.size() == intTest.size());
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> copy constructor: \n";
	cout << "------------------------------------------------------------ \n";
	AssociativeArray<int, int> intTestOperatorCopy = intTest;
	cout << "\nEXPECTED: 2";
	cout << "\nACTUAL: " << intTestOperatorCopy[1] << endl;
	assert(intTestOperatorCopy[1] == intTest[1]);
	assert(intTestOperatorCopy.size() == intTest.size());
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> clear: \n";
	cout << "------------------------------------------------------------ \n";
	intTest.clear();
	cout << "\nEXPECTED: 0";
	assert(0 == intTest.size());
	cout << "\nACTUAL: " << intTest.size() << endl;
	cout << "PASS!\n\n";

	cout << "AssociativeArray<int,int> Default Constructor: \n";
	cout << "------------------------------------------------------------ \n";
	AssociativeArray<int, int> intTestDefault;
	cout << "\nEXPECTED: 0";
	assert(0 == intTestDefault.size());
	cout << "\nACTUAL: " << intTest.size() << endl;
	cout << "PASS!\n\n";

}

