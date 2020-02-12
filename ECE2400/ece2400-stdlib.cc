//========================================================================
// ece2400-stdlib.cc
//========================================================================
// Utility functions and classes for PA4.
//
// Author: Yanghui Ou
//   Date: Oct 28, 2019

#include <algorithm>
#include <string>
//#include <cstdio>
#include "ece2400-stdlib.h"

using namespace ece2400;

//------------------------------------------------------------------------
// OutOfRange
//------------------------------------------------------------------------

OutOfRange::OutOfRange() { }

OutOfRange::OutOfRange( const char* err_msg )
  : m_err_msg( err_msg )
{ }

std::string OutOfRange::to_str() const
{
  return m_err_msg;
}

//------------------------------------------------------------------------
// InvalidArgument
//------------------------------------------------------------------------

InvalidArgument::InvalidArgument() { }

InvalidArgument::InvalidArgument( const char* err_msg )
  : m_err_msg( err_msg )
{ }

std::string InvalidArgument::to_str() const
{
  return m_err_msg;
}

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void ece2400::print_array( int* a, size_t size )
{
  if ( size > 0 )
    std::printf( "%d", a[0] );
  for ( size_t i = 1; i < size; i++ )
    std::printf( ", %d", a[i] );
  std::printf( "\n" );
}

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// Sorts an array of integer in ascending order using std::sort.

void ece2400::sort( int* a, size_t size )
{
  std::sort( a, a + size );
}
