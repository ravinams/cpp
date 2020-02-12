#include "Melt.h"

char Melt::getValue() const 
{
    return value;
}

void Melt::setValue(const char v)  
{
    value = v  ;
}

Melt::Melt() : value('a') {} ; // default 

Melt::Melt(char v) : value(v) {} ; //Parameterized constructor

Melt::~Melt()
{
    
}

int Melt::operator-(const Melt &m1) {

    // return (value != m1.getValue() ? 1 : 0 ) ;
    
     return ((value == m1.getValue() ? 0 : 1 )%26 + 26) % 26 ;   
}

std::ostream& operator<<(std::ostream& os, const Melt & input)
{
    os<<input.getValue() ;
}