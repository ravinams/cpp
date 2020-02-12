//========================================================================
// Image.h
//========================================================================
// Declarations for Image.

#ifndef IMAGE_H
#define IMAGE_H

#include <cstddef>
#include "VectorInt.h"

class Image
{
public:

  // Constructors
  Image();
  Image( const VectorInt& vec, size_t ncols, size_t nrows );

  // Methods
  size_t get_ncols() const;
  size_t get_nrows() const;
  int    at( size_t x, size_t y ) const;
  void   set_label( char l );
  char   get_label() const;
  int    get_intensity() const;
  void   print() const;

  // Operator overloading
  int    operator- ( const Image& rhs ) const;
  bool   operator< ( const Image& rhs ) const;
  bool   operator> ( const Image& rhs ) const;
  bool   operator<=( const Image& rhs ) const;
  bool   operator>=( const Image& rhs ) const;
  bool   operator==( const Image& rhs ) const;
  bool   operator!=( const Image& rhs ) const;

private:

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  VectorInt m_vec ;
  size_t m_cols ;
  size_t m_rows ;
  char m_label ;

  // Image&  operator= ( const Image& rhs ) ;
};

#include "Image.inl"

#endif // IMAGE_H
