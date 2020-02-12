//========================================================================
// VectorImage.cc
//========================================================================
// Implementation of VectorImage.

#include "ece2400-stdlib.h"
#include "VectorImage.h"
#include "Image.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement VectorImage.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

   VectorImage::VectorImage()
   {
      m_size = 0 ;
	  m_arr = NULL;
   }

  VectorImage::~VectorImage()
  {
    clear();
  }

  // Copy constructor
  VectorImage::VectorImage( const VectorImage& vec )
  {

     m_size = vec.m_size;
     m_arr = new Image[m_size] ;
     for (size_t i = 0 ; i < m_size ; i++)
     	  m_arr[i] = vec.at(i) ;     
  }

  VectorImage::VectorImage( Image* data, size_t size )
  {     
      copy(data,size) ;
  }

  // Methods
  size_t VectorImage::size() const
  {
   return m_size ;
  }
  void   VectorImage::push_back( const Image& img )
  {

     size_t newSize = m_size+1 ;
     Image *tmp = new Image[newSize] ;
     for (size_t i = 0 ; i < m_size ; i++)
     {
        tmp[i]=m_arr[i] ;
     }    
     tmp[m_size]=img ;

     clear();
     m_arr = tmp ;
     m_size = newSize ;

  }
  Image  VectorImage::at( size_t idx ) const
  {
      if (idx < m_size)
        return m_arr[idx] ;
     else
     	throw ece2400::OutOfRange("Index value must be less the size.") ;
  }

  bool   VectorImage::find( const Image& img ) const
  {
      
   for (size_t i = 0 ;i < m_size ; i++)
    {
      if (m_arr[i]==img)
      	return true  ;
    }
    return false ;
  }
  Image  VectorImage::find_closest( const Image& img ) const
  {
  	if (m_size == 0)
     	throw ece2400::OutOfRange("The vector is empty.") ;

     if (m_size == 1)
     	return m_arr[0] ;

     int *tmp = new int[m_size] ;  

     //std::memcpy(tmp,m_arr,m_size*sizeof(int)) ;

     for(size_t j = 0 ; j < m_size ; j++)
            tmp[j] = abs(m_arr[j]-img) ;

     int smallDiffIndex = 0 ;
     for(size_t j = 1 ; j < m_size ; j++)
     {
         if ( tmp[j] < tmp[smallDiffIndex] )
         	   smallDiffIndex = j ;
     }

    delete[] tmp ;

    return m_arr[smallDiffIndex];

  }
  void   VectorImage::sort()
  {
  	int min;
    Image temp;
    for (size_t pass = 0; pass <= m_size - 2; pass++)  // passes
    {
        min = pass;
        for (size_t j = pass + 1; j < m_size; j++)  // in each pass
            if (m_arr[min] > m_arr[j])
                min = j;
        temp = m_arr[min];
        m_arr[min] = m_arr[pass];
        m_arr[pass] = temp;
    }  
  }
  void   VectorImage::print() const
  {
    for(size_t j = 0 ; j < m_size ; j++)
     {
        m_arr[j].print() ;
     }
  }

  // Operator overloading

  VectorImage& VectorImage::operator= ( const VectorImage& vec )
  {
   if (m_size > 0)
		clear();
	copy(vec.m_arr,vec.m_size) ;
	return *this ;
  }

  void   VectorImage::clear()
  {
     if (m_arr)
     delete[] m_arr ;
  }
  

void VectorImage::copy(Image *source,size_t size)
{
	m_size = size;
    m_arr = new Image[m_size] ;
     for (size_t i = 0 ; i < m_size ; i++)
     	  m_arr[i] = source[i] ;    
}
 