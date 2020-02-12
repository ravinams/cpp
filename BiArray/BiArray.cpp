#include "BiArray.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std  ;

// default constructor
BiArray::BiArray() {
  m_size =  0 ;
  m_capacity = INITIALCAP ;
  m_start_index = INITIALCAP/2 ;
  m_array = new int[m_capacity] ;
  memset(m_array, 0, sizeof(m_array)); 

  //cout<<"TEMP BiArray() :"<<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<m_capacity<<endl ;
}

// value constructor
BiArray::BiArray(int arr[], int size)  {
	// IMPLEMENT ME
	m_size =  size ;
	m_capacity = LO_THRESHOLD*size > INITIALCAP ? LO_THRESHOLD*size : INITIALCAP ;
	m_array = new int[m_capacity] ;
	memset(m_array, 0, sizeof(m_array)); 
	m_start_index = m_capacity/2 - m_size/2;
	
	/// std::cout<<" m_size = "<<m_size<<" m_capacity = "<<m_capacity<<" m_start_index = "<<m_start_index<<endl ;
	for ( int i = m_start_index, j=0 ; j < size ; i++ , j++)
	{
	    m_array[i] = arr[j]; 
	}
}

// destructor
BiArray::~BiArray() {
	// IMPLEMENT ME
	if (m_array != nullptr)
	   delete[] m_array ;
}

// copy constructor
BiArray::BiArray(const BiArray& other) {
	// IMPLEMENT ME

 m_size =  other.m_size ;
 m_capacity = other.m_capacity ;
 m_array = new int[m_capacity] ;
 
 m_start_index = m_capacity/2 - m_size/2;
 for ( int i = 0 ; i < m_capacity ; i++)
	{
	    m_array[i] = other.m_array[i]; 
	}
 
}

// move constructor
BiArray::BiArray(BiArray&& other) {
    
	// IMPLEMENT ME
	m_size =  other.m_size ;
    m_capacity = other.m_capacity ;
    m_start_index = other.m_start_index ;
    m_array = other.m_array ;
    other.m_array = nullptr ;
}

// copy assignment
BiArray& BiArray::operator=(const BiArray& other) {
	
	m_size =  other.m_size ;
    m_capacity = other.m_capacity ;
    if (m_array != nullptr)
       delete[] m_array ;
       
    m_array = new int[m_capacity] ;
    m_start_index = other.m_start_index ;
    
    for (int i = 0 ; i < m_capacity ; i++)
    {
        m_array[i] = other.m_array[i]; 
    }
    
   
    return * this  ;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
    
    m_size =  other.m_size ;
    m_capacity = other.m_capacity ;
    m_array = other.m_array ;
    m_start_index = other.m_start_index ;
    other.m_array = nullptr ;
    
   return * this ;
}

bool BiArray::get(int i, int& v) const {
   if (i > -1 && i < m_size)
       {
         v = m_array[m_start_index+i] ;
         return true  ;
       }
    return false  ;
    
}

bool BiArray::set(int i, int v) {
    
 if (i > -1 && i < m_size)
       {
         m_array[m_start_index+i]  = v ;
         return true  ;
       }
    return false  ;
}

int BiArray::operator[](int i) const {
   return m_array[m_start_index+i];
}

int& BiArray::operator[](int i) {
   return m_array[m_start_index+i] ;
}

void BiArray::push_back(int v) {
    
	if ( m_start_index == 0 || m_size == m_capacity)
	 {
	    resizeArray() ;
	 }
	 m_array[--m_start_index] = v ;
	 m_size ++ ;
	 
   //cout<<"TEMP push_back()"<< v <<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<m_capacity<<endl ;
}

bool BiArray::pop_back() {
    
    m_start_index++;
    m_size -- ;
    if (m_capacity > HI_THRESHOLD * m_size)
     resizeArray() ;
}

void BiArray::push_front(int v) {
	
	if ( m_start_index+m_size > m_capacity || m_size == m_capacity )
	 {
	    resizeArray() ;
	 }
	 m_array[m_start_index + m_size++] = v ;
	 
   //cout<<"TEMP push_front()"<< v <<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<m_capacity<<endl ;
}

bool BiArray::pop_front() {
    m_size -- ;
    if (m_capacity > HI_THRESHOLD * m_size)
       resizeArray() ;
    
}

int BiArray::getSize() const {
   return m_size ;
}

int BiArray::getCapacity() const {
  return m_capacity ;
}

string BiArray::print() const {
   //cout<<"TEMP print()"<<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<m_capacity<<endl ;
	  string arry = "[";
    for (int i = m_start_index ; i < m_start_index + m_size ; i++)
    {
      
      
       arry = arry+" "+to_string(m_array[i]);
    }
    arry = arry+" ]" ;
    return arry ;
}

string BiArray::printAll() const {
    
    string arry = "[";
  
    for (int i = 0 ; i < m_start_index  ; i++)
    {
       arry = arry+" "+"X";
    }
    
    for (int i = m_start_index ; i < m_start_index + m_size ; i++)
    {      
       arry = arry+" "+to_string(m_array[i]) ;
    }
    
    for (int i = m_start_index + m_size ; i < m_capacity ; i++)
    {
       arry = arry+" "+"X";
    }
   
    arry = arry+" ]" ;
    return arry ;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
   if ( lhs.getSize() != rhs.getSize() )
      return false;
   else
   {
       for (int i = 0 ; i < lhs.getSize() ; i++)
          if (lhs[i] != rhs[i])
              return false ;
   }
   return true  ;
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
 if ( lhs.getSize() != rhs.getSize() )
      return true;
   else
   {
       for (int i = 0 ; i < lhs.getSize() ; i++)
          if (lhs[i] == rhs[i])
               return false ;
   }
   return true  ;
}

	void BiArray::resizeArray() 
	{
	    
	     
       ///cout<<"TEMP before resizeArray() "<<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<m_capacity<<endl ;

       int newCapacity = LO_THRESHOLD*m_size ;
	     int *temp = new int[newCapacity] ;
	     int newStartIndex = newCapacity/2 - m_size/2;
	     
       //cout<<"TEMP newCapacity "<<newCapacity<<" "<<LO_THRESHOLD<<" "<<m_size<<endl ;

	     for ( int i = 0 ; i < m_size ; i++)
	     {
	        temp[newStartIndex+i] = m_array[m_start_index+i]; 
	     }
	     
	    m_capacity = newCapacity ;
	    delete[] m_array ;
      m_array=nullptr ;

	    m_array = temp ;
	    m_start_index = newStartIndex ;

      //cout<<"TEMP After resizeArray() "<<" | m_start_index = "<<m_start_index <<" | m_size = "<<m_size << "| m_capacity = "<<newCapacity<<endl ;
	    
	}
