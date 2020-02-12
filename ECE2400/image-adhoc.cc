//========================================================================
// image-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for Image.

#include <stdio.h>
#include "Image.h"
#include "VectorInt.h"
#include "digits.dat"

int main() {

  VectorInt vec( digit1_image, 28*28 );
  Image img( vec, 28, 28 );
  img.set_label( digit1_label );

  printf( "Print the Image:\n" );
  img.print();

  printf("Label of the image is %c\n", img.get_label() );

  

   //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
   int data0[] = { 1, 9, 9, 5, 0, 4, 2, 3 }; // sum 33
   Image img0 = Image( VectorInt( data0, 8 ), 2, 4 );   
   img0.set_label('x');  
   printf("\nLabel of the image is %c\n", img0.get_label() );
   printf("\nCols of the image is %zu\n", img0.get_ncols() );
   printf("\nRows of the image is %zu\n", img0.get_nrows() );
   printf("\nIntensity of the image is %d\n", img0.get_intensity() );
   printf("\nPixel values of the image is \n");

   for(size_t r = 0 ; r < img0.get_nrows() ; r++)  
        {
          for(size_t c = 0 ;c < img0.get_ncols() ; c++)  
          {
               printf("%d ",img0.at(c,r));        
          }
          printf("\n");        
        }

        printf( "\nPrint the Image:\n" );

   img.print();

   return 0;

}
