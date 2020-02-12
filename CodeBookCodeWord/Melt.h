#ifndef MELT_H
#define MELT_H

#include <iostream>

class Melt
{
private:
    char value ;
    int modulus  ;
public:
   Melt() ;
   Melt(char c) ;  
  ~Melt();   
   char getValue() const  ;
   void setValue(const char v) ;
   int operator-(const Melt &m2) ;
   friend std::ostream& operator<<(std::ostream& os, const Melt & input);
   
};
#endif