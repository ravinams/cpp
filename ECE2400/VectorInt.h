//========================================================================
// VectorInt.h
//========================================================================
// Declarations for VectorInt.

#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include <cstddef>

class VectorInt
{
public:
  VectorInt();
  ~VectorInt();

  // Copy constructor
  VectorInt( const VectorInt& vec );

  // Construct from an array
  VectorInt( int* array, size_t size );

  // Methods
  size_t size() const;
  void   push_back( int value );
  int    at( size_t idx ) const;
  bool   find( int value ) const;
  int    find_closest( int value ) const;
  void   sort();
  void   print() const;

  // Operator overloading
  int        operator[]( size_t idx ) const;
  VectorInt& operator=( const VectorInt& vec );

private:

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  int *m_arr=NULL;  
  size_t m_size ;

  void clear();
  void copy(int *source,size_t size);

};

#include "VectorInt.inl"

#endif // VECTOR_INT_H
