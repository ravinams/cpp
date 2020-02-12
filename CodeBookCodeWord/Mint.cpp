#include "Mint.h"

int Mint::getValue() const {
    return value;
}

void Mint::setValue(const int v)  
{
    value = v  ;
}

Mint::Mint() : value ( 0 ){} ;//default constructor 


Mint::Mint(int v) : value (v){}; //Parameterized constructor


Mint::~Mint()
{

}

int Mint::operator-(const Mint &m1) {

   return ( (value - m1.getValue())%Mint::modulas + Mint::modulas) % Mint::modulas ;           
}

std::ostream& operator<<(std::ostream& os, const Mint & input)
{
    os<<input.getValue() ;
}