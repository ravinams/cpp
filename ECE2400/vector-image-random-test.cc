//========================================================================
// vector-image-random-test.cc
//========================================================================
// This file contains random tests for VectorImage.

#include <iostream>
#include "ece2400-stdlib.h"
#include "VectorInt.h"
#include "Image.h"
#include "VectorImage.h"
#include "utst.h"

//------------------------------------------------------------------------
// rand_img
//------------------------------------------------------------------------
// Randomly generates an image.

Image rand_img( size_t ncols, size_t nrows )
{
  size_t size = ncols * nrows;
  int*   data = new int[size];

  // Randomly generates the data
  for ( size_t i = 0; i < size; i++ )
    data[i] = rand() % 256;

  Image img = Image( VectorInt( data, size ), ncols, nrows );
  delete[] data;
  return img;
}

// Overload rand_img

Image rand_img( size_t ncols, size_t nrows, int min_value, int max_value )
{
  size_t size = ncols * nrows;
  int*   data = new int[size];

  // Randomly generates the data
  for ( size_t i = 0; i < size; i++ )
    data[i] = min_value + rand() % max_value + 1;

  Image img = Image( VectorInt( data, size ), ncols, nrows );
  delete[] data;
  return img;
}

//------------------------------------------------------------------------
// test_case_1_push_back_random
//------------------------------------------------------------------------
// A random test case that tests push back.

void test_case_1_push_back_random()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xfaceb00c );

  const int ntrials = 10;

  for ( int i = 0; i < ntrials; i++ ) {
    VectorImage vec;

    const int size = rand() % 1000;
    Image*    data = new Image[size];

    for ( int j = 0; j < size; j++ ) {

      // Randomly picks ncols and nrows
      const size_t ncols = rand() % 28 + 1;
      const size_t nrows = rand() % 28 + 1;

      // Generate a random image
      Image img = rand_img( ncols, nrows );

      // Push back the image and also store it in the array
      vec.push_back( img );
      data[j] = img;
    }

    UTST_ASSERT_INT_EQ( vec.size(), size );

    // Check each image
    for ( int j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( vec.at( j ) == data[j] );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_2_find_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_2_find_random()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xbadc0de );

  const int ntrials = 1;

  for ( int i = 0; i < ntrials; i++ ) {
    VectorImage vec;

    const int size = rand() % 1000 + 1;

    Image* data = new Image[size];

    // Push back some images
    for ( int j = 0; j < size; j++ ) {

      // Randomly picks ncols and nrows
      const size_t ncols = rand() % 28 + 1;
      const size_t nrows = rand() % 28 + 1;

      // Push back to vector and the array
      Image img = rand_img( ncols, nrows, 0, 10 );
      data[j]   = img;
      vec.push_back( img );
    }

    // Search for images - expecting success
    for ( int j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( vec.find( data[i] ) );

    //Search for images - expecting failure
    for ( int j = 0; j < 1 ; j++ ) {
      const size_t ncols = 27 ;
      const size_t nrows = 1 ;
      std::printf("%zu %zu 11 20  \n", ncols,nrows);
      UTST_ASSERT_FALSE( vec.find( rand_img( ncols, nrows, 11, 20 ) ) );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_3_find_closest_small
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_3_find_closest_small()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xbadc0de );

  const int ntrials = 10;

  for ( int i = 0; i < ntrials; i++ ) {
    VectorImage vec;

    const int    size   = rand() % 1000 + 1;
    const size_t ncols  = rand() % 28 + 1;
    const size_t nrows  = rand() % 28 + 1;
    const int    nfinds = rand() % 100 + 1;

    // Randomly pick an index to insert a small imgae
    const int idx = rand() % size;

    // Insert images with large image
    for ( int j = 0; j < idx; j++ )
      vec.push_back( rand_img( ncols, nrows, 200, 255 ) );

    Image small_img = rand_img( ncols, nrows, 0, 10 );
    vec.push_back( small_img );

    // Keep pushing back images with large image
    for ( int j = idx; j < size; j++ )
      vec.push_back( rand_img( ncols, nrows, 200, 255 ) );

    // Try find_closest with small images
    for ( int j = 0; j < nfinds; j++ ) {
      Image random_img = rand_img( ncols, nrows, 0, 10 );
      UTST_ASSERT_TRUE( vec.find_closest( random_img ) == small_img );
    }
  }
}

//------------------------------------------------------------------------
// test_case_4_find_closest_large
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_4_find_closest_large()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xbadc0de );

  const int ntrials = 10;

  for ( int i = 0; i < ntrials; i++ ) {
    VectorImage vec;

    const int    size   = rand() % 1000 + 1;
    const size_t ncols  = rand() % 28 + 1;
    const size_t nrows  = rand() % 28 + 1;
    const int    nfinds = rand() % 100 + 1;

    // Randomly pick an index to insert a small imgae
    const int idx = rand() % size;

    // Insert images with large image
    for ( int j = 0; j < idx; j++ )
      vec.push_back( rand_img( ncols, nrows, 0, 10 ) );

    Image large_img = rand_img( ncols, nrows, 128, 255 );
    vec.push_back( large_img );

    // Keep pushing back images with large image
    for ( int j = idx; j < size; j++ )
      vec.push_back( rand_img( ncols, nrows, 0, 10 ) );

    // Try find_closest with small images
    for ( int j = 0; j < nfinds; j++ ) {
      Image random_img = rand_img( ncols, nrows, 128, 256 );
      UTST_ASSERT_TRUE( vec.find_closest( random_img ) == large_img );
    }
  }
}

