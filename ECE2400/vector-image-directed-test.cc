//========================================================================
// vector-image-directed-test.cc
//========================================================================
// This file contains directed tests for VectorImage-related functions.

#include "ece2400-stdlib.h"
#include "VectorInt.h"
#include "Image.h"
#include "VectorImage.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests default constructor, push_back, and at.

void test_case_1_simple_push_back()
{
  std::printf( "\n%s\n", __func__ );

  int data[][4] = {
    { 1, 9, 9, 5 },
    { 0, 4, 2, 3 },
    { 1, 1, 0, 3 }
  };

  // Use default constructor to construct empty vecotr
  VectorImage vec;

  // Check size for empty vector
  UTST_ASSERT_INT_EQ( vec.size(), 0 );

  // Push back some images
  for ( auto a : data )
    vec.push_back( Image( VectorInt( a, 4 ), 2, 2 ) );

  // Check value and size
  UTST_ASSERT_TRUE( vec[0].at( 0, 0 ) == 1 );
  UTST_ASSERT_TRUE( vec[0].at( 1, 0 ) == 9 );
  UTST_ASSERT_TRUE( vec[0].at( 0, 1 ) == 9 );
  UTST_ASSERT_TRUE( vec[0].at( 1, 1 ) == 5 );
  UTST_ASSERT_TRUE( vec[0] == Image( VectorInt( data[0], 4 ), 2, 2 ) );
  UTST_ASSERT_TRUE( vec[1] == Image( VectorInt( data[1], 4 ), 2, 2 ) );
  UTST_ASSERT_TRUE( vec[2] == Image( VectorInt( data[2], 4 ), 2, 2 ) );

  UTST_ASSERT_INT_EQ( vec.size(), 3 );
}

//------------------------------------------------------------------------
// test_case_2_at_out_of_bound
//------------------------------------------------------------------------
// Test that exception is properly thrown when at is out of bound.

void test_case_2_at_out_of_bound()
{
  std::printf( "\n%s\n", __func__ );

  VectorImage vec;

  // empty vector

  bool flag = false;
  try {
    vec.at( 0 );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // push back some images

  int data[][4] = {
    { 1, 9, 9, 5 },
    { 0, 4, 2, 3 }
  };

  vec.push_back( Image( VectorInt( data[0], 4 ), 1, 4 ) );
  vec.push_back( Image( VectorInt( data[1], 4 ), 2, 2 ) );

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

  int data[]  = { 1, 9, 9, 5, 0, 4, 2, 3 };
  int dummy[] = { 1, 1, 1, 1, 7, 7, 7, 7 };

  // An array of images
  Image images[] = {
    Image( VectorInt( data, 8 ), 2, 4 ),
    Image( VectorInt( data, 4 ), 1, 4 ),
    Image( VectorInt( data, 8 ), 4, 2 ),
    Image( VectorInt( data, 6 ), 2, 3 ),
  };

  VectorImage vec = VectorImage( images, 4 );

  // Modify the array to test deepcopy
  for ( Image& img : images )
    img = Image( VectorInt( dummy, 8 ), 8, 1 );

  // Check that the value inside the vector is not modified
  UTST_ASSERT_TRUE( vec.at( 0 ) == Image( VectorInt( data, 8 ), 2, 4 ) );
  UTST_ASSERT_TRUE( vec.at( 1 ) == Image( VectorInt( data, 4 ), 1, 4 ) );
  UTST_ASSERT_TRUE( vec.at( 2 ) == Image( VectorInt( data, 8 ), 4, 2 ) );
  UTST_ASSERT_TRUE( vec.at( 3 ) == Image( VectorInt( data, 6 ), 2, 3 ) );

  // Check size
  UTST_ASSERT_INT_EQ( vec.size(), 4 );
}

//------------------------------------------------------------------------
// test_case_4_find_simple
//------------------------------------------------------------------------
// A simple test case that tests find.

void test_case_4_find_simple()
{
  std::printf( "\n%s\n", __func__ );

  int data[][8] = {
    { 1, 9, 9, 5, 0, 4, 2, 3 },
    { 0, 4, 2, 3, 1, 9, 9, 5 },
    { 1, 9, 9, 4, 0, 9, 1, 7 },
    { 0, 8, 2, 0, 1, 9, 9, 6 }
  };

  // Construct an array of images - this will call the default constructor
  Image images[5];

  // Construct images from int array
  for ( int i = 0; i < 4; i++ )
    images[i] = Image( VectorInt( data[i], 8 ), 2, 4 );

  // Construct a vector of images
  VectorImage vec = VectorImage( images, 5 );

  vec.print() ;

  // Search for value, expecting success
  // UTST_ASSERT_TRUE( vec.find( images[0] ) );
  // UTST_ASSERT_TRUE( vec.find( images[1] ) );
  // UTST_ASSERT_TRUE( vec.find( images[2] ) );
  // UTST_ASSERT_TRUE( vec.find( images[3] ) );
  UTST_ASSERT_TRUE( vec.find( Image()   ) ); // Find empty image

  // Search for value, expecting failure
  int arr[] = { 8, 7, 6, 4, 5, 3, 2, 1 };
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data[0], 8 ), 4, 2 ) ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data[1], 6 ), 2, 3 ) ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data[3], 6 ), 1, 6 ) ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( arr,     8 ), 2, 4 ) ) );
}

