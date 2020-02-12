//========================================================================
// HRSBinarySearch.cc
//========================================================================
// Handwritten recognition system that uses linear search.

#include <cstddef>
#include <iostream>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "VectorImage.h"
#include "HRSBinarySearch.h"

#define K 1000

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSBinarySearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  HRSBinarySearch::HRSBinarySearch()
  {

  }

  void  HRSBinarySearch::train   ( const VectorImage& vec )
  {
     m_vectorImage = vec ;
     m_vectorImage.sort() ;
  }
  Image HRSBinarySearch::classify( const Image& img)
  {
      size_t size =   m_vectorImage.size() ; 
      
      size_t l = 0 , r = size-1 , index = 0 ;

      while (l <= r) { 
        size_t m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (m_vectorImage.at(m) == img) 
        {
             index = m; 
             break  ;
        }
  
        // If x greater, ignore left half 
        if (m_vectorImage.at(m) < img) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 

  
    size_t half = K/2  ;
    size_t start_index = 0 , end_index = size-1 ;

    if ( half < index - 0 )
    	  start_index = index - half  ;

    if ( half < size - index )
    	   end_index = index + half  ;
   
    int euclidanIndex = start_index ;
    int euclidianDistance = m_vectorImage.at(start_index) - img ;

    
    for (size_t i = start_index+1 ; index > 0 && i < index-1 ;  i ++)
    {            
       int tempEuclidianDistance = m_vectorImage.at(i) - img ;
       if ( tempEuclidianDistance < euclidianDistance )
       	  {
       	    euclidianDistance = tempEuclidianDistance ;
       	    euclidanIndex = i  ;
       	  }


    }

    for (size_t j = index+1 ; index < size-1 && j <= end_index ; j ++)
    {
      
       int tempEuclidianDistance = m_vectorImage.at(j) - img ;
       if ( tempEuclidianDistance < euclidianDistance )
       	  {
       	    euclidianDistance = tempEuclidianDistance ;
       	    euclidanIndex = j  ;
       	  }
    }

   return m_vectorImage.at(euclidanIndex) ;

  }