//------------------------------------------------------------------------
// test_case_5_copy_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_5_copy_random()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xbadcafe );

  const int ntrials = 10;

  for ( int i = 0; i < ntrials; i ++ ) {
    VectorImage vec0;

    const int base_size = rand() % 1000 + 1;
    const int add_size  = rand() % 1000 + 1;

    Image* data  = new Image[base_size];
    Image* data0 = new Image[add_size];
    Image* data1 = new Image[add_size];

    // Push back to vec0
    for ( int j = 0; j < base_size; j++ ) {
      Image img = rand_img( 28, 28 );
      data[j] = img;
      vec0.push_back( img );
    }

    // Copy constructor
    VectorImage vec1 = VectorImage( vec0 );

    // Push back different images to vec0 and vec1
    for ( int j = 0; j < add_size; j++ ) {
      Image img0 = rand_img( 28, 28, 0,   127 );
      Image img1 = rand_img( 28, 28, 128, 255 );

      data0[j] = img0;
      data1[j] = img1;

      vec0.push_back( img0 );
      vec1.push_back( img1 );
    }

    // Check size
    UTST_ASSERT_INT_EQ( vec0.size(), base_size + add_size );
    UTST_ASSERT_INT_EQ( vec1.size(), base_size + add_size );

    // Check base
    for ( int j = 0; j < base_size; j++ ) {
      UTST_ASSERT_TRUE( vec0.at( j ) == data[j] );
      UTST_ASSERT_TRUE( vec0[j]      == data[j] );
      UTST_ASSERT_TRUE( vec1.at( j ) == data[j] );
      UTST_ASSERT_TRUE( vec1[j]      == data[j] );
    }

    // Check additional images
    for ( int j = 0; j < add_size; j++ ) {
      UTST_ASSERT_TRUE( vec0.at( j + base_size ) == data0[j] );
      UTST_ASSERT_TRUE( vec1.at( j + base_size ) == data1[j] );
      UTST_ASSERT_TRUE( vec0[j + base_size]      == data0[j] );
      UTST_ASSERT_TRUE( vec1[j + base_size]      == data1[j] );
    }

    delete[] data;
    delete[] data0;
    delete[] data1;
  }
}

//------------------------------------------------------------------------
// test_case_6_assignment_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_6_assignment_random()
{
  std::printf( "\n%s\n", __func__ );

  srand( 0xbadbed );

  const int ntrials = 10;

  for ( int i = 0; i < ntrials; i ++ ) {
    VectorImage vec0;
    VectorImage vec1;

    const int base_size = rand() % 1000 + 1;
    const int add_size  = rand() % 1000 + 1;

    Image* data  = new Image[base_size];
    Image* data0 = new Image[add_size];
    Image* data1 = new Image[add_size];

    // Push back to vec0
    for ( int j = 0; j < base_size; j++ ) {
      Image img = rand_img( 28, 28 );
      data[j] = img;
      vec0.push_back( img );
    }

    // Push back some garbage to vec1
    int rand_size = rand() % 30;
    for ( int j = 0; j < rand_size; j++ )
      vec1.push_back( rand_img( 28, 28 ) );

    // Assignment operator
    vec1 = vec0;

    // Push back different images to vec0 and vec1
    for ( int j = 0; j < add_size; j++ ) {
      Image img0 = rand_img( 28, 28, 0,   127 );
      Image img1 = rand_img( 28, 28, 128, 255 );

      data0[j] = img0;
      data1[j] = img1;

      vec0.push_back( img0 );
      vec1.push_back( img1 );
    }

    // Check size
    UTST_ASSERT_INT_EQ( vec0.size(), base_size + add_size );
    UTST_ASSERT_INT_EQ( vec1.size(), base_size + add_size );

    // Check base
    for ( int j = 0; j < base_size; j++ ) {
      UTST_ASSERT_TRUE( vec0.at( j ) == data[j] );
      UTST_ASSERT_TRUE( vec0[j]      == data[j] );
      UTST_ASSERT_TRUE( vec1.at( j ) == data[j] );
      UTST_ASSERT_TRUE( vec1[j]      == data[j] );
    }

    // Check additional images
    for ( int j = 0; j < add_size; j++ ) {
      UTST_ASSERT_TRUE( vec0.at( j + base_size ) == data0[j] );
      UTST_ASSERT_TRUE( vec1.at( j + base_size ) == data1[j] );
      UTST_ASSERT_TRUE( vec0[j + base_size]      == data0[j] );
      UTST_ASSERT_TRUE( vec1[j + base_size]      == data1[j] );
    }

    delete[] data;
    delete[] data0;
    delete[] data1;
  }
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement more test cases here.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1  ) ) test_case_1_push_back_random();
  if ( ( __n == 0 ) || ( __n == 2  ) ) test_case_2_find_random();
  if ( ( __n == 0 ) || ( __n == 3  ) ) test_case_3_find_closest_small();
  if ( ( __n == 0 ) || ( __n == 4  ) ) test_case_4_find_closest_large();
  if ( ( __n == 0 ) || ( __n == 5  ) ) test_case_5_copy_random();
  if ( ( __n == 0 ) || ( __n == 6  ) ) test_case_6_assignment_random();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
