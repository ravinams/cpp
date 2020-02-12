/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oracle
 *
 * Created on March 7, 2018, 10:06 PM
 */

#include <cstdlib>
#include<iostream>

#include "INode.h"
#include "DNode.h"
#include "Int341.h"
#include "SqList.h"

using namespace std;

/*
 * 
 */
void testINode() {

    SqList S ;
     int i;
    Int341 result;
    //iNode.dump();
    
     for ( i = 1000; i < 2000; i += 10) {
       
	S.add(Int341(i));
    }
    
     for ( i = 990; i >= 0; i -= 10) {
	S.add(Int341(i)) ;
    }
    S.consolidate() ;
    
//     for (i = 0; i < 50; i++) {
//	result = S.removeAt(0); 
//    }
//    
//   for (i=149; i >= 100; --i) {
//	result = S.removeAt(i); 
//    }
//    
//    
//     S.add(Int341(506));
//    S.add(Int341(561));
//    for (int i=5; i < 12; i+=3) {
//	result = S.removeAt(i);
//    }
//    result = S.remove(Int341(650));
//    result = S.remove(Int341(690));
//
   
    
   
    
//    iNode->add(Int341(20));
//   
//  iNode->add(Int341(5));
//  
////   iNode->dump();
//  
//    iNode->add(Int341(40));
//    iNode->add(Int341(15));
//    iNode->add(Int341(2));
    S.dump();
    //    
     // iNode->remove(Int341(20)) ;
//    //     iNode->remove(Int341(100)) ;
    //            

   // iNode->removeAt(5);
//    cout<<iNode->indexOf(Int341(2)) ;
    // iNode->dump();
}


void testSqList() {

    SqList S;
    int i;
    Int341 result;

    Int341::m_debug = false;

    // Use add and remove functions
    //
    // First, do 100 additions to tail
    for (i = 1000; i < 2000; i += 10) {
       
	S.add(Int341(i));
    }
   
//    S.dump();
   
  
//      
  
     // Then, do 100 additions to head
    for (i = 990; i >= 0; i -= 10) {
	S.add(Int341(i)) ;
    }
       
//        S.dump();
       S.consolidate() ; 
         
//S.dump();

 

    for (i = 0; i <= 24; i++) {
         cout<<" remove = " <<i  ;
	result = S.removeAt(0); 
        cout<< " SUCCESS" <<endl ;
    }

//  S.dump();

 
    for (i=149; i >= 100; --i) {
	result = S.removeAt(i); 
    }
        

        
    S.dump();
    
 
    /*
   *  
     
    Int341::report();
//    S.inspector();

    S.add(Int341(506));
    S.add(Int341(561));
    for (int i=5; i < 12; i+=3) {
	result = S.removeAt(i);
    }
    result = S.remove(Int341(650));
    result = S.remove(Int341(690));
//
    S.dump();
    Int341::report();
//    S.inspector();

    SqList T(S);
    SqList U;
    
      U.dump(); 
      
    U = T;

    S.dump() ;
    U.dump();

    for(int i=0; i < U.numItems(); i++) {
	cout << "U[" << i << "] = " << U[i].m_data << endl;
    }
    for(int i=0; i < U.numItems(); i+=7) {
	U[i] = 5 + U[i].m_data; 
	cout << "U[" << i << "] = " << U[i].m_data << endl;
    }

    Int341 stuff(1000);
    int pos = U.indexOf(stuff);
    if (pos >= 0) {
	cout << "Found " << stuff.m_data << " in index " << pos << endl;
    } else {
	cout << "Did not find " << stuff.m_data << endl;
    }

    stuff = Int341(99999);
    pos = U.indexOf(stuff);
    if (pos >= 0) {
	cout << "Found " << stuff.m_data << " in index " << pos << endl;
    } else {
	cout << "Did not find " << stuff.m_data << endl;
    }


    U.dump();
    Int341::report();
//
//    U.inspector();
 
     */   
}

int main(int argc, char** argv) {

//    testINode() ;
    testSqList();
    
//    SqList S;
//    int i;
//    Int341 result;
//    
//    S.dump() ;
//    
//    S.add(Int341(99999)) ;
//    
//             S.dump() ;
    
}
