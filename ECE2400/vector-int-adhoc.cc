//========================================================================
// vector-int-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for VectorInt.


#include "VectorInt.h"
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {

  VectorInt vec;

  vec.push_back ( 19 ); 
  vec.push_back ( 95 ); 
  vec.push_back ( 4  ); 
  vec.push_back ( 23  );

  printf( "Vector values are : ");
  vec.print();

  printf( "Value stored at index 0 is %d\n", vec.at( 0 ) );
  printf( "Value stored at index 1 is %d\n", vec.at( 1 ) );
  printf( "Value stored at index 2 is %d\n", vec.at( 2 ) );
  printf( "Value stored at index 3 is %d\n", vec.at( 3 ) );
  
  printf( "vector size is %zu\n", vec.size() );

  printf( "vector contains value %d is %s\n", 5, vec.find(5) ? "true" :"false" );
  printf( "vector contains value %d is %s\n", 19, vec.find(19) ? "true" :"false" );
  printf( "vector contains closest value for %d is %d\n", 25, vec.find_closest(25));


  printf( "Vector values after sorting are : ");
  vec.sort() ;
  vec.print();

  return 0;
}
