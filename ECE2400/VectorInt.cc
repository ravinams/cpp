//========================================================================
// VectorInt.cc
//========================================================================
// Implementation of VectorInt.

#include "ece2400-stdlib.h"
#include "VectorInt.h"
#include <cstring>
#include <cstdio>


//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement VectorInt.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

VectorInt::VectorInt()
{
   
    m_size = 0 ;
	m_arr = NULL;
}
  VectorInt::~VectorInt()
  {
     clear();
     
  }

  // Copy constructor
  VectorInt::VectorInt( const VectorInt& vec )
  {
     
     m_size = vec.m_size;
     m_arr = new int[m_size] ;
     std::memcpy(m_arr,vec.m_arr,m_size*sizeof(int)) ;
  }

  // Construct from an m_array
  VectorInt::VectorInt( int* m_array, size_t size ){ 
    if (size ==0)  
      VectorInt() ;
    else
  	  copy(m_array,size) ;     
  }

  // Methods
  size_t VectorInt::size() const
  {
     return m_size ;
  }
  void   VectorInt::push_back( int value )
  {
     
     size_t newSize = m_size+1 ;
     int *tmp = new int[newSize] ;
     std::memcpy(tmp,m_arr,m_size*sizeof(int)) ;
     tmp[m_size] = value ;

     clear();
     m_arr = tmp ;
     m_size = newSize ;
  }
  int    VectorInt::at( size_t idx ) const
  {
  	 if (idx < m_size)
      return m_arr[idx] ;
     else
     	throw ece2400::OutOfRange("Index value must be less the size.") ;
  }
  bool   VectorInt::find( int value ) const
  {
  for (size_t i = 0 ;i < m_size ; i++)
    {
      if (m_arr[i]==value)
      	return true  ;
    }
    return false ;
  }
  int    VectorInt::find_closest( int value ) const
  {
     if (m_size == 0)
     	throw ece2400::OutOfRange("The vector is empty.") ;

     if (m_size == 1)
     	return m_arr[0] ;

     int *tmp = new int[m_size] ;  

     //std::memcpy(tmp,m_arr,m_size*sizeof(int)) ;

     for(size_t j = 0 ; j < m_size ; j++)
            tmp[j] = abs(m_arr[j]-value) ;

     int smallDiffIndex = 0 ;
     for(size_t j = 1 ; j < m_size ; j++)
     {
         if ( tmp[j] < tmp[smallDiffIndex] )
         	   smallDiffIndex = j ;
     }

    delete[] tmp ;

    return m_arr[smallDiffIndex];
  }

  void   VectorInt::sort()
  {
   ece2400::sort( m_arr, m_size ) ;
  }
  void   VectorInt::print() const
  {
  	ece2400::print_array( m_arr, m_size ) ;    
  }
  void   VectorInt::clear()
  {
     if (m_arr)
     delete[] m_arr ;
  }
  

void VectorInt::copy(int *source,size_t size)
{
	m_size = size;
    m_arr = new int[m_size] ;
    std::memcpy(m_arr,source,size*sizeof(int)) ;
}

VectorInt& VectorInt::operator=( const VectorInt& vec)
{
	
	if (m_size > 0)
		clear();
	copy(vec.m_arr,vec.m_size) ;
	return *this ;
}


