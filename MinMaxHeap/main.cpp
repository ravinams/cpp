#include <cstdlib>
#include <iostream>
#include "MinMaxHeap.cpp"
using namespace std ;

/*
 * 
 */
int main(int argc, char** argv) {

   MinMaxHeap<float> H(25) ;
   
   H.insert(5) ;
//   H.insert(10) ;
//   H.insert(7) ;
//   H.insert(9) ;
//   H.insert(6) ;
//   H.insert(2) ;
//   H.insert(16) ;
//   H.insert(12) ;
//   H.insert(11) ;
//   
   cout << "Initial MinMax Heap\n" ;
   H.dump() ;
//
//   H.insert(8); 
//   cout << "After inserting 8\n" ;
//   H.dump() ;
//   
   return 0;
}

