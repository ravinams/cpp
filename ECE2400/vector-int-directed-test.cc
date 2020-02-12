//========================================================================
// vector-int-directed-test.cc
//========================================================================
// This file contains directed tests for VectorInt-related functions.

#include "ece2400-stdlib.h"
#include "VectorInt.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests default constructor, push_back, and at.

void test_case_1_simple_push_back()
{
  std::printf( "\n%s\n", __func__ );

  // Use the default constructor
  VectorInt vec;

  //Check size of empty vector
  UTST_ASSERT_INT_EQ( vec.size(), 0 );

  // Push back some values
  int data[] = { 0xc01d, 0xdead, 0x2bad };
  for ( int v : data )
    vec.push_back( v );

  // Check value and size
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( vec.at( i ), data[i] );

  UTST_ASSERT_INT_EQ( vec.size(), 3 );

  

}

//------------------------------------------------------------------------
// test_case_2_at_out_of_bound
//------------------------------------------------------------------------
// Test that exception is properly thrown when at is out of bound.

void test_case_2_at_out_of_bound()
{
  std::printf( "\n%s\n", __func__ );

  VectorInt vec;

  // empty vector

  bool flag = false;
  try {
    vec.at( 0 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // push back some values

  vec.push_back( 0 );
  vec.push_back( 9 );

  // right at the boundary

  flag = false;
  try {
    vec.at( 2 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // beyond the boundary

  flag = false;
  try {
    vec.at( 5 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_3_construct
//------------------------------------------------------------------------
// A simple test case that tests non-default constructor.

void test_case_3_construct()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a vector from an array
  int       data[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  VectorInt vec    = VectorInt( data, 8 );

  // Modify the array to test deepcopy
  for ( int& v : data )
    v = 0xDeadFace;

  // Check that the value inside the vector is not modified
  for ( auto i = 0; i < 8; i++ )
    UTST_ASSERT_INT_EQ( vec.at( i ), i );

  UTST_ASSERT_INT_EQ( vec.size(), 8 );
}

//------------------------------------------------------------------------
// test_case_4_find_simple
//------------------------------------------------------------------------
// A simple test case that tests find.

void test_case_4_find_simple()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a vector from array
  int       data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  VectorInt vec    = VectorInt( data, 8 );

  // Search for value, expecting success
  UTST_ASSERT_TRUE( vec.find( 1 ) );
  UTST_ASSERT_TRUE( vec.find( 9 ) );
  UTST_ASSERT_TRUE( vec.find( 5 ) );
  UTST_ASSERT_TRUE( vec.find( 0 ) );
  UTST_ASSERT_TRUE( vec.find( 4 ) );
  UTST_ASSERT_TRUE( vec.find( 2 ) );
  UTST_ASSERT_TRUE( vec.find( 3 ) );

  // Search for value, expecting failure
  UTST_ASSERT_FALSE( vec.find( 6 ) );
  UTST_ASSERT_FALSE( vec.find( 7 ) );
  UTST_ASSERT_FALSE( vec.find( 8 ) );
}

//------------------------------------------------------------------------
// test_case_5_find_empty
//------------------------------------------------------------------------
// A simple test case that tests find for an empty vector.

void test_case_5_find_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Construct an empty vector
  VectorInt vec;

  // Search for value, expecting failure
  for ( int i = 0; i < 10; i++ )
    UTST_ASSERT_FALSE( vec.find( i ) );
}

//------------------------------------------------------------------------
// test_case_6_find_closest
//------------------------------------------------------------------------
// A simple test case that tests copy constructor and assignment operator.

void test_case_6_find_closest()
{
  std::printf( "\n%s\n", __func__ );

  int       data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  VectorInt vec    = VectorInt( data, 8 );

  UTST_ASSERT_INT_EQ( vec.find_closest( 6  ), 5 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 9  ), 9 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 8  ), 9 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 11 ), 9 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 7  ), 9 );
}

//------------------------------------------------------------------------
// test_case_7_find_closest_empty
//------------------------------------------------------------------------
// Test that the exception is properly thrown when calling find_closet on
// an empty vector.

void test_case_7_find_closest_empty()
{
  std::printf( "\n%s\n", __func__ );

  VectorInt vec;

  // find_closest on empty vector
  bool flag = false;
  try {
    vec.find_closest( 0 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_8_sort_simple
//------------------------------------------------------------------------
// A simple sort test.

void test_case_8_sort_simple()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a vector
  int       data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  VectorInt vec    = VectorInt( data, 8 );

  // Sort the vector and input array
  ece2400::sort( data, 8 );
  vec.sort();

  for ( size_t i = 0; i < 8; i++ )
    UTST_ASSERT_INT_EQ( vec.at( i ), data[i] );
}

//------------------------------------------------------------------------
// test_case_9_subscript
//------------------------------------------------------------------------
// A simple test for the subscript operator.

void test_case_9_subscript()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a vector from array
  int       data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  VectorInt vec    = VectorInt( data, 8 );

  // Check the value using subscript operator
  for ( int i = 0; i < 8; i++ )
    UTST_ASSERT_INT_EQ( vec[i], data[i] );
}

//------------------------------------------------------------------------
// test_case_10_copy
//------------------------------------------------------------------------
// A simple test case that tests copy constructor.

void test_case_10_copy()
{
  std::printf( "\n%s\n", __func__ );

  VectorInt vec0;

  int data[]  = { 0xbeef, 0xcafe, 0xf00d, 0xface };
  int data0[] = { 0xface, 0xbabe, 0xbabe, 0xc001 };
  int data1[] = { 0xcafe, 0xba11, 0xb00c, 0xc0de };

  // Push back to vec
  for ( int v : data )
    vec0.push_back( v );

  // Copy constructor
  VectorInt vec1( vec0 );

  // Push different values to vec0 and vec1
  for ( int v : data0 )
    vec0.push_back( v );

  for ( int v : data1 )
    vec1.push_back( v );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec0[i], data[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec1[i], data[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i + 4 ), data0[i] );
    UTST_ASSERT_INT_EQ( vec0[i + 4], data0[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i + 4 ), data1[i] );
    UTST_ASSERT_INT_EQ( vec1[i + 4], data1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_11_assignment_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a empty vector.

void test_case_11_assignment_empty()
{
  std::printf( "\n%s\n", __func__ );

  VectorInt vec0;
  VectorInt vec1;

  int data[]  = {0xBeef, 0xCafe, 0xF00d, 0xFace};
  int data0[] = {0xFace, 0xBabe, 0xBabe, 0xC001};
  int data1[] = {0xCafe, 0xBa11, 0xb00c, 0xC0de};

  // Push back to vec0
  for ( int v : data )
    vec0.push_back( v );

  // Assignment operator
  vec1 = vec0;

  // Push different values to vec0 and vec1
  for ( int v : data0 )
    vec0.push_back( v );

  for ( int v : data1 )
    vec1.push_back( v );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec0[i],      data[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec1[i],      data[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i + 4 ), data0[i] );
    UTST_ASSERT_INT_EQ( vec0[i + 4],      data0[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i + 4 ), data1[i] );
    UTST_ASSERT_INT_EQ( vec1[i + 4],      data1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_12_assignment_non_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a non-empty vector.

void test_case_12_assignment_non_empty()
{
  std::printf( "\n%s\n", __func__ );

  VectorInt vec0;
  VectorInt vec1;

  int data[]  = { 0xbeef, 0xcafe, 0xf00d, 0xface };
  int data0[] = { 0xface, 0xbabe, 0xbabe, 0xc001 };
  int data1[] = { 0xcafe, 0xba11, 0xb00c, 0xc0de };

  // Push back to vec0
  for ( int v : data )
    vec0.push_back( v );

  // Push back some values to vec1
  for ( int i = 0; i < 10; i++ )
    vec1.push_back( i );

  // Assignment operator
  vec1 = vec0;

  // Push different values to vec0 and vec1
  for ( int v : data0 )
    vec0.push_back( v );

  for ( int v : data1 )
    vec1.push_back( v );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec0[i], data[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i ), data[i] );
    UTST_ASSERT_INT_EQ( vec1[i], data[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( vec0.at( i + 4 ), data0[i] );
    UTST_ASSERT_INT_EQ( vec0[i + 4], data0[i] );
    UTST_ASSERT_INT_EQ( vec1.at( i + 4 ), data1[i] );
    UTST_ASSERT_INT_EQ( vec1[i + 4], data1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_13_general
//------------------------------------------------------------------------
// A generic test case.

void test_case_13_general()
{
  std::printf( "\n%s\n", __func__ );

  // Construct a new vector_int_t

  VectorInt vec;

  // Push data into the data structure

  for ( int i = 0; i < 5; i++ )
    vec.push_back( 100 + i );

  for ( int i = 5; i < 10; i++ )
    vec.push_back( 200 + i );

  for ( int i = 10; i < 20; i++ )
    vec.push_back( 300 + i );

  for ( int i = 20; i < 30; i++ )
    vec.push_back( 400 + i );

  // Test data

  for ( int i = 0; i < 5; i++ )
    UTST_ASSERT_INT_EQ( 100 + i, vec.at( i ) );

  for ( int i = 5; i < 10; i++ )
    UTST_ASSERT_INT_EQ( 200 + i, vec.at( i ) );

  for ( int i = 10; i < 20; i++ )
    UTST_ASSERT_INT_EQ( 300 + i, vec.at( i ) );

  for ( int i = 20; i < 30; i++ )
    UTST_ASSERT_INT_EQ( 400 + i, vec.at( i ) );

  // Test size

  UTST_ASSERT_INT_EQ( vec.size(), 30 );

  // Test at and find, expecting successful

  for ( size_t i = 0; i < 5; i++ ) {
    UTST_ASSERT_TRUE( vec.find( 100 + i ) );
    UTST_ASSERT_INT_EQ( vec.at( i ), 100 + i );
  }

  for ( size_t i = 5; i < 10; i++ ) {
    UTST_ASSERT_TRUE( vec.find( 200 + i ) );
    UTST_ASSERT_INT_EQ( vec.at( i ), 200 + i );
  }

  for ( size_t i = 10; i < 20; i++ ) {
    UTST_ASSERT_TRUE( vec.find( 300 + i ) );
    UTST_ASSERT_INT_EQ( vec.at( i ), 300 + i );
  }

  for ( size_t i = 20; i < 30; i++ ) {
    UTST_ASSERT_TRUE( vec.find( 400 + i ) );
    UTST_ASSERT_INT_EQ( vec.at( i ), 400 + i );
  }

  // Test find, expecting not successful

  for ( size_t i = 1000; i < 2000; i++ )
    UTST_ASSERT_FALSE( vec.find( i ) );

  // Test find_closest

  for ( size_t i = 0; i < 100; i++ )
    UTST_ASSERT_INT_EQ( vec.find_closest( i ), 100 );

  UTST_ASSERT_INT_EQ( vec.find_closest( 250 ), 209 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 350 ), 319 );
  UTST_ASSERT_INT_EQ( vec.find_closest( 450 ), 429 );
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Add more test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

 void test_case_14_default_constructor()
 {
     std::printf( "\n%s\n", __func__ );

     VectorInt vec ;
     UTST_ASSERT_INT_EQ(0,vec.size()) ;

     int array[5]={26,34,2,80,7} ;
     size_t size = 5 ;

    for ( size_t i = 0; i < size; i++ )  
     vec.push_back(array[i]) ;

    UTST_ASSERT_INT_EQ(size,vec.size()) ;

     for ( size_t i = 0; i < size; i++ )   
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);
  
 }

 void test_case_15_non_default_constructor()
 {

std::printf( "\n%s\n", __func__ );

 int array[5]={26,34,2,80,7} ;
   size_t size = 5 ;
   VectorInt vec(array,size) ;

   UTST_ASSERT_INT_EQ(size,vec.size()) ;

   for ( size_t i = 0; i < size; i++ ) {   
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);
  }

 }
 void test_case_16_find()
 {
  std::printf( "\n%s\n", __func__ );

    size_t size = 10 ;
    VectorInt vec ;

    for ( size_t i = 0; i < size; i++ ) {   
      vec.push_back(i) ;
   }


for ( size_t i = 0; i < size; i++ ) {   
     UTST_ASSERT_TRUE( vec.find(i));
  }

 }
 void test_case_17_find_closest()
 {

  std::printf( "\n%s\n", __func__ );


  VectorInt vec;

  vec.push_back ( 19 ); 
  vec.push_back ( 95 ); 
  vec.push_back ( 4  ); 
  vec.push_back ( 23  );

   UTST_ASSERT_INT_EQ( vec.find_closest(25),23);

 }
 void test_case_18_sort()
 {

  std::printf( "\n%s\n", __func__ );


    VectorInt vec;
    size_t size = 10 ;

    for ( size_t i = size-1; i > 0; i-- ) {   
      vec.push_back(i) ;
   }
   vec.push_back(0) ;

   vec.sort() ;

   for ( size_t i = 0; i < size ; i++ ) {   
      UTST_ASSERT_INT_EQ( vec.at(i),i);
    }



 }
 void test_case_19_index_operator()
 {
  std::printf( "\n%s\n", __func__ );


   VectorInt vec;

  vec.push_back ( 19 ); 
  vec.push_back ( 95 ); 
  vec.push_back ( 4  ); 
  vec.push_back ( 23  );

   UTST_ASSERT_INT_EQ( vec[0],19);
   UTST_ASSERT_INT_EQ( vec[1],95);
   UTST_ASSERT_INT_EQ( vec[2],4);
   UTST_ASSERT_INT_EQ( vec[3],23);

 }
 void test_case_20_copy_constructor()
 {
  std::printf( "\n%s\n", __func__ );

   VectorInt vec1;

  vec1.push_back ( 19 ); 
  vec1.push_back ( 95 ); 
  vec1.push_back ( 4  ); 
  vec1.push_back ( 23  );

  VectorInt vec2(vec1) ;

  UTST_ASSERT_INT_EQ(vec1.size() , vec2.size());

  UTST_ASSERT_INT_EQ(vec1.at(0) , vec2.at(0));
  UTST_ASSERT_INT_EQ(vec1.at(1) , vec2.at(1));
  UTST_ASSERT_INT_EQ(vec1.at(2) , vec2.at(2));
  UTST_ASSERT_INT_EQ(vec1.at(3) , vec2.at(3));

 }

 void test_case_21_assignment_operator()
 {

std::printf( "\n%s\n", __func__ );

VectorInt vec1;

  vec1.push_back ( 19 ); 
  vec1.push_back ( 95 ); 
  vec1.push_back ( 4  ); 
  vec1.push_back ( 23  );

  VectorInt vec2 = vec1 ;

  UTST_ASSERT_INT_EQ(vec1.size() , vec1.size());

  UTST_ASSERT_INT_EQ(vec1.at(0) , vec1.at(0));
  UTST_ASSERT_INT_EQ(vec1.at(1) , vec1.at(1));
  UTST_ASSERT_INT_EQ(vec1.at(2) , vec1.at(2));
  UTST_ASSERT_INT_EQ(vec1.at(3) , vec1.at(3));

  std::printf( "\n");

 }

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1  ) ) test_case_1_simple_push_back();
  if ( ( __n == 0 ) || ( __n == 2  ) ) test_case_2_at_out_of_bound();
  if ( ( __n == 0 ) || ( __n == 3  ) ) test_case_3_construct();
  if ( ( __n == 0 ) || ( __n == 4  ) ) test_case_4_find_simple();
  if ( ( __n == 0 ) || ( __n == 5  ) ) test_case_5_find_empty();
  if ( ( __n == 0 ) || ( __n == 6  ) ) test_case_6_find_closest();
  if ( ( __n == 0 ) || ( __n == 7  ) ) test_case_7_find_closest_empty();
  if ( ( __n == 0 ) || ( __n == 8  ) ) test_case_8_sort_simple();
  if ( ( __n == 0 ) || ( __n == 9  ) ) test_case_9_subscript();
  if ( ( __n == 0 ) || ( __n == 10 ) ) test_case_10_copy();
  if ( ( __n == 0 ) || ( __n == 11 ) ) test_case_11_assignment_empty();
  if ( ( __n == 0 ) || ( __n == 12 ) ) test_case_12_assignment_non_empty();
  if ( ( __n == 0 ) || ( __n == 13 ) ) test_case_13_general();

  // //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // // Add your test cases here
  // //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  if ( ( __n == 0 ) || ( __n == 14  ) ) test_case_14_default_constructor();
  if ( ( __n == 0 ) || ( __n == 15  ) ) test_case_15_non_default_constructor();
  if ( ( __n == 0 ) || ( __n == 16 ) ) test_case_16_find();
  if ( ( __n == 0 ) || ( __n == 17 ) ) test_case_17_find_closest();
  if ( ( __n == 0 ) || ( __n == 18 ) ) test_case_18_sort();
  if ( ( __n == 0 ) || ( __n == 19  ) ) test_case_19_index_operator();
  if ( ( __n == 0 ) || ( __n == 20 ) ) test_case_20_copy_constructor();
  if ( ( __n == 0 ) || ( __n == 21 ) ) test_case_21_assignment_operator();
}
