//========================================================================
// HRSBinarySearch.h
//========================================================================
// Handwritten recognition system that uses linear search.

#ifndef HRS_BINARY_SEARCH_H
#define HRS_BINARY_SEARCH_H

#include "IHandwritingRecSys.h"
#include "VectorImage.h"

// Here we use forward declaration instead of #include. Forward
// declaration is a declaration of an identifier (type, variable, or
// class) before giving a complete definition.
//
// We should use forward declaration whenever possible. Using forward
// declaration is almost always better than using #include because
// #include may have some side effects such as:
// - including other headers you don't need
// - polluting the namespcae
// - longer compilation time

class Image;

//------------------------------------------------------------------------
// HRSLinearSearch
//------------------------------------------------------------------------

class HRSBinarySearch : public IHandwritingRecSys
{
public:
  HRSBinarySearch();

  void train   ( const VectorImage& vec );
  Image classify( const Image& img       );

private:

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  VectorImage m_vectorImage  ;
};

#endif
