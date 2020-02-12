//========================================================================
// image-random-test.cc
//========================================================================
// Test program that includes directed tests for Image.

#include "ece2400-stdlib.h"
#include "Image.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------

void test_case_1_simple()
{
  std::printf( "\n%s\n", __func__ );

  const char labels[10] = {'0', '1', '2', '3', '4',
                           '5', '6', '7', '8', '9'};
  // Construct a vector
  size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimension from 2 to 41
    size_t dim  = rand() % 40 + 2;
    size_t size = dim * dim;
    int*   data = new int[size];

    // For calculating intensity
    int intensity = 0;

    for ( size_t j = 0; j < size; j++ ) {
      data[j] = rand() % 100;
      intensity += data[j];
    }

    VectorInt vec( data, size );
    Image     img( vec, dim, dim );

    // Make sure img deepcopies
    vec = VectorInt();

    // Check vector initialization is correct
    size_t ind = 0;
    for ( size_t j = 0; j < dim; j++ ) {
      for ( size_t k = 0; k < dim; k++ ) {
        UTST_ASSERT_INT_EQ( img.at( k, j ), data[ind] );
        ind++;
      }
    }

    UTST_ASSERT_INT_EQ( img.get_intensity(), intensity );

    int label = rand() % 10;

    // Check get_label and set_label
    UTST_ASSERT_TRUE( img.get_label() == '?' );
    img.set_label( labels[label] );
    UTST_ASSERT_TRUE( img.get_label() == labels[label] );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_2_copy
//------------------------------------------------------------------------

void test_case_2_copy()
{
  std::printf( "\n%s\n", __func__ );

  const char labels[10] = {'0', '1', '2', '3', '4',
                           '5', '6', '7', '8', '9'};

  // Construct a vector
  size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    size_t dim       = rand() % 40 + 2;
    size_t size      = dim * dim;
    int*   data      = new int[size];
    int    intensity = 0;

    for ( size_t j = 0; j < size; j++ ) {
      data[j] = rand() % 100;
      intensity += data[j];
    }

    VectorInt vec( data, size );
    Image     img0( vec, dim, dim );

    // Change the vector
    vec = VectorInt();

    int label = rand() % 10;

    img0.set_label( labels[label] );

    // Use default assignment operator
    Image img1;
    img1 = img0;

    size_t ind = 0;
    for ( size_t j = 0; j < dim; j++ ) {
      for ( size_t k = 0; k < dim; k++ ) {
        UTST_ASSERT_INT_EQ( img0.at( k, j ), data[ind] );
        UTST_ASSERT_INT_EQ( img1.at( k, j ), data[ind] );
        ind++;
      }
    }

    UTST_ASSERT_INT_EQ( img0.get_intensity(), intensity );
    UTST_ASSERT_INT_EQ( img1.get_intensity(), intensity );

    UTST_ASSERT_TRUE( img0.get_label() == labels[label] );
    UTST_ASSERT_TRUE( img1.get_label() == labels[label] );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_3_compare
//------------------------------------------------------------------------

void test_case_3_compare()
{
  std::printf( "\n%s\n", __func__ );

  const size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimensions from 2 to 41
    size_t dim1 = rand() % 40 + 2;
    size_t dim2 = rand() % 40 + 2;

    size_t num_images = rand() % 10 + 1;
    size_t size       = dim1 * dim2;
    int**  data       = new int*[num_images];
    int*   intensity  = new int[num_images];
    Image* images     = new Image[num_images];

    for ( size_t j = 0; j < num_images; j++ ) {
      data[j] = new int[size];

      // Set intensity for image j to 0
      intensity[j] = 0;

      for ( size_t k = 0; k < size; k++ ) {
        data[j][k] = rand() % 100;
        intensity[j] += data[j][k];
      }

      VectorInt vec( data[j], size );
      images[j] = Image( vec, dim1, dim2 );

      delete[] data[j];
    }

    // Check vector_compare for random vectors
    for ( size_t j = 0; j < 20; j++ ) {
      int rand_i1 = rand() % num_images;
      int rand_i2 = rand() % num_images;

      // Check all boolean operators
      if ( intensity[rand_i1] == intensity[rand_i2] ) {
        UTST_ASSERT_FALSE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] <= images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] >= images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] == images[rand_i2] );
      }
      else if ( intensity[rand_i1] > intensity[rand_i2] ) {
        UTST_ASSERT_FALSE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] <= images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] == images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] >= images[rand_i2] );
      }
      else {
        UTST_ASSERT_FALSE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] >= images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] == images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] <= images[rand_i2] );
      }
    }

    delete[] images;
    delete[] intensity;
    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_4_exceptions
//------------------------------------------------------------------------

