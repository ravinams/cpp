#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::ostream;
using std::vector;

// templated class for a polynomial, with coefficients of type T
// The type T is assumed to have a zero element 0
// Furthermore T is assumed to have implemented:
//   the + operator;
//   the == operator;
//   the << operator.
template<typename T>
class Polynomial {
public:

	// Default constructor. Constructs the polynomial "0"
	Polynomial() {
		// IMPLEMENT ME
		m_degree = 0 ;
		m_coefficients.push_back(0) ;
	}

	// Value constructor. Constructs a polynomial based on the vector
	// of coefficients, in descending order of exponents.
	// For example, if coef contains {0,6,8,9,4}, then it constructs
	// the polynomial 6x^3 + 8x^2 + 9x + 4
	Polynomial(vector<T> other) {
	    
	  
	  for (int i = other.size()-1 ; i >= 0; i--)
	        { 
	            T val = other.at(i) ;
	            //std::cout<<" TEMP :"<<i<<" --> "<<val<<std::endl ;
	           // if (val == 0 && other.at(0)==0)
	           //      continue ;
	            m_coefficients.push_back(val) ;
	        }
	     m_degree = m_coefficients.size()-1 ;
	     
	   //  for (int i = 0 ; i < m_coefficients.size() ; i++)
	   //     std::cout<<m_coefficients[i]<<" ";
	   // std::cout<<std::endl ;
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Return the degree of the polynomial.
	int degree() const {
	  return m_degree ;
	}

	// Return the coefficient of the x^i term. If i is negative or
	// larger than the degree, 0 is returned.
	T getCoef(int i) const {
	    if (i < 0 || i > m_degree)
	      return 0 ;
	    else
	      return m_coefficients[i] ; 
	
	}

	// Addition of two polynomials. This time it is a member function
	Polynomial operator+(const Polynomial& other) const {
	    
	   int maxSize = 0 ;
	   vector<T> v ;
	   if (m_coefficients.size() > other.m_coefficients.size())
	        {
	             maxSize = m_coefficients.size() ;
	        }
	   else
	        {
	           maxSize = other.m_coefficients.size();
	        }
	      
	   for (int i = 0 ; i < m_coefficients.size() ; i++)   
	       v.push_back(m_coefficients[i]) ;
	  
  for (int i = other.m_coefficients.size()-1 ; i >= 0 ; i--)
      {  
         v[i]= v[i]+other.m_coefficients.at(i); 
      }
	  
	   
	   vector<T> t ;
	   t.reserve(v.size());
	   for(int k =  v.size()-1 ;k >= 0 ; k--)
	       t.push_back(v[k]) ;
	   
	  
	   Polynomial<T> p(t);
	   return p ; 
	}

	// Print the polynomial, in descending order of coefficients and
	// with the usual "x^..." terms.
	// It is not necessary to print it "pretty".
	// For example, if the polynomial is 2x^4 + x^3 - 5x - 1, it is
	// sufficient to print it as 2x^4 + 1x^3 + 0x^2 + -5x^1 + -1x^0
	// Minor formatting differences will be accepted.
	// If you print it pretty you get up to 5 bonus marks (out of 100
	// for this task). See the testPrintPretty() test case.
	// (This bonus part may not be as easy as it seems...)
	friend ostream& operator<<(ostream& os, const Polynomial<T>& p) {
		std::string str ;
		
		 std::stringstream ss11;  
		 ss11<<p.getCoef(0) ;
		    
		 std::stringstream ss12;  
		 ss12<<0;
		 str = ss11.str()+"x^"+ss12.str();
		for (int i = 1 ; i < p.m_coefficients.size()  ; i ++)
		  { 
		    std::stringstream ss1;  
		    ss1<<p.getCoef(i) ;
		    
		    std::stringstream ss2;  
		    ss2<<i;
		    
		    str=ss1.str()+"x^"+ss2.str()+" + "+str;
		  }
		os<<str ;
		return os;
	}

private:
	// TODO: add any private variables/functions needed
	
   vector<T> m_coefficients ;
   int m_degree ;
   void setCoef(int i, T value)
    {
      m_coefficients[i]=value ;
    }
};
