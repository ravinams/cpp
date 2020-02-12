//========================================================================
// HRSLinearSearch.cc
//========================================================================
// Handwritten recognition system that uses linear search.

#include <iostream>
#include <cstddef>
#include "Image.h"
#include "VectorImage.h"
#include "HRSLinearSearch.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSLinearSearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  HRSLinearSearch::HRSLinearSearch()
  {

  }

  void  HRSLinearSearch::train   ( const VectorImage& vec )
  {
     m_vectorImage = vec ;
  }
  Image HRSLinearSearch::classify( const Image& img)
  {
     return m_vectorImage.find_closest(img) ;
  }