void test_case_4_exceptions()
{
  std::printf( "\n%s\n", __func__ );

  const int iterations = 100;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimensions from 2 to 41
    size_t dim1 = rand() % 40 + 2;
    size_t dim2 = rand() % 40 + 2;
    size_t size = dim1 * dim2;

    // Initialize vec
    int*      data = new int[size];
    VectorInt vec( data, size );

    // Try constructing an image that has a size greater than data size
    bool flag = false;
    try {
      Image img( vec, dim1 + 1, dim2 + 1 );
    } catch ( ece2400::InvalidArgument e ) {
      flag = true;
    }
    UTST_ASSERT_TRUE( flag );

    // Choose random dimension that can go over dimension sizes, and
    // test if invalid at throws exception
    size_t rand_dim1 = rand() % ( dim1 * 2 );
    size_t rand_dim2 = rand() % ( dim2 * 2 );
    flag             = false;
    try {
      Image img( vec, dim1, dim2 );
      img.at( rand_dim1, rand_dim2 );
    } catch ( ece2400::OutOfRange e ) {
      flag = true;
    }

    if ( rand_dim1 >= dim1 || rand_dim2 >= dim2 ) {
      UTST_ASSERT_TRUE( flag );
    }
    else {
      UTST_ASSERT_FALSE( flag );
    }

    delete[] data;
  }
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement more test cases here.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

 void test_case_5_constuctor_random()
  {
    std::printf( "\n%s\n", __func__ );

     Image img0 ;
     UTST_ASSERT_TRUE( img0.get_label() == '?' );
     UTST_ASSERT_TRUE( img0.get_ncols() == 0 );
     UTST_ASSERT_TRUE( img0.get_nrows() == 0 );

     //int data1[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33

      size_t size =8 ;
      int*   data1      = new int[size];

      for ( size_t j = 0; j < size; j++ ) {
        data1[j] = rand() % 100;      
      }

     Image img1 = Image( VectorInt( data1, size ), 2, 4 );

     UTST_ASSERT_TRUE( img1.get_label() == '?' );
     UTST_ASSERT_TRUE( img1.get_ncols() == 2 );
     UTST_ASSERT_TRUE( img1.get_nrows() == 4 );

      bool flag = false;

      // int data2[] = { 1, 9, 9, 5, 0, 4, 2, 3,9 }; // sum 33
       int*   data2      = new int[size];

       for ( size_t j = 0; j < size; j++ ) {
        data2[j] = rand() % 100;      
      }

     try {
   
     Image img2 = Image( VectorInt( data2, 9 ), 4, 2 );
   
  }
  catch ( ece2400::InvalidArgument e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  delete[] data1 ;
  delete[] data2 ;

  }
  void test_case_6_label_random()
  {
    std::printf( "\n%s\n", __func__ );

    Image empty_img;
  UTST_ASSERT_TRUE( empty_img.get_label() == '?' );

  // Construct an image
  //int   data[] = { 1, 9, 9, 5, 0, 4, 2, 3 };
  size_t size =8 ;
      int*   data      = new int[size];

      for ( size_t j = 0; j < size; j++ ) {
        data[j] = rand() % 100;      
      }
  Image img    = Image( VectorInt( data, 8 ), 4, 2 );

  // Check if label is initialized properly
  UTST_ASSERT_TRUE( img.get_label() == '?' );

  // Set label and check
  img.set_label( 'x' );

  UTST_ASSERT_TRUE( img.get_label() == 'x' );

  img.set_label( 'm' );
  img.set_label( 'n' );

  UTST_ASSERT_TRUE( img.get_label() == 'n' );

  delete[] data ;
  }
 void test_case_7_intensity_random() 
 {
  std::printf( "\n%s\n", __func__ );

  //int data0[] = { 1, 9, 9, 5, 10, 4, 2, 3 }; // sum 43
  //int data1[] = { 1, 9, 9, 4, 10, 9, 1, 7 }; // sum 50
  //int data2[] = { 1, 9, 9, 3, 10, 8, 2, 0 }; // sum 42

      size_t size =8 ;
      int*   data1      = new int[size];
      int*   data2      = new int[size];
      int*   data3      = new int[size];
      int intensity1=0,intensity2=0,intensity3=0 ;

      for ( size_t j = 0; j < size; j++ ) {

        data1[j] = rand() % 100;  
        intensity1 = intensity1 + data1[j];

        data2[j] = rand() % 100;  
        intensity2 = intensity2 + data2[j];

        data3[j] = rand() % 100;      
        intensity3 = intensity3 + data3[j];
      }

  // Construct vectors
  VectorInt vec0( data1, 8 );
  VectorInt vec1( data2, 8 );
  VectorInt vec2( data3, 8 );

  // Construct images
  Image img0( vec0, 2, 4 );
  Image img1( vec1, 2, 4 );
  Image img2( vec2, 2, 4 );

  // Check intensity
  UTST_ASSERT_INT_EQ( img0.get_intensity(), intensity1 );
  UTST_ASSERT_INT_EQ( img1.get_intensity(), intensity2 );
  UTST_ASSERT_INT_EQ( img2.get_intensity(), intensity3 );

  // Check the intensity of empty image
  UTST_ASSERT_INT_EQ( Image().get_intensity(), 0 );

  delete[] data1 ;
  delete[] data2 ;
  delete[] data3 ;

 }
 void test_case_8_operator_diff_random()
 {
   std::printf( "\n%s\n", __func__ );

  //int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  //int data1[] = { 1, 9, 9, 4, 0, 9, 1, 7 }; // sum 40

      size_t size =8 ;
      int*   data0      = new int[size];
      int*   data1      = new int[size];
     
     

      for ( size_t j = 0; j < size; j++ ) {
        data0[j] = rand() % 100;        
        data1[j] = rand() % 100;             
      }

  // Calculate the distance
  int dist = 0;
  for( int i = 0; i < 8; i++ )
    dist += ( data0[i] - data1[i] ) * ( data0[i] - data1[i] );

  // Construct images
  Image img0 = Image( VectorInt( data0, 8 ), 2, 4 );
  Image img1 = Image( VectorInt( data1, 8 ), 2, 4 );


  UTST_ASSERT_INT_EQ( img0-img1, 20744 );

  delete[] data0;
  delete[] data1 ;

 }

 void test_case_9_operator_compare_random()
 {
  std::printf( "\n%s\n", __func__ );

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  int data1[] = { 1, 9, 9, 5, 0, 8, 2, 0 }; // sum 32
  int data2[] = { 1, 9, 9, 6, 0, 4, 2, 1 }; // sum 32

  // Construct vectors
  VectorInt vec0( data0, 8 );
  VectorInt vec1( data1, 6 );
  VectorInt vec2( data2, 8 );

  // Construct images
  Image img0( vec0, 2, 4 );
  Image img1( vec1, 2, 3 );
  Image img2( vec2, 4, 2 );

  // Check comparison
  UTST_ASSERT_TRUE ( img1 <  img0 );
  UTST_ASSERT_FALSE( img2 <  img1 );
  UTST_ASSERT_TRUE ( img1 <= img0 );
  UTST_ASSERT_TRUE ( img2 <= img1 );
  UTST_ASSERT_TRUE ( img0 >  img1 );
  UTST_ASSERT_FALSE( img1 >  img2 );
  UTST_ASSERT_TRUE ( img0 >= img1 );
  UTST_ASSERT_TRUE ( img1 >= img2 );
  UTST_ASSERT_TRUE ( img0 != img2 );

 }
void test_case_10_operator_equality_random()
{
   std::printf( "\n%s\n", __func__ );

  int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
  int data1[] = { 1, 9, 9, 3, 0, 8, 2, 0 }; // sum 32
  int data2[] = { 1, 9, 9, 6, 0, 4, 2, 1 }; // sum 32

  // Construct vectors
  VectorInt vec0( data0, 8 );
  VectorInt vec1( data1, 8 );
  VectorInt vec2( data2, 8 );

  // Construct images
  Image img0( vec0, 2, 4 );
  Image img1( vec1, 2, 4 );
  Image img2( vec2, 2, 4 );

  // Check inequality and equality
  UTST_ASSERT_TRUE ( img0 != img2 );
  UTST_ASSERT_TRUE ( img1 != img2 );
  UTST_ASSERT_TRUE ( img0 != img1 );

  UTST_ASSERT_TRUE ( img0 == Image( VectorInt( data0, 8 ), 2, 4 ) );
  UTST_ASSERT_TRUE ( img1 == Image( VectorInt( data1, 8 ), 2, 4 ) );
  UTST_ASSERT_TRUE ( img2 == Image( VectorInt( data2, 8 ), 2, 4 ) );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) )
    test_case_1_simple();
  if ( ( __n == 0 ) || ( __n == 2 ) )
    test_case_2_copy();
  if ( ( __n == 0 ) || ( __n == 3 ) )
    test_case_3_compare();
  if ( ( __n == 0 ) || ( __n == 4 ) )
    test_case_4_exceptions();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

   if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_constuctor_random();
   if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_label_random();
   if ( ( __n == 0 ) || ( __n == 7 ) ) test_case_7_intensity_random() ;
   if ( ( __n == 0 ) || ( __n == 8 ) ) test_case_8_operator_diff_random();
   if ( ( __n == 0 ) || ( __n == 9 ) ) test_case_9_operator_compare_random();
   if ( ( __n == 0 ) || ( __n == 10 ) ) test_case_10_operator_equality_random();
   
  return 0;
}
