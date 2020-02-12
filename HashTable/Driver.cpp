/****************************************************************
 *
 * test1.cpp: test program for S'18 Project 5: hash tables
 *
 * Tests simple int values
 *
 ****************************************************************/

#include "ProbeHashTable.h"
#include "ChainHashTable.h"
#include <cstdlib>
#include <iostream>

using namespace std;

unsigned int myHashFunction(const int &data) {
    return (unsigned int) data * 149 + 47;
}

main(int argc, char **argv) {

    
     // II - ChainHashTable
    ChainHashTable<int> chainHT(&myHashFunction, 50);

     cout << "============================================================\n"
            << "= Initial chain hash table\n"
            << "============================================================"
            << endl;
    chainHT.dump();

     for (int i = 0; i < 500; i++) {
	if (!chainHT.insert(i)) {
	    cout << "insert(" << i << ") failed!" << endl;
	}
    }
  
    // II.a - insert elements
    cout << "============================================================\n"
	 << "= After 500 insertions\n"
	 << "============================================================"
	 << endl;
    chainHT.dump();

    // II.b - find elements

    cout << "============================================================\n"
            << " Searching for 100 & 300 & 500 in chain hash table \n"
            << "============================================================"
            << endl;

    if (chainHT.find(100)) {
        cout << "Item 100 exists in chain hash table" << endl;
    } else {
        cout << "Item 100 does not exists in chain hash table" << endl;
    }

    if (chainHT.find(300)) {
        cout << "Item 300 exists in chain hash table" << endl;
    } else {
        cout << "Item 300 does not exists in chain hash table" << endl;
    }
    
     if (chainHT.find(500)) {
        cout << "Item 500 exists in chain hash table" << endl;
    } else {
        cout << "Item 500 does not exists in chain hash table" << endl;
    }
    
    
    // II.c - remove elements
    cout << "============================================================\n"
            << " Removing items 20 & 200 from chain hash table \n"
            << "============================================================"
            << endl;

    bool chtFound = false;
    chainHT.remove(20, chtFound);
    if (chtFound) {
        cout << "Item 20 successfully removed from chain hash table" << endl;
    } else {
        cout << "Item 20 NOT removed from chain hash table" << endl;
    }

    chtFound = false;
    chainHT.remove(200, chtFound);
    if (chtFound) {
        cout << "Item 200 successfully removed from chain hash table" << endl;
    } else {
        cout << "Item 200 NOT removed from chain hash table" << endl;
    }

    cout << "============================================================\n"
            << "= After removal of 20 & 200 \n"
            << "============================================================"
            << endl;
    chainHT.dump();
    
    
    // I.d  - at
    std::vector<int> chtContents;
    cout << "============================================================\n"
            << "= Retrieving elements at(10) & at(15) \n"
            << "============================================================"
            << endl;

   
    cout << "\nElement(s) At Index = 10 :";
    chainHT.at(10, chtContents);
    for (std::vector<int>::iterator vecIter = chtContents.begin(); vecIter != chtContents.end(); ++vecIter)
        cout << *vecIter << ",";
     chtContents.erase(chtContents.begin(),chtContents.end()) ;
     
    cout << "\nElement(s) At Index = 15 :";
    chainHT.at(15, chtContents);
    for (std::vector<int>::iterator vecIter = chtContents.begin(); vecIter != chtContents.end(); ++vecIter)
        cout << *vecIter << ",";

    cout << "\n============================================================\n"
            << " End of chain hash table tesing \n"
            << "============================================================"
            << endl;
    
 
     
    // 2 - ProbeHashTable
    ProbeHashTable<int> probeHT(&myHashFunction, 50);
    cout << "============================================================\n"
            << "= Initial probe hash table\n"
            << "============================================================"
            << endl;
    probeHT.dump();

    // 2.a - insert elements
    for (int i = 0; i < 500; i += 10) {
        if (!probeHT.insert(i)) {
            cout << "insert(" << i << ") failed!" << endl;
        }
    }

    cout << "============================================================\n"
            << "= After 50 insertions  (0 .10..100.150..190...490)\n"
            << "============================================================"
            << endl;
    probeHT.dump();

    // 2.b - find elements

    cout << "============================================================\n"
            << " Searching for 20 & 200 in hash table \n"
            << "============================================================"
            << endl;

    if (probeHT.find(20)) {
        cout << "Item 20 exists in probe hash table" << endl;
    } else {
        cout << "Item 20 does not exists in probe hash table" << endl;
    }

    if (probeHT.find(200)) {
        cout << "Item 200 exists in probe hash table" << endl;
    } else {
        cout << "Item 200 does not exists in probe hash table" << endl;
    }

    // 2.c - remove elements
    cout << "============================================================\n"
            << " Removing items 20 & 200 from hash table \n"
            << "============================================================"
            << endl;

    bool phtFound = false;
    probeHT.remove(20, phtFound);
    if (phtFound) {
        cout << "Item 20 successfully removed from probe hash table" << endl;
    } else {
        cout << "Item 20 NOT removed from probe hash table" << endl;
    }

    phtFound = false;
    probeHT.remove(200, phtFound);
    if (phtFound) {
        cout << "Item 200 successfully removed from probe hash table" << endl;
    } else {
        cout << "Item 200 NOT removed from probe hash table" << endl;
    }

    cout << "============================================================\n"
            << "= After removal of 20 & 200 \n"
            << "============================================================"
            << endl;
    probeHT.dump();

    // 2.d  - at
    std::vector<int> phtContents;
    cout << "============================================================\n"
            << "= Retrieving elements at(10) & at(15) \n"
            << "============================================================"
            << endl;

   
    cout << "\nElement(s) At Index = 10 :";
    probeHT.at(10, phtContents);
    for (std::vector<int>::iterator vecIter = phtContents.begin(); vecIter != phtContents.end(); ++vecIter)
        cout << *vecIter << ",";
     phtContents.erase(phtContents.begin(),phtContents.end()) ;
     
    cout << "\nElement(s) At Index = 15 :";
    probeHT.at(15, phtContents);
    for (std::vector<int>::iterator vecIter = phtContents.begin(); vecIter != phtContents.end(); ++vecIter)
        cout << *vecIter << ",";

    cout << "\n============================================================\n"
            << " End of probe hash table tesing \n"
            << "============================================================"
            << endl;

   

}