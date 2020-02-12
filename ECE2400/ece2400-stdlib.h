//========================================================================
// ece2400-stdlib.h
//========================================================================
// Utility functions and classes for PA4.
//
// Author: Yanghui Ou
//   Date: Oct 28, 2019

#ifndef ECE2400_STDLIB_H
#define ECE2400_STDLIB_H

#include <string>

namespace ece2400
{

//------------------------------------------------------------------------
// Exception
//------------------------------------------------------------------------
// Base class for exceptions.


class Exception {};

//------------------------------------------------------------------------
// OutOfRangeException
//------------------------------------------------------------------------
// Exception for out of range access.

class OutOfRange : Exception
{
 public:
  OutOfRange();
  OutOfRange( const char* err_msg );

  std::string to_str() const;

 private:
  std::string m_err_msg;
};

//------------------------------------------------------------------------
// InvalidArgumentException
//------------------------------------------------------------------------
// Exception for out of range access.

class InvalidArgument : Exception
{
public:
  InvalidArgument();
  InvalidArgument( const char* err_msg );

  std::string to_str() const;

private:
  std::string m_err_msg;
};

#endif

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void print_array( int* a, size_t size );

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// Sorts an array of integer in ascending order using std::sort.

void sort( int* a, size_t size );

}