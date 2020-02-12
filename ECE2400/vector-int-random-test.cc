//========================================================================
// vector-int-random-test.cc
//========================================================================
// This file contains random tests for VectorInt-related functions.

#include "ece2400-stdlib.h"
#include "VectorInt.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_push_back_random
//------------------------------------------------------------------------
// A random test case that tests push back.

void test_case_1_push_back_random()
{
  std::printf( "\n%s\n", __func__ );

  const unsigned int iterations = 10;

  for ( unsigned int i = 0; i < iterations; i++ ) {
    VectorInt vec;

    const unsigned int size = rand() % 1000;
    int*               data = new int[size];

    for ( unsigned int j = 0; j < size; j++ ) {
      int random = rand();
      vec.push_back( random );
      data[j] = random;
    }

    UTST_ASSERT_INT_EQ( vec.size(), size );

    // Check vector against array that has same elements
    //  at the same index
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_INT_EQ( vec.at( j ), data[j] );
      UTST_ASSERT_INT_EQ( vec[j], data[j] );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_2_copy_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_2_copy_random()
{
  std::printf( "\n%s\n", __func__ );

  const unsigned int iterations = 10;

  for ( unsigned int i = 0; i < iterations; i++ ) {
    VectorInt vec;
    VectorInt vec0;

    const unsigned int size     = rand() % 1000;
    const unsigned int add_size = rand() % 1000;

    int* data = new int[size];
    // additional data to add onto vec0 and vec1
    int* data0 = new int[add_size];

    for ( unsigned int j = 0; j < size; j++ ) {
      int random = rand();
      vec.push_back( random );
      data[j] = random;
    }

    // Assignment operator
    vec0 = vec;

    // Copy constructor
    VectorInt vec1( vec0 );

    // Add more elements to vec0 and vec1
    for ( unsigned int j = 0; j < add_size; j++ ) {
      int random = rand();
      vec0.push_back( random );
      vec1.push_back( random );
      data0[j] = random;
    }

    UTST_ASSERT_TRUE( vec.size() == size );
    UTST_ASSERT_TRUE( vec0.size() == size + add_size );
    UTST_ASSERT_TRUE( vec1.size() == size + add_size );

    // Check the copied elements
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_INT_EQ( vec.at( j ), data[j] );
      UTST_ASSERT_INT_EQ( vec[j], data[j] );
      UTST_ASSERT_INT_EQ( vec0.at( j ), data[j] );
      UTST_ASSERT_INT_EQ( vec0[j], data[j] );
      UTST_ASSERT_INT_EQ( vec1.at( j ), data[j] );
      UTST_ASSERT_INT_EQ( vec1[j], data[j] );
    }

    // Check additional elements for vec0 and vec1
    for ( unsigned int j = 0; j < add_size; j++ ) {
      UTST_ASSERT_INT_EQ( vec0.at( size + j ), data0[j] );
      UTST_ASSERT_INT_EQ( vec0[size + j], data0[j] );
      UTST_ASSERT_INT_EQ( vec1.at( size + j ), data0[j] );
      UTST_ASSERT_INT_EQ( vec1[size + j], data0[j] );
    }

    delete[] data;
    delete[] data0;
  }
}

//------------------------------------------------------------------------
// test_case_3_array_construct_random
//------------------------------------------------------------------------
// A random test case that tests construct VectorInt from an array.

void test_case_3_array_construct_random()
{
  std::printf( "\n%s\n", __func__ );

  const unsigned int iterations = 10;

  for ( unsigned int i = 0; i < iterations; i++ ) {
    const unsigned int size = rand() % 1000;

    int* data = new int[size];

    for ( unsigned int j = 0; j < size; j++ ) {
      data[j] = j;
    }

    // Construct the vector from an array
    VectorInt vec( data, size );

    // Modify the array to test deepcopy
    for ( unsigned int j = 0; j < size; j++ ) {
      data[j] = size + 1;
    }

    // Check that the value inside the vector is not modified
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_INT_EQ( vec.at( j ), j );
      UTST_ASSERT_INT_EQ( vec[j], j );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_4_find_closest_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

void test_case_4_find_closest_random()
{
  std::printf( "\n%s\n", __func__ );

  const unsigned int iterations = 10;

  for ( unsigned int i = 0; i < iterations; i++ ) {
    const unsigned int size = rand() % 1000;

    int* data   = new int[size];
    int  offset = rand() % 10 + 10;

    for ( unsigned int j = 0; j < size; j++ ) {
      data[j] = j * offset;
    }

    VectorInt vec( data, size );

    // Check the closest value for the multiples of offset plus one
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_INT_EQ( vec.find_closest( j * offset + 1 ), j * offset );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_5_general_random
//------------------------------------------------------------------------

void test_case_5_general_random()
{
  printf( "\n%s\n", __func__ );

  const unsigned int iterations = 10;

  for ( unsigned int i = 0; i < iterations; i++ ) {
    const unsigned int size = rand() % 1000;
    int*               data = new int[size];
    VectorInt          vec;

    for ( unsigned int j = 0; j < size; j++ ) {
      data[j] = j;
      vec.push_back( j );

      UTST_ASSERT_INT_EQ( vec.size(), j + 1 );
    }

    // Test at and find, expecting successful
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_TRUE( vec.find( j ) );
      UTST_ASSERT_INT_EQ( vec.at( j ), j );
    }

    // Test find, expecting not successful
    for ( unsigned int j = size; j < size * 2; j++ ) {
      UTST_ASSERT_FALSE( vec.find( j ) );
    }

    // Test find_closest
    for ( unsigned int j = 0; j < size; j++ ) {
      UTST_ASSERT_INT_EQ( vec.find_closest( j ), j );
    }

    // Test find_closets for values beyond 0 to size
    UTST_ASSERT_INT_EQ( vec.find_closest( size ), size - 1 );
    UTST_ASSERT_INT_EQ( vec.find_closest( -1 ), 0 );

    delete[] data;
  }
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement more test cases here.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

 void test_case_6_default_constructor_random(){

  std::printf( "\n%s\n", __func__ );

     VectorInt vec ;
     UTST_ASSERT_INT_EQ(0,vec.size()) ;

     int array[5] ;
     size_t size = 5 ;

    for ( size_t i = 0; i < size; i++ )  
    {
     array[i] = rand() ;
     vec.push_back(array[i]) ;

    }

    UTST_ASSERT_INT_EQ(size,vec.size()) ;

     for ( size_t i = 0; i < size; i++ )   
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);

 }
void test_case_7_non_default_constructor_random()
{
   printf( "\n%s\n", __func__ );
  
   int array[5] ;
   size_t size = 5 ;

   for ( size_t i = 0; i < size; i++ )  
    {
      array[i] = rand() ;
    }

   VectorInt vec(array,size) ;

   UTST_ASSERT_INT_EQ(size,vec.size()) ;

   for ( size_t i = 0; i < size; i++ ) {   
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);
  }

 }
 void test_case_8_find_random()
 {
   printf( "\n%s\n", __func__ );

    int array[5] ;
    size_t size = 5 ;
    VectorInt vec ;

    for ( size_t i = 0; i < size; i++ ) {  
      array[i] = rand() ; 
      vec.push_back(array[i]) ;
   }


for ( size_t i = 0; i < size; i++ ) {   
     UTST_ASSERT_TRUE( vec.find(array[i]));
  }

 }
 void test_case_9_at_random()
 {
   printf( "\n%s\n", __func__ );

    int array[5] ;
    size_t size = 5 ;
    VectorInt vec ;

    for ( size_t i = 0; i < size; i++ ) {  
      array[i] = rand() ; 
      vec.push_back(array[i]) ;
   }

   UTST_ASSERT_INT_EQ( vec.size(),size);

   for ( size_t i = 0; i < size; i++ ) 
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);

 }

void test_case_10_sort_random()
{
   printf( "\n%s\n", __func__ );

    int array[5] ;
    size_t size = 5 ;
    VectorInt vec ;

    for ( size_t i = 0; i < size; i++ ) {  
      array[i] = rand() ; 
      vec.push_back(array[i]) ;
   }

 ece2400::sort( array, size ) ;
   vec.sort() ;

  for ( size_t i = 0; i < size; i++ ) 
     UTST_ASSERT_INT_EQ( vec.at(i),array[i]);

 
 }

 void test_case_11_index_operator_random()
 {
   printf( "\n%s\n", __func__ );

   int array[5] ;
    size_t size = 5 ;
    VectorInt vec ;

    for ( size_t i = 0; i < size; i++ ) {  
      array[i] = rand() ; 
      vec.push_back(array[i]) ;
   }

  
  for ( size_t i = 0; i < size; i++ ) 
     UTST_ASSERT_TRUE( vec[i]==array[i]);

 }
 void test_case_12_copy_constructor_random()
 {
   printf( "\n%s\n", __func__ );

   VectorInt vec1;

    size_t size = 5 ;

  for ( size_t i = 0; i < size; i++ ) {  
     
      vec1.push_back(rand()) ;
   }

  VectorInt vec2(vec1) ;

  UTST_ASSERT_INT_EQ(vec1.size() , vec1.size());

  for ( size_t i = 0; i < size; i++ ) {  
     
      UTST_ASSERT_INT_EQ(vec1.at(i) , vec2.at(i));
   }
 }

 void test_case_13_assignment_operator_random()
 {
   printf( "\n%s\n", __func__ );

   VectorInt vec1;

    size_t size = 5 ;

  for ( size_t i = 0; i < size; i++ ) {  
     
      vec1.push_back(rand()) ;
   }

  VectorInt vec2 = vec1 ;

  UTST_ASSERT_INT_EQ(vec1.size() , vec1.size());

  for ( size_t i = 0; i < size; i++ ) {  
     
      UTST_ASSERT_INT_EQ(vec1.at(i) , vec2.at(i));
   }

   printf( "\n");
 }
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) )
    test_case_1_push_back_random();
  if ( ( __n == 0 ) || ( __n == 2 ) )
    test_case_2_copy_random();
  if ( ( __n == 0 ) || ( __n == 3 ) )
    test_case_3_array_construct_random();
  if ( ( __n == 0 ) || ( __n == 4 ) )
    test_case_4_find_closest_random();
  if ( ( __n == 0 ) || ( __n == 5 ) )
    test_case_5_general_random();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_default_constructor_random();
  if ( ( __n == 0 ) || ( __n == 7  ) ) test_case_7_non_default_constructor_random();
  if ( ( __n == 0 ) || ( __n == 8 ) ) test_case_8_find_random();
  if ( ( __n == 0 ) || ( __n == 9 ) ) test_case_9_at_random();
  if ( ( __n == 0 ) || ( __n == 10 ) ) test_case_10_sort_random();
  if ( ( __n == 0 ) || ( __n == 11  ) ) test_case_11_index_operator_random();
  if ( ( __n == 0 ) || ( __n == 12 ) ) test_case_12_copy_constructor_random();
  if ( ( __n == 0 ) || ( __n == 13 ) ) test_case_13_assignment_operator_random();
}
