//========================================================================
// VectorImage.h
//========================================================================
// Declarations for VectorImage.

#ifndef VECTOR_IMAGE_H
#define VECTOR_IMAGE_H

#include <cstddef>
#include "Image.h"

class VectorImage
{
public:
  VectorImage();
  ~VectorImage();

  // Copy constructor
  VectorImage( const VectorImage& vec );
  VectorImage( Image* data, size_t size );

  // Methods
  size_t size() const;
  void   push_back( const Image& img );
  Image  at( size_t idx ) const;
  bool   find( const Image& img ) const;
  Image  find_closest( const Image& img ) const;
  void   sort();
  void   print() const;

  // Operator overloading
  Image        operator[]( size_t idx ) const;
  VectorImage& operator= ( const VectorImage& vec );

private:

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  Image *m_arr=NULL;  
  size_t m_size ;

 
  void clear();
  void copy(Image *source,size_t size);

};

#include "VectorImage.inl"

#endif // VECTOR_IMAGE_H
