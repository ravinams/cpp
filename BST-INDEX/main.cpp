#include <iostream>
#include <string>
#include <stdio.h>
#include "MyFileIO.h"
#include "BST.h"

void testCases();

int main()
{
	testCases();
	return 0;
}

void testCases()
{
	std::string FILENAME = "BST-results.txt";
	std::string outString;
	std::string PASSED = " Passed";
	std::string FAILED = " Failed";
	std::string TEST_CASE = "Test Case #";
	int testCount = 1;  // used to track test numbers
	char ch[100000]; // array large enough for the file output
	int char_ptr = 0; // file index pointer

	int testArray1[] = { 115, 100, 90, 110, 80, 95, 105, 8 }; // unbalanced tree
	int testArray2[] = { 100, 90, 110, 80, 95, 105, 115 };  // balanced tree
	unsigned count;
	int index;
	bool result;

	BST<int> intBST1; 
	for (int i = 0; i < 8; i++)
	{
		intBST1.insert(testArray1[i]);
	}
	BST<int> intBST2;
	for (int i = 0; i < 7; i++)
	{
		intBST2.insert(testArray2[i]);
	}
	BST<int> intBST3;   // empty tree

	// Test Case #1 - test countNodes() empty tree case
	count = intBST3.countNodes();
	if (count == 0)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #2 - test countNodes() unbalanced tree
	count = intBST1.countNodes();
	if (count == 8)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #3 - test countNodes() balanced tree
	count = intBST2.countNodes();
	if (count == 7)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #4 - test indexSearch() empty tree
	index = intBST3.indexSearch(115);
	if (index == -1)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #5 - test indexSearch() unbalanced tree
	index = intBST1.indexSearch(115);
	if (index == 0)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #6 - test indexSearch() unbalanced tree
	index = intBST1.indexSearch(8);
	if (index == 15)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #7 - test indexSearch() unbalanced tree
	index = intBST1.indexSearch(95);
	if (index == 8)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #8 - test indexSearch() unbalanced tree
	index = intBST1.indexSearch(106);
	if (index == -1)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #9 - test indexSearch() balanced tree
	index = intBST2.indexSearch(106);
	if (index == -1)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #10 - test indexSearch() balanced tree
	index = intBST2.indexSearch(105);
	if (index == 5)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #11 - test copy constructor unbalanced tree
	BST<int> intBST4(intBST1);
	result = intBST1.isExactlyEqual(intBST4);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #12 - test copy constructor balanced tree
	BST<int> intBST5(intBST2);
	result = intBST2.isExactlyEqual(intBST5);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #13 - test copy constructor empty tree
	BST<int> intBST6(intBST3);
	result = intBST3.isExactlyEqual(intBST3);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #14 - test copy constructor balanced tree shallow copy issue
	index = 80;
	intBST5.remove(index);
	result = intBST2.isExactlyEqual(intBST5);
	if (result == false)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #15 - assignment operator - assign an empty tree to non-empty tree
	intBST5 = intBST3;
	result = intBST3.isExactlyEqual(intBST5);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

        
	// Test Case #16 - assignment operator - assign an non-empty tree to empty tree
	intBST5 = intBST2;
	result = intBST2.isExactlyEqual(intBST5);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #17 - assignment operator - assign an non-empty tree to non-empty tree
	intBST5 = intBST1;
	result = intBST1.isExactlyEqual(intBST5);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #18 - assignment operator shallow copy
	index = 8;
	intBST5.remove(index);
	result = intBST1.isExactlyEqual(intBST5);
	if (result == false)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;

	// Test Case #19 - assignment operator self assignment check
	intBST5 = intBST2;
	intBST2 = intBST2;
	result = intBST2.isExactlyEqual(intBST5);
	if (result == true)
		outString = TEST_CASE + valueOf(testCount) + PASSED + getCRLF();
	else
		outString = TEST_CASE + valueOf(testCount) + FAILED + getCRLF();
	std::cout << outString;
	char_ptr = build_file_array(outString, char_ptr, ch);
	testCount++;
        

	outString = getCRLF();
	char_ptr = build_file_array(outString, char_ptr, ch);
	outString = getCode(char_ptr, ch);
	char_ptr = build_file_array(outString, char_ptr, ch);
	outString = nowtoString();
	char_ptr = build_file_array(outString, char_ptr, ch);
	writefile(FILENAME, ch, char_ptr);
}



