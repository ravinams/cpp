#ifndef __INTMOD_H_
#define __INTMOD_H_

#include <iostream>
using std::ostream;
using std::cout;

// you can assume n is an integer >= 2
template<int n>
class IntMod {

public:

	// Default constructor. Should initialize value to 0
	IntMod() {
	  m_value= 0;
	}

	// Value constructor. Accepts any (positive or negative) integer
	// not necessarily within [0..n-1]
	IntMod(int v) {
	 m_value =v ;
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

    //copy assignment
    IntMod &operator = (const IntMod &t) 
    { 
     // Check for self assignment 
       if(this != &t) 
          m_value = t.m_value ;
      
      return *this; 
   } 

   //deefault destructor
    ~IntMod() {
	}
	
	// Returns the value of this IntMod as an integer, in
	// the range 0..n-1
	int toInt() const {
	   if (m_value < 0)
	    return m_value+n ;
	  else
	   return m_value%n ;
	}

	// Overloaded + operator for adding two IntMods.
	// The two operands must be of same type i.e. same value of n in IntMod<n>
	// otherwise would not compile.
	// For technical reasons they are defined inside the class body
	// even though they are friends; see e.g. https://en.cppreference.com/w/cpp/language/friend#Template_friend_operators
	friend IntMod operator+(const IntMod& lhs, const IntMod& rhs) {
	  return (lhs.m_value + rhs.m_value) % n ;
	}

	// Overloaded * operator for multiplying two IntMods.
	friend IntMod operator*(const IntMod& lhs, const IntMod& rhs) {
	   return (lhs.m_value * rhs.m_value) % n ;
	}

	// Overloaded == operator for comparing two IntMods.
	friend bool operator==(const IntMod& lhs, const IntMod& rhs) {
	    if (lhs.toInt() == rhs.toInt())
		   return true;
		else
		   return false ;
	}

	// Return the multiplicative inverse of the current number mod n
	// (note that this is a member function).
	// An inverse of a number x, modulo n, is a number y such that
	// x*y mod n == 1.
	// It is sufficient to simply test the above condition
	// for each number in 1,2,...,n-1. You don't need to implement any
	// "better" algorithms.
	// If the inverse does not exist, throw a std::domain_error exception.
	IntMod inverse() {
	    
	int x, y; 
    int g = gcdExtended(m_value, n, &x, &y); 
    if (g != 1) 
        throw std::domain_error("Inverse doesn't exist");
    else
    { 
        // m is added to handle negative x 
        int res = (x%n + n) % n; 
        IntMod<n> inv = res ;
        return inv ;
    } 
	}

	// Overloaded << operator, printing the IntMod like an integer
	friend ostream& operator<<(ostream& os, const IntMod& p) {
		os<<p.toInt() ;
		return os;
	}

private:
	// TODO: add any private variables/functions needed
	int m_value ;
	int gcdExtended(int a, int b, int *x, int *y)
	{
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
	}
};

#endif /* __INTMOD_H_ */