//------------------------------------------------------------------------
// test_case_5_find_empty
//------------------------------------------------------------------------
// A simple test case that tests find for an empty vector.

void test_case_5_find_empty()
{
  std::printf( "\n%s\n", __func__ );

  // Construct an empty vector
  VectorImage vec;

  // Search for value, expecting failure
  int data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  UTST_ASSERT_FALSE( vec.find( Image() ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data, 8 ), 4, 2 ) ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data, 4 ), 4, 1 ) ) );
  UTST_ASSERT_FALSE( vec.find( Image( VectorInt( data, 6 ), 2, 3 ) ) );
}

//------------------------------------------------------------------------
// test_case_6_find_closest
//------------------------------------------------------------------------
// A simple test case that tests copy constructor and assignment operator.

void test_case_6_find_closest()
{
  std::printf( "\n%s\n", __func__ );

  int data[][8] = {
    { 1, 9, 9, 5, 0, 4, 2, 3 },
    { 1, 9, 9, 5, 0, 7, 3, 1 },
    { 1, 9, 9, 5, 0, 1, 2, 3 },
    { 2, 0, 0, 0, 1, 1, 0, 3 }
  };

  // An array of images
  Image images[] = {
    Image( VectorInt( data[0], 8 ), 2, 4 ),
    Image( VectorInt( data[1], 8 ), 2, 4 ),
    Image( VectorInt( data[2], 8 ), 2, 4 ),
    Image( VectorInt( data[3], 8 ), 2, 4 )
  };

  // Construct a vector of images
  VectorImage vec = VectorImage( images, 4 );

  // Find exact match
  UTST_ASSERT_TRUE( vec.find_closest( images[0] ) == images[0] );
  UTST_ASSERT_TRUE( vec.find_closest( images[1] ) == images[1] );
  UTST_ASSERT_TRUE( vec.find_closest( images[2] ) == images[2] );
  UTST_ASSERT_TRUE( vec.find_closest( images[3] ) == images[3] );

  // Find images that are not in the vector
  int   arr0[] = { 1, 9, 9, 5, 0, 5, 2, 4 };
  int   arr1[] = { 1, 9, 9, 4, 0, 8, 3, 0 };
  Image img    = Image( VectorInt( arr0, 8 ), 2, 4 );

  UTST_ASSERT_TRUE( vec.find_closest( img ) == images[0] );

  img = Image( VectorInt( arr1, 8 ), 2, 4 );
  UTST_ASSERT_TRUE( vec.find_closest( img ) == images[1] );
}

//------------------------------------------------------------------------
// test_case_7_find_closest_empty
//------------------------------------------------------------------------
// Test that the exception is properly thrown when calling find_closet on
// an empty vector.

