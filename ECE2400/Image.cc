//========================================================================
// Image.cc
//========================================================================
// Implementations for Image.

#include "ece2400-stdlib.h"
#include "Image.h"

//------------------------------------------------------------------------
// print_pixel
//------------------------------------------------------------------------
// A helper function that prints a grayscale pixel using unicode based on
// the integer value.

void print_pixel( int v )
{
  if ( v <= 0 )
    std::printf( "%s", "  " );
  else if ( 0 < v && v <= 64 )
    std::printf( "%s", "\u2591\u2591" );
  else if ( 64 < v && v <= 128 )
    std::printf( "%s", "\u2592\u2592" );
  else if ( 128 < v && v <= 192 )
    std::printf( "%s", "\u2593\u2593" );
  else
    std::printf( "%s", "\u2588\u2588" );
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Image.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Image::Image()
{
   m_cols = 0 ;
   m_rows = 0;
   m_label = '?';
}

Image::Image( const VectorInt& vec, size_t ncols, size_t nrows )
{
   if (nrows * ncols != vec.size() )
     throw ece2400::InvalidArgument("Size does not match the number of columns and number of rows.") ;
   m_vec = vec ;
   m_cols = ncols ;
   m_rows = nrows ;
   m_label = '?';
}

int Image::at( size_t x, size_t y ) const
{
  
  if ( m_vec.size() == 0 || (x >= m_cols || y >= m_rows))
     throw ece2400::OutOfRange("Out of range") ; //TEMP
   return m_vec.at(x+y*m_cols) ;
}

int Image::get_intensity() const
{
  int sum = 0 ;

  for(size_t i = 0 ;i < m_vec.size() ;i++)
    sum = sum+m_vec.at(i) ;

  return sum;
}

void Image::print() const
{
 for(size_t i = 0 ;i < m_vec.size() ;i++)
     print_pixel(m_vec.at(i)) ;
 printf("\n") ;
}

int Image::operator- ( const Image& rhs ) const
{   
   if (m_cols != rhs.get_ncols() || m_rows !=rhs.get_nrows())
     throw  ece2400::InvalidArgument("Dimensions does not match") ;
   int diff = 0;

     for(size_t r = 0 ; r < m_rows ; r++)  
        {
          for(size_t c = 0 ;c < m_cols ; c++)  
          {
             diff = diff + ( (at(c,r) - rhs.at(c,r)) * (at(c,r) - rhs.at(c,r))) ;             
          }
        }
          
   return diff ;
}
bool Image::operator< ( const Image& rhs ) const
{
  return get_intensity() < rhs.get_intensity() ;
}
bool Image::operator> ( const Image& rhs ) const
{
   return get_intensity() > rhs.get_intensity() ;
}
bool Image::operator<=( const Image& rhs ) const
{
  return get_intensity() <= rhs.get_intensity() ;
}
bool Image::operator>=( const Image& rhs ) const
{
  return get_intensity() >= rhs.get_intensity() ;
}
bool Image::operator==( const Image& rhs ) const
{
   // std::printf("source = %zu %zu ; riggt =  %zu %zu \n",m_cols,m_rows,rhs.get_ncols(),rhs.get_nrows()); // TEMP
   
   if (m_cols != rhs.get_ncols() || m_rows != rhs.get_nrows() )
     return false;
   else  if (get_intensity() == 0 && rhs.get_intensity()==0) // EMPTY IMAGE COMPARE
      return true ;

  // std::printf("Comparing -- \n"); // TEMP

   for(size_t i = 0 ; i < m_cols ; i++)    
     for(size_t j = 0 ; j < m_rows ; j++)  
         {  
          // std::printf("%d %d \n",at(i,j),rhs.at(i,j)); // TEMP

          if (at(i,j) != rhs.at(i,j))
             return false ;
          }
   return true ;
}
bool Image::operator!=( const Image& rhs ) const
{
   
   if (get_intensity() == 0 && rhs.get_intensity()==0)
      return false ;

   if (m_cols != rhs.get_ncols() || m_rows != rhs.get_nrows())
     return true;

   for(size_t i = 0 ; i < m_cols ; i++)    
     for(size_t j = 0 ; j < m_rows ; j++) 
         {
          if (at(i,j) != rhs.at(i,j))
             return true ;
          }
   return true ;
}

// Image&  Image::operator= ( const Image& rhs ) 
// {
//    m_cols = rhs.get_ncols() ;
//    m_rows = rhs.get_nrows() ;
//    m_label = rhs.get_label() ;
//    m_vec = rhs.m_vec ;

//    return *this ;
// }