void test_case_7_find_closest_empty()
{
  std::printf( "\n%s\n", __func__ );

  VectorImage vec;

  // find_closest on empty vector
  bool flag = false;
  try {
    vec.find_closest( Image() );
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

  int data[][8] = {
    { 1, 9, 9, 5, 0, 4, 2, 3 },
    { 1, 9, 9, 5, 0, 7, 3, 1 },
    { 1, 9, 9, 5, 0, 1, 2, 3 },
    { 2, 0, 0, 0, 1, 1, 0, 3 }
  };

  // An array of images
  Image images[] = {
    Image( VectorInt( data[0], 8 ), 2, 4 ),
    Image( VectorInt( data[1], 8 ), 2, 4 ),
    Image( VectorInt( data[2], 8 ), 2, 4 ),
    Image( VectorInt( data[3], 8 ), 2, 4 )
  };

  // Construct a vector of images
  VectorImage vec = VectorImage( images, 4 );

  vec.sort();

  UTST_ASSERT_TRUE( vec.at( 0 ) == images[3] );
  UTST_ASSERT_TRUE( vec.at( 1 ) == images[2] );
  UTST_ASSERT_TRUE( vec.at( 2 ) == images[0] );
  UTST_ASSERT_TRUE( vec.at( 3 ) == images[1] );
}

//------------------------------------------------------------------------
// test_case_9_subscript
//------------------------------------------------------------------------
// A simple test for the subscript operator.

void test_case_9_subscript()
{
  std::printf( "\n%s\n", __func__ );

  int data[][8] = {
    { 1, 9, 9, 5, 0, 4, 2, 3 },
    { 1, 9, 9, 5, 0, 7, 3, 1 },
    { 1, 9, 9, 5, 0, 1, 2, 3 },
    { 2, 0, 0, 0, 1, 1, 0, 3 }
  };

  // An array of images
  Image images[] = {
    Image( VectorInt( data[0], 8 ), 2, 4 ),
    Image( VectorInt( data[1], 8 ), 2, 4 ),
    Image( VectorInt( data[2], 8 ), 2, 4 ),
    Image( VectorInt( data[3], 8 ), 2, 4 )
  };

  // Construct a vector of images
  VectorImage vec = VectorImage( images, 4 );

  // Check the value using subscript operator
  for ( int i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( vec[i] == images[i] );
}

//------------------------------------------------------------------------
// test_case_10_copy
//------------------------------------------------------------------------
// A simple test case that tests copy constructor.

void test_case_10_copy()
{
  std::printf( "\n%s\n", __func__ );

  int data[][4] = {
    { 1, 9, 9, 5 },
    { 0, 4, 2, 3 },
    { 1, 9, 9, 5 },
    { 0, 7, 3, 1 },
  };

  int data0[][4] = {
    { 6, 5, 4, 3 },
    { 7, 6, 5, 4 },
    { 8, 7, 6, 5 },
    { 9, 8, 7, 6 }
  };

  int data1[][4] = {
    { 3, 4, 5, 6 },
    { 4, 5, 6, 7 },
    { 5, 6, 7, 8 },
    { 6, 7, 8, 9 }
  };

  // Array of images - first 4 iamges are the same
  Image images[] = {
    Image( VectorInt( data[0], 4 ), 2, 2 ),
    Image( VectorInt( data[1], 4 ), 2, 2 ),
    Image( VectorInt( data[2], 4 ), 2, 2 ),
    Image( VectorInt( data[3], 4 ), 2, 2 ),
  };

  Image images0[] = {
    Image( VectorInt( data0[0], 4 ), 2, 2 ),
    Image( VectorInt( data0[1], 4 ), 2, 2 ),
    Image( VectorInt( data0[2], 4 ), 2, 2 ),
    Image( VectorInt( data0[3], 4 ), 2, 2 ),
  };

  Image images1[] = {
    Image( VectorInt( data1[0], 4 ), 2, 2 ),
    Image( VectorInt( data1[1], 4 ), 2, 2 ),
    Image( VectorInt( data1[2], 4 ), 2, 2 ),
    Image( VectorInt( data1[3], 4 ), 2, 2 ),
  };

  // Empty vector
  VectorImage vec0;

  // Push back to vec0
  for ( auto img : images )
    vec0.push_back( img );

  // Copy constructor
  VectorImage vec1( vec0 );

  // Push different values to vec0 and vec1
  for ( auto img : images0 )
    vec0.push_back( img );

  for ( auto img : images1 )
    vec1.push_back( img );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec0[i]      == images[i] );
    UTST_ASSERT_TRUE( vec1.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec1[i]      == images[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i + 4 ) == images0[i] );
    UTST_ASSERT_TRUE( vec0[i + 4]      == images0[i] );
    UTST_ASSERT_TRUE( vec1.at( i + 4 ) == images1[i] );
    UTST_ASSERT_TRUE( vec1[i + 4]      == images1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_11_assignment_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a empty vector.

void test_case_11_assignment_empty()
{
  std::printf( "\n%s\n", __func__ );

  int data[][4] = {
    { 1, 9, 9, 5 },
    { 0, 4, 2, 3 },
    { 1, 9, 9, 5 },
    { 0, 7, 3, 1 },
  };

  int data0[][4] = {
    { 6, 5, 4, 3 },
    { 7, 6, 5, 4 },
    { 8, 7, 6, 5 },
    { 9, 8, 7, 6 }
  };

  int data1[][4] = {
    { 3, 4, 5, 6 },
    { 4, 5, 6, 7 },
    { 5, 6, 7, 8 },
    { 6, 7, 8, 9 }
  };

  // Array of images - first 4 iamges are the same
  Image images[] = {
    Image( VectorInt( data[0], 4 ), 2, 2 ),
    Image( VectorInt( data[1], 4 ), 2, 2 ),
    Image( VectorInt( data[2], 4 ), 2, 2 ),
    Image( VectorInt( data[3], 4 ), 2, 2 ),
  };

  Image images0[] = {
    Image( VectorInt( data0[0], 4 ), 2, 2 ),
    Image( VectorInt( data0[1], 4 ), 2, 2 ),
    Image( VectorInt( data0[2], 4 ), 2, 2 ),
    Image( VectorInt( data0[3], 4 ), 2, 2 ),
  };

  Image images1[] = {
    Image( VectorInt( data1[0], 4 ), 2, 2 ),
    Image( VectorInt( data1[1], 4 ), 2, 2 ),
    Image( VectorInt( data1[2], 4 ), 2, 2 ),
    Image( VectorInt( data1[3], 4 ), 2, 2 ),
  };

  // Empty vector
  VectorImage vec0;

  // Push back to vec0
  for ( auto img : images )
    vec0.push_back( img );

  // Assignment operator
  VectorImage vec1;
  vec1 = vec0;

  // Push different values to vec0 and vec1
  for ( auto img : images0 )
    vec0.push_back( img );

  for ( auto img : images1 )
    vec1.push_back( img );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec0[i]      == images[i] );
    UTST_ASSERT_TRUE( vec1.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec1[i]      == images[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i + 4 ) == images0[i] );
    UTST_ASSERT_TRUE( vec0[i + 4]      == images0[i] );
    UTST_ASSERT_TRUE( vec1.at( i + 4 ) == images1[i] );
    UTST_ASSERT_TRUE( vec1[i + 4]      == images1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_12_assignment_non_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a empty vector.

void test_case_12_assignment_non_empty()
{
  std::printf( "\n%s\n", __func__ );

  int data[][4] = {
    { 1, 9, 9, 5 },
    { 0, 4, 2, 3 },
    { 1, 9, 9, 5 },
    { 0, 7, 3, 1 },
  };

  int data0[][4] = {
    { 6, 5, 4, 3 },
    { 7, 6, 5, 4 },
    { 8, 7, 6, 5 },
    { 9, 8, 7, 6 }
  };

  int data1[][4] = {
    { 3, 4, 5, 6 },
    { 4, 5, 6, 7 },
    { 5, 6, 7, 8 },
    { 6, 7, 8, 9 }
  };

  // Array of images - first 4 iamges are the same
  Image images[] = {
    Image( VectorInt( data[0], 4 ), 2, 2 ),
    Image( VectorInt( data[1], 4 ), 2, 2 ),
    Image( VectorInt( data[2], 4 ), 2, 2 ),
    Image( VectorInt( data[3], 4 ), 2, 2 ),
  };

  Image images0[] = {
    Image( VectorInt( data0[0], 4 ), 2, 2 ),
    Image( VectorInt( data0[1], 4 ), 2, 2 ),
    Image( VectorInt( data0[2], 4 ), 2, 2 ),
    Image( VectorInt( data0[3], 4 ), 2, 2 ),
  };

  Image images1[] = {
    Image( VectorInt( data1[0], 4 ), 2, 2 ),
    Image( VectorInt( data1[1], 4 ), 2, 2 ),
    Image( VectorInt( data1[2], 4 ), 2, 2 ),
    Image( VectorInt( data1[3], 4 ), 2, 2 ),
  };

  // Empty vector
  VectorImage vec0;
  VectorImage vec1;

  // Push back to vec0
  for ( auto img : images )
    vec0.push_back( img );

  // Push back to vec1
  for ( auto img : images1 )
    vec1.push_back( img );

  for ( auto img : images0 )
    vec1.push_back( img );

  // Assignment operator
  vec1 = vec0;

  // Push different values to vec0 and vec1
  for ( auto img : images0 )
    vec0.push_back( img );

  for ( auto img : images1 )
    vec1.push_back( img );

  // Check size
  UTST_ASSERT_TRUE( vec0.size() == 8 );
  UTST_ASSERT_TRUE( vec1.size() == 8 );

  // Check the first 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec0[i]      == images[i] );
    UTST_ASSERT_TRUE( vec1.at( i ) == images[i] );
    UTST_ASSERT_TRUE( vec1[i]      == images[i] );
  }

  // Check the last 4 elements
  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at( i + 4 ) == images0[i] );
    UTST_ASSERT_TRUE( vec0[i + 4]      == images0[i] );
    UTST_ASSERT_TRUE( vec1.at( i + 4 ) == images1[i] );
    UTST_ASSERT_TRUE( vec1[i + 4]      == images1[i] );
  }
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Add more test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

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

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}
